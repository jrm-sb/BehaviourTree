#include "Composite.h"

namespace BehaviourTree
{
	void Composite::AddChild(std::unique_ptr<Node> node)
	{
		m_Children.emplace_back(std::move(node));
	}

	void Composite::RemoveChild(std::unique_ptr<Node> node)
	{
		auto foundIt = std::find(m_Children.begin(), m_Children.end(), std::move(node));
		if (foundIt != m_Children.end())
			m_Children.erase(foundIt, foundIt + 1);
	}

	void Composite::RemoveAllChildren()
	{
		m_Children.clear();
	}
}