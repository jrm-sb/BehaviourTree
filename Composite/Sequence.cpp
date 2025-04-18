#include "Sequence.h"

namespace BehaviourTree
{
    void Sequence::OnEnter()
    {
        currentChildInterator = m_Children.begin();
    }

    Result Sequence::UpdateResult()
    {
        if (m_Children.empty() || currentChildInterator == m_Children.end())
            return Result::SUCCESS;

        const Result result = (*currentChildInterator)->Run();

        switch (result)
        {
            case Result::SUCCESS:
            {
                if (++currentChildInterator == m_Children.end())
                    return Result::SUCCESS;

                return Result::RUNNING;
            }

            default:
                return result;
        }
    }
}
