#pragma once
#include "z64.h"
#include "PyZelda.h"

namespace ScriptInterface {

//**************************
// Actor
//**************************

s16 GetActorID(Actor* actor);

u8 GetActorCategory(Actor* actor);
void SetActorCategory(Actor* actor, u8 category);

s8 GetActorRoom(Actor* actor);
void SetActorRoom(Actor* actor, s8 room);

u32 GetActorFlags(Actor* actor);
void SetActorFlags(Actor* actor, u32 flags); // TODO AND/OR convenience?

// TODO home

s16 GetActorParams(Actor* actor);
void SetActorParams(Actor* actor, s16 params); // TODO AND/OR convenience?

s8 GetActorObjBankIndex(Actor* actor);
void SetActorObjBankIndex(Actor* actor, s8 objBankIndex);

s8 GetActorTargetMode(Actor* actor);
void SetActorTargetMode(Actor* actor, s8 targetMode);

u16 GetActorSfx(Actor* actor);
void SetActorSfx(Actor* actor, u16 sfx);

f32 GetActorPosX(Actor* actor);
f32 GetActorPosY(Actor* actor);
f32 GetActorPosZ(Actor* actor);
void GetActorPos(Actor* actor, f32* x, f32* y, f32* z);

void SetActorPosX(Actor* actor, f32 x);
void SetActorPosY(Actor* actor, f32 y);
void SetActorPosZ(Actor* actor, f32 z);
void SetActorPos(Actor* actor, f32 x, f32 y, f32 z);

s16 GetActorRotX(Actor* actor);
s16 GetActorRotY(Actor* actor);
s16 GetActorRotZ(Actor* actor);
void GetActorRot(Actor* actor, s16* x, s16* y, s16* z);

void SetActorRotX(Actor* actor, s16 x);
void SetActorRotY(Actor* actor, s16 y);
void SetActorRotZ(Actor* actor, s16 z);
void SetActorRot(Actor* actor, s16 x, s16 y, s16 z);

void GetActorPosRot(Actor* actor, f32* posX, f32* posY, f32* posZ, s16* rotX, s16* rotY, s16* rotZ);
void SetActorPosRot(Actor* actor, f32 posX, f32 posY, f32 posZ, s16 rotX, s16 rotY, s16 rotZ);

f32 GetActorFocusPosX(Actor* actor);
f32 GetActorFocusPosY(Actor* actor);
f32 GetActorFocusPosZ(Actor* actor);
void GetActorFocusPos(Actor* actor, f32* x, f32* y, f32* z);

void SetActorFocusPosX(Actor* actor, f32 x);
void SetActorFocusPosY(Actor* actor, f32 y);
void SetActorFocusPosZ(Actor* actor, f32 z);
void SetActorFocusPos(Actor* actor, f32 x, f32 y, f32 z);

s16 GetActorFocusRotX(Actor* actor);
s16 GetActorFocusRotY(Actor* actor);
s16 GetActorFocusRotZ(Actor* actor);
void GetActorFocusRot(Actor* actor, s16* x, s16* y, s16* z);

void SetActorFocusRotX(Actor* actor, s16 x);
void SetActorFocusRotY(Actor* actor, s16 y);
void SetActorFocusRotZ(Actor* actor, s16 z);
void SetActorFocusRot(Actor* actor, s16 x, s16 y, s16 z);

void GetActorFocusPosRot(Actor* actor, f32* posX, f32* posY, f32* posZ, s16* rotX, s16* rotY, s16* rotZ);
void SetActorFocusPosRot(Actor* actor, f32 posX, f32 posY, f32 posZ, s16 rotX, s16 rotY, s16 rotZ);

f32 GetActorTargetArrowOffset(Actor* actor);
void SetActorTargetArrowOffset(Actor* actor, f32 targetArrowOffset);

f32 GetActorScaleX(Actor* actor);
f32 GetActorScaleY(Actor* actor);
f32 GetActorScaleZ(Actor* actor);
void GetActorScale(Actor* actor, f32* x, f32* y, f32* z);

void SetActorScaleX(Actor* actor, f32 x);
void SetActorScaleY(Actor* actor, f32 y);
void SetActorScaleZ(Actor* actor, f32 z);
void SetActorScale(Actor* actor, f32 x, f32 y, f32 z);
//TODO SetScale(f32 scale) for all 3 dims

// TODO what should the getters/setter for velocity and speedXZ be?
f32 GetActorVelocityX(Actor* actor);
f32 GetActorVelocityY(Actor* actor);
f32 GetActorVelocityZ(Actor* actor);
void GetActorVelocity(Actor* actor, f32* x, f32* y, f32* z);

void SetActorVelocityX(Actor* actor, f32 x);
void SetActorVelocityY(Actor* actor, f32 y);
void SetActorVelocityZ(Actor* actor, f32 z);
void SetActorVelocity(Actor* actor, f32 x, f32 y, f32 z);

f32 GetActorSpeedXZ(Actor* actor);

f32 GetActorGravity(Actor* actor);
void SetActorGravity(Actor* actor, f32 gravity);

f32 GetActorMinVelocityY(Actor* actor);
void SetActorMinVelocityY(Actor* actor, f32 minVelocityY);

// TODO the rest of the owl

// CollisionCheckInfo
// TODO damageTable
// TODO colChkInfo pointer?

void CollisionCheck_SetInfo(Actor* actor, DamageTable* damageTable, CollisionCheckInfoInit* init);
void CollisionCheck_SetInfoRaw(Actor* actor, DamageTable* damageTable, u8 health, s16 cylRadius, s16 cylHeight, u8 mass);

f32 GetActorCollisionDisplacementX(Actor* actor);
f32 GetActorCollisionDisplacementY(Actor* actor);
f32 GetActorCollisionDisplacementZ(Actor* actor);
void GetActorCollisionDisplacement(Actor* actor, f32* x, f32* y, f32* z);

void SetActorCollisionDisplacementX(Actor* actor, f32 x);
void SetActorCollisionDisplacementY(Actor* actor, f32 y);
void SetActorCollisionDisplacementZ(Actor* actor, f32 z);
void SetActorCollisionDisplacement(Actor* actor, f32 x, f32 y, f32 z);

s16 GetActorCollisionCylRadius(Actor* actor);
void SetActorCollisionCylRadius(Actor* actor, s16 cylRadius);

s16 GetActorCollisionCylHeight(Actor* actor);
void SetActorCollisionCylHeight(Actor* actor, s16 cylHeight);

s16 GetActorCollisionCylYShift(Actor* actor);
void SetActorCollisionCylYShift(Actor* actor, s16 cylYShift);

u8 GetActorCollisionMass(Actor* actor);
void SetActorCollisionMass(Actor* actor, u8 mass);

u8 GetActorCollisionHealth(Actor* actor);
void SetActorCollisionHealth(Actor* actor, u8 health);

u8 GetActorCollisionDamage(Actor* actor);
void SetActorCollisionDamage(Actor* actor, u8 damage);

u8 GetActorCollisionDamageEffect(Actor* actor);
void SetActorCollisionDamageEffect(Actor* actor, u8 damageEffect);

u8 GetActorCollisionAtHitEffect(Actor* actor);
void SetActorCollisionAtHitEffect(Actor* actor, u8 atHitEffect);

u8 GetActorCollisionAcHitEffect(Actor* actor);
void SetActorCollisionAcHitEffect(Actor* actor, u8 acHitEffect);

// ActorShape
// TODO actor pointer?
ActorShape* GetActorShape(Actor* actor);

// TODO more built-ins, function name case?
void ActorShape_Init(ActorShape* shape, f32 yOffset, ActorShadowFunc shadowDraw, f32 shadowScale);
void ActorShape_InitCircle(ActorShape* shape, f32 yOffset, f32 shadowScale);

//TODO more variables (face, rot, feetPos)?

f32 ActorShape_GetYOffset(ActorShape* shape);
void ActorShape_SetYOffset(ActorShape* shape, f32 yOffset);

f32 ActorShape_GetShadowScale(ActorShape* shape);
void ActorShape_SetShadowScale(ActorShape* shape, f32 shadowScale);

u8 ActorShape_GetShadowAlpha(ActorShape* shape);
void ActorShape_SetShadowAlpha(ActorShape* shape, u8 shadowAlpha);

u8 ActorShape_GetFeetFloorFlags(ActorShape* shape);
void ActorShape_SetFeetFloorFlags(ActorShape* shape, u8 feetFloorFlags);

template <typename T> T* GetInstanceData(ScriptActor* actor) {
    return (T*)actor->instanceData;
}

// TODO Actor_ProcessInitChain?

// Util
// TODO ActorID enum
// TODO infer ActorContext from play?
Actor* Actor_Spawn(ActorContext* actorCtx, PlayState* play, s16 actorId, f32 posX, f32 posY, f32 posZ,
    s16 rotX, s16 rotY, s16 rotZ, s16 params, s16 canRandomize);
Actor* Actor_SpawnAsChild(ActorContext* actorCtx, Actor* parent, PlayState* play, s16 actorId, f32 posX,
    f32 posY, f32 posZ, s16 rotX, s16 rotY, s16 rotZ, s16 params);

void Actor_Kill(Actor* actor);

s32 Actor_GetActorCount(ActorContext* actorCtx, ActorCategory category);
Actor* Actor_GetActorHead(ActorContext* actorCtx, ActorCategory category);

void Actor_MoveForward(Actor* actor);

void Actor_UpdateBgCheckInfo(PlayState* play, Actor* actor, f32 wallCheckHeight, f32 wallCheckRadius, f32 ceilingCheckHeight, s32 flags);

f32 Actor_WorldDistXYZToActor(Actor* actorA, Actor* actorB);

//**************************
// Player
//**************************

Player* GetPlayer(PlayState* play);

u8 GetPlayerIvanFloating(Player* player);
void SetPlayerIvanFloating(Player* player, u8 ivanFloating);

u8 GetPlayerIvanDamageMultiplier(Player* player);
void SetPlayerIvanDamageMultiplier(Player* player, u8 ivanDamageMultiplier);

f32 Player_GetHeight(Player* player);

s32 Player_InCsMode(PlayState* play);

// TODO unk_A73

//**************************
// Collider
//**************************

// Base
void Collider_SetBase(Collider* collider, Actor* actor, ColliderInit* init);
void Collider_SetBaseRaw(Collider* collider, Actor* actor, u8 colType, u8 atFlags, u8 acFlags, u8 ocFlags1, u8 ocFlags2, u8 shape);

Actor* Collider_GetActor(Collider* collider);
void Collider_SetActor(Collider* collider, Actor* actor);

Actor* Collider_GetAt(Collider* collider);
void Collider_SetAt(Collider* collider, Actor* at); // TODO Include?

Actor* Collider_GetAc(Collider* collider);
void Collider_SetAc(Collider* collider, Actor* ac); // TODO Include?

Actor* Collider_GetOc(Collider* collider);
void Collider_SetOc(Collider* collider, Actor* oc); // TODO Include?

u8 Collider_GetAtFlags(Collider* collider);
void Collider_SetAtFlags(Collider* collider, u8 atFlags); // TODO AND/OR convenience?

u8 Collider_GetAcFlags(Collider* collider);
void Collider_SetAcFlags(Collider* collider, u8 acFlags); // TODO AND/OR convenience?

u8 Collider_GetOcFlags1(Collider* collider);
void Collider_SetOcFlags1(Collider* collider, u8 ocFlags1); // TODO AND/OR convenience?

u8 Collider_GetOcFlags2(Collider* collider);
void Collider_SetOcFlags2(Collider* collider, u8 ocFlags2); // TODO AND/OR convenience?

u8 Collider_GetColType(Collider* collider);
void Collider_SetColType(Collider* collider, u8 colType);

u8 Collider_GetShape(Collider* collider);
void Collider_SetShape(Collider* collider, u8 shape); // TODO include?

// Info
void Collider_SetInfo(ColliderInfo* info, ColliderInfoInit* infoInit);
void Collider_SetInfoRaw(ColliderInfo* info, u8 elemType, u32 toucherDmgFlags, u8 toucherEffect, u8 toucherDamage, u32 bumperDmgFlags, u8 bumperEffect, u8 bumperDamage, u8 toucherFlags, u8 bumperFlags, u8 ocElemFlags);

u32 Collider_TouchGetDmgFlags(ColliderInfo* info);
void Collider_TouchSetDmgFlags(ColliderInfo* info, u32 dmgFlags);

u8 Collider_TouchGetEffect(ColliderInfo* info);
void Collider_TouchSetEffect(ColliderInfo* info, u8 effect);

u8 Collider_TouchGetDamage(ColliderInfo* info);
void Collider_TouchSetDamage(ColliderInfo* info, u8 damage);

u32 Collider_BumpGetDmgFlags(ColliderInfo* info);
void Collider_BumpSetDmgFlags(ColliderInfo* info, u32 dmgFlags);

u8 Collider_BumpGetEffect(ColliderInfo* info);
void Collider_BumpSetEffect(ColliderInfo* info, u8 effect);

u8 Collider_BumpGetDefense(ColliderInfo* info);
void Collider_BumpSetDefense(ColliderInfo* info, u8 defense);

s16 Collider_BumpGetHitX(ColliderInfo* info);
s16 Collider_BumpGetHitY(ColliderInfo* info);
s16 Collider_BumpGetHitZ(ColliderInfo* info);
void Collider_BumpGetHit(ColliderInfo* info, s16* x, s16* y, s16* z);

void Collider_BumpSetHitX(ColliderInfo* info, s16 x);
void Collider_BumpSetHitY(ColliderInfo* info, s16 y);
void Collider_BumpSetHitZ(ColliderInfo* info, s16 z);
void Collider_BumpSetHit(ColliderInfo* info, s16 x, s16 y, s16 z);

u8 Collider_InfoGetElemType(ColliderInfo* info);
void Collider_InfoSetElemType(ColliderInfo* info, u8 elemType);

u8 Collider_InfoGetToucherFlags(ColliderInfo* info);
void Collider_InfoSetToucherFlags(ColliderInfo* info, u8 toucherFlags);

u8 Collider_InfoGetBumperFlags(ColliderInfo* info);
void Collider_InfoSetBumperFlags(ColliderInfo* info, u8 bumperFlags);

u8 Collider_InfoGetOcElemFlags(ColliderInfo* info);
void Collider_InfoSetOcElemFlags(ColliderInfo* info, u8 ocElemFlags);

Collider* Collider_InfoGetAtHit(ColliderInfo* info);
void Collider_InfoSetAtHit(ColliderInfo* info, Collider* atHit); // TODO include?

Collider* Collider_InfoGetAcHit(ColliderInfo* info);
void Collider_InfoSetAcHit(ColliderInfo* info, Collider* acHit); // TODO include?

ColliderInfo* Collider_InfoGetAtHitInfo(ColliderInfo* info);
void Collider_InfoSetAtHitInfo(ColliderInfo* info, ColliderInfo* atHitInfo); // TODO include?

ColliderInfo* Collider_InfoGetAcHitInfo(ColliderInfo* info);
void Collider_InfoSetAcHitInfo(ColliderInfo* info, ColliderInfo* acHitInfo); // TODO include?

// Cylinder
ColliderCylinder* Collider_AllocCylinder();
void Collider_DeallocCylinder(ColliderCylinder* cylinder);

void Collider_InitCylinder(ColliderCylinder* cylinder); // TODO pass in play?
void Collider_DestroyCylinder(ColliderCylinder* cylinder); // TODO pass in play?

Collider* Collider_CylinderGetBase(ColliderCylinder* cylinder);

ColliderInfo* Collider_CylinderGetInfo(ColliderCylinder* cylinder);

s16 Collider_CylinderGetRadius(ColliderCylinder* cylinder);
void Collider_CylinderSetRadius(ColliderCylinder* cylinder, s16 radius);

s16 Collider_CylinderGetHeight(ColliderCylinder* cylinder);
void Collider_CylinderSetHeight(ColliderCylinder* cylinder, s16 height);

s16 Collider_CylinderGetYShift(ColliderCylinder* cylinder);
void Collider_CylinderSetYShift(ColliderCylinder* cylinder, s16 yShift);

s16 Collider_CylinderGetX(ColliderCylinder* cylinder);
s16 Collider_CylinderGetY(ColliderCylinder* cylinder);
s16 Collider_CylinderGetZ(ColliderCylinder* cylinder);
void Collider_CylinderGetPos(ColliderCylinder* cylinder, s16* x, s16* y, s16* z);

void Collider_CylinderSetX(ColliderCylinder* cylinder, s16 x);
void Collider_CylinderSetY(ColliderCylinder* cylinder, s16 y);
void Collider_CylinderSetZ(ColliderCylinder* cylinder, s16 z);
void Collider_CylinderSetPos(ColliderCylinder* cylinder, s16 x, s16 y, s16 z);

void Collider_SetCylinder(ColliderCylinder* cylinder, Actor* actor, ColliderCylinderInit* init);
void Collider_SetCylinderRaw(Cylinder16* cylinder, s16 radius, s16 height, s16 yShift, s16 x, s16 y, s16 z);

void Collider_UpdateCylinder(ColliderCylinder* cylinder, Actor* actor); // TODO switch parameters to match OG?

//TODO more shapes

//**************************
// SkelAnime
//**************************

SkelAnime* SkelAnime_Alloc();
void SkelAnime_Dealloc(SkelAnime* skelAnime);

// TODO
//s32 SkelAnime_Init(PlayState* play, SkelAnime* skelAnime, SkeletonHeader* skeletonHeaderSeg, AnimationHeader* animation, Vec3s* jointTable, Vec3s* morphTable, s32 limbCount);
s32 SkelAnime_Init(PlayState* play, SkelAnime* skelAnime, char* skeletonHeaderSeg, char* animation, s32 limbCount);

s32 SkelAnime_Update(SkelAnime* skelAnime);

Gfx* SkelAnime_Draw(PlayState* play, void** skeleton, Vec3s* jointTable, OverrideLimbDraw overrideLimbDraw, PostLimbDraw postLimbDraw, void* arg, Gfx* gfx);
Gfx* SkelAnime_DrawWithNames(PlayState* play, void** skeleton, Vec3s* jointTable, void* arg, Gfx* gfx); // TODO arg must be actor?

void SkelAnime_Free(SkelAnime* skelAnime, PlayState* play);

void ResourceMgr_UnregisterSkeleton(SkelAnime* skelAnime);

//**************************
// Lights
//**************************

LightInfo* Lights_AllocInfo();
void Lights_DeallocInfo(LightInfo* info);

// TODO getters and setters for each attribute

void Lights_PointSetInfo(LightInfo* info, s16 x, s16 y, s16 z, u8 r, u8 g, u8 b, s16 radius, s32 type);
void Lights_PointGlowSetInfo(LightInfo* info, s16 x, s16 y, s16 z, u8 r, u8 g, u8 b, s16 radius);
void Lights_PointNoGlowSetInfo(LightInfo* info, s16 x, s16 y, s16 z, u8 r, u8 g, u8 b, s16 radius);
void Lights_PointSetColorAndRadius(LightInfo* info, u8 r, u8 g, u8 b, s16 radius);
void Lights_DirectionalSetInfo(LightInfo* info, s8 x, s8 y, s8 z, u8 r, u8 g, u8 b);

LightNode* LightContext_InsertLight(LightContext* lightCtx, LightInfo* info);
void LightContext_RemoveLight(LightContext* lightCtx, LightNode* node);

//**************************
// PlayState
//**************************

// TODO
// TODO GameState?
Input* Play_GetInput(PlayState* play, s32 index);
u32 Play_GetFrames(PlayState* play);
Camera* Play_GetActiveCamera(PlayState* play);
GraphicsContext* Play_GetGraphicsContext(PlayState* play);
LightContext* Play_GetLightContext(PlayState* play);
ActorContext* Play_GetActorContext(PlayState* play);
PauseContext* Play_GetPauseContext(PlayState* play);
MtxF* Play_GetBillboardMtxF(PlayState* play);

//**************************
// Camera
//**************************

// TODO
s16 Camera_GetCamDirPitch(Camera* camera);
s16 Camera_GetCamDirYaw(Camera* camera);

//**************************
// Input
//**************************

// TODO
OSContPad* Input_GetCur(Input* in);
OSContPad* Input_GetPrev(Input* in);
OSContPad* Input_GetPress(Input* in);
OSContPad* Input_GetRel(Input* in);

u16 Input_GetButton(OSContPad* pad);
s8 Input_GetStickX(OSContPad* pad);
s8 Input_GetStickY(OSContPad* pad);
u8 Input_GetErrNo(OSContPad* pad);
f32 Input_GetGyroX(OSContPad* pad);
f32 Input_GetGyroY(OSContPad* pad);
s8 Input_GetRightStickX(OSContPad* pad);
s8 Input_GetRightRightY(OSContPad* pad);

//**************************
// PauseContext
//**************************

// TODO
u16 Pause_GetState(PauseContext* pause);

//**************************
// EffectSS
//**************************

// TODO

//**************************
// Save
//**************************

// TODO

//**************************
// Inventory
//**************************

// TODO
// TODO itemID enum
// TODO should itemID be an enum if mods are going to add more?
s8 Inventory_GetAmmo(ItemID type);
void Inventory_ChangeAmmo(ItemID item, s16 ammoChange);

s16 Rupees_Get();
void Rupees_ChangeBy(s16 rupeeChange);

s8 Magic_Get();
void Magic_Fill();
void Magic_Reset();
void Magic_RequestChange(PlayState* play, s16 amount, s16 type);

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

// TODO

void* Graph_Alloc(GraphicsContext* gfxCtx, size_t size); // TODO no need to free, right?
void Graph_OpenDisp(GraphicsContext* gfxCtx);
void Graph_CloseDisp(GraphicsContext* gfxCtx);

Gfx* Graph_GetWorkDisp(GraphicsContext* gfxCtx);
void Graph_SetWorkDisp(GraphicsContext* gfxCtx, Gfx* gfx);

Gfx* Graph_GetOpaDisp(GraphicsContext* gfxCtx);
void Graph_SetOpaDisp(GraphicsContext* gfxCtx, Gfx* gfx);

Gfx* Graph_GetXluDisp(GraphicsContext* gfxCtx);
void Graph_SetXluDisp(GraphicsContext* gfxCtx, Gfx* gfx);

Gfx* Graph_GetOverlayDisp(GraphicsContext* gfxCtx);
void Graph_SetOverlayDisp(GraphicsContext* gfxCtx, Gfx* gfx);

// TODO SoH specific lists?

//**************************
// Gfx
//**************************

// TODO
void Gfx_SetupDL_25Xlu(GraphicsContext* gfxCtx);
void Gfx_SetupDL_27Xlu(GraphicsContext* gfxCtx);

// TODO a function for every macro (not syncs tho lol)
Gfx* Gfx_Segment(Gfx* gfx, u8 segNum, uintptr_t target);
Gfx* Gfx_SetPrimColor(Gfx* gfx, u8 m, u8 l, u8 r, u8 g, u8 b, u8 a);
Gfx* Gfx_SetEnvColor(Gfx* gfx, u8 r, u8 g, u8 b, u8 a);
Gfx* Gfx_SetRenderMode(Gfx* gfx, u32 c0, u32 c1);
Gfx* Gfx_DisplayList(Gfx* gfx, Gfx* dl);
Gfx* Gfx_EndDisplayList(Gfx* gfx);
Gfx* Gfx_Matrix(Gfx* gfx, Mtx* m, u8 flags);

//**************************
// Matrix
//**************************

// TODO
// TODO maybe handle these in native libraries?
Mtx* Matrix_NewMtx(GraphicsContext* gfxCtx);
void Matrix_Translate(f32 x, f32 y, f32 z, u8 mode);
void Matrix_Scale(f32 x, f32 y, f32 z, u8 mode);
void Matrix_Mult(MtxF* mf, u8 mode);
void Matrix_RotateX(f32 x, u8 mode);
void Matrix_RotateY(f32 y, u8 mode);
void Matrix_RotateZ(f32 z, u8 mode);
void Matrix_MultVec3f(Vec3f* src, Vec3f* dest);
void Matrix_Push();
void Matrix_Pop();

//**************************
// Math
//**************************

// TODO
// TODO maybe handle these in native libraries?
f32 Math_CosS(s16 angle);
f32 Math_SinS(s16 angle);
s16 Math_Atan2S(f32 x, f32 y);
s16 Math_SmoothStepToS(s16* pValue, s16 target, s16 scale, s16 step, s16 minStep);
f32 Math_SmoothStepToF(f32* pValue, f32 target, f32 scale, f32 step, f32 minStep);

//**************************
// CVars
//**************************

// TODO
s32 CVar_GetInteger(const char* name, s32 defaultValue); // TODO test char*

//**************************
// Temp
//**************************

void DrawTemp(PlayState* play, Actor* actor);

}
