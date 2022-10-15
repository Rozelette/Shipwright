/*
 * File: z_eff_ss_ice_smoke.c
 * Overlay: ovl_Effect_Ss_Ice_Smoke
 * Description: Ice Smoke
 */

#include "z_eff_ss_ice_smoke.h"
#include "objects/object_fz/object_fz.h"

#define rAlpha regs[1]
#define rScale regs[2]

u32 EffectSsIceSmoke_Init(GlobalContext* globalCtx, u32 index, EffectSs* this, void* initParamsx);
void EffectSsIceSmoke_Draw(GlobalContext* globalCtx, u32 index, EffectSs* this);
void EffectSsIceSmoke_Update(GlobalContext* globalCtx, u32 index, EffectSs* this);

EffectSsInit Effect_Ss_Ice_Smoke_InitVars = {
    EFFECT_SS_ICE_SMOKE,
    EffectSsIceSmoke_Init,
};

u32 EffectSsIceSmoke_Init(GlobalContext* globalCtx, u32 index, EffectSs* this, void* initParamsx) {
    EffectSsIceSmokeInitParams* initParams = (EffectSsIceSmokeInitParams*)initParamsx;

    Math_Vec3f_Copy(&this->pos, &initParams->pos);
    Math_Vec3f_Copy(&this->velocity, &initParams->velocity);
    Math_Vec3f_Copy(&this->accel, &initParams->accel);
    this->rAlpha = 0;
    this->rScale = initParams->scale;
    this->life = 50;
    this->draw = EffectSsIceSmoke_Draw;
    this->update = EffectSsIceSmoke_Update;

    return 1;
}

void EffectSsIceSmoke_Draw(GlobalContext* globalCtx, u32 index, EffectSs* this) {
    s32 pad;
    Mtx* mtx;
    f32 scale;
    s32 objBankIdx;

    OPEN_DISPS(globalCtx->state.gfxCtx);

    gDPPipeSync(POLY_XLU_DISP++);
    func_80093D84(globalCtx->state.gfxCtx);
    gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(gFreezardSteamStartDL));
    gDPPipeSync(POLY_XLU_DISP++);
    gDPSetPrimColor(POLY_XLU_DISP++, 0, 0, 195, 235, 235, this->rAlpha);
    gSPSegment(
        POLY_XLU_DISP++, 0x08,
        Gfx_TwoTexScroll(globalCtx->state.gfxCtx, 0, this->life * 3, this->life * 15, 32, 64, 1, 0, 0, 32, 32));
    Matrix_Translate(this->pos.x, this->pos.y, this->pos.z, MTXMODE_NEW);
    Matrix_ReplaceRotation(&globalCtx->billboardMtxF);
    scale = this->rScale * 0.0001f;
    Matrix_Scale(scale, scale, 1.0f, MTXMODE_APPLY);

    mtx = MATRIX_NEWMTX(globalCtx->state.gfxCtx);

    if (mtx != NULL) {
        gSPMatrix(POLY_XLU_DISP++, mtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(POLY_XLU_DISP++, SEGMENTED_TO_VIRTUAL(gFreezardSteamDL));
    }

    CLOSE_DISPS(globalCtx->state.gfxCtx);
}

void EffectSsIceSmoke_Update(GlobalContext* globalCtx, u32 index, EffectSs* this) {
    if (this->rAlpha < 100) {
        this->rAlpha += 10;
    }
}
