#include "snake.hpp"

#include <ranges>

namespace snake {
void Snake::OnCreate() {
    for (int i = 0; i < 10; ++i) CreateSegment({Bounds / 2, Bounds / 2});
}
void Snake::OnUpdate(f32 dt) {
    if (GetInput().IsPressed(Wraith::Key::W)) {
        m_Dir = {0, -1};
    }
    if (GetInput().IsPressed(Wraith::Key::S)) {
        m_Dir = {0, 1};
    }
    if (GetInput().IsPressed(Wraith::Key::A)) {
        m_Dir = {-1, 0};
    }
    if (GetInput().IsPressed(Wraith::Key::D)) {
        m_Dir = {1, 0};
    }

    m_TimeToMove -= dt;
    if (m_TimeToMove < 0.f) {
        m_TimeToMove += MoveInterval;
        Move();
    }

    m_TimeToGrow -= dt;
    if (m_TimeToGrow < 0.f) {
        m_TimeToGrow += SecondsPerGrowth;
        CreateSegment(m_Segments.back().pos);
    }
}
void Snake::Move() {
    for (std::size_t i = m_Segments.size() - 1; i > 0; --i) {
        UpdateSegment(i, m_Segments[i - 1].pos);
    }

    auto nextPos = m_Segments[0].pos + m_Dir;
    nextPos.x    = (nextPos.x + Bounds) % Bounds;
    nextPos.y    = (nextPos.y + Bounds) % Bounds;
    UpdateSegment(0, nextPos);
}

void Snake::CreateSegment(Wraith::Vec2i p) {
    auto  entity       = m_Scene->CreateEntity();
    auto& sprite       = entity.AddComponent<Wraith::SpriteComponent>();
    sprite.texture     = Wraith::StringID("assets/textures/frog.png");
    sprite.origin      = {0.5f, 0.5f};
    sprite.layer       = 0;
    sprite.color       = {1.f, 1.f, 1.f, 1.f};
    sprite.world_space = true;

    auto& transform    = entity.GetComponent<Wraith::TransformComponent>();
    transform.position = {static_cast<f32>(p.x - Bounds / 2),
                          static_cast<f32>(p.y - Bounds / 2),
                          0};
    transform.scale    = {1.f / 200.f, 1.f / 200.f, 1.f};

    m_Segments.push_back(Segment{.entity = entity, .pos = p});
}

void Snake::UpdateSegment(std::size_t index, Wraith::Vec2i p) {
    auto& segment   = m_Segments[index];
    segment.pos     = p;
    auto& transform = segment.entity.GetComponent<Wraith::TransformComponent>();
    transform.position = {static_cast<f32>(p.x - Bounds / 2),
                          static_cast<f32>(p.y - Bounds / 2),
                          0};
}

}  // namespace snake