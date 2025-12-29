#include "Scripting.h"
#include <ship/Context.h>
#include <soh/ActorDB.h>
#include "global.h"

#include <filesystem>

// TODO temp
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

namespace Scripting {

static ActorDBInit EnPythonInit = {
    "En_Python",
    "snek",
    ACTORCAT_BG,
    (ACTOR_FLAG_UPDATE_CULLING_DISABLED | ACTOR_FLAG_DRAW_CULLING_DISABLED | ACTOR_FLAG_HOOKSHOT_PULLS_PLAYER |
     ACTOR_FLAG_CAN_PRESS_SWITCHES),
    OBJECT_GAMEPLAY_KEEP,
    sizeof(ScriptActor),
    nullptr,
    nullptr,
    nullptr,
    nullptr,
    nullptr,
};
s16 gEnPythonId;

// TODO temp
void LoadScriptActors() {
    std::string testPath = Ship::Context::GetAppBundlePath() + "/mods/actors/test2.py";
    if (std::filesystem::exists(testPath)) {
        std::ifstream ifs(testPath);
        if (!ifs.is_open()) {
            assert(false);
        }

        std::ostringstream oss;
        oss << ifs.rdbuf();

        EnPythonInit.script = PyZelda::Instance->Compile(oss.str());

        gEnPythonId = ActorDB::Instance->AddEntry(EnPythonInit).entry.id;
    }
}

} // namespace Scripting