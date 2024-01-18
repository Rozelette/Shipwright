#pragma once

#include "ScriptingImpl.h"

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

template <> struct GetTypeChar<signed char> { static constexpr std::string_view value = "c"; };

template <> struct GetTypeChar<short int> { static constexpr std::string_view value = "h"; };

template <> struct GetTypeChar<unsigned short int> { static constexpr std::string_view value = "H"; };

template <> struct GetTypeChar<int> { static constexpr std::string_view value = "i"; };

template <> struct GetTypeChar<unsigned int> { static constexpr std::string_view value = "I"; };

template <> struct GetTypeChar<float> { static constexpr std::string_view value = "f"; };

template <> struct GetTypeChar<double> { static constexpr std::string_view value = "d"; };

template <> struct GetTypeChar<char*> { static constexpr std::string_view value = "s"; };

template <typename T> struct GetTypeChar<T*> { static constexpr std::string_view value = "K"; };

template <typename ReturnType> static ReturnType GetCallResult(PyObject* ret);

template <> static void GetCallResult<void>(PyObject* ret) {
    return;
}
template <> static int GetCallResult<int>(PyObject* ret) {
    if (ret != nullptr) {
        int retValue = PyLong_AsLong(ret);
        Py_DECREF(ret);
        return retValue;
    }
    return 0;
}
template <> static unsigned int GetCallResult<unsigned int>(PyObject* ret) {
    if (ret != nullptr) {
        unsigned int retValue = PyLong_AsUnsignedLong(ret);
        Py_DECREF(ret);
        return retValue;
    }
    return 0;
}
template <> static short GetCallResult<short>(PyObject* ret) {
    if (ret != nullptr) {
        int retValue = PyLong_AsLong(ret);
        Py_DECREF(ret);
        return static_cast<short>(retValue);
    }
    return 0;
}
template <> static unsigned short GetCallResult<unsigned short>(PyObject* ret) {
    if (ret != nullptr) {
        unsigned int retValue = PyLong_AsUnsignedLong(ret);
        Py_DECREF(ret);
        return static_cast<unsigned short>(retValue);
    }
    return 0;
}
template <> static char GetCallResult<char>(PyObject* ret) {
    if (ret != nullptr) {
        int retValue = PyLong_AsLong(ret);
        Py_DECREF(ret);
        return static_cast<char>(retValue);
    }
    return 0;
}
template <> static unsigned char GetCallResult<unsigned char>(PyObject* ret) {
    if (ret != nullptr) {
        unsigned int retValue = PyLong_AsUnsignedLong(ret);
        Py_DECREF(ret);
        return static_cast<unsigned char>(retValue);
    }
    return 0;
}

static void PrintObject(PyObject* object) {
    if (object != nullptr) {
        PyObject* msg = PyObject_Repr(object);

        const char* msgString = PyUnicode_AsUTF8(msg);
        printf("%s\n", msgString);
        Py_XDECREF(msg);
    }
}

static bool CheckError() {
    if (PyErr_Occurred()) {
        PyObject* ptype;
        PyObject* pvalue;
        PyObject* ptraceback;
        PyErr_Fetch(&ptype, &pvalue, &ptraceback);

        PrintObject(ptype);
        PrintObject(pvalue);

        Py_XDECREF(ptype);
        Py_XDECREF(pvalue);
        Py_XDECREF(ptraceback);

        return true;
    }

    return false;
}

static void AssertError() {
    assert(!CheckError());
}

class CompiledPythonScript final : public ICompiledScript {
  public:
    CompiledPythonScript(const std::string& script);
    ~CompiledPythonScript();

    template <typename T> struct CallImpl;
    template <typename ReturnType, typename... ArgTypes> struct CallImpl<ReturnType(ArgTypes...)> {
        static constexpr std::string_view value = join_v<GetTypeChar<ArgTypes>::value...>;

        static PyObject* Call(PyObject* moduleObject, std::string name, ArgTypes... args) {
            PyObject* funcObject = PyObject_GetAttrString(moduleObject, name.c_str());

            AssertError();

            PyObject* retObject = PyObject_CallFunction(funcObject, value.data(), args...);

            AssertError();

            Py_XDECREF(funcObject);

            return retObject;
        }
    };

    bool FunctionExists(const std::string& name) override;

    template <typename T, typename... ArgsTypes> std::function<T>::result_type Call(std::string name, ArgsTypes... args) {
        return GetCallResult<std::function<T>::result_type>(CallImpl<T>::Call(moduleObject, name, args...));
    }

    template <typename T, typename... ArgsTypes> std::function<T>::result_type CallIfExists(std::string name, ArgsTypes... args) {
        if (!FunctionExists(name)) {
            return GetCallResult<std::function<T>::result_type>(nullptr);
        }
        return Call<T>(name, args...);
    }

    IScriptImplementation* GetImplementation() override;

    private:
    PyObject* scriptObject;
    PyObject* moduleObject;
};

class PyZelda : public IScriptImplementation {
  public:
    PyZelda();
    virtual ~PyZelda();

    void Run(const std::string& script) override;

    std::shared_ptr<ICompiledScript> Compile(const std::string& script) override;

    void* CreateActorInstanceData(size_t size) override;
    void DeleteActorInstanceData(void* data) override;

    ScriptLanguage GetLanguage() override {
        return ScriptLanguage::Python;
    }
};
