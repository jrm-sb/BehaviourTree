#pragma once
#include "Task.h"

namespace BehaviourTree
{
    class SuccessTask : public Task
    {
    public:
        SuccessTask() : Task("SuccessTask") {}
        virtual ~SuccessTask() = default;

        virtual Result UpdateResult() override { return Result::SUCCESS; }
    };
}

