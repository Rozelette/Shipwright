#include "../PyZelda.h"
#include "pybind11/native_enum.h"

#include "libultraship/color.h"
#include "ship/utils/color.h"

void PyZelda_RegisterColor(pybind11::module_& m) {
    pybind11::module_ color = m.def_submodule("Color");

    pybind11::class_<Color_RGBAf>(color, "RGBAf")
        .def(pybind11::init([](float r, float g, float b, float a) {
            return new Color_RGBAf{ r, g, b, a };
        }))
        .def_readwrite("r", &Color_RGBAf::r)
        .def_readwrite("g", &Color_RGBAf::g)
        .def_readwrite("b", &Color_RGBAf::b)
        .def_readwrite("a", &Color_RGBAf::a);
    

    pybind11::class_<Color_RGB8>(color, "RGB8")
        .def(pybind11::init([](uint8_t r, uint8_t g, uint8_t b) {
            return new Color_RGB8{ r, g, b };
        }))
        .def_readwrite("r", &Color_RGB8::r)
        .def_readwrite("g", &Color_RGB8::g)
        .def_readwrite("b", &Color_RGB8::b);
    

    pybind11::class_<Color_RGBA8>(color, "RGBA8")
        .def(pybind11::init([](uint8_t r, uint8_t g, uint8_t b, uint8_t a) {
            return new Color_RGBA8{ r, g, b, a };
        }))
        .def_readwrite("r", &Color_RGBA8::r)
        .def_readwrite("g", &Color_RGBA8::g)
        .def_readwrite("b", &Color_RGBA8::b)
        .def_readwrite("a", &Color_RGBA8::a);

    // TODO more
}