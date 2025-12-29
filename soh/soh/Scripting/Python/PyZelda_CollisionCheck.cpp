#include "../PyZelda.h"
#include "pybind11/native_enum.h"

#include "z64collision_check.h"
#include "global.h"

namespace {
enum class AtEnum {
    NONE = AT_NONE,
    ON = AT_ON,
    HIT = AT_HIT,
    BOUNCED = AT_BOUNCED,
    TYPE_PLAYER = AT_TYPE_PLAYER,
    TYPE_ENEMY = AT_TYPE_ENEMY,
    TYPE_OTHER = AT_TYPE_OTHER,
    SELF = AT_SELF,
    TYPE_ALL = AT_TYPE_ALL,
};
enum class AcEnum {
    NONE = AC_NONE,
    ON = AC_ON,
    HIT = AC_HIT,
    HARD = AC_HARD,
    TYPE_PLAYER = AC_TYPE_PLAYER,
    TYPE_ENEMY = AC_TYPE_ENEMY,
    TYPE_OTHER = AC_TYPE_OTHER,
    NO_DAMAGE = AC_NO_DAMAGE,
    BOUNCED = AC_BOUNCED,
    TYPE_ALL = AC_TYPE_ALL,
};
enum class Oc1Enum {
    NONE = OC1_NONE,
    ON = OC1_ON,
    HIT = OC1_HIT,
    NO_PUSH = OC1_NO_PUSH,
    TYPE_PLAYER = OC1_TYPE_PLAYER,
    TYPE_1 = OC1_TYPE_1,
    TYPE_2 = OC1_TYPE_2,
    TYPE_ALL = OC1_TYPE_ALL,
};
enum class Oc2Enum {
    NONE = OC2_NONE,
    HIT_PLAYER = OC2_HIT_PLAYER,
    UNK1 = OC2_UNK1,
    UNK2 = OC2_UNK2,
    TYPE_PLAYER = OC2_TYPE_PLAYER,
    TYPE_1 = OC2_TYPE_1,
    TYPE_2 = OC2_TYPE_2,
    FIRST_ONLY = OC2_FIRST_ONLY,
};
enum class TouchEnum {
    NONE = TOUCH_NONE,
    ON = TOUCH_ON,
    HIT = TOUCH_HIT,
    NEAREST = TOUCH_NEAREST,
    SFX_NORMAL = TOUCH_SFX_NORMAL,
    SFX_HARD = TOUCH_SFX_HARD,
    SFX_WOOD = TOUCH_SFX_WOOD,
    SFX_NONE = TOUCH_SFX_NONE,
    AT_HITMARK = TOUCH_AT_HITMARK,
    DREW_HITMARK = TOUCH_DREW_HITMARK,
    UNK7 = TOUCH_UNK7,
};
enum class BumpEnum {
    NONE = BUMP_NONE,
    ON = BUMP_ON,
    HIT = BUMP_HIT,
    HOOKABLE = BUMP_HOOKABLE,
    NO_AT_INFO = BUMP_NO_AT_INFO,
    NO_DAMAGE = BUMP_NO_DAMAGE,
    NO_SWORD_SFX = BUMP_NO_SWORD_SFX,
    NO_HITMARK = BUMP_NO_HITMARK,
    DRAW_HITMARK = BUMP_DRAW_HITMARK,
};
enum class OcElemEnum {
    NONE = OCELEM_NONE,
    ON = OCELEM_ON,
    HIT = OCELEM_HIT,
    UNK3 = OCELEM_UNK3,
};
enum class OcLineEnum {
    NONE = OCLINE_NONE,
    HIT = OCLINE_HIT,
};
} // namespace

void PyZelda_RegisterCollisionCheck(pybind11::module_& m) {
    pybind11::module_ collisionCheck = m.def_submodule("CollisionCheck");

    pybind11::native_enum<ColliderType>(collisionCheck, "COLTYPE", "enum.IntEnum")
        .value("HIT0", ColliderType::COLTYPE_HIT0)
        .value("HIT1", ColliderType::COLTYPE_HIT1)
        .value("HIT2", ColliderType::COLTYPE_HIT2)
        .value("HIT3", ColliderType::COLTYPE_HIT3)
        .value("HIT4", ColliderType::COLTYPE_HIT4)
        .value("HIT5", ColliderType::COLTYPE_HIT5)
        .value("HIT6", ColliderType::COLTYPE_HIT6)
        .value("HIT7", ColliderType::COLTYPE_HIT7)
        .value("HIT8", ColliderType::COLTYPE_HIT8)
        .value("METAL", ColliderType::COLTYPE_METAL)
        .value("NONE", ColliderType::COLTYPE_NONE)
        .value("WOOD", ColliderType::COLTYPE_WOOD)
        .value("HARD", ColliderType::COLTYPE_HARD)
        .value("TREE", ColliderType::COLTYPE_TREE)
        .finalize();

    pybind11::native_enum<ColliderShape>(collisionCheck, "COLSHAPE", "enum.IntEnum")
        .value("JNTSPH", ColliderShape::COLSHAPE_JNTSPH)
        .value("CYLINDER", ColliderShape::COLSHAPE_CYLINDER)
        .value("TRIS", ColliderShape::COLSHAPE_TRIS)
        .value("QUAD", ColliderShape::COLSHAPE_QUAD)
        .value("INVALID", ColliderShape::COLSHAPE_INVALID)
        .finalize();

    pybind11::native_enum<AtEnum>(collisionCheck, "AT", "enum.IntFlag")
        .value("NONE", AtEnum::NONE)
        .value("ON", AtEnum::ON)
        .value("HIT", AtEnum::HIT)
        .value("BOUNCED", AtEnum::BOUNCED)
        .value("TYPE_PLAYER", AtEnum::TYPE_PLAYER)
        .value("TYPE_ENEMY", AtEnum::TYPE_ENEMY)
        .value("TYPE_OTHER", AtEnum::TYPE_OTHER)
        .value("SELF", AtEnum::SELF)
        .value("TYPE_ALL", AtEnum::TYPE_ALL)
        .finalize();

    pybind11::native_enum<AcEnum>(collisionCheck, "AC", "enum.IntFlag")
        .value("NONE", AcEnum::NONE)
        .value("ON", AcEnum::ON)
        .value("HIT", AcEnum::HIT)
        .value("HARD", AcEnum::HARD)
        .value("TYPE_PLAYER", AcEnum::TYPE_PLAYER)
        .value("TYPE_ENEMY", AcEnum::TYPE_ENEMY)
        .value("TYPE_OTHER", AcEnum::TYPE_OTHER)
        .value("NO_DAMAGE", AcEnum::NO_DAMAGE)
        .value("BOUNCED", AcEnum::BOUNCED)
        .value("TYPE_ALL", AcEnum::TYPE_ALL)
        .finalize();

    pybind11::native_enum<Oc1Enum>(collisionCheck, "OC1", "enum.IntFlag")
        .value("NONE", Oc1Enum::NONE)
        .value("ON", Oc1Enum::ON)
        .value("HIT", Oc1Enum::HIT)
        .value("NO_PUSH", Oc1Enum::NO_PUSH)
        .value("TYPE_PLAYER", Oc1Enum::TYPE_PLAYER)
        .value("TYPE_1", Oc1Enum::TYPE_1)
        .value("TYPE_2", Oc1Enum::TYPE_2)
        .value("TYPE_ALL", Oc1Enum::TYPE_ALL)
        .finalize();

    pybind11::native_enum<Oc2Enum>(collisionCheck, "OC2", "enum.IntFlag")
        .value("NONE", Oc2Enum::NONE)
        .value("HIT_PLAYER", Oc2Enum::HIT_PLAYER)
        .value("UNK1", Oc2Enum::UNK1)
        .value("UNK2", Oc2Enum::UNK2)
        .value("TYPE_PLAYER", Oc2Enum::TYPE_PLAYER)
        .value("TYPE_1", Oc2Enum::TYPE_1)
        .value("TYPE_2", Oc2Enum::TYPE_2)
        .value("FIRST_ONLY", Oc2Enum::FIRST_ONLY)
        .finalize();

    pybind11::native_enum<TouchEnum>(collisionCheck, "TOUCH", "enum.IntFlag")
        .value("NONE", TouchEnum::NONE)
        .value("ON", TouchEnum::ON)
        .value("HIT", TouchEnum::HIT)
        .value("NEAREST", TouchEnum::NEAREST)
        .value("SFX_NORMAL", TouchEnum::SFX_NORMAL)
        .value("SFX_HARD", TouchEnum::SFX_HARD)
        .value("SFX_WOOD", TouchEnum::SFX_WOOD)
        .value("SFX_NONE", TouchEnum::SFX_NONE)
        .value("AT_HITMARK", TouchEnum::AT_HITMARK)
        .value("DREW_HITMARK", TouchEnum::DREW_HITMARK)
        .value("UNK7", TouchEnum::UNK7)
        .finalize();

    pybind11::native_enum<BumpEnum>(collisionCheck, "BUMP", "enum.IntFlag")
        .value("NONE", BumpEnum::NONE)
        .value("ON", BumpEnum::ON)
        .value("HIT", BumpEnum::HIT)
        .value("HOOKABLE", BumpEnum::HOOKABLE)
        .value("NO_AT_INFO", BumpEnum::NO_AT_INFO)
        .value("NO_DAMAGE", BumpEnum::NO_DAMAGE)
        .value("NO_SWORD_SFX", BumpEnum::NO_SWORD_SFX)
        .value("NO_HITMARK", BumpEnum::NO_HITMARK)
        .value("DRAW_HITMARK", BumpEnum::DRAW_HITMARK)
        .finalize();

    pybind11::native_enum<OcElemEnum>(collisionCheck, "OCELEM", "enum.IntFlag")
        .value("NONE", OcElemEnum::NONE)
        .value("ON", OcElemEnum::ON)
        .value("HIT", OcElemEnum::HIT)
        .value("UNK3", OcElemEnum::UNK3)
        .finalize();

    pybind11::native_enum<OcLineEnum>(collisionCheck, "OCLINE", "enum.IntFlag")
        .value("NONE", OcLineEnum::NONE)
        .value("HIT", OcLineEnum::HIT)
        .finalize();

    pybind11::class_<Collider>(collisionCheck, "Collider")
        .def_readwrite("actor", &Collider::actor)
        .def_readwrite("at", &Collider::at)
        .def_readwrite("ac", &Collider::ac)
        .def_readwrite("oc", &Collider::oc)
        .def_readwrite("atFlags", &Collider::atFlags)
        .def_readwrite("acFlags", &Collider::acFlags)
        .def_readwrite("ocFlags1", &Collider::ocFlags1)
        .def_readwrite("ocFlags2", &Collider::ocFlags2)
        .def_readwrite("colType", &Collider::colType)
        .def_readwrite("shape", &Collider::shape);

    RegisterPybindArray<Collider*>(m, "Collider_Ptr_Array");

    pybind11::class_<ColliderTouch>(collisionCheck, "ColliderTouch")
        .def_readwrite("dmgFlags", &ColliderTouch::dmgFlags)
        .def_readwrite("effect", &ColliderTouch::effect)
        .def_readwrite("damage", &ColliderTouch::damage);

    pybind11::class_<ColliderBump>(collisionCheck, "ColliderBump")
        .def_readwrite("dmgFlags", &ColliderBump::dmgFlags)
        .def_readwrite("effect", &ColliderBump::effect)
        .def_readwrite("defense", &ColliderBump::defense)
        .def_readwrite("hitPos", &ColliderBump::hitPos);

    pybind11::class_<ColliderInfo>(collisionCheck, "ColliderInfo")
        .def_readwrite("toucher", &ColliderInfo::toucher)
        .def_readwrite("bumper", &ColliderInfo::bumper)
        .def_readwrite("elemType", &ColliderInfo::elemType)
        .def_readwrite("toucherFlags", &ColliderInfo::toucherFlags)
        .def_readwrite("bumperFlags", &ColliderInfo::bumperFlags)
        .def_readwrite("ocElemFlags", &ColliderInfo::ocElemFlags)
        .def_readwrite("atHit", &ColliderInfo::atHit)
        .def_readwrite("acHit", &ColliderInfo::acHit)
        .def_readwrite("atHitInfo", &ColliderInfo::atHitInfo)
        .def_readwrite("acHitInfo", &ColliderInfo::acHitInfo);

    pybind11::class_<ColliderJntSphElementDim>(collisionCheck, "ColliderJntSphElementDim")
        .def_readwrite("modelSphere", &ColliderJntSphElementDim::modelSphere)
        .def_readwrite("worldSphere", &ColliderJntSphElementDim::worldSphere)
        .def_readwrite("scale", &ColliderJntSphElementDim::scale)
        .def_readwrite("limb", &ColliderJntSphElementDim::limb);

    pybind11::class_<ColliderJntSphElement>(collisionCheck, "ColliderJntSphElement")
        .def_readwrite("info", &ColliderJntSphElement::info)
        .def_readwrite("dim", &ColliderJntSphElement::dim);

    RegisterPybindArray<ColliderJntSphElement>(m, "ColliderJntSphElement_Array");

    pybind11::class_<ColliderJntSph>(collisionCheck, "ColliderJntSph")
        .def_readwrite("base", &ColliderJntSph::base)
        .def_readwrite("count", &ColliderJntSph::count)
        .def_property_readonly("elements", [](pybind11::object& obj) {
            ColliderJntSph& collider = obj.cast<ColliderJntSph&>(); // TODO no cast?
            return PybindArray<ColliderJntSphElement>{ collider.elements,
                                                       static_cast<size_t>(collider.count) }; // TODO size macro?
        });

    pybind11::class_<ColliderCylinder>(collisionCheck, "ColliderCylinder")
        .def(pybind11::init([](Actor* actor) { 
            ColliderCylinder* collider = new ColliderCylinder{};
            Collider_InitCylinder(nullptr, collider);
            collider->base.actor = actor;
            collider->base.shape = COLSHAPE_CYLINDER;
            return collider;
        }))
        .def_readwrite("base", &ColliderCylinder::base)
        .def_readwrite("info", &ColliderCylinder::info)
        .def_readwrite("dim", &ColliderCylinder::dim);

    pybind11::class_<ColliderTrisElement>(collisionCheck, "ColliderTrisElement")
        .def_readwrite("info", &ColliderTrisElement::info)
        .def_readwrite("dim", &ColliderTrisElement::dim);

    RegisterPybindArray<ColliderTrisElement>(m, "ColliderTrisElement_Array");

    pybind11::class_<ColliderTris>(collisionCheck, "ColliderTris")
        .def_readwrite("base", &ColliderTris::base)
        .def_readwrite("count", &ColliderTris::count)
        .def_property_readonly("elements", [](pybind11::object& obj) {
            ColliderTris& collider = obj.cast<ColliderTris&>(); // TODO no cast?
            return PybindArray<ColliderTrisElement>{ collider.elements,
                                                     static_cast<size_t>(collider.count) }; // TODO size macro?
        });

    pybind11::class_<ColliderQuadDim>(collisionCheck, "ColliderQuadDim")
        .def_property_readonly("quad", [](pybind11::object& obj) {
            ColliderQuadDim& collider = obj.cast<ColliderQuadDim&>(); // TODO no cast?
            return PybindArray<Vec3f>{ collider.quad, 4 };            // TODO size macro?
        })
        .def_readwrite("dcMid", &ColliderQuadDim::dcMid)
        .def_readwrite("baMid", &ColliderQuadDim::baMid)
        .def_readwrite("acDist", &ColliderQuadDim::acDist);

    pybind11::class_<ColliderQuadElement>(collisionCheck, "ColliderQuadElement")
        .def_readwrite("info", &ColliderQuadElement::info)
        .def_readwrite("dim", &ColliderQuadElement::dim);

    pybind11::class_<ColliderQuad>(collisionCheck, "ColliderQuad")
        .def_readwrite("base", &ColliderQuad::base)
        .def_readwrite("info", &ColliderQuad::info)
        .def_readwrite("dim", &ColliderQuad::dim);

    pybind11::class_<OcLine>(collisionCheck, "OcLine")
        .def_readwrite("line", &OcLine::line)
        .def_readwrite("ocFlags", &OcLine::ocFlags);

    RegisterPybindArray<OcLine*>(m, "OcLine_Ptr_Array");

    collisionCheck.def("SetAC", &CollisionCheck_SetAC);
    collisionCheck.def("SetOC", &CollisionCheck_SetOC);

    // TODO more
}