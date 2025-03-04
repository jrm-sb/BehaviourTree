#pragma once
#include <memory>
#include <vector>

#include "Blackboard.h"
#include "Node.h"
namespace BehaviourTree
{
	class Tree
	{
	public:
		Tree() = default;

		void AddNode(std::unique_ptr<Node> node);
		void RunTree();

		const std::vector<std::unique_ptr<Node>>& GetNodes() const { return m_Nodes; }
		const Blackboard& GetBlackboard() const { return m_Blackboard; }

	private:
		std::vector<std::unique_ptr<Node>> m_Nodes;
		Blackboard m_Blackboard;
	};
}

