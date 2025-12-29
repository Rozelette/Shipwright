#include "../PyZelda.h"
#include "pybind11/native_enum.h"

#include "z64light.h"
#include "global.h"

void PyZelda_RegisterLight(pybind11::module_& m) {
    pybind11::module_ light = m.def_submodule("Light");

    pybind11::native_enum<LightType>(light, "LIGHT", "enum.IntEnum")
        .value("POINT_NOGLOW", LightType::LIGHT_POINT_NOGLOW)
        .value("DIRECTIONAL", LightType::LIGHT_DIRECTIONAL)
        .value("POINT_GLOW", LightType::LIGHT_POINT_GLOW)
        .finalize();

    pybind11::class_<LightPoint>(light, "LightPoint")
        .def_readwrite("x", &LightPoint::x)
        .def_readwrite("y", &LightPoint::y)
        .def_readwrite("z", &LightPoint::z)
        .def_property_readonly("color", [](pybind11::object& obj) {
            LightPoint& light = obj.cast<LightPoint&>(); // TODO no cast?
            return PybindArray<u8>{ light.color, 3 };   // TODO size macro?
        })
        .def_readwrite("drawGlow", &LightPoint::drawGlow)
        .def_readwrite("radius", &LightPoint::radius);

    pybind11::class_<LightDirectional>(light, "LightDirectional")
        .def_readwrite("x", &LightDirectional::x)
        .def_readwrite("y", &LightDirectional::y)
        .def_readwrite("z", &LightDirectional::z)
        .def_property_readonly("color", [](pybind11::object& obj) {
            LightDirectional& light = obj.cast<LightDirectional&>(); // TODO no cast?
            return PybindArray<u8>{ light.color, 3 };   // TODO size macro?
        });

    pybind11::class_<LightParams>(light, "LightParams")
        .def_readwrite("point", &LightParams::point)
        .def_readwrite("dir", &LightParams::dir);

    pybind11::class_<LightInfo>(light, "LightInfo")
        .def_readwrite("type", &LightInfo::type)
        .def_readwrite("params", &LightInfo::params);

    pybind11::class_<Lights>(light, "Lights")
        .def_readwrite("numLights", &Lights::numLights)
        .def_readwrite("l", &Lights::l);

    pybind11::class_<LightNode>(light, "LightNode")
        .def_readwrite("info", &LightNode::info)
        .def_readwrite("prev", &LightNode::prev)
        .def_readwrite("next", &LightNode::next);

    pybind11::class_<LightContext>(light, "LightContext")
        .def_readwrite("listHead", &LightContext::listHead)
        .def_property_readonly("ambientColor", [](pybind11::object& obj) {
            LightContext& lightCtx = obj.cast<LightContext&>(); // TODO no cast?
            return PybindArray<u8>{ lightCtx.ambientColor, 3 };   // TODO size macro?
        })
        .def_property_readonly("fogColor", [](pybind11::object& obj) {
            LightContext& lightCtx = obj.cast<LightContext&>(); // TODO no cast?
            return PybindArray<u8>{ lightCtx.fogColor, 3 };   // TODO size macro?
        })
        .def_readwrite("fogNear", &LightContext::fogNear)
        .def_readwrite("fogFar", &LightContext::fogFar);

    // TODO Vec3* and RGB*?
    light.def("new_point_glow", [](s16 x, s16 y, s16 z, u8 r, u8 g, u8 b, s16 radius) {
        LightInfo* info = new LightInfo{};
        Lights_PointGlowSetInfo(info, x, y, z, r, g, b, radius);
        return info;
    });

    light.def("new_point_no_glow", [](s16 x, s16 y, s16 z, u8 r, u8 g, u8 b, s16 radius) {
        LightInfo* info = new LightInfo{};
        Lights_PointNoGlowSetInfo(info, x, y, z, r, g, b, radius);
        return info;
    });

    light.def("new_directional", [](s16 x, s16 y, s16 z, u8 r, u8 g, u8 b) {
        LightInfo* info = new LightInfo{};
        Lights_DirectionalSetInfo(info, x, y, z, r, g, b);
        return info;
    });

    light.def("insert_light", [](LightContext* lightCtx, LightInfo* info) {
        return LightContext_InsertLight(nullptr, lightCtx, info);
    }, pybind11::return_value_policy::reference);

    light.def("remove_light", [](LightContext* lightCtx, LightNode* node) { 
        LightContext_RemoveLight(nullptr, lightCtx, node);
    });
}