#include "z64light.h"
#include "z64light_mod.h"

#include <stdlib.h>

void Mod_Lights_InitPointNoGlow(LightInfo* info, s16 x, s16 y, s16 z, u8 r, u8 g, u8 b, s16 radius) {
    Lights_PointNoGlowSetInfo(info, x, y, z, r, g, b, radius);
}

void Mod_Lights_InitPointGlow(LightInfo* info, s16 x, s16 y, s16 z, u8 r, u8 g, u8 b, s16 radius) {
    Lights_PointGlowSetInfo(info, x, y, z, r, g, b, radius);
}

void Mod_Lights_InitDirectional(LightInfo* info, s8 x, s8 y, s8 z, u8 r, u8 g, u8 b) {
    Lights_DirectionalSetInfo(info, x, y, z, r, g, b);
}

LightInfo* Mod_Lights_AllocLightInfo(void) {
    return malloc(sizeof(LightInfo));
}

void Mod_Lights_FreeLightInfo(LightInfo* info) {
    free(info);
}

void Mod_Lights_PointSetColorAndRadius(LightInfo* info, u8 r, u8 g, u8 b, s16 radius) {
    Lights_PointSetColorAndRadius(info, r, g, b, radius);
}

void Mod_LightContext_SetAmbientColor(LightContext* lightCtx, u8 r, u8 g, u8 b) {
    LightContext_SetAmbientColor(lightCtx, r, g, b);
}

void Mod_LightContext_SetFog(LightContext* lightCtx, u8 r, u8 g, u8 b, s16 fogNear, s16 fogFar) {
    LightContext_SetFog(lightCtx, r, g, b, fogNear, fogFar);
}

LightNode* Mod_LightContext_InsertLight(LightContext* lightCtx, LightInfo* info) {
    return LightContext_InsertLight(NULL, lightCtx, info);
}

void Mod_LightContext_RemoveLight(LightContext* lightCtx, LightNode* node) {
    LightContext_RemoveLight(NULL, lightCtx, node);
}
