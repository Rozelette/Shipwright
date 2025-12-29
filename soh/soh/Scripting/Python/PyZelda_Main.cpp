#include "../PyZelda.h"
#include "pybind11/native_enum.h"

#include "z64.h"

namespace {
enum BtnEnum {
    CRIGHT = BTN_CRIGHT,
    CLEFT = BTN_CLEFT,
    CDOWN = BTN_CDOWN,
    CUP = BTN_CUP,
    R = BTN_R,
    L = BTN_L,
    DRIGHT = BTN_DRIGHT,
    DLEFT = BTN_DLEFT,
    DDOWN = BTN_DDOWN,
    DUP = BTN_DUP,
    START = BTN_START,
    Z = BTN_Z,
    B = BTN_B,
    A = BTN_A,
    STICKLEFT = BTN_STICKLEFT,
    STICKRIGHT = BTN_STICKRIGHT,
    STICKDOWN = BTN_STICKDOWN,
    STICKUP = BTN_STICKUP,
    VSTICKUP = BTN_VSTICKUP,
    VSTICKDOWN = BTN_VSTICKDOWN,
    VSTICKLEFT = BTN_VSTICKLEFT,
    VSTICKRIGHT = BTN_VSTICKRIGHT,
};
} // namespace

void PyZelda_RegisterMain(pybind11::module_& m) {
    pybind11::module_ main = m.def_submodule("Main");

    pybind11::class_<OSMesg>(main, "OSMesg");           // TODO move out
    pybind11::class_<OSMesgQueue>(main, "OSMesgQueue"); // TODO move out
    pybind11::class_<OSViMode>(main, "OSViMode");       // TODO move out
    pybind11::class_<OSTask>(main, "OSTask");           // TODO move out
    pybind11::class_<OSContPad>(main, "OSContPad")
        .def_readwrite("button", &OSContPad::button)
        .def_readwrite("stick_x", &OSContPad::stick_x)
        .def_readwrite("stick_y", &OSContPad::stick_y)
        .def_readwrite("err_no", &OSContPad::err_no)
        .def_readwrite("gyro_x", &OSContPad::gyro_x)
        .def_readwrite("gyro_y", &OSContPad::gyro_y)
        .def_readwrite("right_stick_x", &OSContPad::right_stick_x)
        .def_readwrite("right_stick_y", &OSContPad::right_stick_y)
        ; // TODO move out

    RegisterPybindArray<OSMesg>(m, "OSMesg_Array");

    // TODO move out
    pybind11::native_enum<BtnEnum>(main, "BTN", "enum.IntFlag")
        .value("CRIGHT", BtnEnum::CRIGHT)
        .value("CLEFT", BtnEnum::CLEFT)
        .value("CDOWN", BtnEnum::CDOWN)
        .value("CUP", BtnEnum::CUP)
        .value("R", BtnEnum::R)
        .value("L", BtnEnum::L)
        .value("DRIGHT", BtnEnum::DRIGHT)
        .value("DLEFT", BtnEnum::DLEFT)
        .value("DDOWN", BtnEnum::DDOWN)
        .value("DUP", BtnEnum::DUP)
        .value("START", BtnEnum::START)
        .value("Z", BtnEnum::Z)
        .value("B", BtnEnum::B)
        .value("A", BtnEnum::A)
        .value("STICKLEFT", BtnEnum::STICKLEFT)
        .value("STICKRIGHT", BtnEnum::STICKRIGHT)
        .value("STICKDOWN", BtnEnum::STICKDOWN)
        .value("STICKUP", BtnEnum::STICKUP)
        .value("VSTICKUP", BtnEnum::VSTICKUP)
        .value("VSTICKDOWN", BtnEnum::VSTICKDOWN)
        .value("VSTICKLEFT", BtnEnum::VSTICKLEFT)
        .value("VSTICKRIGHT", BtnEnum::VSTICKRIGHT)
        .finalize();

    pybind11::class_<TwoHeadArena>(main, "TwoHeadArena")
        .def_readwrite("size", &TwoHeadArena::size)
        .def_readwrite("bufp", &TwoHeadArena::bufp)
        .def_readwrite("head", &TwoHeadArena::head)
        .def_readwrite("tail", &TwoHeadArena::tail);

    pybind11::class_<TwoHeadGfxArena>(main, "TwoHeadGfxArena")
        .def_readwrite("size", &TwoHeadGfxArena::size)
        .def_readwrite("bufp", &TwoHeadGfxArena::bufp)
        .def_readwrite("p", &TwoHeadGfxArena::p)
        .def_readwrite("d", &TwoHeadGfxArena::d);

    pybind11::class_<CfbInfo>(main, "CfbInfo")
        .def_readwrite("fb1", &CfbInfo::fb1)
        .def_readwrite("swapBuffer", &CfbInfo::swapBuffer)
        .def_readwrite("viMode", &CfbInfo::viMode)
        .def_readwrite("features", &CfbInfo::features)
        .def_readwrite("unk_10", &CfbInfo::unk_10)
        .def_readwrite("updateRate", &CfbInfo::updateRate)
        .def_readwrite("updateRate2", &CfbInfo::updateRate2)
        .def_readwrite("unk_13", &CfbInfo::unk_13)
        .def_readwrite("xScale", &CfbInfo::xScale)
        .def_readwrite("yScale", &CfbInfo::yScale);

    pybind11::class_<OSScTask>(main, "OSScTask")
        .def_readwrite("next", &OSScTask::next)
        .def_readwrite("state", &OSScTask::state)
        .def_readwrite("flags", &OSScTask::flags)
        .def_readwrite("framebuffer", &OSScTask::framebuffer)
        .def_readwrite("list", &OSScTask::list)
        .def_readwrite("msgQ", &OSScTask::msgQ)
        .def_readwrite("msg", &OSScTask::msg);

    pybind11::class_<GraphicsContext>(main, "GraphicsContext")
        .def_readwrite("polyOpaBuffer", &GraphicsContext::polyOpaBuffer)
        .def_readwrite("polyXluBuffer", &GraphicsContext::polyXluBuffer)
        .def_readwrite("overlayBuffer", &GraphicsContext::overlayBuffer)
        .def_readwrite("unk_014", &GraphicsContext::unk_014)
        .def_property_readonly("msgBuff", [](pybind11::object& obj) {
            GraphicsContext& gctxt = obj.cast<GraphicsContext&>();     // TODO no cast?
            return PybindArray<OSMesg>{ gctxt.msgBuff, 8 };                 // TODO size macro?
        })
        .def_readwrite("schedMsgQ", &GraphicsContext::schedMsgQ)
        .def_readwrite("queue", &GraphicsContext::queue)
        .def_readwrite("task", &GraphicsContext::task)
        .def_readwrite("workBuffer", &GraphicsContext::workBuffer)
        .def_readwrite("work", &GraphicsContext::work)
        .def_readwrite("viMode", &GraphicsContext::viMode)
        .def_readwrite("overlay", &GraphicsContext::overlay)
        .def_readwrite("polyOpa", &GraphicsContext::polyOpa)
        .def_readwrite("polyXlu", &GraphicsContext::polyXlu)
        .def_readwrite("gfxPoolIdx", &GraphicsContext::gfxPoolIdx)
        .def_readwrite("curFrameBuffer", &GraphicsContext::curFrameBuffer)
        .def_readwrite("viFeatures", &GraphicsContext::viFeatures)
        .def_readwrite("fbIdx", &GraphicsContext::fbIdx)
        .def_readwrite("callback", &GraphicsContext::callback)
        .def_readwrite("callbackParam", &GraphicsContext::callbackParam)
        .def_readwrite("xScale", &GraphicsContext::xScale)
        .def_readwrite("yScale", &GraphicsContext::yScale);

    pybind11::class_<Input>(main, "Input")
        .def_readwrite("cur", &Input::cur)
        .def_readwrite("prev", &Input::prev)
        .def_readwrite("press", &Input::press)
        .def_readwrite("rel", &Input::rel);

    pybind11::class_<Viewport>(main, "Viewport")
        .def_readwrite("topY", &Viewport::topY)
        .def_readwrite("bottomY", &Viewport::bottomY)
        .def_readwrite("leftX", &Viewport::leftX)
        .def_readwrite("rightX", &Viewport::rightX);

    pybind11::class_<View>(main, "View")
        .def_readwrite("magic", &View::magic)
        .def_readwrite("gfxCtx", &View::gfxCtx)
        .def_readwrite("viewport", &View::viewport)
        .def_readwrite("fovy", &View::fovy)
        .def_readwrite("zNear", &View::zNear)
        .def_readwrite("zFar", &View::zFar)
        .def_readwrite("scale", &View::scale)
        .def_readwrite("eye", &View::eye)
        .def_readwrite("lookAt", &View::lookAt)
        .def_readwrite("up", &View::up)
        .def_readwrite("vp", &View::vp)
        .def_readwrite("projection", &View::projection)
        .def_readwrite("viewing", &View::viewing)
        .def_readwrite("projectionPtr", &View::projectionPtr)
        .def_readwrite("projectionFlippedPtr", &View::projectionFlippedPtr)
        .def_readwrite("viewingPtr", &View::viewingPtr)
        .def_readwrite("distortionOrientation", &View::distortionOrientation)
        .def_readwrite("distortionScale", &View::distortionScale)
        .def_readwrite("distortionSpeed", &View::distortionSpeed)
        .def_readwrite("curDistortionOrientation", &View::curDistortionOrientation)
        .def_readwrite("curDistortionScale", &View::curDistortionScale)
        .def_readwrite("normal", &View::normal)
        .def_readwrite("flags", &View::flags)
        .def_readwrite("unk_124", &View::unk_124);

    RegisterPybindArray<Input>(m, "Input_Array");

    pybind11::class_<ActorListEntry>(main, "ActorListEntry")
        .def_readwrite("length", &ActorListEntry::length)
        .def_readwrite("head", &ActorListEntry::head);

    RegisterPybindArray<ActorListEntry>(m, "ActorListEntry_Array");

    pybind11::class_<ActorContext>(main, "ActorContext")
        .def_readwrite("freezeFlashTimer", &ActorContext::freezeFlashTimer)
        .def_readwrite("unk_02", &ActorContext::unk_02)
        .def_readwrite("lensActive", &ActorContext::lensActive)
        .def_readwrite("total", &ActorContext::total)
        .def_property_readonly("actorLists", [](pybind11::object& obj) {
            ActorContext& actorCtxt = obj.cast<ActorContext&>(); // TODO no cast?
            return PybindArray<ActorListEntry>{ actorCtxt.actorLists, ACTORCAT_MAX }; // TODO size macro?
        })
        //.def_readwrite("targetCtx", &ActorContext::targetCtx)
        //.def_readwrite("flags", &ActorContext::flags)
        //.def_readwrite("titleCtx", &ActorContext::titleCtx)
        .def_readwrite("absoluteSpace", &ActorContext::absoluteSpace);

    pybind11::class_<GameAllocEntry>(main, "GameAllocEntry")
        .def_readwrite("next", &GameAllocEntry::next)
        .def_readwrite("prev", &GameAllocEntry::prev)
        .def_readwrite("size", &GameAllocEntry::size)
        .def_readwrite("unk_0C", &GameAllocEntry::unk_0C);

    pybind11::class_<CollisionCheckContext>(main, "CollisionCheckContext")
        .def_readwrite("colATCount", &CollisionCheckContext::colATCount)
        .def_readwrite("sacFlags", &CollisionCheckContext::sacFlags)
        .def_property_readonly("colAT", [](pybind11::object& obj) {
            CollisionCheckContext& colChkCtxt = obj.cast<CollisionCheckContext&>(); // TODO no cast?
            return PybindArray<Collider*>{ colChkCtxt.colAT, COLLISION_CHECK_AT_MAX }; // TODO size macro?
        })
        .def_readwrite("colACCount", &CollisionCheckContext::colACCount)
        .def_property_readonly("colAC", [](pybind11::object& obj) {
            CollisionCheckContext& colChkCtxt = obj.cast<CollisionCheckContext&>(); // TODO no cast?
            return PybindArray<Collider*>{ colChkCtxt.colAC, COLLISION_CHECK_AC_MAX }; // TODO size macro?
        })
        .def_readwrite("colOCCount", &CollisionCheckContext::colOCCount)
        .def_property_readonly("colOC", [](pybind11::object& obj) {
            CollisionCheckContext& colChkCtxt = obj.cast<CollisionCheckContext&>(); // TODO no cast?
            return PybindArray<Collider*>{ colChkCtxt.colOC, COLLISION_CHECK_OC_MAX }; // TODO size macro?
        })
        .def_readwrite("colLineCount", &CollisionCheckContext::colLineCount)
        .def_property_readonly("colLine", [](pybind11::object& obj) {
            CollisionCheckContext& colChkCtxt = obj.cast<CollisionCheckContext&>();    // TODO no cast?
            return PybindArray<OcLine*>{ colChkCtxt.colLine, COLLISION_CHECK_OC_LINE_MAX }; // TODO size macro?
        });


    pybind11::class_<GameAlloc>(main, "GameAlloc")
        .def_readwrite("base", &GameAlloc::base)
        .def_readwrite("head", &GameAlloc::head);

    pybind11::class_<GameState>(main, "GameState")
        .def_readwrite("gfxCtx", &GameState::gfxCtx)
        .def_readwrite("main", &GameState::main)
        .def_readwrite("destroy", &GameState::destroy)
        .def_readwrite("destroy", &GameState::destroy)
        .def_readwrite("init", &GameState::init)
        .def_readwrite("size", &GameState::size)
        .def_property_readonly("input", [](pybind11::object& obj) {
            GameState& state = obj.cast<GameState&>();     // TODO no cast?
            return PybindArray<Input>{ state.input, 4 };                 // TODO size macro?
        })
        .def_readwrite("tha", &GameState::tha)
        .def_readwrite("alloc", &GameState::alloc)
        .def_readwrite("running", &GameState::running)
        .def_readwrite("frames", &GameState::frames)
        .def_readwrite("unk_A0", &GameState::unk_A0);

    pybind11::class_<PlayState>(main, "PlayState")
        .def_readwrite("state", &PlayState::state)
        .def_readwrite("sceneNum", &PlayState::sceneNum)
        .def_readwrite("sceneConfig", &PlayState::sceneConfig)
        .def_readwrite("sceneSegment", &PlayState::sceneSegment)
        .def_readwrite("view", &PlayState::view)
        .def_readwrite("mainCamera", &PlayState::mainCamera)
        .def_property_readonly("subCameras", [](pybind11::object& obj) {
            PlayState& state = obj.cast<PlayState&>();   // TODO no cast?
            return PybindArray<Camera>{ state.subCameras, NUM_CAMS - SUBCAM_FIRST }; // TODO size macro?
        })
        .def_property_readonly("cameraPtrs", [](pybind11::object& obj) {
            PlayState& state = obj.cast<PlayState&>();   // TODO no cast?
            return PybindArray<Camera*>{ state.cameraPtrs, NUM_CAMS }; // TODO size macro?
        })
        .def_readwrite("activeCamera", &PlayState::activeCamera)
        .def_readwrite("nextCamera", &PlayState::nextCamera)
        .def_readwrite("manualCamera", &PlayState::manualCamera)
        .def_readwrite("camX", &PlayState::camX)
        .def_readwrite("camY", &PlayState::camY)
        //.def_readwrite("sequenceCtx", &PlayState::sequenceCtx) // TODO
        .def_readwrite("lightCtx", &PlayState::lightCtx)
        //.def_readwrite("frameAdvCtx", &PlayState::frameAdvCtx)
        .def_readwrite("colCtx", &PlayState::colCtx)
        .def_readwrite("actorCtx", &PlayState::actorCtx)
        // TODO more
        .def_readwrite("colChkCtx", &PlayState::colChkCtx)
        // TODO more
        ;

    // TODO more
}