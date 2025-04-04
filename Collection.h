#pragma once
#include <memory>
#include <string>
#include <vector>
#include "Decorator.h"
#include "Node.h"

namespace BehaviourTree
{
    class Collection : public Node
    {
    public:
        Collection() : Node("Collection") {}
        Collection(const std::string& name) : Node(name) {}

        void AddDecorator(std::unique_ptr<Decorator> decorator);
        void RemoveDecorator(std::unique_ptr<Decorator> decorator);
        void RemoveAllDecorators();

        const std::vector<std::unique_ptr<Decorator>>& GetDecorators() const { return std::move(m_Decorators); }

    protected:
        std::vector<std::unique_ptr<Decorator>> m_Decorators;
    };
}

