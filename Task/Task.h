#pragma once
#include <memory>
#include <vector>
#include "Decorator.h"

namespace BehaviourTree
{
    class Task : public Node
    {
    public:
        Task() : Node("TaskNode") {}
        Task(const std::string& name) : Node(name) {}
        virtual ~Task() = default;

        virtual Result UpdateResult() override = 0;
        virtual void AddChild(std::unique_ptr<Node> child) override {}

    protected:
        virtual void OnEnter() override {}
        virtual void OnExit() override {}
    };
}

