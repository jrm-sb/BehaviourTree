#include "Tree.h"

namespace BehaviourTree
{
	void Tree::RunTree()
	{
		if (m_Root)
		{
			m_Root->Run();
		}
	}
}