#include "ScriptInterface.h"
#include "global.h"
#include "objects/gameplay_field_keep/gameplay_field_keep.h"

namespace ScriptInterface {

Player* GetPlayer(PlayState* play) {
    return GET_PLAYER(play);
}

int GetActorX(Actor* actor) {
    return actor->world.pos.x;
}
int GetActorY(Actor* actor) {
    return actor->world.pos.y;
}
int GetActorZ(Actor* actor) {
    return actor->world.pos.z;
}

void SetActorX(Actor* actor, int x) {
    actor->world.pos.x = x;
}
void SetActorY(Actor* actor, int y) {
    actor->world.pos.y = y;
}
void SetActorZ(Actor* actor, int z) {
    actor->world.pos.z = z;
}

void SetActorScaleX(Actor* actor, float x) {
    actor->scale.x = x;
}
void SetActorScaleY(Actor* actor, float y) {
    actor->scale.y = y;
}
void SetActorScaleZ(Actor* actor, float z) {
    actor->scale.z = z;
}

void DrawTemp(PlayState* play, Actor* actor) {
    Gfx_DrawDListOpa(play, (Gfx*)gFieldBushDL);
}

}