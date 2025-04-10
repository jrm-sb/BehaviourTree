#pragma once
#include "Task.h"

namespace BehaviourTree
{
    class FailTask : public Task
    {
    public:
        FailTask() : Task("FailTask") {}
        virtual ~FailTask() = default;

        virtual Result UpdateResult() override { return Result::FAILURE; }
    };
}

