#pragma once
#include <chrono>
#include "Task.h"

namespace BehaviourTree
{
    class WaitTask : public Task
    {
    public:
        WaitTask() : Task("WaitTask"), m_WaitTime(0.1f) {}
        WaitTask(float time) : Task("WaitTask"), m_WaitTime(time) {}
        WaitTask(const WaitTask& other) : m_WaitTime(other.m_WaitTime) {}
        virtual ~WaitTask() = default;

        virtual void OnEnter() override;
        virtual Result UpdateResult() override;

        bool IsFinished() const;

    private:
        std::chrono::time_point<std::chrono::steady_clock> m_StartTime;
        float m_WaitTime;  // en secondes
        bool m_IsWaiting = false;
    };
}

