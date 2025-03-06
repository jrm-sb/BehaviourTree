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
        for (const std::unique_ptr<Task>& child : m_Children)
        {
            m_Result = child->Run();
            if (m_Result == Result::SUCCESS)
            {
                return Result::SUCCESS;
            }
        }

        return m_Result;
    }
}
