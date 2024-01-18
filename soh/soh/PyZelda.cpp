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
#include <filesystem>
#include <fstream>

IScriptImplementation* PyZelda::Instance;

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

PyObject* GetResult(PyObject* ret) {
    Py_XINCREF(ret);
    return ret;
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
    { #func, PythonFuncWrapper < decltype(func), func> ::WrappedFunc, METH_VARARGS, doc_string }

#define METHOD_ENTRY_NAME(func, name, doc_string) \
    { name, PythonFuncWrapper<decltype(func), func>::WrappedFunc, METH_VARARGS, doc_string }

using namespace ScriptInterface;

static PyMethodDef PyZeldaImplMethods[] = {
    // Actor
    METHOD_ENTRY(GetActorID, "Test"),
    METHOD_ENTRY(GetActorCategory, "Test"),
    METHOD_ENTRY(SetActorCategory, "Test"),
    METHOD_ENTRY(GetActorRoom, "Test"),
    METHOD_ENTRY(SetActorRoom, "Test"),
    METHOD_ENTRY(GetActorFlags, "Test"),
    METHOD_ENTRY(SetActorFlags, "Test"),
    METHOD_ENTRY(GetActorParams, "Test"),
    METHOD_ENTRY(SetActorParams, "Test"),
    METHOD_ENTRY(GetActorObjBankIndex, "Test"),
    METHOD_ENTRY(SetActorObjBankIndex, "Test"),
    METHOD_ENTRY(GetActorTargetMode, "Test"),
    METHOD_ENTRY(SetActorTargetMode, "Test"),
    METHOD_ENTRY(GetActorSfx, "Test"),
    METHOD_ENTRY(SetActorSfx, "Test"),
    METHOD_ENTRY(GetActorPosX, "Test"),
    METHOD_ENTRY(GetActorPosY, "Test"),
    METHOD_ENTRY(GetActorPosZ, "Test"),
    METHOD_ENTRY(SetActorPosX, "Test"),
    METHOD_ENTRY(SetActorPosY, "Test"),
    METHOD_ENTRY(SetActorPosZ, "Test"),
    METHOD_ENTRY(SetActorPos, "Test"),
    METHOD_ENTRY(GetActorRotX, "Test"),
    METHOD_ENTRY(GetActorRotY, "Test"),
    METHOD_ENTRY(GetActorRotZ, "Test"),
    METHOD_ENTRY(SetActorRotX, "Test"),
    METHOD_ENTRY(SetActorRotY, "Test"),
    METHOD_ENTRY(SetActorRotZ, "Test"),
    METHOD_ENTRY(SetActorRot, "Test"),
    METHOD_ENTRY(SetActorPosRot, "Test"),
    METHOD_ENTRY(GetActorFocusPosX, "Test"),
    METHOD_ENTRY(GetActorFocusPosY, "Test"),
    METHOD_ENTRY(GetActorFocusPosZ, "Test"),
    METHOD_ENTRY(SetActorFocusPosX, "Test"),
    METHOD_ENTRY(SetActorFocusPosY, "Test"),
    METHOD_ENTRY(SetActorFocusPosZ, "Test"),
    METHOD_ENTRY(SetActorFocusPos, "Test"),
    METHOD_ENTRY(GetActorFocusRotX, "Test"),
    METHOD_ENTRY(GetActorFocusRotY, "Test"),
    METHOD_ENTRY(GetActorFocusRotZ, "Test"),
    METHOD_ENTRY(SetActorFocusRotX, "Test"),
    METHOD_ENTRY(SetActorFocusRotY, "Test"),
    METHOD_ENTRY(SetActorFocusRotZ, "Test"),
    METHOD_ENTRY(SetActorFocusRot, "Test"),
    METHOD_ENTRY(SetActorFocusPosRot, "Test"),
    METHOD_ENTRY(GetActorTargetArrowOffset, "Test"),
    METHOD_ENTRY(SetActorTargetArrowOffset, "Test"),
    METHOD_ENTRY(GetActorScaleX, "Test"),
    METHOD_ENTRY(GetActorScaleY, "Test"),
    METHOD_ENTRY(GetActorScaleZ, "Test"),
    METHOD_ENTRY(SetActorScaleX, "Test"),
    METHOD_ENTRY(SetActorScaleY, "Test"),
    METHOD_ENTRY(SetActorScaleZ, "Test"),
    METHOD_ENTRY(SetActorScale, "Test"),
    // TODO once velocity and speedXY are figured out, add them
    METHOD_ENTRY_NAME(GetInstanceData<PyObject>, "GetInstanceData", "Test"),
    // Player
    METHOD_ENTRY(GetPlayer, "Test"),
    METHOD_ENTRY(GetPlayerIvanFloating, "Test"),
    METHOD_ENTRY(SetPlayerIvanFloating, "Test"),
    METHOD_ENTRY(GetPlayerIvanDamageMultiplier, "Test"),
    METHOD_ENTRY(SetPlayerIvanDamageMultiplier, "Test"),
    // Temp
    METHOD_ENTRY(DrawTemp, "Test"),
    // Actor Instance Data
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef PyZeldaImplModule = {
    PyModuleDef_HEAD_INIT,
    "PyZeldaImpl",
    "Python interface C warpper for Zelda",
    -1,
    PyZeldaImplMethods
};

PyMODINIT_FUNC PyInit_PyZeldaImpl() {
    return PyModule_Create(&PyZeldaImplModule);
}

CompiledPythonScript::CompiledPythonScript(const std::string& script) {
    scriptObject = Py_CompileString(script.c_str(), "test.py", Py_file_input);
    // TODO check errors
    CheckError();

    moduleObject = PyImport_ExecCodeModule("TestPlsIgnore", scriptObject);

    CheckError();

    PyObject_SetAttrString(moduleObject, "__builtins__", PyEval_GetBuiltins());
    //PyObject_SetAttrString(moduleObject, "PyZeldaImpl", PyInit_PyZeldaImpl());

    PrintObject(moduleObject);

    CheckError();
}

CompiledPythonScript::~CompiledPythonScript() {
    Py_XDECREF(scriptObject);
    Py_XDECREF(moduleObject);
}

IScriptImplementation* CompiledPythonScript::GetImplementation() {
    return PyZelda::Instance;
}

bool CompiledPythonScript::FunctionExists(const std::string& name) {
    return PyObject_HasAttrString(moduleObject, name.c_str()) != 0;
}

PyZelda::PyZelda() {
    if (PyImport_AppendInittab("PyZeldaImpl", PyInit_PyZeldaImpl) != 0) {
        assert(false);
    }

    Py_Initialize();

    auto s = std::filesystem::current_path();

    std::ifstream pyZeldaFile{ "../../../soh/soh/PyZelda.py" };

    if (pyZeldaFile.is_open()) {
        std::string script((std::istreambuf_iterator<char>(pyZeldaFile)), std::istreambuf_iterator<char>());
        PyObject* scriptObject = Py_CompileString(script.c_str(), "PyZelda.py", Py_file_input);
        AssertError();
        PyObject* moduleObject = PyImport_ExecCodeModule("PyZelda", scriptObject);
        AssertError();
    } else {
        assert(false);
    }
    pyZeldaFile.close();

    //PyObject* g = PyDict_New();
    //PyObject* l = PyDict_New();

    //PyDict_SetItemString(g, "__builtins__", PyEval_GetBuiltins());
    //PyDict_SetItemString(g, "PyZeldaImpl", PyInit_PyZeldaImpl());

    /*
    PyRun_StringFlags(
                                                "PyZelda.test_method(5)\n"
                                                "PyZelda.test_method2()\n",
                                                Py_file_input, g, l, NULL);
                                                */

    //CheckError();
}

PyZelda::~PyZelda() {
    if (Py_FinalizeEx() != 0) {
        assert(false);
    }
}

std::shared_ptr<ICompiledScript> PyZelda::Compile(const std::string& script) {
    return std::make_shared<CompiledPythonScript>(script);
}

void PyZelda::Run(const std::string& script) {

}

void* PyZelda::CreateActorInstanceData(size_t size) {
    // TODO check errors
    PyObject* pClassName = PyUnicode_FromString("InstanceData");
    PyObject* pClassBases = PyTuple_New(0); // An empty tuple for bases is equivalent to `(object,)`
    PyObject* pClassDic = PyDict_New();

    // pClass = type(pClassName, pClassBases, pClassDic)
    PyObject* pClass = PyObject_CallFunctionObjArgs((PyObject*)&PyType_Type, pClassName, pClassBases, pClassDic, NULL);

    Py_XDECREF(pClassName);
    Py_XDECREF(pClassBases);
    Py_XDECREF(pClassDic);

    AssertError();

    PyObject* dir = PyObject_Dir(pClass);
    PrintObject(dir);
    Py_XDECREF(dir);

    return (void*)pClass;
}

void PyZelda::DeleteActorInstanceData(void* data) {
    Py_XDECREF(data);
    return;
}
