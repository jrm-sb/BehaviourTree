#include "Decorator.h"

namespace BehaviourTree
{
	Result Decorator::UpdateResult()
	{
		if (Evaluate())
		{
			if (child)
			{
				child->Run();
			}
			else
			{
				return Result::SUCCESS;
			}
		}

		return Result::FAILURE;
	}
}
