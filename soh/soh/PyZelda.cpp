#include "PyZelda.h"

#define PY_SSIZE_T_CLEAN
#include "Python.h"

#include <functional>
#include <string_view>
#include <array>
#include <tuple>
#include <utility>
#include <type_traits>

PyZelda* PyZelda::Instance;

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

PyObject* GetResult(int ret) {
    return PyLong_FromLong(ret);
}

template <typename T> struct PythonFuncWrapperImpl;

template <typename ReturnType, typename... ArgTypes> struct PythonFuncWrapperImpl<ReturnType(ArgTypes...)> {
    static constexpr std::string_view value = join_v<GetTypeChar<ArgTypes>::value...>;
    using IntSeq = std::index_sequence_for<ArgTypes...>;
    using FuncType = ReturnType(ArgTypes...);

    template <typename T, T... Ints>
    static PyObject* WrappedFuncImpl(FuncType func, PyObject* self, PyObject* args,
                                  std::integer_sequence<T, Ints...> int_seq) {
        std::tuple<ArgTypes...> argTuple;

        // TODO errors
        PyArg_ParseTuple(args, value.data(), &std::get<Ints>(argTuple)...);

        ReturnType ret = func(std::get<Ints>(argTuple)...);

        return GetResult(ret);
    }

    static PyObject* WrappedFunc(FuncType func, PyObject* self, PyObject* args) {
        return WrappedFuncImpl(func, self, args, IntSeq{});
    }
};

template <typename T, T* Func> struct PythonFuncWrapper {
    static PyObject* WrappedFunc(PyObject* self, PyObject* args) {
        return PythonFuncWrapperImpl<T>::WrappedFunc(Func, self, args);
    }
};

int test_method(int i) {
    return i + 1;
}

#define METHOD_ENTRY(func, doc_string) \
    { #func, PythonFuncWrapper<decltype(func), func>::WrappedFunc, METH_VARARGS, doc_string }

static PyMethodDef PyZeldaMethods[] = {
    METHOD_ENTRY(test_method, "Test"),
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef PyZeldaModule = {
    PyModuleDef_HEAD_INIT,
    "PyZelda",
    "Python interface for Zelda",
    -1,
    PyZeldaMethods
};

PyMODINIT_FUNC PyInit_PyZelda() {
    return PyModule_Create(&PyZeldaModule);
}

PyZelda::PyZelda() {
    Py_Initialize();

    PyObject* g = PyDict_New();
    PyObject* l = PyDict_New();

    PyDict_SetItemString(g, "__builtins__", PyEval_GetBuiltins());
    PyDict_SetItemString(g, "PyZelda", PyInit_PyZelda());

    PyObject* string_result = PyRun_StringFlags(
                                                "PyZelda.test_method(5)\n",
                                                Py_file_input, g, l, NULL);

    if (PyErr_Occurred()) {
        //PyErr_Print();

        PyObject *ptype, *pvalue, *ptraceback;
        PyErr_Fetch(&ptype, &pvalue, &ptraceback);
        // pvalue contains error message
        // ptraceback contains stack snapshot and many other information
        //(see python traceback structure)

        // Get error message
        const char* pStrErrorMessage = PyUnicode_AsUTF8(pvalue);
        printf(pStrErrorMessage);

        PyErr_Clear();
    }

    const char* buff;
    Py_ssize_t len;
    PyObject_AsCharBuffer(string_result, &buff, &len);

    volatile int bp = 0;
}

PyZelda::~PyZelda() {
    // TODO check error
    Py_FinalizeEx();
}
