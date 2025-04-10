#include "DistanceCondition.h"

namespace BehaviourTree
{
	bool DistanceCondition::Evaluate()
	{
		std::optional<float> blackboardValue = m_Blackboard.GetValue<float>(m_Key);
		if (!blackboardValue.has_value())
			return false;

		switch (m_Operator)
		{
		case BehaviourTree::Operator::EQUALS:
		{
			return m_Value == blackboardValue;
		}
		case BehaviourTree::Operator::LESS:
		{
			return m_Value < blackboardValue;
		}
		case BehaviourTree::Operator::LESS_EQUAL:
		{
			return m_Value <= blackboardValue;
		}
		case BehaviourTree::Operator::GREATER:
		{
			return m_Value > blackboardValue;
		}
		case BehaviourTree::Operator::GREATER_EQUAL:
		{
			return m_Value >= blackboardValue;
		}
		default:
			return false;
		}
	}
}
