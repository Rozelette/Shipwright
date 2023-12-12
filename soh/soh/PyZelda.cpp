#include "PyZelda.h"
#include "z64actor.h"
#include "ScriptInterface.h"

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

template<typename T>
PyObject* GetResult(T* ret) {
    return PyLong_FromLongLong((uintptr_t)ret);
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
        Py_RETURN_NONE;
    }
};

template <typename T, T* Func> struct PythonFuncWrapper {
    static PyObject* WrappedFunc(PyObject* self, PyObject* args) {
        return PythonFuncWrapperImpl<T>::WrappedFunc(Func, self, args);
    }
};

#define METHOD_ENTRY(func, doc_string) \
    { #func, PythonFuncWrapper<decltype(func), func>::WrappedFunc, METH_VARARGS, doc_string }

using namespace ScriptInterface;

static PyMethodDef PyZeldaMethods[] = {
    METHOD_ENTRY(GetPlayer, "Test"),
    METHOD_ENTRY(GetActorX, "Test"),
    METHOD_ENTRY(GetActorY, "Test"),
    METHOD_ENTRY(GetActorZ, "Test"),
    METHOD_ENTRY(SetActorX, "Test"),
    METHOD_ENTRY(SetActorY, "Test"),
    METHOD_ENTRY(SetActorZ, "Test"),
    METHOD_ENTRY(SetActorScaleX, "Test"),
    METHOD_ENTRY(SetActorScaleY, "Test"),
    METHOD_ENTRY(SetActorScaleZ, "Test"),
    METHOD_ENTRY(DrawTemp, "Test"),
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
    CheckError();

    moduleObject = PyImport_ExecCodeModule("__test__", scriptObject);

    PyObject_SetAttrString(moduleObject, "__builtins__", PyEval_GetBuiltins());
    PyObject_SetAttrString(moduleObject, "PyZelda", PyInit_PyZelda());

    PyObject* msg = PyObject_Repr(moduleObject);

    const char* pStrErrorMessage = PyUnicode_AsUTF8(msg);
    printf("%s", pStrErrorMessage);

    CheckError();
}

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

    CheckError();

    //CompiledScript script = Compile(test_script_source);

    //int test = script.Call<ActorFunc>("Update", 6, 9);

    //printf("%i\n", test);

    volatile int bp = 0;
}

PyZelda::~PyZelda() {
    // TODO check error
    Py_FinalizeEx();
}

CompiledScript PyZelda::Compile(const std::string& script) {
    return CompiledScript(script);
}
