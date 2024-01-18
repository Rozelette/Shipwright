#include "ScriptInterface.h"
#include "global.h"
#include "objects/gameplay_field_keep/gameplay_field_keep.h"

namespace ScriptInterface {

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

void DrawTemp(PlayState* play, Actor* actor) {
    assert(play != nullptr);
    assert(actor != nullptr);
    Gfx_DrawDListOpa(play, (Gfx*)gFieldBushDL);
}

}