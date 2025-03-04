#pragma once
#include <memory>
#include "Blackboard.h"
#include "Node.h"

namespace BehaviourTree
{
	class Decorator : public Node
	{
	public:
		Decorator() : Node("DecoratorNode") {}
		Decorator(const std::string& name) : Node(name) {}
		virtual ~Decorator() = default;
		virtual bool Evaluate() override = 0;
	};
}
