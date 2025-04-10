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
		virtual bool Evaluate() = 0;
		virtual Result Run();
		virtual void OnExit() override {};

	private:
		std::unique_ptr<Node> child;
	};
}
