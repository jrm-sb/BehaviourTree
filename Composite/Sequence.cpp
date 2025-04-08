#include "Sequence.h"

namespace BehaviourTree
{
    Result BehaviourTree::Sequence::Run()
    {
        int i = 0;
        Result result = m_Result;
        while (i < m_Children.size())
        {
            result = m_Children[i]->Run();
            if (result == Result::FAILURE)
            {
                m_Result = result;
                return Result::FAILURE;
            }
            else if (result == Result::SUCCESS)
            {
                ++i;
            }
        }

        // No child has returned FAILURE
        // meaning that result = SUCCESS
        m_Result = result;
        return m_Result;
    }
}
