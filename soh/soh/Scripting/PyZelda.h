#pragma once
#define PY_SSIZE_T_CLEAN // TODO remove after upgrading to python > 3.12?

// TODO ugh
#ifdef _DEBUG
#undef _DEBUG
#include "Python.h" // TODO remove after removing all raw python calls
#define _DEBUG
#else
#include "Python.h" // TODO remove after removing all raw python calls
#endif
#include "pybind11/pybind11.h" // must be first include

#include "ScriptingImpl.h"

#include <string>
#include <functional>
#include <concepts>
#include <type_traits>

// Helper to convert void returns
template <typename ReturnType> static ReturnType GetDefaultCallResult();
template <> static void GetDefaultCallResult<void>() {
    return;
}
template <typename ReturnType> static ReturnType GetDefaultCallResult() {
    return ReturnType{};
}

// TODO convert to pybind11
static void PrintObject(PyObject* object) {
    if (object != nullptr) {
        PyObject* msg = PyObject_Repr(object);

        const char* msgString = PyUnicode_AsUTF8(msg);
        printf("%s\n", msgString);
        Py_XDECREF(msg);
    }
}

// TODO convert to pybind11
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

// TODO figure out how to move this into the .cpp
// Call and CallIfExists should not need to cast to this
class CompiledPythonScript final : public ICompiledScript {
  public:
    CompiledPythonScript(const std::string& script);
    ~CompiledPythonScript();

    bool FunctionExists(const std::string& name) override;

    // TODO try catch for Call and CallIfExists
    template <typename T, typename... ArgsTypes>
    std::function<T>::result_type Call(std::string name, ArgsTypes... args) {
        return locals[name.c_str()](args...).cast<std::function<T>::result_type>(); // TODO errors
    }

    template <typename T, typename... ArgsTypes>
    std::function<T>::result_type CallIfExists(std::string name, ArgsTypes... args) {
        if (!FunctionExists(name)) {
            return GetDefaultCallResult<std::function<T>::result_type>();
        }
        return Call<T>(name, args...);
    }

    IScriptImplementation* GetImplementation() override;

  private:
    pybind11::dict locals;
};

// TODO better place
template <typename T> struct PybindArray {
    T* data;
    size_t size;
};

template <typename T> void RegisterPybindArray(pybind11::module_& m, const std::string& name) {
    pybind11::class_<PybindArray<T>>(m, name.c_str())
        .def("__getitem__", [](PybindArray<T>& a, size_t i) -> T& { return a.data[i]; }, pybind11::return_value_policy::reference)
        .def("__setitem__", [](PybindArray<T>& a, size_t i, const T& item) { a.data[i] = item; })
        /*
        .def_buffer([](PybindArray<T>& a) -> pybind11::buffer_info {
            return pybind11::buffer_info {
                a.data,
                sizeof(T),
                pybind11::format_descriptor<T>::format(),
                1,
                { a.size },
                { sizeof(T) }
            };
        })
        */
        ;
}

class PyZelda : public IScriptImplementation {
  public:
    PyZelda();
    virtual ~PyZelda();

    void Run(const std::string& script) override;

    std::shared_ptr<ICompiledScript> Compile(const std::string& script) override;

    void CreateActorInstanceData(Actor* actor, size_t size) override;
    void DeleteActorInstanceData(Actor* actor) override;

    ScriptLanguage GetLanguage() override {
        return ScriptLanguage::Python;
    }

  private:
    std::vector<std::shared_ptr<ICompiledScript>> scripts; // TODO need to have exclusive ownership in order to delete them all before shutting down the interpreter
};