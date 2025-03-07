#include "Composite.h"

namespace BehaviourTree
{
	void Composite::AddChild(std::unique_ptr<Task> task)
	{
		m_Children.emplace_back(std::move(task));
	}

	void Composite::RemoveChild(std::unique_ptr<Task> task)
	{
		auto foundIt = std::find(m_Children.begin(), m_Children.end(), std::move(task));
		if (foundIt != m_Children.end())
			m_Children.erase(foundIt, foundIt + 1);
	}

	void Composite::RemoveAllChildren()
	{
		m_Children.clear();
	}

	bool Composite::Evaluate()
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