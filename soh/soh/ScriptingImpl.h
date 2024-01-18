#pragma once
#include <string>
#include <memory>

#include "z64actor.h"

enum class ScriptLanguage {
    Python
};

class IScriptImplementation;

class ICompiledScript {
  public:
    virtual bool FunctionExists(const std::string& name) = 0;
    virtual IScriptImplementation* GetImplementation() = 0;
};

class IScriptImplementation {
  public:
    static IScriptImplementation* Instance;

    virtual std::shared_ptr<ICompiledScript> Compile(const std::string& script) = 0;

    virtual void Run(const std::string& script) = 0;

    virtual void* CreateActorInstanceData(size_t size) = 0;
    virtual void DeleteActorInstanceData(void* data) = 0;

    virtual ScriptLanguage GetLanguage() = 0;
};

struct ScriptActor {
    Actor actor;
    void* instanceData;
};
