#pragma once

#include <Application.h>
#include <Scene/Scene.h>

namespace snake {
class Game : public Wraith::Application {
public:
    Game();
    virtual ~Game() = default;

    void OnUpdate(f32 dt) override;
    void OnUIRender() override;

private:
    Wraith::Scene m_Scene;
};
}  // namespace snake
