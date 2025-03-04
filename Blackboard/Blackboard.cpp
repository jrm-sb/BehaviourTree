#include "Blackboard.h"

namespace BehaviourTree
{
	bool BehaviourTree::Blackboard::Contains(Key key) const
	{
		return m_Map.contains(key);
	}
}