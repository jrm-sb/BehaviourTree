#pragma once
#include <memory>
#include <vector>

#include "Decorator/Decorator.h"
#include "Node.h"

namespace BehaviourTree
{
    class Composite : public Node
    {
    public:
        Composite() : Node("CompositeNode") {}
        Composite(const std::string& name) : Node(name) {}

        virtual ~Composite() = default;

        void AddDecorator(std::unique_ptr<Decorator> decorator);
        void AddChild(std::unique_ptr<Node> node);

        const std::vector<std::unique_ptr<Decorator>>& GetDecorators() const { return m_Decorators; }
        const std::vector<std::unique_ptr<Node>>& GetChildren() const { return m_Children; }

        virtual bool Evaluate() override { return true; }
        virtual Result Run() override = 0;
        
    protected:
        std::vector<std::unique_ptr<Decorator>> m_Decorators;
        std::vector<std::unique_ptr<Node>> m_Children;
    };
}

