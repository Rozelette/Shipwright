#include "ScriptInterface.h"
#include "global.h"
#include "ActorDB.h"
#include "objects/gameplay_field_keep/gameplay_field_keep.h"

namespace ScriptInterface {

// TODO new for Alloc* functions?

//**************************
// Actor
//**************************

s16 GetActorID(Actor* actor) {
    assert(actor != nullptr);
    return actor->id;
}

u8 GetActorCategory(Actor* actor) {
    assert(actor != nullptr);
    return actor->category;
}
void SetActorCategory(Actor* actor, u8 category) {
    assert(actor != nullptr);
    actor->category = category;
}

s8 GetActorRoom(Actor* actor) {
    assert(actor != nullptr);
    return actor->room;
}

void SetActorRoom(Actor* actor, s8 room) {
    assert(actor != nullptr);
    actor->room = room;
}

u32 GetActorFlags(Actor* actor) {
    assert(actor != nullptr);
    return actor->flags;
}
void SetActorFlags(Actor* actor, u32 flags) {
    assert(actor != nullptr);
    actor->flags = flags;
}

s16 GetActorParams(Actor* actor) {
    assert(actor != nullptr);
    return actor->params;
}
void SetActorParams(Actor* actor, s16 params) {
    assert(actor != nullptr);
    actor->params = params;
}

s8 GetActorObjBankIndex(Actor* actor) {
    assert(actor != nullptr);
    return actor->objBankIndex;
}
void SetActorObjBankIndex(Actor* actor, s8 objBankIndex) {
    assert(actor != nullptr);
    actor->objBankIndex = objBankIndex;
}

s8 GetActorTargetMode(Actor* actor) {
    assert(actor != nullptr);
    return actor->targetMode;
}
void SetActorTargetMode(Actor* actor, s8 targetMode) {
    assert(actor != nullptr);
    actor->targetMode = targetMode;
}

u16 GetActorSfx(Actor* actor) {
    assert(actor != nullptr);
    return actor->sfx;
}
void SetActorSfx(Actor* actor, u16 sfx) {
    assert(actor != nullptr);
    actor->sfx = sfx;
}

f32 GetActorPosX(Actor* actor) {
    assert(actor != nullptr);
    return actor->world.pos.x;
}
f32 GetActorPosY(Actor* actor) {
    assert(actor != nullptr);
    return actor->world.pos.y;
}
f32 GetActorPosZ(Actor* actor) {
    assert(actor != nullptr);
    return actor->world.pos.z;
}
void GetActorPos(Actor* actor, f32* x, f32* y, f32* z) {
    assert(actor != nullptr);
    if (x != nullptr) {
        *x = actor->world.pos.x;
    }
    if (y != nullptr) {
        *y = actor->world.pos.y;
    }
    if (z != nullptr) {
        *z = actor->world.pos.z;
    }
}

void SetActorPosX(Actor* actor, f32 x) {
    assert(actor != nullptr);
    actor->world.pos.x = x;
}
void SetActorPosY(Actor* actor, f32 y) {
    assert(actor != nullptr);
    actor->world.pos.y = y;
}
void SetActorPosZ(Actor* actor, f32 z) {
    assert(actor != nullptr);
    actor->world.pos.z = z;
}
void SetActorPos(Actor* actor, f32 x, f32 y, f32 z) {
    assert(actor != nullptr);
    actor->world.pos.x = x;
    actor->world.pos.y = y;
    actor->world.pos.z = z;
}

s16 GetActorRotX(Actor* actor) {
    assert(actor != nullptr);
    return actor->world.rot.x;
}
s16 GetActorRotY(Actor* actor) {
    assert(actor != nullptr);
    return actor->world.rot.y;
}
s16 GetActorRotZ(Actor* actor) {
    assert(actor != nullptr);
    return actor->world.rot.z;
}
void GetActorRot(Actor* actor, s16* x, s16* y, s16* z) {
    assert(actor != nullptr);
    if (x != nullptr) {
        *x = actor->world.rot.x;
    }
    if (y != nullptr) {
        *y = actor->world.rot.y;
    }
    if (z != nullptr) {
        *z = actor->world.rot.z;
    }
}

void SetActorRotX(Actor* actor, s16 x) {
    assert(actor != nullptr);
    actor->world.rot.x = x;
}
void SetActorRotY(Actor* actor, s16 y) {
    assert(actor != nullptr);
    actor->world.rot.y = y;
}
void SetActorRotZ(Actor* actor, s16 z) {
    assert(actor != nullptr);
    actor->world.rot.z = z;
}
void SetActorRot(Actor* actor, s16 x, s16 y, s16 z) {
    assert(actor != nullptr);
    actor->world.rot.x = x;
    actor->world.rot.y = y;
    actor->world.rot.z = z;
}

void GetActorPosRot(Actor* actor, f32* posX, f32* posY, f32* posZ, s16* rotX, s16* rotY, s16* rotZ) {
    assert(actor != nullptr);
    if (posX != nullptr) {
        *posX = actor->world.pos.x;
    }
    if (posY != nullptr) {
        *posY = actor->world.pos.y;
    }
    if (posZ != nullptr) {
        *posZ = actor->world.pos.z;
    }
    if (rotX != nullptr) {
        *rotX = actor->world.rot.x;
    }
    if (rotY != nullptr) {
        *rotY = actor->world.rot.y;
    }
    if (rotZ != nullptr) {
        *rotZ = actor->world.rot.z;
    }
}
void SetActorPosRot(Actor* actor, f32 posX, f32 posY, f32 posZ, s16 rotX, s16 rotY, s16 rotZ) {
    assert(actor != nullptr);
    actor->world.pos.x = posX;
    actor->world.pos.y = posY;
    actor->world.pos.z = posZ;
    actor->world.rot.x = rotX;
    actor->world.rot.y = rotY;
    actor->world.rot.z = rotZ;
}

// TODO focus
f32 GetActorFocusPosX(Actor* actor) {
    assert(actor != nullptr);
    return actor->focus.pos.x;
}
f32 GetActorFocusPosY(Actor* actor) {
    assert(actor != nullptr);
    return actor->focus.pos.y;
}
f32 GetActorFocusPosZ(Actor* actor) {
    assert(actor != nullptr);
    return actor->focus.pos.z;
}
void GetActorFocusPos(Actor* actor, f32* x, f32* y, f32* z) {
    assert(actor != nullptr);
    if (x != nullptr) {
        *x = actor->focus.pos.x;
    }
    if (y != nullptr) {
        *y = actor->focus.pos.y;
    }
    if (z != nullptr) {
        *z = actor->focus.pos.z;
    }
}

void SetActorFocusPosX(Actor* actor, f32 x) {
    assert(actor != nullptr);
    actor->focus.pos.x = x;
}
void SetActorFocusPosY(Actor* actor, f32 y) {
    assert(actor != nullptr);
    actor->focus.pos.y = y;
}
void SetActorFocusPosZ(Actor* actor, f32 z) {
    assert(actor != nullptr);
    actor->focus.pos.z = z;
}
void SetActorFocusPos(Actor* actor, f32 x, f32 y, f32 z) {
    assert(actor != nullptr);
    actor->focus.pos.x = x;
    actor->focus.pos.z = y;
    actor->focus.pos.z = z;
}

s16 GetActorFocusRotX(Actor* actor) {
    assert(actor != nullptr);
    return actor->focus.rot.x;
}
s16 GetActorFocusRotY(Actor* actor) {
    assert(actor != nullptr);
    return actor->focus.rot.y;
}
s16 GetActorFocusRotZ(Actor* actor) {
    assert(actor != nullptr);
    return actor->focus.rot.z;
}
void GetActorFocusRot(Actor* actor, s16* x, s16* y, s16* z) {
    assert(actor != nullptr);
    if (x != nullptr) {
        *x = actor->focus.rot.x;
    }
    if (y != nullptr) {
        *y = actor->focus.rot.y;
    }
    if (z != nullptr) {
        *z = actor->focus.rot.z;
    }
}

void SetActorFocusRotX(Actor* actor, s16 x) {
    assert(actor != nullptr);
    actor->focus.rot.x = x;
}
void SetActorFocusRotY(Actor* actor, s16 y) {
    assert(actor != nullptr);
    actor->focus.rot.y = y;
}
void SetActorFocusRotZ(Actor* actor, s16 z) {
    assert(actor != nullptr);
    actor->focus.rot.z = z;
}
void SetActorFocusRot(Actor* actor, s16 x, s16 y, s16 z) {
    assert(actor != nullptr);
    actor->focus.rot.x = x;
    actor->focus.rot.y = y;
    actor->focus.rot.z = z;
}

void GetActorFocusPosRot(Actor* actor, f32* posX, f32* posY, f32* posZ, s16* rotX, s16* rotY, s16* rotZ) {
    assert(actor != nullptr);
    if (posX != nullptr) {
        *posX = actor->focus.pos.x;
    }
    if (posY != nullptr) {
        *posY = actor->focus.pos.y;
    }
    if (posZ != nullptr) {
        *posZ = actor->focus.pos.z;
    }
    if (rotX != nullptr) {
        *rotX = actor->focus.rot.x;
    }
    if (rotY != nullptr) {
        *rotY = actor->focus.rot.y;
    }
    if (rotZ != nullptr) {
        *rotZ = actor->focus.rot.z;
    }
}
void SetActorFocusPosRot(Actor* actor, f32 posX, f32 posY, f32 posZ, s16 rotX, s16 rotY, s16 rotZ) {
    assert(actor != nullptr);
    actor->focus.pos.x = posX;
    actor->focus.pos.z = posY;
    actor->focus.pos.z = posZ;
    actor->focus.rot.x = rotX;
    actor->focus.rot.y = rotY;
    actor->focus.rot.z = rotZ;
}

f32 GetActorTargetArrowOffset(Actor* actor) {
    assert(actor != nullptr);
    return actor->targetArrowOffset;
}
void SetActorTargetArrowOffset(Actor* actor, f32 targetArrowOffset) {
    assert(actor != nullptr);
    actor->targetArrowOffset = targetArrowOffset;
}

f32 GetActorScaleX(Actor* actor) {
    assert(actor != nullptr);
    return actor->scale.x;
}
f32 GetActorScaleY(Actor* actor) {
    assert(actor != nullptr);
    return actor->scale.y;
}
f32 GetActorScaleZ(Actor* actor) {
    assert(actor != nullptr);
    return actor->scale.z;
}
void GetActorScale(Actor* actor, f32* x, f32* y, f32* z) {
    assert(actor != nullptr);
    if (x != nullptr) {
        *x = actor->scale.x;
    }
    if (y != nullptr) {
        *y = actor->scale.y;
    }
    if (z != nullptr) {
        *z = actor->scale.z;
    }
}

void SetActorScaleX(Actor* actor, f32 x) {
    assert(actor != nullptr);
    actor->scale.x = x;
}
void SetActorScaleY(Actor* actor, f32 y) {
    assert(actor != nullptr);
    actor->scale.y = y;
}
void SetActorScaleZ(Actor* actor, f32 z) {
    assert(actor != nullptr);
    actor->scale.z = z;
}
void SetActorScale(Actor* actor, f32 x, f32 y, f32 z) {
    assert(actor != nullptr);
    actor->scale.x = x;
    actor->scale.y = y;
    actor->scale.z = z;
}

f32 GetActorVelocityX(Actor* actor) {
    assert(actor != nullptr);
    return actor->velocity.x;
}
f32 GetActorVelocityY(Actor* actor) {
    assert(actor != nullptr);
    return actor->velocity.y;
}
f32 GetActorVelocityZ(Actor* actor) {
    assert(actor != nullptr);
    return actor->velocity.z;
}
void GetActorVelocity(Actor* actor, f32* x, f32* y, f32* z) {
    assert(actor != nullptr);
    if (x != nullptr) {
        *x = actor->velocity.x;
    }
    if (y != nullptr) {
        *y = actor->velocity.y;
    }
    if (z != nullptr) {
        *z = actor->velocity.z;
    }
}

void SetActorVelocityX(Actor* actor, f32 x) {
    assert(actor != nullptr);
    actor->velocity.x = x;
}
void SetActorVelocityY(Actor* actor, f32 y) {
    assert(actor != nullptr);
    actor->velocity.y = y;
}
void SetActorVelocityZ(Actor* actor, f32 z) {
    assert(actor != nullptr);
    actor->velocity.z = z;
}
void SetActorVelocity(Actor* actor, f32 x, f32 y, f32 z) {
    assert(actor != nullptr);
    actor->velocity.x = x;
    actor->velocity.y = y;
    actor->velocity.z = z;
}

f32 GetActorSpeedXZ(Actor* actor) {
    assert(actor != nullptr);
    return actor->speedXZ;
}

f32 GetActorGravity(Actor* actor) {
    assert(actor != nullptr);
    return actor->gravity;
}
void SetActorGravity(Actor* actor, f32 gravity) {
    assert(actor != nullptr);
    actor->gravity = gravity;
}

f32 GetActorMinVelocityY(Actor* actor) {
    assert(actor != nullptr);
    return actor->minVelocityY;
}
void SetActorMinVelocityY(Actor* actor, f32 minVelocityY) {
    assert(actor != nullptr);
    actor->minVelocityY = minVelocityY;
}

// CollisionCheckInfo

void CollisionCheck_SetInfo(Actor* actor, DamageTable* damageTable, CollisionCheckInfoInit* init) {
    assert(actor != nullptr);
    ::CollisionCheck_SetInfo(&actor->colChkInfo, damageTable, init);
}
void CollisionCheck_SetInfoRaw(Actor* actor, DamageTable* damageTable, u8 health, s16 cylRadius, s16 cylHeight, u8 mass) {
    assert(actor != nullptr);
    CollisionCheckInfoInit init{health, cylRadius, cylHeight, mass};
    ::CollisionCheck_SetInfo(&actor->colChkInfo, damageTable, &init);
}

f32 GetActorCollisionDisplacementX(Actor* actor) {
    assert(actor != nullptr);
    return actor->colChkInfo.displacement.x;
}
f32 GetActorCollisionDisplacementY(Actor* actor) {
    assert(actor != nullptr);
    return actor->colChkInfo.displacement.y;
}
f32 GetActorCollisionDisplacementZ(Actor* actor) {
    assert(actor != nullptr);
    return actor->colChkInfo.displacement.z;
}
void GetActorCollisionDisplacement(Actor* actor, f32* x, f32* y, f32* z) {
    assert(actor != nullptr);
    if (x != nullptr) {
        *x = actor->colChkInfo.displacement.x;
    }
    if (y != nullptr) {
        *y = actor->colChkInfo.displacement.y;
    }
    if (z != nullptr) {
        *z = actor->colChkInfo.displacement.z;
    }
}

void SetActorCollisionDisplacementX(Actor* actor, f32 x) {
    assert(actor != nullptr);
    actor->colChkInfo.displacement.x = x;
}
void SetActorCollisionDisplacementY(Actor* actor, f32 y) {
    assert(actor != nullptr);
    actor->colChkInfo.displacement.y = y;
}
void SetActorCollisionDisplacementZ(Actor* actor, f32 z) {
    assert(actor != nullptr);
    actor->colChkInfo.displacement.z = z;
}
void SetActorCollisionDisplacement(Actor* actor, f32 x, f32 y, f32 z) {
    assert(actor != nullptr);
    actor->colChkInfo.displacement.x = x;
    actor->colChkInfo.displacement.y = y;
    actor->colChkInfo.displacement.z = z;
}

s16 GetActorCollisionCylRadius(Actor* actor) {
    assert(actor != nullptr);
    return actor->colChkInfo.cylRadius;
}
void SetActorCollisionCylRadius(Actor* actor, s16 cylRadius) {
    assert(actor != nullptr);
    actor->colChkInfo.cylRadius = cylRadius;
}

s16 GetActorCollisionCylHeight(Actor* actor) {
    assert(actor != nullptr);
    return actor->colChkInfo.cylHeight;
}
void SetActorCollisionCylHeight(Actor* actor, s16 cylHeight) {
    assert(actor != nullptr);
    actor->colChkInfo.cylRadius = cylHeight;
}

s16 GetActorCollisionCylYShift(Actor* actor) {
    assert(actor != nullptr);
    return actor->colChkInfo.cylYShift;
}
void SetActorCollisionCylYShift(Actor* actor, s16 cylYShift) {
    assert(actor != nullptr);
    actor->colChkInfo.cylYShift = cylYShift;
}

u8 GetActorCollisionMass(Actor* actor) {
    assert(actor != nullptr);
    return actor->colChkInfo.mass;
}
void SetActorCollisionMass(Actor* actor, u8 mass) {
    assert(actor != nullptr);
    actor->colChkInfo.mass = mass;
}

u8 GetActorCollisionHealth(Actor* actor) {
    assert(actor != nullptr);
    return actor->colChkInfo.health;
}
void SetActorCollisionHealth(Actor* actor, u8 health) {
    assert(actor != nullptr);
    actor->colChkInfo.health = health;
}

u8 GetActorCollisionDamage(Actor* actor) {
    assert(actor != nullptr);
    return actor->colChkInfo.damage;
}
void SetActorCollisionDamage(Actor* actor, u8 damage) {
    assert(actor != nullptr);
    actor->colChkInfo.damage = damage;
}

u8 GetActorCollisionDamageEffect(Actor* actor) {
    assert(actor != nullptr);
    return actor->colChkInfo.damageEffect;
}
void SetActorCollisionDamageEffect(Actor* actor, u8 damageEffect) {
    assert(actor != nullptr);
    actor->colChkInfo.damageEffect = damageEffect;
}

u8 GetActorCollisionAtHitEffect(Actor* actor) {
    assert(actor != nullptr);
    return actor->colChkInfo.atHitEffect;
}
void SetActorCollisionAtHitEffect(Actor* actor, u8 atHitEffect) {
    assert(actor != nullptr);
    actor->colChkInfo.atHitEffect = atHitEffect;
}

u8 GetActorCollisionAcHitEffect(Actor* actor) {
    assert(actor != nullptr);
    return actor->colChkInfo.acHitEffect;
}
void SetActorCollisionAcHitEffect(Actor* actor, u8 acHitEffect) {
    assert(actor != nullptr);
    actor->colChkInfo.acHitEffect = acHitEffect;
}

// ActorShape
ActorShape* GetActorShape(Actor* actor) {
    assert(actor != nullptr);
    return &actor->shape;
}

void ActorShape_Init(ActorShape* shape, f32 yOffset, ActorShadowFunc shadowDraw, f32 shadowScale) {
    assert(shape != nullptr);
    assert(shadowDraw != nullptr);
    ::ActorShape_Init(shape, yOffset, shadowDraw, shadowScale);
}
void ActorShape_InitCircle(ActorShape* shape, f32 yOffset, f32 shadowScale) {
    ScriptInterface::ActorShape_Init(shape, yOffset, ActorShadow_DrawCircle, shadowScale);
}

f32 ActorShape_GetYOffset(ActorShape* shape) {
    assert(shape != nullptr);
    return shape->yOffset;
}
void ActorShape_SetYOffset(ActorShape* shape, f32 yOffset) {
    assert(shape != nullptr);
    shape->yOffset = yOffset;
}

f32 ActorShape_GetShadowScale(ActorShape* shape) {
    assert(shape != nullptr);
    return shape->shadowScale;
}
void ActorShape_SetShadowScale(ActorShape* shape, f32 shadowScale) {
    assert(shape != nullptr);
    shape->shadowScale = shadowScale;
}

u8 ActorShape_GetShadowAlpha(ActorShape* shape) {
    assert(shape != nullptr);
    return shape->shadowAlpha;
}
void ActorShape_SetShadowAlpha(ActorShape* shape, u8 shadowAlpha) {
    assert(shape != nullptr);
    shape->shadowAlpha = shadowAlpha;
}

u8 ActorShape_GetFeetFloorFlags(ActorShape* shape) {
    assert(shape != nullptr);
    return shape->feetFloorFlags;
}
void ActorShape_SetFeetFloorFlags(ActorShape* shape, u8 feetFloorFlags) {
    assert(shape != nullptr);
    shape->feetFloorFlags = feetFloorFlags;
}

// Util
Actor* Actor_Spawn(ActorContext* actorCtx, PlayState* play, s16 actorId, f32 posX, f32 posY, f32 posZ,
    s16 rotX, s16 rotY, s16 rotZ, s16 params, s16 canRandomize) {
    assert(actorCtx != nullptr);
    assert(play != nullptr);
    return ::Actor_Spawn(actorCtx, play, actorId, posX, posY, posZ, rotX, rotY, rotZ, params, canRandomize);
}
Actor* Actor_SpawnAsChild(ActorContext* actorCtx, Actor* parent, PlayState* play, s16 actorId, f32 posX,
    f32 posY, f32 posZ, s16 rotX, s16 rotY, s16 rotZ, s16 params) {
    assert(actorCtx != nullptr);
    assert(parent != nullptr);
    assert(play != nullptr);
    return ::Actor_SpawnAsChild(actorCtx, parent, play, actorId, posX, posY, posZ, rotX, rotY, rotZ, params);
}

void Actor_Kill(Actor* actor) {
    assert(actor != nullptr);
    ::Actor_Kill(actor);
}

s32 Actor_GetActorCount(ActorContext* actorCtx, ActorCategory category) {
    assert(actorCtx != nullptr);
    return actorCtx->actorLists[category].length;
}
Actor* Actor_GetActorHead(ActorContext* actorCtx, ActorCategory category) {
    assert(actorCtx != nullptr);
    return actorCtx->actorLists[category].head;
}

void Actor_MoveForward(Actor* actor) {
    assert(actor != nullptr);
    ::Actor_MoveForward(actor);
}

void Actor_UpdateBgCheckInfo(PlayState* play, Actor* actor, f32 wallCheckHeight, f32 wallCheckRadius, f32 ceilingCheckHeight, s32 flags) {
    assert(play != nullptr);
    assert(actor != nullptr);
    ::Actor_UpdateBgCheckInfo(play, actor, wallCheckHeight, wallCheckRadius, ceilingCheckHeight, flags);
}

f32 Actor_WorldDistXYZToActor(Actor* actorA, Actor* actorB) {
    assert(actorA != nullptr);
    assert(actorB != nullptr);
    return ::Actor_WorldDistXYZToActor(actorA, actorB);
}

//**************************
// Player
//**************************

Player* GetPlayer(PlayState* play) {
    assert(play != nullptr);
    return GET_PLAYER(play);
}

u8 GetPlayerIvanFloating(Player* player) {
    assert(player != nullptr);
    assert(player->actor.id == ACTOR_PLAYER);
    return player->ivanFloating;
}
void SetPlayerIvanFloating(Player* player, u8 ivanFloating) {
    assert(player != nullptr);
    assert(player->actor.id == ACTOR_PLAYER);
    player->ivanFloating = ivanFloating;
}

u8 GetPlayerIvanDamageMultiplier(Player* player) {
    assert(player != nullptr);
    assert(player->actor.id == ACTOR_PLAYER);
    return player->ivanDamageMultiplier;
}
void SetPlayerIvanDamageMultiplier(Player* player, u8 ivanDamageMultiplier) {
    assert(player != nullptr);
    assert(player->actor.id == ACTOR_PLAYER);
    player->ivanDamageMultiplier = ivanDamageMultiplier;
}

f32 Player_GetHeight(Player* player) {
    assert(player != nullptr);
    assert(player->actor.id == ACTOR_PLAYER);
    return ::Player_GetHeight(player);
}

s32 Player_InCsMode(PlayState* play) {
    assert(play != nullptr);
    return ::Player_InCsMode(play);
}

//**************************
// Collider
//**************************

// Base
Actor* Collider_GetActor(Collider* collider) {
    assert(collider != nullptr);
    return collider->actor;
}
void Collider_SetActor(Collider* collider, Actor* actor) {
    assert(collider != nullptr);
    collider->actor = actor;
}

Actor* Collider_GetAt(Collider* collider) {
    assert(collider != nullptr);
    return collider->at;
}
void Collider_SetAt(Collider* collider, Actor* at) {
    assert(collider != nullptr);
    collider->at = at;
}

Actor* Collider_GetAc(Collider* collider) {
    assert(collider != nullptr);
    return collider->ac;
}
void Collider_SetAc(Collider* collider, Actor* ac) {
    assert(collider != nullptr);
    collider->ac = ac;
}

Actor* Collider_GetOc(Collider* collider) {
    assert(collider != nullptr);
    return collider->oc;
}
void Collider_SetOc(Collider* collider, Actor* oc) {
    assert(collider != nullptr);
    collider->oc = oc;
}

u8 Collider_GetAtFlags(Collider* collider) {
    assert(collider != nullptr);
    return collider->atFlags;
}
void Collider_SetAtFlags(Collider* collider, u8 atFlags) {
    assert(collider != nullptr);
    collider->atFlags = atFlags;
}

u8 Collider_GetAcFlags(Collider* collider) {
    assert(collider != nullptr);
    return collider->acFlags;
}
void Collider_SetAcFlags(Collider* collider, u8 acFlags) {
    assert(collider != nullptr);
    collider->acFlags = acFlags;
}

u8 Collider_GetOcFlags1(Collider* collider) {
    assert(collider != nullptr);
    return collider->ocFlags1;
}
void Collider_SetOcFlags1(Collider* collider, u8 ocFlags1) {
    assert(collider != nullptr);
    collider->ocFlags1 = ocFlags1;
}

u8 Collider_GetOcFlags2(Collider* collider) {
    assert(collider != nullptr);
    return collider->ocFlags2;
}
void Collider_SetOcFlags2(Collider* collider, u8 ocFlags2) {
    assert(collider != nullptr);
    collider->ocFlags2 = ocFlags2;
}

u8 Collider_GetColType(Collider* collider) {
    assert(collider != nullptr);
    return collider->colType;
}
void Collider_SetColType(Collider* collider, u8 colType) {
    assert(collider != nullptr);
    collider->colType = colType;
}

u8 Collider_GetShape(Collider* collider) {
    assert(collider != nullptr);
    return collider->shape;
}
void Collider_SetShape(Collider* collider, u8 shape) {
    assert(collider != nullptr);
    collider->shape = shape;
}

// Info
u32 Collider_TouchGetDmgFlags(ColliderInfo* info) {
    assert(info != nullptr);
    return info->toucher.dmgFlags;
}
void Collider_TouchSetDmgFlags(ColliderInfo* info, u32 dmgFlags) {
    assert(info != nullptr);
    info->toucher.dmgFlags = dmgFlags;
}

u8 Collider_TouchGetEffect(ColliderInfo* info) {
    assert(info != nullptr);
    return info->toucher.effect;
}
void Collider_TouchSetEffect(ColliderInfo* info, u8 effect) {
    assert(info != nullptr);
    info->toucher.effect = effect;
}

u8 Collider_TouchGetDamage(ColliderInfo* info) {
    assert(info != nullptr);
    return info->toucher.damage;
}
void Collider_TouchSetDamage(ColliderInfo* info, u8 damage) {
    assert(info != nullptr);
    info->toucher.damage = damage;
}

u32 Collider_BumpGetDmgFlags(ColliderInfo* info) {
    assert(info != nullptr);
    return info->bumper.dmgFlags;
}
void Collider_BumpSetDmgFlags(ColliderInfo* info, u32 dmgFlags) {
    assert(info != nullptr);
    info->bumper.dmgFlags = dmgFlags;
}

u8 Collider_BumpGetEffect(ColliderInfo* info) {
    assert(info != nullptr);
    return info->bumper.effect;
}
void Collider_BumpSetEffect(ColliderInfo* info, u8 effect) {
    assert(info != nullptr);
    info->bumper.effect = effect;
}

u8 Collider_BumpGetDefense(ColliderInfo* info) {
    assert(info != nullptr);
    return info->bumper.defense;
}
void Collider_BumpSetDefense(ColliderInfo* info, u8 defense) {
    assert(info != nullptr);
    info->bumper.defense = defense;
}

s16 Collider_BumpGetHitX(ColliderInfo* info) {
    assert(info != nullptr);
    return info->bumper.hitPos.x;
}
s16 Collider_BumpGetHitY(ColliderInfo* info) {
    assert(info != nullptr);
    return info->bumper.hitPos.y;
}
s16 Collider_BumpGetHitZ(ColliderInfo* info) {
    assert(info != nullptr);
    return info->bumper.hitPos.z;
}
void Collider_BumpGetHit(ColliderInfo* info, s16* x, s16* y, s16* z) {
    assert(info != nullptr);
    if (x != nullptr) {
        *x = info->bumper.hitPos.x;
    }
    if (y != nullptr) {
        *y = info->bumper.hitPos.y;
    }
    if (z != nullptr) {
        *z = info->bumper.hitPos.z;
    }
}

void Collider_BumpSetHitX(ColliderInfo* info, s16 x) {
    assert(info != nullptr);
    info->bumper.hitPos.x = x;
}
void Collider_BumpSetHitY(ColliderInfo* info, s16 y) {
    assert(info != nullptr);
    info->bumper.hitPos.y = y;
}
void Collider_BumpSetHitZ(ColliderInfo* info, s16 z) {
    assert(info != nullptr);
    info->bumper.hitPos.z = z;
}
void Collider_BumpSetHit(ColliderInfo* info, s16 x, s16 y, s16 z) {
    assert(info != nullptr);
    info->bumper.hitPos.x = x;
    info->bumper.hitPos.y = y;
    info->bumper.hitPos.z = z;
}

u8 Collider_InfoGetElemType(ColliderInfo* info) {
    assert(info != nullptr);
    return info->elemType;
}
void Collider_InfoSetElemType(ColliderInfo* info, u8 elemType) {
    assert(info != nullptr);
    info->elemType = elemType;
}

u8 Collider_InfoGetToucherFlags(ColliderInfo* info) {
    assert(info != nullptr);
    return info->toucherFlags;
}
void Collider_InfoSetToucherFlags(ColliderInfo* info, u8 toucherFlags) {
    assert(info != nullptr);
    info->toucherFlags = toucherFlags;
}

u8 Collider_InfoGetBumperFlags(ColliderInfo* info) {
    assert(info != nullptr);
    return info->bumperFlags;
}
void Collider_InfoSetBumperFlags(ColliderInfo* info, u8 bumperFlags) {
    assert(info != nullptr);
    info->bumperFlags = bumperFlags;
}

u8 Collider_InfoGetOcElemFlags(ColliderInfo* info) {
    assert(info != nullptr);
    return info->ocElemFlags;
}
void Collider_InfoSetOcElemFlags(ColliderInfo* info, u8 ocElemFlags) {
    assert(info != nullptr);
    info->ocElemFlags = ocElemFlags;
}

Collider* Collider_InfoGetAtHit(ColliderInfo* info) {
    assert(info != nullptr);
    return info->atHit;
}
void Collider_InfoSetAtHit(ColliderInfo* info, Collider* atHit) {
    assert(info != nullptr);
    info->atHit = atHit;
}

Collider* Collider_InfoGetAcHit(ColliderInfo* info) {
    assert(info != nullptr);
    return info->acHit;
}
void Collider_InfoSetAcHit(ColliderInfo* info, Collider* acHit) {
    assert(info != nullptr);
    info->acHit = acHit;
}

ColliderInfo* Collider_InfoGetAtHitInfo(ColliderInfo* info) {
    assert(info != nullptr);
    return info->atHitInfo;
}
void Collider_InfoSetAtHitInfo(ColliderInfo* info, ColliderInfo* atHitInfo) {
    assert(info != nullptr);
    info->atHitInfo = atHitInfo;
}

ColliderInfo* Collider_InfoGetAcHitInfo(ColliderInfo* info) {
    assert(info != nullptr);
    return info->acHitInfo;
}
void Collider_InfoSetAcHitInfo(ColliderInfo* info, ColliderInfo* acHitInfo) {
    assert(info != nullptr);
    info->acHitInfo = acHitInfo;
}

// Cylinder
ColliderCylinder* Collider_AllocCylinder() {
    return new ColliderCylinder;
}
void Collider_DeallocCylinder(ColliderCylinder* cylinder) {
    assert(cylinder != nullptr);
    delete cylinder;
}

void Collider_InitCylinder(ColliderCylinder* cylinder) {
    assert(cylinder != nullptr);
    ::Collider_InitCylinder(nullptr, cylinder);
}
void Collider_DestroyCylinder(ColliderCylinder* cylinder) {
    assert(cylinder != nullptr);
    ::Collider_DestroyCylinder(nullptr, cylinder);
}

Collider* Collider_CylinderGetBase(ColliderCylinder* cylinder) {
    assert(cylinder != nullptr);
    return &cylinder->base;
}

ColliderInfo* Collider_CylinderGetInfo(ColliderCylinder* cylinder) {
    assert(cylinder != nullptr);
    return &cylinder->info;
}

s16 Collider_CylinderGetRadius(ColliderCylinder* cylinder) {
    assert(cylinder != nullptr);
    return cylinder->dim.radius;
}
void Collider_CylinderSetRadius(ColliderCylinder* cylinder, s16 radius) {
    assert(cylinder != nullptr);
    cylinder->dim.radius = radius;
}

s16 Collider_CylinderGetHeight(ColliderCylinder* cylinder) {
    assert(cylinder != nullptr);
    return cylinder->dim.height;
}
void Collider_CylinderSetHeight(ColliderCylinder* cylinder, s16 height) {
    assert(cylinder != nullptr);
    cylinder->dim.height = height;
}

s16 Collider_CylinderGetYShift(ColliderCylinder* cylinder) {
    assert(cylinder != nullptr);
    return cylinder->dim.yShift;
}
void Collider_CylinderSetYShift(ColliderCylinder* cylinder, s16 yShift) {
    assert(cylinder != nullptr);
    cylinder->dim.yShift = yShift;
}

s16 Collider_CylinderGetX(ColliderCylinder* cylinder) {
    assert(cylinder != nullptr);
    return cylinder->dim.pos.x;
}
s16 Collider_CylinderGetY(ColliderCylinder* cylinder) {
    assert(cylinder != nullptr);
    return cylinder->dim.pos.y;
}
s16 Collider_CylinderGetZ(ColliderCylinder* cylinder) {
    assert(cylinder != nullptr);
    return cylinder->dim.pos.z;
}
void Collider_CylinderGetPos(ColliderCylinder* cylinder, s16* x, s16* y, s16* z) {
    assert(cylinder != nullptr);
    if (x != nullptr) {
        *x = cylinder->dim.pos.x;
    }
    if (y != nullptr) {
        *y = cylinder->dim.pos.y;
    }
    if (z != nullptr) {
        *z = cylinder->dim.pos.z;
    }
}

void Collider_CylinderSetX(ColliderCylinder* cylinder, s16 x) {
    assert(cylinder != nullptr);
    cylinder->dim.pos.x = x;
}
void Collider_CylinderSetY(ColliderCylinder* cylinder, s16 y) {
    assert(cylinder != nullptr);
    cylinder->dim.pos.y = y;
}
void Collider_CylinderSetZ(ColliderCylinder* cylinder, s16 z) {
    assert(cylinder != nullptr);
    cylinder->dim.pos.z = z;
}
void Collider_CylinderSetPos(ColliderCylinder* cylinder, s16 x, s16 y, s16 z) {
    assert(cylinder != nullptr);
    cylinder->dim.pos.x = x;
    cylinder->dim.pos.y = y;
    cylinder->dim.pos.z = z;
}

void Collider_SetCylinder(ColliderCylinder* cylinder, Actor* actor, ColliderCylinderInit* init) {
    assert(cylinder != nullptr);
    assert(actor != nullptr);
    assert(init != nullptr);
    ::Collider_SetCylinder(nullptr, cylinder, actor, init);
}
void Collider_SetCylinderRaw(Cylinder16* cylinder, s16 radius, s16 height, s16 yShift, s16 x, s16 y, s16 z) {
    assert(cylinder != nullptr);
}

void Collider_UpdateCylinder(ColliderCylinder* cylinder, Actor* actor) {
    assert(cylinder != nullptr);
    assert(actor != nullptr);
    ::Collider_UpdateCylinder(actor, cylinder);
}

//**************************
// SkelAnime
//**************************

SkelAnime* SkelAnime_Alloc() {
    return new SkelAnime();
}
void SkelAnime_Dealloc(SkelAnime* skelAnime) {
    assert(skelAnime != nullptr);
    delete skelAnime;
}

s32 SkelAnime_Init(PlayState* play, SkelAnime* skelAnime, char* skeletonHeaderSeg, char* animation, s32 limbCount) {
    assert(skelAnime != nullptr);
    return ::SkelAnime_Init(play, skelAnime, (SkeletonHeader*)skeletonHeaderSeg, (AnimationHeader*)animation, nullptr, nullptr, limbCount);
}

s32 SkelAnime_Update(SkelAnime* skelAnime) {
    assert(skelAnime != nullptr);
    return ::SkelAnime_Update(skelAnime);
}

Gfx* SkelAnime_Draw(PlayState* play, void** skeleton, Vec3s* jointTable, OverrideLimbDraw overrideLimbDraw, PostLimbDraw postLimbDraw, void* arg, Gfx* gfx) {
    assert(play != nullptr);
    assert(skeleton != nullptr);
    assert(jointTable != nullptr);
    assert(gfx != nullptr);
    return ::SkelAnime_Draw(play, skeleton, jointTable, overrideLimbDraw, postLimbDraw, arg, gfx);
}

Gfx* SkelAnime_DrawWithNames(PlayState* play, void** skeleton, Vec3s* jointTable, void* arg, Gfx* gfx) {
    assert(play != nullptr);
    assert(skeleton != nullptr);
    assert(jointTable != nullptr);
    assert(gfx != nullptr);

    // TODO get rid of cast
    return ::SkelAnime_Draw(play, skeleton, jointTable, (OverrideLimbDraw)ActorDB::ActorOverrideLimbDrawScriptWrapper, (PostLimbDraw)ActorDB::ActorPostLimbDrawScriptWrapper, arg, gfx);
}

void SkelAnime_Free(SkelAnime* skelAnime, PlayState* play) {
    assert(skelAnime != nullptr);
    assert(play != nullptr);
    ::SkelAnime_Free(skelAnime, play);
}

// TODO
void ResourceMgr_UnregisterSkeleton(SkelAnime* skelAnime) {
    assert(skelAnime != nullptr);
    //ResourceMgr_UnregisterSkeleton(skelAnime);
}

//**************************
// Lights
//**************************

LightInfo* Lights_AllocInfo() {
    return new LightInfo; // TODO errors (all allocs)
}
void Lights_DeallocInfo(LightInfo* info) {
    assert(info != nullptr); // TODO needed for delete? (all deallocs)
    delete info;
}

// TODO getters and setters for each attribute

void Lights_PointSetInfo(LightInfo* info, s16 x, s16 y, s16 z, u8 r, u8 g, u8 b, s16 radius, s32 type) {
    assert(info != nullptr);
    ::Lights_PointSetInfo(info, x, y, z, r, g, b, radius, type);
}
void Lights_PointGlowSetInfo(LightInfo* info, s16 x, s16 y, s16 z, u8 r, u8 g, u8 b, s16 radius) {
    assert(info != nullptr);
    ::Lights_PointGlowSetInfo(info, x, y, z, r, g, b, radius);
}
void Lights_PointNoGlowSetInfo(LightInfo* info, s16 x, s16 y, s16 z, u8 r, u8 g, u8 b, s16 radius) {
    assert(info != nullptr);
    ::Lights_PointGlowSetInfo(info, x, y, z, r, g, b, radius);
}
void Lights_PointSetColorAndRadius(LightInfo* info, u8 r, u8 g, u8 b, s16 radius) {
    assert(info != nullptr);
    ::Lights_PointSetColorAndRadius(info, r, g, b, radius);
}
void Lights_DirectionalSetInfo(LightInfo* info, s8 x, s8 y, s8 z, u8 r, u8 g, u8 b) {
    assert(info != nullptr);
    ::Lights_DirectionalSetInfo(info, x, y, z, r, g, b);
}

LightNode* LightContext_InsertLight(LightContext* lightCtx, LightInfo* info) {
    assert(lightCtx != nullptr);
    assert(info != nullptr);
    return ::LightContext_InsertLight(nullptr, lightCtx, info);
}
void LightContext_RemoveLight(LightContext* lightCtx, LightNode* node) {
    assert(lightCtx != nullptr);
    assert(node != nullptr);
    ::LightContext_RemoveLight(nullptr, lightCtx, node);
}

//**************************
// PlayState
//**************************

Input* Play_GetInput(PlayState* play, s32 index) {
    assert(play != nullptr);
    assert(index < 4 && index >= 0); // TODO constant // TODO u32?
    return &play->state.input[index];
}
u32 Play_GetFrames(PlayState* play) {
    assert(play != nullptr);
    return play->state.frames;
}
Camera* Play_GetActiveCamera(PlayState* play) {
    assert(play != nullptr);
    return GET_ACTIVE_CAM(play);
}
GraphicsContext* Play_GetGraphicsContext(PlayState* play) {
    assert(play != nullptr);
    return play->state.gfxCtx;
}
LightContext* Play_GetLightContext(PlayState* play) {
    assert(play != nullptr);
    return &play->lightCtx;
}
ActorContext* Play_GetActorContext(PlayState* play) {
    assert(play != nullptr);
    return &play->actorCtx;
}
PauseContext* Play_GetPauseContext(PlayState* play) {
    assert(play != nullptr);
    return &play->pauseCtx;
}
MtxF* Play_GetBillboardMtxF(PlayState* play) {
    assert(play != nullptr);
    return &play->billboardMtxF;
}

//**************************
// Camera
//**************************

s16 Camera_GetCamDirPitch(Camera* camera) {
    assert(camera != nullptr);
    return ::Camera_GetCamDirPitch(camera);
}
s16 Camera_GetCamDirYaw(Camera* camera) {
    assert(camera != nullptr);
    return ::Camera_GetCamDirYaw(camera);
}

//**************************
// Input
//**************************

OSContPad* Input_GetCur(Input* in) {
    assert(in != nullptr);
    return &in->cur;
}
OSContPad* Input_GetPrev(Input* in) {
    assert(in != nullptr);
    return &in->prev;
}
OSContPad* Input_GetPress(Input* in) {
    assert(in != nullptr);
    return &in->press;
}
OSContPad* Input_GetRel(Input* in) {
    assert(in != nullptr);
    return &in->rel;
}

u16 Input_GetButton(OSContPad* pad) {
    assert(pad = nullptr);
    return pad->button;
}
s8 Input_GetStickX(OSContPad* pad) {
    assert(pad = nullptr);
    return pad->stick_x;
}
s8 Input_GetStickY(OSContPad* pad) {
    assert(pad = nullptr);
    return pad->stick_y;
}
u8 Input_GetErrNo(OSContPad* pad) {
    assert(pad = nullptr);
    return pad->err_no;
}
f32 Input_GetGyroX(OSContPad* pad) {
    assert(pad = nullptr);
    return pad->gyro_x;
}
f32 Input_GetGyroY(OSContPad* pad) {
    assert(pad = nullptr);
    return pad->gyro_y;
}
s8 Input_GetRightStickX(OSContPad* pad) {
    assert(pad = nullptr);
    return pad->right_stick_x;
}
s8 Input_GetRightRightY(OSContPad* pad) {
    assert(pad = nullptr);
    return pad->right_stick_y;
}

//**************************
// PauseContext
//**************************

u16 Pause_GetState(PauseContext* pause) {
    assert(pause != nullptr);
    return pause->state;
}

//**************************
// EffectSS
//**************************

//**************************
// Save
//**************************

//**************************
// Inventory
//**************************
s8 Inventory_GetAmmo(ItemID type) {
    return AMMO(type);
}
void Inventory_ChangeAmmo(ItemID item, s16 ammoChange) {
    ::Inventory_ChangeAmmo(item, ammoChange);
}

s16 Rupees_Get() {
    return gSaveContext.rupees;
}
void Rupees_ChangeBy(s16 rupeeChange) {
    ::Rupees_ChangeBy(rupeeChange);
}

s8 Magic_Get() {
    return gSaveContext.magic;
}
void Magic_Fill() {
    ::Magic_Fill(nullptr);
}
void Magic_Reset() {
    ::Magic_Reset(nullptr);
}
void Magic_RequestChange(PlayState* play, s16 amount, s16 type) {
    assert(play != nullptr);
    ::Magic_RequestChange(play, amount, type);
}

//**************************
// Sound
//**************************

// TODO
// func_808328EC
// func_80078884
// Audio_PlayActorSound2
// Audio_PlaySoundTransposed

//**************************
// Graph
//**************************

void* Graph_Alloc(GraphicsContext* gfxCtx, size_t size) {
    assert(gfxCtx != nullptr);
    return ::Graph_Alloc(gfxCtx, size);
}
void Graph_OpenDisp(GraphicsContext* gfxCtx) {
    assert(gfxCtx != nullptr);
    //OPEN_DISPS(gfxCtx); TODO
}
void Graph_CloseDisp(GraphicsContext* gfxCtx) {
    assert(gfxCtx != nullptr);
    //CLOSE_DISPS(gfxCtx); TODO
}

Gfx* Graph_GetWorkDisp(GraphicsContext* gfxCtx) {
    assert(gfxCtx != nullptr);
    return gfxCtx->workBuffer;
}
void Graph_SetWorkDisp(GraphicsContext* gfxCtx, Gfx* gfx) {
    assert(gfxCtx != nullptr);
    gfxCtx->workBuffer = gfx;
}

Gfx* Graph_GetOpaDisp(GraphicsContext* gfxCtx) {
    assert(gfxCtx != nullptr);
    return gfxCtx->polyOpaBuffer;
}
void Graph_SetOpaDisp(GraphicsContext* gfxCtx, Gfx* gfx) {
    assert(gfxCtx != nullptr);
    gfxCtx->polyOpaBuffer = gfx;
}

Gfx* Graph_GetXluDisp(GraphicsContext* gfxCtx) {
    assert(gfxCtx != nullptr);
    return gfxCtx->polyXluBuffer;
}
void Graph_SetXluDisp(GraphicsContext* gfxCtx, Gfx* gfx) {
    assert(gfxCtx != nullptr);
    gfxCtx->polyXluBuffer = gfx;
}

Gfx* Graph_GetOverlayDisp(GraphicsContext* gfxCtx) {
    assert(gfxCtx != nullptr);
    return gfxCtx->overlayBuffer;
}
void Graph_SetOverlayDisp(GraphicsContext* gfxCtx, Gfx* gfx) {
    assert(gfxCtx != nullptr);
    gfxCtx->overlayBuffer = gfx;
}

//**************************
// Gfx
//**************************

void Gfx_SetupDL_25Xlu(GraphicsContext* gfxCtx) {
    assert(gfxCtx != nullptr);
    ::Gfx_SetupDL_25Xlu(gfxCtx);
}
void Gfx_SetupDL_27Xlu(GraphicsContext* gfxCtx) {
    assert(gfxCtx != nullptr);
    ::Gfx_SetupDL_27Xlu(gfxCtx);
}

Gfx* Gfx_Segment(Gfx* gfx, u8 segNum, uintptr_t target) {
    assert(gfx != nullptr);
    gSPSegment(gfx++, segNum, target);
    return gfx;
}
Gfx* Gfx_SetPrimColor(Gfx* gfx, u8 m, u8 l, u8 r, u8 g, u8 b, u8 a) {
    assert(gfx != nullptr);
    gDPSetPrimColor(gfx++, m, l, r, g, b, a);
    return gfx;
}
Gfx* Gfx_SetEnvColor(Gfx* gfx, u8 r, u8 g, u8 b, u8 a) {
    assert(gfx != nullptr);
    gDPSetEnvColor(gfx++, r, g, b, a);
    return gfx;
}
Gfx* Gfx_SetRenderMode(Gfx* gfx, u32 c0, u32 c1) {
    assert(gfx != nullptr);
    gDPSetRenderMode(gfx++, c0, c1);
    return gfx;
}
Gfx* Gfx_DisplayList(Gfx* gfx, Gfx* dl) {
    assert(gfx != nullptr);
    gSPDisplayList(gfx++, dl);
    return gfx;
}
Gfx* Gfx_EndDisplayList(Gfx* gfx) {
    assert(gfx != nullptr);
    gSPEndDisplayList(gfx++);
    return gfx;
}
Gfx* Gfx_Matrix(Gfx* gfx, Mtx* m, u8 flags) {
    assert(gfx != nullptr);
    gSPMatrix(gfx++, m, flags);
    return gfx;
}

//**************************
// Matrix
//**************************

Mtx* Matrix_NewMtx(GraphicsContext* gfxCtx) {
    assert(gfxCtx != nullptr);
    return ::Matrix_NewMtx(gfxCtx, nullptr, 0); // TODO some const stuff
}
void Matrix_Translate(f32 x, f32 y, f32 z, u8 mode) {
    ::Matrix_Translate(x, y, z, mode);
}
void Matrix_Scale(f32 x, f32 y, f32 z, u8 mode) {
    ::Matrix_Scale(x, y, z, mode);
}
void Matrix_Mult(MtxF* mf, u8 mode) {
    ::Matrix_Mult(mf, mode);
}
void Matrix_RotateX(f32 x, u8 mode) {
    ::Matrix_RotateX(x, mode);
}
void Matrix_RotateY(f32 y, u8 mode) {
    ::Matrix_RotateY(y, mode);
}
void Matrix_RotateZ(f32 z, u8 mode) {
    ::Matrix_RotateZ(z, mode);
}
void Matrix_MultVec3f(Vec3f* src, Vec3f* dest) {
    ::Matrix_MultVec3f(src, dest);
}
void Matrix_Push() {
    ::Matrix_Push();

}
void Matrix_Pop() {
    ::Matrix_Pop();
}

//**************************
// Math
//**************************

f32 Math_CosS(s16 angle) {
    return ::Math_CosS(angle);
}
f32 Math_SinS(s16 angle) {
    return ::Math_SinS(angle);
}
s16 Math_Atan2S(f32 x, f32 y) {
    return ::Math_Atan2S(x, y);
}
s16 Math_SmoothStepToS(s16* pValue, s16 target, s16 scale, s16 step, s16 minStep) {
    return ::Math_SmoothStepToS(pValue, target, scale, step, minStep);
}
f32 Math_SmoothStepToF(f32* pValue, f32 target, f32 scale, f32 step, f32 minStep) {
    return ::Math_SmoothStepToF(pValue, target, scale, step, minStep);
}

//**************************
// CVars
//**************************

s32 CVar_GetInteger(const char* name, s32 defaultValue) {
    return ::CVarGetInteger(name, defaultValue);
}

void DrawTemp(PlayState* play, Actor* actor) {
    assert(play != nullptr);
    assert(actor != nullptr);
    Gfx_DrawDListOpa(play, (Gfx*)gFieldBushDL);
}

}