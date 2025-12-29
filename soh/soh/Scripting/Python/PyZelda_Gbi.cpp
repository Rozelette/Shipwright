#include "../PyZelda.h"
#include "pybind11/native_enum.h"

#include <libultraship/libultra.h>
#include <libultraship/libultra/gbi.h>

// TODO should this be part of LUS?

void PyZelda_RegisterGbi(pybind11::module_& m) {
    pybind11::module_ gbi = m.def_submodule("Gbi");

    pybind11::class_<Vp>(gbi, "Vp"); // TODO

    pybind11::class_<Light_t>(gbi, "Light_t")
        .def_property_readonly("col", [](pybind11::object& obj) {
            Light_t& light = obj.cast<Light_t&>();   // TODO no cast?
            return PybindArray<unsigned char>{ light.col, 3 }; // TODO size macro?
        })
        .def_readwrite("pad1", &Light_t::pad1)
        .def_property_readonly("colc", [](pybind11::object& obj) {
            Light_t& light = obj.cast<Light_t&>();   // TODO no cast?
            return PybindArray<unsigned char>{ light.colc, 3 }; // TODO size macro?
        })
        .def_readwrite("pad3", &Light_t::pad1)
        .def_property_readonly("dir", [](pybind11::object& obj) {
            Light_t& light = obj.cast<Light_t&>();   // TODO no cast?
            return PybindArray<signed char>{ light.dir, 3 }; // TODO size macro?
        })
        .def_readwrite("pad1", &Light_t::pad3);

    pybind11::class_<PointLight_t>(gbi, "PointLight_t")
        .def_property_readonly("col", [](pybind11::object& obj) {
            PointLight_t& light = obj.cast<PointLight_t&>();   // TODO no cast?
            return PybindArray<unsigned char>{ light.col, 3 }; // TODO size macro?
        })
        .def_readwrite("unk3", &PointLight_t::unk3)
        .def_property_readonly("colc", [](pybind11::object& obj) {
            PointLight_t& light = obj.cast<PointLight_t&>();   // TODO no cast?
            return PybindArray<unsigned char>{ light.colc, 3 }; // TODO size macro?
        })
        .def_readwrite("unk7", &PointLight_t::unk7)
        .def_property_readonly("pos", [](pybind11::object& obj) {
            PointLight_t& light = obj.cast<PointLight_t&>();   // TODO no cast?
            return PybindArray<short>{ light.pos, 3 }; // TODO size macro?
        })
        .def_readwrite("unkE", &PointLight_t::unkE);

    pybind11::class_<Ambient_t>(gbi, "Ambient_t")
        .def_property_readonly("col", [](pybind11::object& obj) {
            Ambient_t& light = obj.cast<Ambient_t&>();   // TODO no cast?
            return PybindArray<unsigned char>{ light.col, 3 }; // TODO size macro?
        })
        .def_readwrite("pad1", &Ambient_t::pad1)
        .def_property_readonly("colc", [](pybind11::object& obj) {
            Ambient_t& light = obj.cast<Ambient_t&>();   // TODO no cast?
            return PybindArray<unsigned char>{ light.colc, 3 }; // TODO size macro?
        })
        .def_readwrite("pad2", &Ambient_t::pad2);

    pybind11::class_<Hilite_t>(gbi, "Hilite_t")
        .def_readwrite("x1", &Hilite_t::x1)
        .def_readwrite("y1", &Hilite_t::y1)
        .def_readwrite("x2", &Hilite_t::x2)
        .def_readwrite("y2", &Hilite_t::y2);

    pybind11::class_<Light>(gbi, "Light")
        .def_readwrite("l", &Light::l)
        .def_readwrite("p", &Light::p);

    pybind11::class_<Ambient>(gbi, "Ambient")
        .def_readwrite("l", &Ambient::l);


    pybind11::class_<Lightsn>(gbi, "Lightsn")
        .def_readwrite("a", &Lightsn::a)
        .def_property_readonly("l", [](pybind11::object& obj) {
            Lightsn& lights = obj.cast<Lightsn&>();       // TODO no cast?
            return PybindArray<Light>{ lights.l, 7 }; // TODO size macro?
        });

    pybind11::class_<Gwords>(gbi, "Gwords")
        .def_readwrite("w0", &Gwords::w0)
        .def_readwrite("w1", &Gwords::w1);

    pybind11::class_<Gfx>(gbi, "Gfx")
        .def_readwrite("words", &Gfx::words);

    RegisterPybindArray<Gfx>(m, "Gfx_Array");

    // TODO more
}