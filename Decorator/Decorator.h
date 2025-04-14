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
		virtual Result UpdateResult();
		virtual void OnExit() override {};

		virtual void AddChild(std::unique_ptr<Node> child) override { SetChild(std::move(child)); }
		void SetChild(std::unique_ptr<Node> child) { m_Child = std::move(child); }

	private:
		std::unique_ptr<Node> m_Child;
	};
}
