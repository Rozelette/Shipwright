#include "../PyZelda.h"
#include "pybind11/native_enum.h"
#include "pybind11/functional.h"

#include "z64actor.h"
#include "global.h"

#include <functional>
#include <type_traits>

namespace {
enum ActorFlagEnum {
    ATTENTION_ENABLED = ACTOR_FLAG_ATTENTION_ENABLED,
    HOSTILE = ACTOR_FLAG_HOSTILE,
    FRIENDLY = ACTOR_FLAG_FRIENDLY,
    UPDATE_CULLING_DISABLED = ACTOR_FLAG_UPDATE_CULLING_DISABLED,
    DRAW_CULLING_DISABLED = ACTOR_FLAG_DRAW_CULLING_DISABLED,
    INSIDE_CULLING_VOLUME = ACTOR_FLAG_INSIDE_CULLING_VOLUME,
    REACT_TO_LENS = ACTOR_FLAG_REACT_TO_LENS,
    TALK = ACTOR_FLAG_TALK,
    HOOKSHOT_PULLS_ACTOR = ACTOR_FLAG_HOOKSHOT_PULLS_ACTOR,
    HOOKSHOT_PULLS_PLAYER = ACTOR_FLAG_HOOKSHOT_PULLS_PLAYER,
    GRASS_DESTROYED = ACTOR_FLAG_GRASS_DESTROYED,
    IGNORE_QUAKE = ACTOR_FLAG_IGNORE_QUAKE,
    HOOKSHOT_ATTACHED = ACTOR_FLAG_HOOKSHOT_ATTACHED,
    CAN_ATTACH_TO_ARROW = ACTOR_FLAG_CAN_ATTACH_TO_ARROW,
    TALK_OFFER_AUTO_ACCEPTED = ACTOR_FLAG_TALK_OFFER_AUTO_ACCEPTED,
    CARRY_X_ROT_INFLUENCE = ACTOR_FLAG_CARRY_X_ROT_INFLUENCE,
    TALK_WITH_C_UP = ACTOR_FLAG_TALK_WITH_C_UP,
    IGNORE_POINTLIGHTS = ACTOR_FLAG_IGNORE_POINTLIGHTS,
    THROW_ONLY = ACTOR_FLAG_THROW_ONLY,
    SFX_FOR_PLAYER_BODY_HIT = ACTOR_FLAG_SFX_FOR_PLAYER_BODY_HIT,
    UPDATE_DURING_OCARINA = ACTOR_FLAG_UPDATE_DURING_OCARINA,
    CAN_PRESS_SWITCHES = ACTOR_FLAG_CAN_PRESS_SWITCHES,
    LOCK_ON_DISABLED = ACTOR_FLAG_LOCK_ON_DISABLED,
};

enum DynaInteractEnum {
    ACTOR_ON_TOP = DYNA_INTERACT_ACTOR_ON_TOP,
    PLAYER_ON_TOP = DYNA_INTERACT_PLAYER_ON_TOP,
    PLAYER_ABOVE = DYNA_INTERACT_PLAYER_ABOVE,
    ACTOR_SWITCH_PRESSED = DYNA_INTERACT_ACTOR_SWITCH_PRESSED,
};
} // namespace

void PyZelda_RegisterActor(pybind11::module_& m) {
    pybind11::module_ actor = m.def_submodule("Actor");

    actor.attr("MASS_IMMOVABLE") = MASS_IMMOVABLE;
    actor.attr("MASS_HEAVY") = MASS_HEAVY;

    actor.attr("BODYBREAK_OBJECT_DEFAULT") = BODYBREAK_OBJECT_DEFAULT;
    actor.attr("BODYBREAK_STATUS_READY") = BODYBREAK_STATUS_READY;
    actor.attr("BODYBREAK_STATUS_FINISHED") = BODYBREAK_STATUS_FINISHED;

    pybind11::native_enum<ActorFlagEnum>(actor, "ACTOR_FLAG", "enum.IntFlag")
        .value("ATTENTION_ENABLED", ActorFlagEnum::ATTENTION_ENABLED)
        .value("HOSTILE", ActorFlagEnum::HOSTILE)
        .value("FRIENDLY", ActorFlagEnum::FRIENDLY)
        .value("UPDATE_CULLING_DISABLED", ActorFlagEnum::UPDATE_CULLING_DISABLED)
        .value("DRAW_CULLING_DISABLED", ActorFlagEnum::DRAW_CULLING_DISABLED)
        .value("INSIDE_CULLING_VOLUME", ActorFlagEnum::INSIDE_CULLING_VOLUME)
        .value("REACT_TO_LENS", ActorFlagEnum::REACT_TO_LENS)
        .value("TALK", ActorFlagEnum::TALK)
        .value("HOOKSHOT_PULLS_ACTOR", ActorFlagEnum::HOOKSHOT_PULLS_ACTOR)
        .value("HOOKSHOT_PULLS_PLAYER", ActorFlagEnum::HOOKSHOT_PULLS_PLAYER)
        .value("GRASS_DESTROYED", ActorFlagEnum::GRASS_DESTROYED)
        .value("IGNORE_QUAKE", ActorFlagEnum::IGNORE_QUAKE)
        .value("HOOKSHOT_ATTACHED", ActorFlagEnum::HOOKSHOT_ATTACHED)
        .value("CAN_ATTACH_TO_ARROW", ActorFlagEnum::CAN_ATTACH_TO_ARROW)
        .value("TALK_OFFER_AUTO_ACCEPTED", ActorFlagEnum::TALK_OFFER_AUTO_ACCEPTED)
        .value("CARRY_X_ROT_INFLUENCE", ActorFlagEnum::CARRY_X_ROT_INFLUENCE)
        .value("TALK_WITH_C_UP", ActorFlagEnum::TALK_WITH_C_UP)
        .value("IGNORE_POINTLIGHTS", ActorFlagEnum::IGNORE_POINTLIGHTS)
        .value("THROW_ONLY", ActorFlagEnum::THROW_ONLY)
        .value("SFX_FOR_PLAYER_BODY_HIT", ActorFlagEnum::SFX_FOR_PLAYER_BODY_HIT)
        .value("UPDATE_DURING_OCARINA", ActorFlagEnum::UPDATE_DURING_OCARINA)
        .value("CAN_PRESS_SWITCHES", ActorFlagEnum::CAN_PRESS_SWITCHES)
        .value("LOCK_ON_DISABLED", ActorFlagEnum::LOCK_ON_DISABLED)
        .finalize();

    pybind11::native_enum<ActorFootIndex>(actor, "FOOT_INDEX", "enum.IntEnum")
        .value("LEFT", FOOT_LEFT)
        .value("RIGHT", FOOT_RIGHT)
        .finalize();

    pybind11::native_enum<DynaInteractEnum>(actor, "DYNA_INTERACT", "enum.IntFlag")
        .value("ACTOR_ON_TOP", DynaInteractEnum::ACTOR_ON_TOP)
        .value("PLAYER_ON_TOP", DynaInteractEnum::PLAYER_ON_TOP)
        .value("PLAYER_ABOVE", DynaInteractEnum::PLAYER_ABOVE)
        .value("ACTOR_SWITCH_PRESSED", DynaInteractEnum::ACTOR_SWITCH_PRESSED)
        .finalize();

    pybind11::native_enum<Item00Type>(actor, "ITEM00", "enum.IntEnum")
        .value("RUPEE_GREEN", Item00Type::ITEM00_RUPEE_GREEN)
        .value("RUPEE_BLUE", Item00Type::ITEM00_RUPEE_BLUE)
        .value("RUPEE_RED", Item00Type::ITEM00_RUPEE_RED)
        .value("HEART", Item00Type::ITEM00_HEART)
        .value("BOMBS_A", Item00Type::ITEM00_BOMBS_A)
        .value("ARROWS_SINGLE", Item00Type::ITEM00_ARROWS_SINGLE)
        .value("HEART_PIECE", Item00Type::ITEM00_HEART_PIECE)
        .value("HEART_CONTAINER", Item00Type::ITEM00_HEART_CONTAINER)
        .value("ARROWS_SMALL", Item00Type::ITEM00_ARROWS_SMALL)
        .value("ARROWS_MEDIUM", Item00Type::ITEM00_ARROWS_MEDIUM)
        .value("ARROWS_LARGE", Item00Type::ITEM00_ARROWS_LARGE)
        .value("BOMBS_B", Item00Type::ITEM00_BOMBS_B)
        .value("NUTS", Item00Type::ITEM00_NUTS)
        .value("STICK", Item00Type::ITEM00_STICK)
        .value("MAGIC_LARGE", Item00Type::ITEM00_MAGIC_LARGE)
        .value("MAGIC_SMALL", Item00Type::ITEM00_MAGIC_SMALL)
        .value("SEEDS", Item00Type::ITEM00_SEEDS)
        .value("SMALL_KEY", Item00Type::ITEM00_SMALL_KEY)
        .value("FLEXIBLE", Item00Type::ITEM00_FLEXIBLE)
        .value("RUPEE_ORANGE", Item00Type::ITEM00_RUPEE_ORANGE)
        .value("RUPEE_PURPLE", Item00Type::ITEM00_RUPEE_PURPLE)
        .value("SHIELD_DEKU", Item00Type::ITEM00_SHIELD_DEKU)
        .value("SHIELD_HYLIAN", Item00Type::ITEM00_SHIELD_HYLIAN)
        .value("TUNIC_ZORA", Item00Type::ITEM00_TUNIC_ZORA)
        .value("TUNIC_GORON", Item00Type::ITEM00_TUNIC_GORON)
        .value("BOMBS_SPECIAL", Item00Type::ITEM00_BOMBS_SPECIAL)
        .value("BOMBCHU", Item00Type::ITEM00_BOMBCHU)
        .value("SOH_DUMMY", Item00Type::ITEM00_SOH_DUMMY)
        .value("SOH_GIVE_ITEM_ENTRY", Item00Type::ITEM00_SOH_GIVE_ITEM_ENTRY)
        .value("SOH_GIVE_ITEM_ENTRY_GI", Item00Type::ITEM00_SOH_GIVE_ITEM_ENTRY_GI)
        .value("MAX", Item00Type::ITEM00_MAX)
        .value("NONE", Item00Type::ITEM00_NONE)
        .finalize();

    pybind11::native_enum<AObjType>(actor, "A_OBJ", "enum.IntEnum")
        .value("BLOCK_SMALL", AObjType::A_OBJ_BLOCK_SMALL)
        .value("BLOCK_LARGE", AObjType::A_OBJ_BLOCK_LARGE)
        .value("BLOCK_HUGE", AObjType::A_OBJ_BLOCK_HUGE)
        .value("BLOCK_SMALL_ROT", AObjType::A_OBJ_BLOCK_SMALL_ROT)
        .value("BLOCK_LARGE_ROT", AObjType::A_OBJ_BLOCK_LARGE_ROT)
        .value("UNKNOWN_6", AObjType::A_OBJ_UNKNOWN_6)
        .value("GRASS_CLUMP", AObjType::A_OBJ_GRASS_CLUMP)
        .value("TREE_STUMP", AObjType::A_OBJ_TREE_STUMP)
        .value("SIGNPOST_OBLONG", AObjType::A_OBJ_SIGNPOST_OBLONG)
        .value("SIGNPOST_ARROW", AObjType::A_OBJ_SIGNPOST_ARROW)
        .value("BOULDER_FRAGMENT", AObjType::A_OBJ_BOULDER_FRAGMENT)
        .finalize();

    pybind11::native_enum<ActorCategory>(actor, "ACTORCAT", "enum.IntEnum")
        .value("SWITCH", ActorCategory::ACTORCAT_SWITCH)
        .value("BG", ActorCategory::ACTORCAT_BG)
        .value("PLAYER", ActorCategory::ACTORCAT_PLAYER)
        .value("EXPLOSIVE", ActorCategory::ACTORCAT_EXPLOSIVE)
        .value("NPC", ActorCategory::ACTORCAT_NPC)
        .value("ENEMY", ActorCategory::ACTORCAT_ENEMY)
        .value("PROP", ActorCategory::ACTORCAT_PROP)
        .value("ITEMACTION", ActorCategory::ACTORCAT_ITEMACTION)
        .value("MISC", ActorCategory::ACTORCAT_MISC)
        .value("BOSS", ActorCategory::ACTORCAT_BOSS)
        .value("DOOR", ActorCategory::ACTORCAT_DOOR)
        .value("CHEST", ActorCategory::ACTORCAT_CHEST)
        .finalize();

    pybind11::native_enum<DoorLockType>(actor, "DOORLOCK", "enum.IntEnum")
        .value("NORMAL", DoorLockType::DOORLOCK_NORMAL)
        .value("BOSS", DoorLockType::DOORLOCK_BOSS)
        .value("NORMAL_SPIRIT", DoorLockType::DOORLOCK_NORMAL_SPIRIT)
        .finalize();

    pybind11::native_enum<NpcTalkState>(actor, "NPC_TALK_STATE", "enum.IntEnum")
        .value("IDLE", NpcTalkState::NPC_TALK_STATE_IDLE)
        .value("TALKING", NpcTalkState::NPC_TALK_STATE_TALKING)
        .value("ACTION", NpcTalkState::NPC_TALK_STATE_ACTION)
        .value("ITEM_GIVEN", NpcTalkState::NPC_TALK_STATE_ITEM_GIVEN)
        .finalize();

    pybind11::native_enum<NpcTrackingMode>(actor, "NPC_TRACKING", "enum.IntEnum")
        .value("PLAYER_AUTO_TURN", NpcTrackingMode::NPC_TRACKING_PLAYER_AUTO_TURN)
        .value("NONE", NpcTrackingMode::NPC_TRACKING_NONE)
        .value("HEAD_AND_TORSO", NpcTrackingMode::NPC_TRACKING_HEAD_AND_TORSO)
        .value("HEAD", NpcTrackingMode::NPC_TRACKING_HEAD)
        .value("FULL_BODY", NpcTrackingMode::NPC_TRACKING_FULL_BODY)
        .finalize();

    pybind11::native_enum<ActorID>(actor, "ACTOR", "enum.IntEnum")
        .value("EN_SI", ActorID::ACTOR_EN_SI)
        .finalize();

    pybind11::class_<PosRot>(actor, "PosRot")
        .def_readwrite("pos", &PosRot::pos)
        .def_readwrite("rot", &PosRot::rot);

    pybind11::class_<DamageTable>(actor, "DamageTable")
        .def_property_readonly("table", [](pybind11::object& obj) {
            DamageTable& table = obj.cast<DamageTable&>(); // TODO no cast?
            return PybindArray<u8>{ table.table, 32 };   // TODO size macro?
        });

    pybind11::class_<CollisionCheckInfo>(actor, "CollisionCheckInfo")
        .def_readwrite("damageTable", &CollisionCheckInfo::damageTable)
        .def_readwrite("displacement", &CollisionCheckInfo::displacement)
        .def_readwrite("cylRadius", &CollisionCheckInfo::cylRadius)
        .def_readwrite("cylHeight", &CollisionCheckInfo::cylHeight)
        .def_readwrite("cylYShift", &CollisionCheckInfo::cylYShift)
        .def_readwrite("mass", &CollisionCheckInfo::mass)
        .def_readwrite("health", &CollisionCheckInfo::health)
        .def_readwrite("damage", &CollisionCheckInfo::damage)
        .def_readwrite("damageEffect", &CollisionCheckInfo::damageEffect)
        .def_readwrite("atHitEffect", &CollisionCheckInfo::atHitEffect)
        .def_readwrite("acHitEffect", &CollisionCheckInfo::acHitEffect);

    pybind11::class_<ActorShape>(actor, "ActorShape")
        .def_readwrite("rot", &ActorShape::rot)
        .def_readwrite("face", &ActorShape::face)
        .def_readwrite("yOffset", &ActorShape::yOffset)
        .def_property("shadowDraw", [](ActorShape& shape) { // TODO func pointer helper templates
            return shape.shadowDraw;
        },
        [](ActorShape& shape, std::function<std::remove_pointer_t<ActorShadowFunc>>& func) {
            ActorShadowFunc* funcRaw = func.target<ActorShadowFunc>();
            assert(funcRaw); // TODO throw
            shape.shadowDraw = *funcRaw;
        })
        .def_readwrite("shadowScale", &ActorShape::shadowScale)
        .def_readwrite("shadowAlpha", &ActorShape::shadowAlpha)
        .def_readwrite("feetFloorFlags", &ActorShape::feetFloorFlags)
        .def_property_readonly("feetPos", [](pybind11::object& obj) {
            ActorShape& shape = obj.cast<ActorShape&>();     // TODO no cast?
            return PybindArray<Vec3f>{ shape.feetPos, 2 };                 // TODO size macro?
        });

    pybind11::class_<Actor>(actor, "Actor")
        .def_readonly("id", &Actor::id)
        .def_readonly("category", &Actor::category)
        .def_readwrite("room", &Actor::room)
        .def_readonly("flags", &Actor::flags)
        .def_readonly("home", &Actor::home)
        .def_readonly("params", &Actor::params)
        .def_readonly("objBankIndex", &Actor::objBankIndex)
        .def_readwrite("targetMode", &Actor::targetMode)
        .def_readwrite("sfx", &Actor::sfx)
        .def_readwrite("world", &Actor::world)
        .def_readwrite("focus", &Actor::focus)
        .def_readwrite("targetArrowOffset", &Actor::targetArrowOffset)
        .def_readwrite("scale", &Actor::scale)
        .def_readwrite("velocity", &Actor::velocity)
        .def_readwrite("speedXZ", &Actor::speedXZ)
        .def_readwrite("gravity", &Actor::gravity)
        .def_readwrite("minVelocityY", &Actor::minVelocityY)
        .def_readonly("wallPoly", &Actor::wallPoly)
        .def_readonly("floorPoly", &Actor::floorPoly)
        .def_readonly("wallBgId", &Actor::wallBgId)
        .def_readonly("floorBgId", &Actor::floorBgId)
        .def_readonly("wallYaw", &Actor::wallYaw)
        .def_readonly("floorHeight", &Actor::floorHeight)
        .def_readonly("yDistToWater", &Actor::yDistToWater)
        .def_readwrite("bgCheckFlags", &Actor::bgCheckFlags)
        .def_readonly("yawTowardsPlayer", &Actor::yawTowardsPlayer)
        .def_readonly("xyzDistToPlayerSq", &Actor::xyzDistToPlayerSq)
        .def_readonly("xzDistToPlayer", &Actor::xzDistToPlayer)
        .def_readonly("yDistToPlayer", &Actor::yDistToPlayer)
        .def_readwrite("colChkInfo", &Actor::colChkInfo)
        .def_readwrite("shape", &Actor::shape)
        .def_readonly("projectedPos", &Actor::projectedPos)
        .def_readonly("projectedW", &Actor::projectedW)
        .def_readwrite("uncullZoneForward", &Actor::uncullZoneForward)
        .def_readwrite("uncullZoneScale", &Actor::uncullZoneScale)
        .def_readwrite("uncullZoneDownward", &Actor::uncullZoneDownward)
        .def_readonly("prevPos", &Actor::prevPos)
        .def_readonly("isTargeted", &Actor::isTargeted)
        .def_readwrite("targetPriority", &Actor::targetPriority)
        .def_readwrite("textId", &Actor::textId)
        .def_readwrite("freezeTimer", &Actor::freezeTimer)
        .def_readwrite("colorFilterParams", &Actor::colorFilterParams)
        .def_readwrite("colorFilterTimer", &Actor::colorFilterTimer)
        .def_readwrite("isDrawn", &Actor::isDrawn)
        .def_readwrite("dropFlag", &Actor::dropFlag)
        .def_readwrite("naviEnemyId", &Actor::naviEnemyId)
        .def_readonly("parent", &Actor::parent)
        .def_readonly("child", &Actor::child)
        .def_readonly("prev", &Actor::prev)
        .def_readonly("next", &Actor::next);

    
    pybind11::class_<DynaPolyActor>(actor, "DynaPolyActor")
        .def_readwrite("actor", &DynaPolyActor::actor)
        .def_readonly("bgId", &DynaPolyActor::bgId)
        .def_readwrite("unk_150", &DynaPolyActor::unk_150)
        .def_readwrite("unk_154", &DynaPolyActor::unk_154)
        .def_readwrite("unk_158", &DynaPolyActor::unk_158)
        .def_readwrite("unk_15A", &DynaPolyActor::unk_15A)
        .def_readwrite("transformFlags", &DynaPolyActor::transformFlags)
        .def_readwrite("interactFlags", &DynaPolyActor::interactFlags)
        .def_readwrite("unk_162", &DynaPolyActor::unk_162);

    pybind11::class_<BodyBreak>(actor, "BodyBreak")
        .def_property_readonly("matrices", [](pybind11::object& obj) {
            BodyBreak& body = obj.cast<BodyBreak&>(); // TODO no cast?
            return PybindArray<MtxF>{ body.matrices, 0 };   // TODO size macro?
        })
        .def_property_readonly("objectIds", [](pybind11::object& obj) {
            BodyBreak& body = obj.cast<BodyBreak&>(); // TODO no cast?
            return PybindArray<s16>{ body.objectIds, static_cast<size_t>(body.count + 1) };   // TODO size macro?
        })
        .def_readwrite("count", &BodyBreak::count)
        //.def_readwrite("dLists", &BodyBreak::dLists) // TODO fix
        .def_readwrite("val", &BodyBreak::val)
        .def_readwrite("prevLimbIndex", &BodyBreak::prevLimbIndex);

    pybind11::class_<EnItem00>(actor, "EnItem00")
        .def_readwrite("actor", &EnItem00::actor)
        .def_readwrite("collectibleFlag", &EnItem00::collectibleFlag)
        .def_readwrite("getItemId", &EnItem00::getItemId)
        .def_readwrite("unk_154", &EnItem00::unk_154)
        .def_readwrite("unk_156", &EnItem00::unk_156)
        .def_readwrite("unk_158", &EnItem00::unk_158)
        .def_readwrite("unk_15A", &EnItem00::unk_15A)
        .def_readwrite("scale", &EnItem00::scale)
        .def_readwrite("collider", &EnItem00::collider);

    pybind11::class_<EnAObj>(actor, "EnAObj")
        .def_readwrite("dyna", &EnAObj::dyna)
        .def_readwrite("rotateWaitTimer", &EnAObj::rotateWaitTimer)
        .def_readwrite("textId", &EnAObj::textId)
        .def_readwrite("rotateState", &EnAObj::rotateState)
        .def_readwrite("rotateForTimer", &EnAObj::rotateForTimer)
        .def_readwrite("rotSpeedY", &EnAObj::rotSpeedY)
        .def_readwrite("rotSpeedX", &EnAObj::rotSpeedX)
        .def_readwrite("focusYoffset", &EnAObj::focusYoffset)
        .def_readwrite("collider", &EnAObj::collider);

    pybind11::class_<NpcInteractInfo>(actor, "NpcInteractInfo")
        .def_readwrite("talkState", &NpcInteractInfo::talkState)
        .def_readwrite("trackingMode", &NpcInteractInfo::trackingMode)
        .def_readwrite("autoTurnTimer", &NpcInteractInfo::autoTurnTimer)
        .def_readwrite("autoTurnState", &NpcInteractInfo::autoTurnState)
        .def_readwrite("headRot", &NpcInteractInfo::headRot)
        .def_readwrite("torsoRot", &NpcInteractInfo::torsoRot)
        .def_readwrite("yOffset", &NpcInteractInfo::yOffset)
        .def_readwrite("trackPos", &NpcInteractInfo::trackPos);

    actor.def("ActorShadow_DrawCircle", &ActorShadow_DrawCircle);
    actor.def("MoveXZGravity", &Actor_MoveXZGravity);
    actor.def("UpdateBgCheckInfo", &Actor_UpdateBgCheckInfo);
    actor.def("func_8002F948", &func_8002F948);
    actor.def("WorldDistXYZToActor", &Actor_WorldDistXYZToActor);

    // TODO macros/functions
}