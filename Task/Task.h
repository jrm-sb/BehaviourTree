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

    protected:
        virtual void OnEnter() override {}
        virtual void OnExit() override {}
    };
}

