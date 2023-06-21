#pragma once
#include <TemplatedMessenger/Recipient.hpp>
#include "Messages.hpp"
#include <variant>
#include <iostream>

namespace ConsoleTestApp
{
	class StdErrMessageHandler : public TemplatedMessenger::Recipient<Messages>
	{
		inline static const std::string name = "StdErrMessageHandler";

		void Recive(Messages const message) override
		{
			// We dont realy need the handler function as we already have all the behaivor in the ostream operators
			std::visit([this](auto&& arg) { std::cerr << "StdErrMessageHandler " << arg << std::endl; }, message);
		}
	};
	inline std::ostream& operator<<(std::ostream& os, const StdErrMessageHandler& m)
	{
		os << "StdErrMessageHandler";
		return os;
	}
}