#pragma once
#include "Composite.h"

namespace BehaviourTree
{
    class Sequence : public Composite
    {
    public:
        Sequence() : Composite("SequenceNode") {}
        Sequence(const std::string& name) : Composite(name) {}
        virtual ~Sequence() = default;

        virtual void OnEnter() override;
        virtual Result UpdateResult() override;
    };
}

