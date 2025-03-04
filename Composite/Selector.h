#pragma once
#include "Composite.h"

namespace BehaviourTree
{
    class Selector : public Composite
    {
    public:
        Selector() : Composite("SelectorNode") {}
        Selector(const std::string& name) : Composite(name) {}
        virtual ~Selector() = default;

        virtual bool Evaluate() override;
        virtual Result Run() override;
    };
}

