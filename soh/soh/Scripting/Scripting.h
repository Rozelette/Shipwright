#pragma once
#include "ScriptingImpl.h"
#include "PyZelda.h"

#include <functional>
#include <memory>
#include <stdint.h>
#include <string>

#include "z64actor.h"

namespace Scripting {

template <typename T, typename... ArgsTypes>
std::function<T>::result_type Call(std::shared_ptr<ICompiledScript> script, std::string name, ArgsTypes... args) {
    IScriptImplementation* impl = script->GetImplementation();
    switch (impl->GetLanguage()) {
        case ScriptLanguage::Python:
            return std::reinterpret_pointer_cast<CompiledPythonScript>(script)->Call<T>(name, args...);
    }
}

template <typename T, typename... ArgsTypes>
std::function<T>::result_type CallIfExists(std::shared_ptr<ICompiledScript> script, std::string name,
                                           ArgsTypes... args) {
    IScriptImplementation* impl = script->GetImplementation();
    switch (impl->GetLanguage()) {
        case ScriptLanguage::Python:
            return std::reinterpret_pointer_cast<CompiledPythonScript>(script)->CallIfExists<T>(name, args...);
    }
}

// TODO temp
void LoadScriptActors();

} // namespace Scripting