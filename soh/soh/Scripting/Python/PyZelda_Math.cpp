#include "../PyZelda.h"
#include "pybind11/numpy.h"

#include "z64math.h"
#include "global.h"

namespace {
// TODO get rid of size?
template <typename TVec, int size>
    requires(size == 2 or size == 3)
decltype(TVec::x) getitem(TVec& vec, size_t index) {
    if constexpr (size == 2) {
        switch (index) {
            case 0:
                return vec.x;
            case 1:
                return vec.y;
            default:
                throw pybind11::index_error("Index out of bounds.");
        }
    } else if constexpr (size == 3) {
        switch (index) {
            case 0:
                return vec.x;
            case 1:
                return vec.y;
            case 2:
                return vec.z;
            default:
                throw pybind11::index_error("Index out of bounds.");
        }
    }
}

template <typename TVec, int size>
    requires(size == 2 or size == 3)
void setitem(TVec& vec, size_t index, const decltype(TVec::x)& val) {
    if constexpr (size == 2) {
        switch (index) {
            case 0:
                vec.x = val;
                break;
            case 1:
                vec.y = val;
                break;
            default:
                throw pybind11::index_error("Index out of bounds.");
        }
    } else if constexpr (size == 3) {
        switch (index) {
            case 0:
                vec.x = val;
                break;
            case 1:
                vec.y = val;
                break;
            case 2:
                vec.z = val;
                break;
            default:
                throw pybind11::index_error("Index out of bounds.");
        }
    }
}
} // namespace

void PyZelda_RegisterMath(pybind11::module_& m) {
    pybind11::module_ math = m.def_submodule("Math");

    // TODO tuple assignment e.g. pos = (1, 2)
    pybind11::class_<Vec2f>(math, "Vec2f")
        .def_readwrite("x", &Vec2f::x)
        .def_readwrite("y", &Vec2f::y)
        .def("__getitem__", &getitem<Vec2f, 2>)
        .def("__setitem__", &setitem<Vec2f, 2>);

    pybind11::class_<Vec3f>(math, "Vec3f")
        .def(pybind11::init([](f32 x, f32 y, f32 z) {
            return new Vec3f{ x, y, z };
        }))
        .def_readwrite("x", &Vec3f::x)
        .def_readwrite("y", &Vec3f::y)
        .def_readwrite("z", &Vec3f::z)
        .def("__getitem__", &getitem<Vec3f, 3>)
        .def("__setitem__", &setitem<Vec3f, 3>);

    RegisterPybindArray<Vec3f>(m, "Vec3f_Array");

    pybind11::class_<Vec3us>(math, "Vec3us")
        .def_readwrite("x", &Vec3us::x)
        .def_readwrite("y", &Vec3us::y)
        .def_readwrite("z", &Vec3us::z)
        .def("__getitem__", &getitem<Vec3us, 3>)
        .def("__setitem__", &setitem<Vec3us, 3>);

    pybind11::class_<Vec3s>(math, "Vec3s")
        .def_readwrite("x", &Vec3s::x)
        .def_readwrite("y", &Vec3s::y)
        .def_readwrite("z", &Vec3s::z)
        .def("__getitem__", &getitem<Vec3us, 3>)
        .def("__setitem__", &setitem<Vec3us, 3>);

    pybind11::class_<Vec3i>(math, "Vec3i")
        .def_readwrite("x", &Vec3i::x)
        .def_readwrite("y", &Vec3i::y)
        .def_readwrite("z", &Vec3i::z)
        .def("__getitem__", &getitem<Vec3us, 3>)
        .def("__setitem__", &setitem<Vec3us, 3>);

    pybind11::class_<Sphere16>(math, "Sphere16")
        .def_readwrite("center", &Sphere16::center)
        .def_readwrite("radius", &Sphere16::radius);

    pybind11::class_<Spheref>(math, "Spheref")
        .def_readwrite("center", &Spheref::center)
        .def_readwrite("radius", &Spheref::radius);

    pybind11::class_<Plane>(math, "Plane")
        .def_readwrite("normal", &Plane::normal)
        .def_readwrite("originDist", &Plane::originDist);

    pybind11::class_<TriNorm>(math, "TriNorm")
        .def_property_readonly("vtx", [](pybind11::object& obj) {
            TriNorm& tri = obj.cast<TriNorm&>();     // TODO no cast?
            return PybindArray<Vec3f>{ tri.vtx, 3 };                 // TODO size macro?
        })
        .def_readwrite("plane", &TriNorm::plane);

    pybind11::class_<Cylinder16>(math, "Cylinder16")
        .def_readwrite("radius", &Cylinder16::radius)
        .def_readwrite("height", &Cylinder16::height)
        .def_readwrite("yShift", &Cylinder16::yShift)
        .def_readwrite("pos", &Cylinder16::pos);

    pybind11::class_<Cylinderf>(math, "Cylinderf")
        .def_readwrite("radius", &Cylinderf::radius)
        .def_readwrite("height", &Cylinderf::height)
        .def_readwrite("yShift", &Cylinderf::yShift)
        .def_readwrite("pos", &Cylinderf::pos);
    

    pybind11::class_<InfiniteLine>(math, "InfiniteLine")
        .def_readwrite("point", &InfiniteLine::point)
        .def_readwrite("dir", &InfiniteLine::dir);
    

    pybind11::class_<Linef>(math, "Linef")
        .def_readwrite("a", &Linef::a)
        .def_readwrite("b", &Linef::b);
    

    pybind11::class_<VecSph>(math, "VecSph")
        .def_readwrite("r", &VecSph::r)
        .def_readwrite("pitch", &VecSph::pitch)
        .def_readwrite("yaw", &VecSph::yaw);

    math.def("Atan2S", &Math_Atan2S);
    math.def("SmoothStepToS", &Math_SmoothStepToS);
    math.def("SmoothStepToF", &Math_SmoothStepToF);

    // TODO different place

    math.def("Rand_CenteredFloat", &Rand_CenteredFloat);
    math.def("Rand_ZeroOne", &Rand_ZeroOne);

    // TODO macros/functions
}