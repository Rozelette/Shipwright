#include "../PyZelda.h"
#include "pybind11/native_enum.h"

#include "z64audio.h"
#include "global.h"

namespace {
enum NaSeEnum {
    EV_FAIRY_DASH = NA_SE_EV_FAIRY_DASH,
};
} // namespace

void PyZelda_RegisterAudio(pybind11::module_& m) {
    pybind11::module_ audio = m.def_submodule("Audio");

    pybind11::native_enum<NaSeEnum>(audio, "NA_SE", "enum.IntEnum")
        .value("EV_FAIRY_DASH", NaSeEnum::EV_FAIRY_DASH)
        .finalize();

    audio.def("PlayActorSound2", &Audio_PlayActorSound2);
}