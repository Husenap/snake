#pragma once

#include <vector>

#include <Scene/Components.h>
#include <Scene/Scene.h>

namespace snake {
class Snake : public Wraith::ScriptableEntity {
public:
    Snake(Wraith::Scene* scene)
        : m_Scene(scene) {}

    void OnCreate() override;
    void OnUpdate(f32) override;

private:
    struct Segment {
        Wraith::Entity entity;
        Wraith::Vec2i  pos;
    };

    void    Move();
    void CreateSegment(Wraith::Vec2i p);
    void    UpdateSegment(std::size_t index, Wraith::Vec2i p);

    std::vector<Segment> m_Segments;
    Wraith::Scene*       m_Scene;

    constexpr static f32 MovesPerSecond = 5.f;
    constexpr static f32 MoveInterval   = 1.f / 10.f;
    constexpr static i32 Bounds         = 15;

    constexpr static f32 SecondsPerGrowth = 5.f;

    f32           m_TimeToGrow = SecondsPerGrowth;
    f32           m_TimeToMove = MoveInterval;
    Wraith::Vec2i m_Dir        = {0, 1};
};
}  // namespace snake