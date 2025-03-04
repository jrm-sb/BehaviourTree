#include "WaitTask.h"

namespace BehaviourTree
{
    void WaitTask::OnEnter()
    {
        m_IsWaiting = true;
        m_StartTime = std::chrono::steady_clock::now();
    }

    Result WaitTask::Run()
    {
        if (IsFinished())
            return Result::SUCCESS;

        auto now = std::chrono::steady_clock::now();
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
