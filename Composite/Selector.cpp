#include "Selector.h"

namespace BehaviourTree
{
    void Selector::OnEnter()
    {
        currentChildInterator = m_Children.begin();
    }

    Result Selector::UpdateResult()
    {
        if (m_Children.empty())
            return Result::SUCCESS;

        if (currentChildInterator == m_Children.end())
            return Result::FAILURE;

        const Result result = (*currentChildInterator)->Run();

        switch (result)
        {
            case Result::SUCCESS:
                return result;

            default:
            {
                if (++currentChildInterator == m_Children.end())
                    return Result::FAILURE;

                return Result::RUNNING;
            }
        }
    }
}
