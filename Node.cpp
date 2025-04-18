#include "Node.h"

namespace BehaviourTree
{
	Result Node::Run()
	{
		if (m_Result != Result::RUNNING)
		{
			OnEnter();
		}

		m_Result = UpdateResult();

		if (m_Result != Result::RUNNING)
		{
			OnExit();
		}

		return m_Result;
	}
}
