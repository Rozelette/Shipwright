#pragma once

#include "z64light.h"

// Q: Should these have a signature like `void Mod_Lights_InitPointNoGlow(LightInfo* info, Vec3s pos, ColorRGB8 col, s16 radius)` ?
// I'm not sure how non-trivial types affect script bindings, and how performant the different bindings would be
void Mod_Lights_InitPointNoGlow(LightInfo* info, s16 x, s16 y, s16 z, u8 r, u8 g, u8 b, s16 radius);
void Mod_Lights_InitPointGlow(LightInfo* info, s16 x, s16 y, s16 z, u8 r, u8 g, u8 b, s16 radius);
void Mod_Lights_InitDirectional(LightInfo* info, s8 x, s8 y, s8 z, u8 r, u8 g, u8 b);

// Q: Should we have alloc/free for structs later intended to be passed in as pointers?
// I don't know how feasible it would be to pass in memory allocated in the memory space of a script
LightInfo* Mod_Lights_AllocLightInfo(void);
void Mod_Lights_FreeLightInfo(LightInfo* info);

// Q: This is a convenience function for setting several variables at once. Do we want things like this in the API? Should they
// be implemented by wrapping an engine function or in the wrapping layer to avoid the extra function call? Should we expect
// bindings reimplement them in their native language to be more performant?
void Mod_Lights_PointSetColorAndRadius(LightInfo* info, u8 r, u8 g, u8 b, s16 radius);

void Mod_LightContext_SetAmbientColor(LightContext* lightCtx, u8 r, u8 g, u8 b);
void Mod_LightContext_SetFog(LightContext* lightCtx, u8 r, u8 g, u8 b, s16 fogNear, s16 fogFar);

// Q: Should these functions also take in a PlayState*?
// The functions they hook into don't actually use it, so we can simplify the API by removing it in the wrapper, but
// that means if we modify those functions later, we would need to change the API. Options:
// 1. We include a PlayState* in the mod API
// 2. We exclude them and document the possible NULL-ness in the engine function
// 3. We exclude them and pass in gPlayState
// 4. We exclude them and modify the engine function to simplify that too
LightNode* Mod_LightContext_InsertLight(LightContext* lightCtx, LightInfo* info);
void Mod_LightContext_RemoveLight(LightContext* lightCtx, LightNode* node);
