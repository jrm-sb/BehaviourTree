#include "Task.h"

namespace BehaviourTree
{
	void Task::AddDecorator(std::unique_ptr<Decorator> decorator)
	{
		m_Decorators.push_back(std::move(decorator));
	}

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
