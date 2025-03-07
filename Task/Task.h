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

        virtual bool Evaluate() override;
        virtual Result Run() override = 0;

    protected:
        virtual void OnEnter() override {}
        virtual void OnExit() override {}
    };
}

