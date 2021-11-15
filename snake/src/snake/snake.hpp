#pragma once

#include <Application.h>
#include <Scene/Scene.h>

namespace snake {
class Snake : public Wraith::Application {
public:
    Snake();
    virtual ~Snake() = default;

    void OnUpdate(f32 dt) override;
    void OnUIRender() override;

private:
    Wraith::Scene m_Scene;
};
}  // namespace snake
