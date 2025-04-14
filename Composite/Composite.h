#pragma once
#include <memory>
#include <vector>

#include "Decorator/Decorator.h"
#include "Task/Task.h"

namespace BehaviourTree
{
    class Composite : public Node
    {
    public:
        Composite() : Node("CompositeNode") {}
        Composite(const std::string& name) : Node(name) {}

        virtual ~Composite() = default;

        virtual void AddChild(std::unique_ptr<Node> child) override;
        void RemoveChild(std::unique_ptr<Node> child);
        void RemoveAllChildren();

        virtual void OnExit() override {};

        const std::vector<std::unique_ptr<Node>>& GetChildren() const { return m_Children; }
        
    protected:
        std::vector<std::unique_ptr<Node>> m_Children;
        std::vector<std::unique_ptr<Node>>::iterator currentChildIndex;
    };
}

