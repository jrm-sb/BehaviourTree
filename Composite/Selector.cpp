#include "Selector.h"

namespace BehaviourTree
{
    void Selector::OnEnter()
    {
        currentChildIndex = m_Children.begin();
    }

    Result Selector::UpdateResult()
    {
        if (m_Children.empty())
            return Result::SUCCESS;

        if (currentChildIndex == m_Children.end())
            return Result::FAILURE;

        const Result result = (*currentChildIndex)->Run();

        switch (result)
        {
            case Result::SUCCESS:
                return result;

            default:
            {
                ++currentChildIndex;
                return Result::RUNNING;
            }
        }
    }
}
