#include "PyZelda.h"

#define PY_SSIZE_T_CLEAN
#include "Python.h"

#include <functional>
#include <string_view>
#include <array>
#include <tuple>
#include <utility>
#include <type_traits>
#include <concepts>

PyZelda* PyZelda::Instance;

const std::string test_script_source =
""
"def Update(play, actor):"
"    return play * actor + 5"
"";

PyObject* GetResult(int ret) {
    return PyLong_FromLong(ret);
}

template <typename T> struct PythonFuncWrapperImpl;

template <typename ReturnType, typename... ArgTypes> struct PythonFuncWrapperImpl<ReturnType(ArgTypes...)> {
    static constexpr std::string_view value = join_v<GetTypeChar<ArgTypes>::value...>;
    using IntSeq = std::index_sequence_for<ArgTypes...>;
    using FuncType = ReturnType(ArgTypes...);

    template <typename T, T... Ints>
    static ReturnType WrappedFuncImpl(FuncType func, PyObject* self, PyObject* args,
                                  std::integer_sequence<T, Ints...> int_seq) {
        std::tuple<ArgTypes...> argTuple;

        // TODO errors
        PyArg_ParseTuple(args, value.data(), &std::get<Ints>(argTuple)...);

        return func(std::get<Ints>(argTuple)...);
    }

    static PyObject* WrappedFunc(FuncType func, PyObject* self, PyObject* args) {
        return GetResult(WrappedFuncImpl(func, self, args, IntSeq{}));
    }

    static PyObject* WrappedFunc(FuncType func, PyObject* self, PyObject* args) requires std::is_same_v<ReturnType, void> {
        WrappedFuncImpl(func, self, args, IntSeq{});
        return nullptr;
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

void test_method2() {
    printf("yo");
}

#define METHOD_ENTRY(func, doc_string) \
    { #func, PythonFuncWrapper<decltype(func), func>::WrappedFunc, METH_VARARGS, doc_string }

static PyMethodDef PyZeldaMethods[] = {
    METHOD_ENTRY(test_method, "Test"),
    METHOD_ENTRY(test_method2, "Test"),
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

CompiledScript::CompiledScript(const std::string& script) {
    scriptObject = Py_CompileString(script.c_str(), "test.py", Py_file_input);
    // TODO check errors

    if (PyErr_Occurred()) {
        PyObject *ptype, *pvalue, *ptraceback;
        PyErr_Fetch(&ptype, &pvalue, &ptraceback);

        PyErr_Clear();
    }

    moduleObject = PyImport_ExecCodeModule("__test__", scriptObject);

    if (PyErr_Occurred()) {
        PyObject *ptype, *pvalue, *ptraceback;
        PyErr_Fetch(&ptype, &pvalue, &ptraceback);

        PyErr_Clear();
    }
}

using ActorFunc = int(int, int);

PyZelda::PyZelda() {
    Py_Initialize();

    PyObject* g = PyDict_New();
    PyObject* l = PyDict_New();

    PyDict_SetItemString(g, "__builtins__", PyEval_GetBuiltins());
    PyDict_SetItemString(g, "PyZelda", PyInit_PyZelda());

    /*
    PyRun_StringFlags(
                                                "PyZelda.test_method(5)\n"
                                                "PyZelda.test_method2()\n",
                                                Py_file_input, g, l, NULL);
                                                */

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

    CompiledScript script = CompiledScript(test_script_source);

    int test = script.Call<ActorFunc>("Update", 6, 9);

    printf("%i\n", test);

    volatile int bp = 0;
}

PyZelda::~PyZelda() {
    // TODO check error
    Py_FinalizeEx();
}
