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
				auto val = std::get_if<T>(&m_Map[key]);
				if (val)
					return *val;
			}

			return {};
		}

		template<typename T>
		requires std::is_same_v<T, int> || std::is_same_v<T, float> || std::is_same_v<T, bool> || std::is_same_v<T, std::string>
		void SetValue(Key key, T value)
		{
			m_Map[key] = value;
		}

		int GetSize() const { return static_cast<int>(m_Map.size()); }

	private:
		std::unordered_map<Key, Value> m_Map;
	};
}

