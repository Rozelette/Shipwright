#ifndef Z64LIGHT_H
#define Z64LIGHT_H

#include <libultraship/libultra.h>
#include <libultraship/libultra/gbi.h>
#include "z64math.h"

struct GraphicsContext;
struct PlayState;

typedef struct {
    s16 x;
    s16 y;
    s16 z;
    u8 color[3];
    u8 drawGlow;
    s16 radius;
} LightPoint;

typedef struct {
    s8 x;
    s8 y;
    s8 z;
    u8 color[3];
} LightDirectional;

typedef union {
    LightPoint point;
    LightDirectional dir;
} LightParams;

typedef struct {
    u8 type;
    LightParams params;
} LightInfo;

typedef struct Lights {
    u8 numLights;
    Lightsn l;
} Lights;

typedef struct LightNode {
    LightInfo* info;
    struct LightNode* prev;
    struct LightNode* next;
} LightNode;

typedef struct {
    LightNode* listHead;
    u8 ambientColor[3];
    u8 fogColor[3];
    s16 fogNear; // how close until fog starts taking effect. range 0 - 1000
    s16 fogFar; // how far until fog starts to saturate. range 0 - 1000
} LightContext;

typedef enum {
    LIGHT_POINT_NOGLOW,
    LIGHT_DIRECTIONAL,
    LIGHT_POINT_GLOW
} LightType;

#ifdef __cplusplus
extern "C"
{
#endif

void Lights_PointSetInfo(LightInfo* info, s16 x, s16 y, s16 z, u8 r, u8 g, u8 b, s16 radius, s32 type);
void Lights_PointNoGlowSetInfo(LightInfo* info, s16 x, s16 y, s16 z, u8 r, u8 g, u8 b, s16 radius);
void Lights_PointGlowSetInfo(LightInfo* info, s16 x, s16 y, s16 z, u8 r, u8 g, u8 b, s16 radius);
void Lights_PointSetColorAndRadius(LightInfo* info, u8 r, u8 g, u8 b, s16 radius);
void Lights_DirectionalSetInfo(LightInfo* info, s8 x, s8 y, s8 z, u8 r, u8 g, u8 b);
void Lights_Draw(Lights* lights, struct GraphicsContext* gfxCtx);
void Lights_BindAll(Lights* lights, LightNode* listHead, Vec3f* vec);
void LightContext_Init(struct PlayState* play, LightContext* lightCtx);
void LightContext_SetAmbientColor(LightContext* lightCtx, u8 r, u8 g, u8 b);
void LightContext_SetFog(LightContext* lightCtx, u8 r, u8 g, u8 b, s16 fogNear, s16 zFar);
Lights* LightContext_NewLights(LightContext* lightCtx, struct GraphicsContext* gfxCtx);
void LightContext_InitList(struct PlayState* play, LightContext* lightCtx);
void LightContext_DestroyList(struct PlayState* play, LightContext* lightCtx);
LightNode* LightContext_InsertLight(struct PlayState* play, LightContext* lightCtx, LightInfo* info);
void LightContext_RemoveLight(struct PlayState* play, LightContext* lightCtx, LightNode* node);
Lights* Lights_New(struct GraphicsContext* gfxCtx, u8 ambientR, u8 ambientG, u8 ambientB);
void Lights_GlowCheck(struct PlayState* play);
void Lights_DrawGlow(struct PlayState* play);

#ifdef __cplusplus
}
#endif

#endif
