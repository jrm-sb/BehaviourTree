#include "Node.h"

namespace BehaviourTree
{
	Result Node::Run()
	{
		OnEnter();

		m_Result = UpdateResult();

		if (m_Result != Result::RUNNING)
		{
			OnExit();
		}

		return m_Result;
	}
}
