#include "snake.hpp"

#include <Graphics/Texture.h>
#include <imgui/imgui.h>

namespace snake {
class SnakeController : public Wraith::ScriptableEntity {
public:
    void OnUpdate(f32 dt) override {
        auto& transform = GetComponent<Wraith::TransformComponent>();
        if (GetInput().IsPressed(Wraith::Key::W)) {
            transform.position.y -= 1.f;
        }
        if (GetInput().IsPressed(Wraith::Key::S)) {
            transform.position.y += 1.f;
        }
        if (GetInput().IsPressed(Wraith::Key::A)) {
            transform.position.x -= 1.f;
        }
        if (GetInput().IsPressed(Wraith::Key::D)) {
            transform.position.x += 1.f;
        }
    }

private:
};

Snake::Snake()
    : Application("Snake") {
    m_Scene.Init(m_Engine->GetRenderer());

    {
        auto entity = m_Scene.CreateEntity("Main Camera");
        auto camera = entity.AddComponent<Wraith::CameraComponent>(
            Wraith::Camera(Wraith::Mat4f::CreatePerspectiveProjection(
                90.0f, -1.f, 0.01f, 100.0f)));
        entity.GetComponent<Wraith::TransformComponent>().position = {
            0.0f, 0.0f, -10.0f};
    }

    {
        auto  entity   = m_Scene.CreateEntity();
        auto& sprite   = entity.AddComponent<Wraith::SpriteComponent>();
        sprite.texture = Wraith::StringID("assets/engine/textures/default.png");
        sprite.origin  = {0.5f, 0.5f};
        sprite.layer   = 0;
        sprite.color   = {1.f, 1.f, 1.f, 1.f};
        sprite.world_space = true;

        auto& transform    = entity.GetComponent<Wraith::TransformComponent>();
        transform.position = {0, 0, 0};
        transform.scale    = {1.f / 512.f, 1.f / 512.f, 1.f / 512.f};

        entity.AddComponent<Wraith::NativeScriptComponent>()
            .Bind<SnakeController>();
    }

    m_Scene.Play();
}

void Snake::OnUpdate(f32 dt) {
    m_Scene.UpdateRuntime(dt);
}

void Snake::OnUIRender() {
    auto& texture = m_Engine->GetRenderer()->GetRenderTexture();
    ImGui::Image(
        texture.GetShaderResourceView(), {800.f, 800.f}, {0, 0}, {1, 1});
}

}  // namespace snake