#pragma once
#include "Decorator.h"

namespace BehaviourTree
{
    enum class Operator
    {
        EQUALS,
        LESS,
        LESS_EQUAL,
        GREATER,
        GREATER_EQUAL
    };

    class DistanceCondition : public Decorator
    {
    public:
        DistanceCondition(float valueToCheck, const Blackboard& blackboard, Blackboard::Key key, Operator op)
            : Decorator("DistanceCondition"), m_Value(valueToCheck), m_Blackboard(blackboard), m_Key(key), m_Operator(op) {}

        virtual bool Evaluate() override;

        void SetOperator(Operator op) { m_Operator = op; }

    private:
        float m_Value;
        Blackboard m_Blackboard;
        Blackboard::Key m_Key;
        Operator m_Operator;
    };
}

