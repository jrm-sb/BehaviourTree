#pragma once
#include <memory>
#include <vector>
#include "Decorator.h"
#include "Collection.h"

namespace BehaviourTree
{
    class Task : public Collection
    {
    public:
        Task() : Collection("TaskNode") {}
        Task(const std::string& name) : Collection(name) {}
        virtual ~Task() = default;

        virtual Result UpdateResult() override = 0;

    protected:
        virtual void OnEnter() override {}
        virtual void OnExit() override {}
    };
}

