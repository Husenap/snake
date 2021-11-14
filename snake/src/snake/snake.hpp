#pragma once

#include <Application.h>

namespace snake {
class Snake : public Wraith::Application {
public:
    Snake()
        : Application("Snake") {}
    virtual ~Snake() = default;

    void OnUpdate(f32 dt) override;
    void OnUIRender() override;

private:
};
}  // namespace snake
