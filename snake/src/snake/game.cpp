#include "game.hpp"

#include <Graphics/Texture.h>
#include <imgui/imgui.h>

#include "snake.hpp"

namespace snake {
Game::Game()
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
        auto entity = m_Scene.CreateEntity();
        entity.AddComponent<Wraith::NativeScriptComponent>().Bind<Snake>(
            &m_Scene);
    }

    m_Scene.Play();
}

void Game::OnUpdate(f32 dt) {
    m_Scene.UpdateRuntime(dt);
}

void Game::OnUIRender() {
    auto& texture = m_Engine->GetRenderer()->GetRenderTexture();
    ImGui::Image(
        texture.GetShaderResourceView(), {800.f, 800.f}, {0, 0}, {1, 1});
}

}  // namespace snake