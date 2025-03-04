#include "Selector.h"

namespace BehaviourTree
{
    bool Selector::Evaluate()
    {
        for (const std::unique_ptr<Decorator>& decorator : m_Decorators)
        {
            if (!decorator->Evaluate())
            {
                return false;
            }
        }

        return true;
    }

    Result Selector::Run()
    {
        for (const std::unique_ptr<Node>& child : m_Children)
        {
            if (child->Run() == Result::SUCCESS)
            {
                return Result::SUCCESS;
            }
        }

        return Result::FAILURE;
    }
}
