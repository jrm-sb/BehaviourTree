#include "Tree.h"

namespace BehaviourTree
{
	void Tree::AddNode(std::unique_ptr<Node> node)
	{
		m_Nodes.push_back(std::move(node));
	}

	void Tree::RunTree()
	{
        int currentIndex = 0;
        while (currentIndex < m_Nodes.size())
        {
            if (!m_Nodes[currentIndex]->Evaluate())
                ++currentIndex;

            m_Nodes[currentIndex]->OnEnter();
            Result result = m_Nodes[currentIndex]->Run();
            if (result == Result::SUCCESS)
            {
                m_Nodes[currentIndex]->OnExit();
                currentIndex = 0;
            }
            else if (result == Result::FAILURE)
            {
                currentIndex = 0;
            }
        }
	}
}