#define PY_SSIZE_T_CLEAN // TODO remove after upgrading to python > 3.12?
#include "pybind11/embed.h" // must be first include
#include "pybind11/numpy.h"

#include "PyZelda.h"
#include "global.h"
#include "z64actor.h"

#include "soh/ObjectExtension/ObjectExtension.h"

#include "objects/gameplay_field_keep/gameplay_field_keep.h"

IScriptImplementation* PyZelda::Instance;

struct ActorScriptData {
    pybind11::object data;
};
static ObjectExtension::Register<ActorScriptData> ActorScriptDataRegister;

// returning a pointer is problematic because the pointer can change if the object extensions map is changed
// Need to rethink this
pybind11::object* GetActorScriptData(const Actor* actor) {
    ActorScriptData* scriptData = ObjectExtension::GetInstance().Get<ActorScriptData>(actor);
    return scriptData != nullptr ? &scriptData->data : nullptr; // TODO return nullptr?
}

void SetActorScriptData(const Actor* actor, const pybind11::object& data) {
    ObjectExtension::GetInstance().Set<ActorScriptData>(actor, ActorScriptData{ data });
}

struct ActorScriptDataPythonStruct {};

// TODO needed?
void PyZelda_RegisterMath(pybind11::module_& m);
void PyZelda_RegisterColor(pybind11::module_& m);
void PyZelda_RegisterGbi(pybind11::module_& m);
void PyZelda_RegisterLight(pybind11::module_& m);
void PyZelda_RegisterBgCheck(pybind11::module_& m);
void PyZelda_RegisterCollisionCheck(pybind11::module_& m);
void PyZelda_RegisterAudio(pybind11::module_& m);
void PyZelda_RegisterActor(pybind11::module_& m);
void PyZelda_RegisterCamera(pybind11::module_& m);
void PyZelda_RegisterEffectSs(pybind11::module_& m);
void PyZelda_RegisterAnimation(pybind11::module_& m);
void PyZelda_RegisterPlayer(pybind11::module_& m);
void PyZelda_RegisterMain(pybind11::module_& m);

extern "C" s32 EnPartner_OverrideLimbDraw(PlayState* play, s32 limbIndex, Gfx** dList, Vec3f* pos, Vec3s* rot,
                                         void* thisx, Gfx** gfx);
extern "C" void FrameInterpolation_RecordOpenChild(const void* a, int b);
extern "C" void FrameInterpolation_RecordCloseChild(void);

PYBIND11_EMBEDDED_MODULE(PyZelda, m) {
    try {
        // TODO register these somewhere else
        RegisterPybindArray<u8>(m, "u8_Array");
        RegisterPybindArray<u16>(m, "u16_Array");
        RegisterPybindArray<u32>(m, "u32_Array");
        RegisterPybindArray<u64>(m, "u64_Array");
        RegisterPybindArray<s8>(m, "s8_Array");
        RegisterPybindArray<s16>(m, "s16_Array");
        RegisterPybindArray<s32>(m, "s32_Array");
        RegisterPybindArray<s64>(m, "s64_Array");

        pybind11::class_<MtxS>(m, "MtxS");
        pybind11::class_<MtxF>(m, "MtxF");
        RegisterPybindArray<MtxS>(m, "MtxS_Array");
        RegisterPybindArray<MtxF>(m, "MtxF_Array");

        PyZelda_RegisterMath(m);
        PyZelda_RegisterColor(m);
        PyZelda_RegisterGbi(m);
        PyZelda_RegisterLight(m);
        PyZelda_RegisterBgCheck(m);
        PyZelda_RegisterCollisionCheck(m);
        PyZelda_RegisterAudio(m);
        PyZelda_RegisterActor(m);
        PyZelda_RegisterCamera(m);
        PyZelda_RegisterEffectSs(m);
        PyZelda_RegisterAnimation(m);
        PyZelda_RegisterPlayer(m);
        PyZelda_RegisterMain(m);

        m.def("get_actor_data", [](Actor* actor) -> pybind11::object {
            return *GetActorScriptData(actor);
        });

        m.def("get_player", []() -> Player* {
            return GET_PLAYER(gPlayState);
        }, pybind11::return_value_policy::reference);

        // TODO temp
        m.def("DrawTemp",
              [](PlayState* play, Actor* actor, Color_RGBAf* innerColor, Color_RGBAf* outerColor, SkelAnime* skelAnime) -> void {
            //Gfx_DrawDListOpa(gPlayState, (Gfx*)gFieldBushDL);

            Gfx* dListHead = (Gfx*)Graph_Alloc(play->state.gfxCtx, sizeof(Gfx) * 4);

            //OPEN_DISPS(play->state.gfxCtx);

            {
                FrameInterpolation_RecordOpenChild(__FILE__, __LINE__);
                GraphicsContext* __gfxCtx;
                Gfx* dispRefs[4];
                __gfxCtx = play->state.gfxCtx;
                (void)__gfxCtx;
                Graph_OpenDisps(dispRefs, play->state.gfxCtx, __FILE__, __LINE__);

            Gfx_SetupDL_27Xlu(play->state.gfxCtx);

            s32 envAlpha = (50) & 0x1FF;
            envAlpha = (envAlpha > 255) ? 511 - envAlpha : envAlpha;

            f32 alphaScale = 1.0f;

            gSPSegment(POLY_XLU_DISP++, 0x08, (uintptr_t)dListHead);
            gDPPipeSync(dListHead++);
            gDPSetPrimColor(dListHead++, 0, 0x01, (u8)innerColor->r, (u8)innerColor->g, (u8)innerColor->b,
                            (u8)(innerColor->a * alphaScale));

            gDPSetRenderMode(dListHead++, G_RM_PASS, G_RM_ZB_CLD_SURF2);

            gSPEndDisplayList(dListHead++);
            gDPSetEnvColor(POLY_XLU_DISP++, (u8)outerColor->r, (u8)outerColor->g, (u8)outerColor->b,
                           (u8)(envAlpha * alphaScale));
            POLY_XLU_DISP = SkelAnime_DrawSkeleton2(play, skelAnime, (OverrideLimbDrawOpa)EnPartner_OverrideLimbDraw,
                                                    NULL, actor, POLY_XLU_DISP);

            //CLOSE_DISPS(play->state.gfxCtx);
            FrameInterpolation_RecordCloseChild();
            Graph_CloseDisps(dispRefs, play->state.gfxCtx, __FILE__, __LINE__);
            }
        });

        m.def("CVarGetInteger", [](char* name, s32 defaultValue) -> s32 {
            return CVarGetInteger(name , defaultValue);
        });

        m.def("CVarGetColor24", [](char* name, Color_RGB8 defaultValue) -> Color_RGB8 {
            return CVarGetColor24(name , defaultValue);
        });

        m.def("CHECK_BTN_ALL", [](u64 state, u64 combo) -> bool {
            return CHECK_BTN_ALL(state , combo);
        });

        m.def("CHECK_BTN_ANY", [](u64 state, u64 combo) -> bool {
            return CHECK_BTN_ANY(state , combo);
        });

        // TODO move into internal python file
        pybind11::class_<ActorScriptDataPythonStruct>(m, "ActorScriptDataPythonStruct", pybind11::dynamic_attr())
            .def(pybind11::init<>());
    } catch (pybind11::error_already_set& e) {
        printf("%s", e.what());
        assert(false);
    }
}

CompiledPythonScript::CompiledPythonScript(const std::string& script) {
    // TODO try-catch?
    try {
        pybind11::exec(script, locals, locals);
        printf("%s", locals.str().cast<std::string>().c_str());
    } catch (pybind11::error_already_set& e) {
        printf("%s", e.what()); // TODO
        assert(false);
    }
}

CompiledPythonScript::~CompiledPythonScript() {
}

IScriptImplementation* CompiledPythonScript::GetImplementation() {
    return PyZelda::Instance;
}

bool CompiledPythonScript::FunctionExists(const std::string& name) {
    return locals.contains(name); // TODO test this
}

PyZelda::PyZelda() {
    pybind11::initialize_interpreter();

    pybind11::dict locals = pybind11::dict();

    pybind11::exec(
        "def test(a, b):\n"
        "    return a + b\n"
        , pybind11::globals(), locals);
    bool test = locals.contains("test");
    bool test2 = locals.contains("test2");
    int x = locals["test"](7, 8).cast<int>();
    printf("%u\n", test);
    printf("%u\n", test2);
    printf("%u\n", x);

    pybind11::object sys = pybind11::module_::import("sys");
    pybind11::object path = sys.attr("path");
    printf("%s\n", path.str().cast<std::string>().c_str());

    try {
        auto py_module = pybind11::module::import("numpy");
        auto version = py_module.attr("__version__");
        printf("%s\n", version.str().cast<std::string>().c_str());
    } catch (pybind11::error_already_set& e) {
        printf("%s", e.what());
        printf("TRACE:\n%s", e.trace().str().cast<std::string>().c_str());
        assert(false);
    }
}

PyZelda::~PyZelda() {
    // TODO pybind objects can not outlive interpreter
    ObjectExtension::GetInstance().FreeType<ActorScriptData>();

    pybind11::finalize_interpreter();
}

std::shared_ptr<ICompiledScript> PyZelda::Compile(const std::string& script) {
    return std::make_shared<CompiledPythonScript>(script);
}

void PyZelda::Run(const std::string& script) {
}

void PyZelda::CreateActorInstanceData(Actor* actor, size_t size) {
    try {
        static pybind11::module_ dataStruct = pybind11::module_::import("PyZelda");
        SetActorScriptData(actor, dataStruct.attr("ActorScriptDataPythonStruct")());
    } catch (pybind11::error_already_set& e) {
        printf("%s", e.what());
        assert(false);
    }
}

void PyZelda::DeleteActorInstanceData(Actor* actor) {
    // Instance data will be deleted when object extensions are cleaned up.
    // Nothing to do here.
}