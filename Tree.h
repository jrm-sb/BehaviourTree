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
		Tree(const Blackboard& blackboard, std::unique_ptr<Node> root)
			: m_Blackboard(blackboard), m_Root(std::move(root)) {}

		void RunTree();

		const Blackboard& GetBlackboard() const { return m_Blackboard; }

		const std::unique_ptr<Node>& GetRoot() const { return m_Root; }
		void SetRoot(std::unique_ptr<Node> root) { m_Root = std::move(root); }

	private:
		std::unique_ptr<Node> m_Root;
		Blackboard m_Blackboard;
	};
}

