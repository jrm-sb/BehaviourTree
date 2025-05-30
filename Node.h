#pragma once
#include <memory>
#include <string>
namespace BehaviourTree
{
	enum class Result
	{
		SUCCESS,
		FAILURE,
		RUNNING,
		INVALID
	};

	class Node
	{
	public:
		Node()
			: m_Name("EmptyNode"), m_Id(0), m_Index(0), m_Result(Result::INVALID) {}

		Node(const std::string& name)
			: m_Name(name), m_Id(0), m_Index(0), m_Result(Result::INVALID) {}

		Node(const std::string& name, int id, int index)
			: m_Name(name), m_Id(id), m_Index(index), m_Result(Result::INVALID) {}

		Node(const Node& other)
			: m_Name(other.m_Name), m_Id(other.m_Id), m_Index(other.m_Index), m_Result(other.m_Result) {}

		virtual ~Node() = default;

		virtual void AddChild(std::unique_ptr<Node> child) = 0;

		std::string GetName() const { return m_Name; }
		unsigned int GetId() const { return m_Id; }
		unsigned int GetIndex() const { return m_Index; }
		Result GetResult() const { return m_Result; }

		virtual Result UpdateResult() = 0;
		virtual Result Run();
		virtual void OnEnter() { m_Result = Result::RUNNING; }
		virtual void OnExit() = 0;

	protected:
		std::string m_Name;
		unsigned int m_Id;
		unsigned int m_Index;
		Result m_Result = Result::INVALID;
	};
}


