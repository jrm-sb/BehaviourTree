#pragma once
#include <algorithm>
#include <functional>
#include <iostream>
#include <initializer_list>
#include <memory>
#include <vector>

namespace Test
{
	struct TestEntry
	{
		std::string m_Name;
		std::function<void()> m_Func;
	};

	class TestRunner
	{
	public:
		static TestRunner& GetInstance()
		{
			static TestRunner instance;
			return instance;
		}

		void Register(std::string name, std::function<void()> func)
		{
			m_Tests.emplace_back(std::move(name), std::move(func));
		}

		void RunTests()
		{
			for (TestEntry& test : m_Tests)
			{
				std::string testDisplayName(test.m_Name);
				std::replace(std::begin(testDisplayName), std::end(testDisplayName), '_', ' ');

				std::cout << "Testing : " << test.m_Name << '\n';
				test.m_Func();
			}
		}

	private:
		std::vector<TestEntry> m_Tests;
	};

	static void RunAllTests()
	{
		TestRunner::GetInstance().RunTests();
	}
}

#define TEST(TestName) \
void TestName(); \
namespace \
{ \
    [[maybe_unused]] static auto TestRegistrationHandler_##TestName = []() \
    { \
        Test::TestRunner::GetInstance().Register(#TestName, []() { TestName(); }); \
        return nullptr; \
    } \
    (); \
} \
void TestName()

#define EXPECT(expression) \
{ \
    if (!(expression)) \
    { \
        printf("Test failed! %s::%d - expected '%s'\n", __func__, __LINE__, #expression); \
        return; \
    } \
}
