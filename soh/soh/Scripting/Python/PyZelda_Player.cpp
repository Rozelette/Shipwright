#include "../PyZelda.h"
#include "pybind11/native_enum.h"

#include "z64player.h"
#include "global.h"

void PyZelda_RegisterPlayer(pybind11::module_& m) {
    pybind11::module_ player = m.def_submodule("Player");

    pybind11::class_<Player>(player, "Player")
        .def_readwrite("actor", &Player::actor)
        .def_readwrite("boomerangQuickRecall", &Player::boomerangQuickRecall)
        .def_readwrite("ivanFloating", &Player::ivanFloating)
        .def_readwrite("ivanDamageMultiplier", &Player::ivanDamageMultiplier)
        ;

    player.def("GetHeight", &Player_GetHeight);
    player.def("InCsMode", &Player_InCsMode);

    // TODO more
}