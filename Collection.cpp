#include "Collection.h"

namespace BehaviourTree
{
	void Collection::AddDecorator(std::unique_ptr<Decorator> decorator)
	{
		m_Decorators.push_back(std::move(decorator));
	}

	void Collection::RemoveDecorator(std::unique_ptr<Decorator> decorator)
	{
		auto foundIt = std::find(m_Decorators.begin(), m_Decorators.end(), std::move(decorator));
		if (foundIt != m_Decorators.end())
			m_Decorators.erase(foundIt, foundIt + 1);
	}

	void Collection::RemoveAllDecorators()
	{
		m_Decorators.clear();
	}
}
