#include "../PyZelda.h"
#include "pybind11/native_enum.h"

#include "z64animation.h"
#include "global.h"
#include "soh/ResourceManagerHelpers.h"

void PyZelda_RegisterAnimation(pybind11::module_& m) {
    pybind11::module_ anim = m.def_submodule("Animation");

    pybind11::class_<SkelAnime>(anim, "SkelAnime")
        .def(pybind11::init([](char* skeletonHeaderSeg, char* animation, s32 limbCount) { // TODO types?
            SkelAnime* skel = new SkelAnime{};
            SkeletonHeader* skeletonHeader = (SkeletonHeader*)skeletonHeaderSeg;
            AnimationHeader* animationHeader = (AnimationHeader*)animation;
            if (ResourceMgr_OTRSigCheck(skeletonHeaderSeg)) {
                skeletonHeader = ResourceMgr_LoadSkeletonByName(skeletonHeaderSeg, skel);
            }
            if (ResourceMgr_OTRSigCheck(animation)) {
                animationHeader = (AnimationHeader*)ResourceMgr_LoadAnimByName(animation);
            }
            SkelAnime_Init(nullptr, skel, skeletonHeader, animationHeader, nullptr, nullptr, limbCount);
            return skel;
        }))
        .def_readwrite("limbCount", &SkelAnime::limbCount)
        .def_readwrite("mode", &SkelAnime::mode)
        .def_readwrite("dListCount", &SkelAnime::dListCount)
        .def_readwrite("taper", &SkelAnime::taper)
        //.def_readwrite("skeleton", &SkelAnime::skeleton) // TODO
        //.def_readwrite("animation", &SkelAnime::animation) // TODO
        .def_readwrite("startFrame", &SkelAnime::startFrame)
        .def_readwrite("endFrame", &SkelAnime::endFrame)
        .def_readwrite("animLength", &SkelAnime::animLength)
        .def_readwrite("curFrame", &SkelAnime::curFrame)
        .def_readwrite("playSpeed", &SkelAnime::playSpeed)
        .def_readwrite("jointTable", &SkelAnime::jointTable)
        .def_readwrite("morphTable", &SkelAnime::morphTable)
        .def_readwrite("morphWeight", &SkelAnime::morphWeight)
        .def_readwrite("morphRate", &SkelAnime::morphRate)
        //.def_readwrite("update", &SkelAnime::update) // TODO
        .def_readwrite("initFlags", &SkelAnime::initFlags)
        .def_readwrite("movementFlags", &SkelAnime::movementFlags)
        .def_readwrite("prevRot", &SkelAnime::prevRot)
        .def_readwrite("prevTransl", &SkelAnime::prevTransl)
        .def_readwrite("baseTransl", &SkelAnime::baseTransl)
        //.def_readwrite("skeletonHeader", &SkelAnime::skeletonHeader) // TODO
        ;

        anim.def("free", [](SkelAnime* skel) {
            SkelAnime_Free(skel, nullptr);
        });

        anim.def("update", [](SkelAnime* skel) {
            SkelAnime_Update(skel);
        });
    
    // TODO more
}