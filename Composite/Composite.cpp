#include "Composite.h"

namespace BehaviourTree
{
	void Composite::AddDecorator(std::unique_ptr<Decorator> decorator)
	{
		m_Decorators.push_back(std::move(decorator));
	}

	void Composite::AddChild(std::unique_ptr<Node> node)
	{
		m_Children.push_back(std::move(node));
	}
}