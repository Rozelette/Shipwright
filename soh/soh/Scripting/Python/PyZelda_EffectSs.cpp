#include "../PyZelda.h"
#include "pybind11/native_enum.h"

#include "global.h"

void PyZelda_RegisterEffectSs(pybind11::module_& m) {
    pybind11::module_ effectSs = m.def_submodule("EffectSs");

    effectSs.def("KiraKira_SpawnDispersed", &EffectSsKiraKira_SpawnDispersed);

    // TODO more
}
