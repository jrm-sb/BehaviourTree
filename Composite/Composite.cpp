#include "Composite.h"

namespace BehaviourTree
{
	void Composite::AddDecorator(std::unique_ptr<Decorator> decorator)
	{
		m_Decorators.push_back(std::move(decorator));
	}

	void Composite::RemoveDecorator(std::unique_ptr<Decorator> decorator)
	{
		auto foundIt = std::find(m_Decorators.begin(), m_Decorators.end(), std::move(decorator));
		if (foundIt != m_Decorators.end())
			m_Decorators.erase(foundIt, foundIt + 1);
	}

	void Composite::RemoveAllDecorators()
	{
		m_Decorators.clear();
	}

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
}