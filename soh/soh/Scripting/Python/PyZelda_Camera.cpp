#include "../PyZelda.h"
#include "pybind11/native_enum.h"

#include "z64camera.h"
#include "z64.h"

void PyZelda_RegisterCamera(pybind11::module_& m) {
    pybind11::module_ camera = m.def_submodule("Camera");

    
    pybind11::class_<Camera>(camera, "Camera")
        //.def_readwrite("paramData", &Camera::paramData) // TODO array
        .def_readwrite("at", &Camera::at)
        .def_readwrite("eye", &Camera::eye)
        .def_readwrite("up", &Camera::up)
        .def_readwrite("eyeNext", &Camera::eyeNext)
        .def_readwrite("skyboxOffset", &Camera::skyboxOffset)
        .def_readwrite("play", &Camera::play)
        .def_readwrite("player", &Camera::player)
        .def_readwrite("playerPosRot", &Camera::playerPosRot)
        .def_readwrite("target", &Camera::target)
        .def_readwrite("targetPosRot", &Camera::targetPosRot)
        .def_readwrite("rUpdateRateInv", &Camera::rUpdateRateInv)
        .def_readwrite("pitchUpdateRateInv", &Camera::pitchUpdateRateInv)
        .def_readwrite("yawUpdateRateInv", &Camera::yawUpdateRateInv)
        .def_readwrite("xzOffsetUpdateRate", &Camera::xzOffsetUpdateRate)
        .def_readwrite("yOffsetUpdateRate", &Camera::yOffsetUpdateRate)
        .def_readwrite("fovUpdateRate", &Camera::fovUpdateRate)
        .def_readwrite("xzSpeed", &Camera::xzSpeed)
        .def_readwrite("dist", &Camera::dist)
        .def_readwrite("speedRatio", &Camera::speedRatio)
        .def_readwrite("posOffset", &Camera::posOffset)
        .def_readwrite("playerPosDelta", &Camera::playerPosDelta)
        .def_readwrite("fov", &Camera::fov)
        .def_readwrite("atLERPStepScale", &Camera::atLERPStepScale)
        .def_readwrite("playerGroundY", &Camera::playerGroundY)
        .def_readwrite("floorNorm", &Camera::floorNorm)
        .def_readwrite("waterYPos", &Camera::waterYPos)
        .def_readwrite("waterPrevCamIdx", &Camera::waterPrevCamIdx)
        .def_readwrite("waterPrevCamSetting", &Camera::waterPrevCamSetting)
        .def_readwrite("waterQuakeId", &Camera::waterQuakeId)
        .def_readwrite("data0", &Camera::data0)
        .def_readwrite("data1", &Camera::data1)
        .def_readwrite("data2", &Camera::data2)
        .def_readwrite("data3", &Camera::data3)
        .def_readwrite("uid", &Camera::uid)
        .def_readwrite("inputDir", &Camera::inputDir)
        .def_readwrite("camDir", &Camera::camDir)
        .def_readwrite("status", &Camera::status)
        .def_readwrite("setting", &Camera::setting)
        .def_readwrite("mode", &Camera::mode)
        .def_readwrite("bgCheckId", &Camera::bgCheckId)
        .def_readwrite("camDataIdx", &Camera::camDataIdx)
        .def_readwrite("unk_14A", &Camera::unk_14A)
        .def_readwrite("unk_14C", &Camera::unk_14C)
        .def_readwrite("childCamIdx", &Camera::childCamIdx)
        .def_readwrite("waterDistortionTimer", &Camera::waterDistortionTimer)
        .def_readwrite("distortionFlags", &Camera::distortionFlags)
        .def_readwrite("prevSetting", &Camera::prevSetting)
        .def_readwrite("nextCamDataIdx", &Camera::nextCamDataIdx)
        .def_readwrite("nextBGCheckId", &Camera::nextBGCheckId)
        .def_readwrite("roll", &Camera::roll)
        .def_readwrite("paramFlags", &Camera::paramFlags)
        .def_readwrite("animState", &Camera::animState)
        .def_readwrite("timer", &Camera::timer)
        .def_readwrite("parentCamIdx", &Camera::parentCamIdx)
        .def_readwrite("thisIdx", &Camera::thisIdx)
        .def_readwrite("prevCamDataIdx", &Camera::prevCamDataIdx)
        .def_readwrite("csId", &Camera::csId)
        .def_readwrite("unk_16A", &Camera::unk_16A);

    RegisterPybindArray<Camera>(m, "Camera_Array");
    RegisterPybindArray<Camera*>(m, "Camera_Ptr_Array");

    // TODO more
}
