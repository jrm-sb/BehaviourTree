#include "Sequence.h"

namespace BehaviourTree
{
    void Sequence::OnEnter()
    {
        currentChildIndex = m_Children.begin();
    }

    Result Sequence::UpdateResult()
    {
        if (m_Children.empty() || currentChildIndex == m_Children.end())
            return Result::SUCCESS;

        const Result result = (*currentChildIndex)->Run();

        switch (result)
        {
            case Result::SUCCESS:
            {
                ++currentChildIndex;
                return Result::RUNNING;
            }

            default:
                return result;
        }
    }
}
