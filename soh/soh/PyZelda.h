#pragma once

#include <string>
#include <functional>
#include <concepts>
#include <type_traits>

#define PY_SSIZE_T_CLEAN
#include "Python.h"

template <std::string_view const&... Strs> struct join {
    // Join all strings into a single std::array of chars
    static constexpr auto impl() noexcept {
        constexpr std::size_t len = (Strs.size() + ... + 0);
        std::array<char, len + 1> arr{};
        auto append = [i = 0, &arr](auto const& s) mutable {
            for (auto c : s)
                arr[i++] = c;
        };
        (append(Strs), ...);
        arr[len] = 0;
        return arr;
    }
    // Give the joined string static storage
    static constexpr auto arr = impl();
    // View as a std::string_view
    static constexpr std::string_view value{ arr.data(), arr.size() - 1 };
};
// Helper to get the value out
template <std::string_view const&... Strs> static constexpr std::string_view join_v = join<Strs...>::value;

template <typename T, typename = void> struct GetTypeChar;

template <> struct GetTypeChar<unsigned char> { static constexpr std::string_view value = "b"; };

template <> struct GetTypeChar<char> { static constexpr std::string_view value = "c"; };

template <> struct GetTypeChar<short int> { static constexpr std::string_view value = "h"; };

template <> struct GetTypeChar<unsigned short int> { static constexpr std::string_view value = "H"; };

template <> struct GetTypeChar<int> { static constexpr std::string_view value = "i"; };

template <> struct GetTypeChar<unsigned int> { static constexpr std::string_view value = "I"; };

template <> struct GetTypeChar<float> { static constexpr std::string_view value = "f"; };

template <> struct GetTypeChar<double> { static constexpr std::string_view value = "d"; };

template <> struct GetTypeChar<char*> { static constexpr std::string_view value = "s"; };

template <typename T> struct GetTypeChar<T*> { static constexpr std::string_view value = "K"; };

template <typename ReturnType> static ReturnType GetCallResult(PyObject* ret);

template <> static int GetCallResult<int>(PyObject* ret) {
    return PyLong_AsLong(ret);
}
template <> static void GetCallResult<void>(PyObject* ret) {
    return;
}

static bool CheckError() {
    if (PyErr_Occurred()) {
        PyObject *ptype, *pvalue, *ptraceback;
        PyErr_Fetch(&ptype, &pvalue, &ptraceback);

        PyObject* msg = PyObject_Repr(pvalue);

        const char* pStrErrorMessage = PyUnicode_AsUTF8(msg);
        printf("%s", pStrErrorMessage);

        return true;
    }

    return false;
}

class CompiledScript {
  public:
    CompiledScript(const std::string& script);

    template <typename T> struct CallImpl;
    template <typename ReturnType, typename... ArgTypes> struct CallImpl<ReturnType(ArgTypes...)> {
        static constexpr std::string_view value = join_v<GetTypeChar<ArgTypes>::value...>;

        static PyObject* Call(PyObject* moduleObject, std::string name, ArgTypes... args) {
            PyObject* funcObject = PyObject_GetAttrString(moduleObject, name.c_str());

            CheckError();

            PyObject* retObject = PyObject_CallFunction(funcObject, value.data(), args...);

            CheckError();

            return retObject;
        }
    };

    template <typename T, typename... ArgsTypes> std::function<T>::result_type Call(std::string name, ArgsTypes... args) {
        return GetCallResult<std::function<T>::result_type>(CallImpl<T>::Call(moduleObject, name, args...));
    }

    private:
    PyObject* scriptObject;
    PyObject* moduleObject;
};

class PyZelda {
  public:
    static PyZelda* Instance;

    PyZelda();
    virtual ~PyZelda();

    void Run(const std::string& script);

    CompiledScript Compile(const std::string& script);
};
