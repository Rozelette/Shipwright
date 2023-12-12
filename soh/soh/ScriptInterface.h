#pragma once
#include "z64.h"

namespace ScriptInterface {

Player* GetPlayer(PlayState* play);

int GetActorX(Actor* actor);
int GetActorY(Actor* actor);
int GetActorZ(Actor* actor);

void SetActorX(Actor* actor, int x);
void SetActorY(Actor* actor, int y);
void SetActorZ(Actor* actor, int z);

void SetActorScaleX(Actor* actor, float x);
void SetActorScaleY(Actor* actor, float y);
void SetActorScaleZ(Actor* actor, float z);

void DrawTemp(PlayState* play, Actor* actor);

}
