#pragma once
#include "Task.h"

namespace BehaviourTree
{
    class FailTask : public Task
    {
    public:
        FailTask() : Task("FailTask") {}
        virtual ~FailTask() = default;

        virtual Result Run() override { return Result::FAILURE; }
    };
}

