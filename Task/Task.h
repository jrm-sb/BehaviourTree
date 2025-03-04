#pragma once
#include <memory>
#include <vector>
#include "Decorator.h"
#include "Node.h"

namespace BehaviourTree
{
    class Task : public Node
    {
    public:
        Task() : Node("TaskNode") {}
        Task(const std::string& name) : Node(name) {}
        virtual ~Task() = default;

        void AddDecorator(std::unique_ptr<Decorator> decorator);
        const std::vector<std::unique_ptr<Decorator>>& GetDecorators() const { return std::move(m_Decorators); }

        virtual bool Evaluate() override;
        virtual Result Run() override = 0;

    protected:
        virtual void OnEnter() override {}
        virtual void OnExit() override {}

        std::vector<std::unique_ptr<Decorator>> m_Decorators;
    };
}

