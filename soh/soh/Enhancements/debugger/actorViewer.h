#pragma once

#include <libultraship/libultraship.h>

#include "soh/Enhancements/game-interactor/GameInteractor.h"

class ActorViewerWindow final : public Ship::GuiWindow {
  public:
    using GuiWindow::GuiWindow;

    void DrawElement() override;
    void InitElement() override;
    void UpdateElement() override{};

  private:
    HookAutoUnregisterer<GameInteractor::OnActorInit> OnActorInitHook;
};
