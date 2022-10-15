#ifndef Z_DEMO_EC_H
#define Z_DEMO_EC_H

#include "ultra64.h"
#include "global.h"

struct DemoEc;

typedef void (*DemoEcInitFunc)(struct DemoEc*, GlobalContext*);
typedef void (*DemoEcUpdateFunc)(struct DemoEc*, GlobalContext*);
typedef void (*DemoEcDrawFunc)(struct DemoEc*, GlobalContext*);

typedef struct DemoEc {
    /* 0x0000 */ Actor actor;
    /* 0x014C */ SkelAnime skelAnime;
    /* 0x0190 */ s16 eyeTexIndex;
    /* 0x0192 */ s16 blinkTimer;
    /* 0x0194 */ s32 updateMode;
    /* 0x0198 */ s32 drawConfig;
    /* 0x019C */ s32 npcAction;
} DemoEc; // size = 0x01A8

#endif
