#include "Task.h"

namespace BehaviourTree
{
	bool Task::Evaluate()
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
}
