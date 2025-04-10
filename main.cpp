#include <chrono>
#include <iostream>
#include <thread>

#include "Blackboard/Blackboard.h"
#include "Composite/Selector.h"
#include "Composite/Sequence.h"
#include "Decorator/DistanceCondition.h"
#include "Task/FailTask.h"
#include "Task/SuccessTask.h"
#include "Task/WaitTask.h"
#include "Node.h"
#include "TestRunner.h"
#include "Tree.h"

TEST(CreateSuccessTask)
{
    BehaviourTree::SuccessTask t{};

    EXPECT(t.GetName() == "SuccessTask");
    EXPECT(t.GetId() == 0);
    EXPECT(t.GetIndex() == 0);
    EXPECT(t.GetResult() == BehaviourTree::Result::INVALID);
}

TEST(AddBlackboardEntry)
{
    BehaviourTree::Blackboard blackboard{};
    EXPECT(blackboard.GetValue<int>(0) == std::nullopt);
    EXPECT(blackboard.Contains(0) == false);

    blackboard.SetValue(0, 1);
    EXPECT(blackboard.Contains(0) == true);

    EXPECT(blackboard.GetValue<int>(0) == 1);
    EXPECT(blackboard.GetValue<float>(0) == std::nullopt);
    EXPECT(blackboard.GetValue<bool>(0) == std::nullopt);
    EXPECT(blackboard.GetValue<std::string>(0) == std::nullopt);

    blackboard.SetValue(0, 1.0f);
    EXPECT(blackboard.GetValue<int>(0) == std::nullopt);
    EXPECT(blackboard.GetValue<float>(0) == 1.0f);
    EXPECT(blackboard.GetValue<bool>(0) == std::nullopt);
    EXPECT(blackboard.GetValue<std::string>(0) == std::nullopt);

    blackboard.SetValue(0, true);
    EXPECT(blackboard.GetValue<int>(0) == std::nullopt);
    EXPECT(blackboard.GetValue<float>(0) == std::nullopt);
    EXPECT(blackboard.GetValue<bool>(0) == true);
    EXPECT(blackboard.GetValue<std::string>(0) == std::nullopt);

    blackboard.SetValue(0, std::string{ "TestStringValue" });
    EXPECT(blackboard.GetValue<int>(0) == std::nullopt);
    EXPECT(blackboard.GetValue<float>(0) == std::nullopt);
    EXPECT(blackboard.GetValue<bool>(0) == std::nullopt);
    EXPECT(blackboard.GetValue<std::string>(0) == "TestStringValue");
}

TEST(CheckDistanceCondition)
{
    BehaviourTree::Blackboard blackboard{};
    static constexpr BehaviourTree::Blackboard::Key key = 0;
    static constexpr float value = 10.f;
    blackboard.SetValue(key, value);

    BehaviourTree::DistanceCondition condition{ value, blackboard, key, BehaviourTree::Operator::EQUALS };
    EXPECT(condition.GetName() == "DistanceCondition");
    EXPECT(condition.Evaluate() == true);

    condition.SetOperator(BehaviourTree::Operator::GREATER_EQUAL);
    EXPECT(condition.Evaluate() == true);

    condition.SetOperator(BehaviourTree::Operator::LESS_EQUAL);
    EXPECT(condition.Evaluate() == true);

    condition.SetOperator(BehaviourTree::Operator::GREATER);
    EXPECT(condition.Evaluate() == false);

    condition.SetOperator(BehaviourTree::Operator::LESS);
    EXPECT(condition.Evaluate() == false);
}

TEST(WaitTask)
{
    constexpr float timeToWait = 1.0f;
    BehaviourTree::WaitTask waitTask{ timeToWait };

    EXPECT(waitTask.GetName() == "WaitTask");
    waitTask.OnEnter();
    EXPECT(waitTask.Run() == BehaviourTree::Result::RUNNING);

    std::thread secondThread([timeToWait]()
        {
            std::this_thread::sleep_for(std::chrono::duration<float>(timeToWait));
        });
    secondThread.join();
    EXPECT(waitTask.Run() == BehaviourTree::Result::SUCCESS);
}

TEST(FailTask)
{
    BehaviourTree::FailTask failTask{};

    EXPECT(failTask.GetName() == "FailTask");
    EXPECT(failTask.Run() == BehaviourTree::Result::FAILURE);
}

TEST(SuccessTask)
{
    BehaviourTree::SuccessTask successTask{};

    EXPECT(successTask.GetName() == "SuccessTask");
    EXPECT(successTask.Run() == BehaviourTree::Result::SUCCESS);
}

/*TEST(AddDecoratorsToTaskAndEvaluate)
{
    BehaviourTree::Blackboard blackboard{};
    static constexpr BehaviourTree::Blackboard::Key key1 = 1;
    static constexpr BehaviourTree::Blackboard::Key key2 = 2;
    blackboard.SetValue(key1, 10.f);
    blackboard.SetValue(key2, 20.f);

    static constexpr float currentDistanceToTarget = 15.0f;

    BehaviourTree::DistanceCondition condition1{ currentDistanceToTarget, blackboard, key1, BehaviourTree::Operator::GREATER_EQUAL };
    BehaviourTree::DistanceCondition condition2{ currentDistanceToTarget, blackboard, key2, BehaviourTree::Operator::LESS_EQUAL };

    static constexpr float timeToWait = 1.0f;
    BehaviourTree::WaitTask waitTask{ timeToWait };

    waitTask.AddDecorator(std::make_unique<BehaviourTree::DistanceCondition>(condition1));
    waitTask.AddDecorator(std::make_unique<BehaviourTree::DistanceCondition>(condition2));

    EXPECT(waitTask.GetDecorators().size() == 2);
    EXPECT(waitTask.Evaluate() == true);

    static constexpr float newDistanceToTarget = 150.0f;

    BehaviourTree::DistanceCondition condition3{ newDistanceToTarget, blackboard, key1, BehaviourTree::Operator::GREATER_EQUAL };
    waitTask.AddDecorator(std::make_unique<BehaviourTree::DistanceCondition>(condition3));
    EXPECT(waitTask.GetDecorators().size() == 3);
    EXPECT(waitTask.Evaluate() == true);

    BehaviourTree::DistanceCondition condition4{ newDistanceToTarget, blackboard, key2, BehaviourTree::Operator::LESS_EQUAL };
    waitTask.AddDecorator(std::make_unique<BehaviourTree::DistanceCondition>(condition4));
    EXPECT(waitTask.GetDecorators().size() == 4);
    EXPECT(waitTask.Evaluate() == false);
}

TEST(SelectorNodeWithFailTasks)
{
    BehaviourTree::Selector selector{};
    EXPECT(selector.GetName() == "SelectorNode");

    selector.AddChild(std::make_unique<BehaviourTree::FailTask>());
    selector.AddChild(std::make_unique<BehaviourTree::FailTask>());

    EXPECT(selector.GetChildren().size() == 2);
    EXPECT(selector.Evaluate() == true);
    selector.OnEnter();
    EXPECT(selector.Run() == BehaviourTree::Result::FAILURE);
}*/

TEST(SelectorNodeWithFailTasksAndSuccessTask)
{
    BehaviourTree::Selector selector{};
    EXPECT(selector.GetName() == "SelectorNode");

    selector.AddChild(std::make_unique<BehaviourTree::FailTask>());
    selector.AddChild(std::make_unique<BehaviourTree::FailTask>());
    selector.AddChild(std::make_unique<BehaviourTree::SuccessTask>());
    EXPECT(selector.GetChildren().size() == 3);

    selector.OnEnter();
    EXPECT(selector.Run() == BehaviourTree::Result::SUCCESS);
}

TEST(SequenceNodeWithFailTask)
{
    BehaviourTree::Sequence sequence{};
    EXPECT(sequence.GetName() == "SequenceNode");

    sequence.AddChild(std::make_unique<BehaviourTree::FailTask>());
    EXPECT(sequence.GetChildren().size() == 1);

    sequence.OnEnter();
    EXPECT(sequence.Run() == BehaviourTree::Result::FAILURE);
}

TEST(SequenceNodeWithSuccessTask)
{
    BehaviourTree::Sequence sequence{};

    sequence.AddChild(std::make_unique<BehaviourTree::SuccessTask>());

    EXPECT(sequence.GetChildren().size() == 1);

    sequence.OnEnter();
    EXPECT(sequence.Run() == BehaviourTree::Result::SUCCESS);
}

TEST(SequenceNodeWithSuccessTaskAndFailTask)
{
    BehaviourTree::Sequence sequence{};

    sequence.AddChild(std::make_unique<BehaviourTree::SuccessTask>());
    sequence.AddChild(std::make_unique<BehaviourTree::FailTask>());

    EXPECT(sequence.GetChildren().size() == 2);

    sequence.OnEnter();
    EXPECT(sequence.Run() == BehaviourTree::Result::FAILURE);
}

int main()
{
    Test::RunAllTests();
}