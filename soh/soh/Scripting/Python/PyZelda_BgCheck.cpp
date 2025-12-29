#include "../PyZelda.h"

#include "z64bgcheck.h"

void PyZelda_RegisterBgCheck(pybind11::module_& m) {
    pybind11::module_ bgCheck = m.def_submodule("BgCheck");

    pybind11::class_<ScaleRotPos>(bgCheck, "ScaleRotPos")
        .def_readwrite("scale", &ScaleRotPos::scale)
        .def_readwrite("rot", &ScaleRotPos::rot)
        .def_readwrite("pos", &ScaleRotPos::pos);

    pybind11::class_<CollisionPoly>(bgCheck, "CollisionPoly")
        .def_readonly("type", &CollisionPoly::type)
        .def_readonly("vtxData", &CollisionPoly::vtxData) // TODO do arrays work?
        .def_readonly("flags_vIA", &CollisionPoly::flags_vIA)
        .def_readonly("flags_vIB", &CollisionPoly::flags_vIB)
        .def_readonly("vIC", &CollisionPoly::vIC)
        .def_readonly("normal", &CollisionPoly::normal);

    pybind11::class_<CamData>(bgCheck, "CamData")
        .def_readwrite("cameraSType", &CamData::cameraSType)
        .def_readwrite("numCameras", &CamData::numCameras)
        .def_readwrite("camPosData", &CamData::camPosData);

    pybind11::class_<WaterBox>(bgCheck, "WaterBox")
        .def_readwrite("xMin", &WaterBox::xMin)
        .def_readwrite("ySurface", &WaterBox::ySurface)
        .def_readwrite("zMin", &WaterBox::zMin)
        .def_readwrite("xLength", &WaterBox::xLength)
        .def_readwrite("zLength", &WaterBox::zLength)
        .def_readwrite("properties", &WaterBox::properties);

    pybind11::class_<SurfaceType>(bgCheck, "SurfaceType");
        //.def_readwrite("data", &SurfaceType::data); // TODO do arrays work?

    pybind11::class_<CollisionContext>(bgCheck, "CollisionContext");
    // TODO macros/functions
}