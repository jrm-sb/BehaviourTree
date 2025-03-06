#pragma once
#include "Task.h"

namespace BehaviourTree
{
    class FailTask : public Task
    {
    public:
        FailTask() : Task("FailTask") {}
        FailTask(FailTask&&) = default;
        FailTask& operator=(FailTask&&) = default;
        virtual ~FailTask() = default;

        virtual Result Run() override { return Result::FAILURE; }
    };
}

