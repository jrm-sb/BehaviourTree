#pragma once
#include <memory>
#include <vector>

#include "Collection.h"
#include "Decorator/Decorator.h"
#include "Task/Task.h"

namespace BehaviourTree
{
    class Composite : public Collection
    {
    public:
        Composite() : Collection("CompositeNode") {}
        Composite(const std::string& name) : Collection(name) {}

        virtual ~Composite() = default;

        void AddChild(std::unique_ptr<Node> child);
        void RemoveChild(std::unique_ptr<Node> child);
        void RemoveAllChildren();

        const std::vector<std::unique_ptr<Node>>& GetChildren() const { return m_Children; }

        virtual Result Run() override = 0;
        virtual void OnExit() override {};
        
    protected:
        std::vector<std::unique_ptr<Node>> m_Children;
    };
}

