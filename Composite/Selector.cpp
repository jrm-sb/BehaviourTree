#include "Selector.h"

namespace BehaviourTree
{
    Result Selector::Run()
    {
        int i = 0;
        Result result = m_Result;
        while (i < m_Children.size())
        {
            result = m_Children[i]->Run();
            if (result == Result::SUCCESS)
            {
                m_Result = result;
                return Result::SUCCESS;
            }
            else if (result == Result::FAILURE)
            {
                ++i;
            }
        }

        // No child has returned SUCCESS
        // meaning that result = FAILURE
        m_Result = result;
        return m_Result;
    }
}
