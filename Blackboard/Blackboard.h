#pragma once
#include <concepts>
#include <optional>
#include <string>
#include <unordered_map>
#include <variant>
namespace BehaviourTree
{
	class Blackboard
	{
		using Value = std::variant<int, float, bool, std::string>;

	public:
		using Key = int;
		Blackboard() = default;

		bool Contains(Key key) const;

		template<typename T>
		std::optional<T> GetValue(Key key)
		{
			if (Contains(key))
			{
				if (const T* val = std::get_if<T>(&m_Map[key]))
					return *val;
			}

			return {};
		}

		void SetValue(Key key, Value value)
		{
			m_Map[key] = value;
		}

	private:
		std::unordered_map<Key, Value> m_Map;
	};
}

