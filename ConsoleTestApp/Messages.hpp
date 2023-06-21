#pragma once
#include <iostream>

namespace ConsoleTestApp
{
	struct TestMessage1
	{
		double value;
	};
	inline std::ostream& operator<<(std::ostream& os, const TestMessage1& m)
	{
		os << "TestMessage1 " << m.value;
		return os;
	}

	struct TestMessage2
	{
		int value;
	};
	inline std::ostream& operator<<(std::ostream& os, const TestMessage2& m)
	{
		os << "TestMessage2 " << m.value;
		return os;
	}

	struct TestMessage3
	{
		std::string value;
	};
	inline std::ostream& operator<<(std::ostream& os, const TestMessage3& m)
	{
		os << "TestMessage3 " << m.value;
		return os;
	}

	using Messages = std::variant<TestMessage1, TestMessage2, TestMessage3>;
}