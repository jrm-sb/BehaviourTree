#pragma once
#include <memory>
#include <vector>

#include "Decorator/Decorator.h"
#include "Node.h"
#include "Task/Task.h"

namespace BehaviourTree
{
    class Composite : public Node
    {
    public:
        Composite() : Node("CompositeNode") {}
        Composite(const std::string& name) : Node(name) {}

        virtual ~Composite() = default;

        void AddDecorator(std::unique_ptr<Decorator> decorator);
        void RemoveDecorator(std::unique_ptr<Decorator> decorator);
        void RemoveAllDecorators();

        void AddChild(std::unique_ptr<Task> task);
        void RemoveChild(std::unique_ptr<Task> task);
        void RemoveAllChildren();

        const std::vector<std::unique_ptr<Decorator>>& GetDecorators() const { return std::move(m_Decorators); }
        const std::vector<std::unique_ptr<Task>>& GetChildren() const { return std::move(m_Children); }

        virtual bool Evaluate() override { return true; }
        virtual Result Run() override = 0;
        
    protected:
        std::vector<std::unique_ptr<Decorator>> m_Decorators;
        std::vector<std::unique_ptr<Task>> m_Children;
    };
}

