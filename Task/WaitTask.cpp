#include "WaitTask.h"

namespace BehaviourTree
{
    void WaitTask::OnEnter()
    {
        m_IsWaiting = true;
        m_StartTime = std::chrono::steady_clock::now();
    }

    Result WaitTask::UpdateResult()
    {
        auto now = std::chrono::steady_clock::now();

        // Make sure m_StartTime is initialized
        if (m_StartTime == std::chrono::time_point<std::chrono::steady_clock>())
        {
            m_StartTime = now;
        }

        float elapsed = std::chrono::duration<float>(now - m_StartTime).count();

        if (elapsed >= m_WaitTime)
        {
            m_IsWaiting = false;
            return Result::SUCCESS;
        }

        return Result::RUNNING;
    }

    bool WaitTask::IsFinished() const
    {
        return !m_IsWaiting;
    }
}
