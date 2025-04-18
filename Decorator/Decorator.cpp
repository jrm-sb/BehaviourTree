#include "Decorator.h"

namespace BehaviourTree
{
	Result Decorator::UpdateResult()
	{
		if (Evaluate())
		{
			if (m_Child)
			{
				return m_Child->Run();
			}
			else
			{
				return Result::SUCCESS;
			}
		}

		return Result::FAILURE;
	}
}
