#pragma once
#include <TemplatedMessenger/Recipient.hpp>
#include "Messages.hpp"
#include <variant>
#include <iostream>

namespace ConsoleTestApp
{
	class StdOutMessageHandler : public TemplatedMessenger::Recipient<Messages>
	{
		void Recive(Messages const message) override
		{
			// Forward messages to handlers
			std::visit([this](auto&& arg) { handle(arg); }, message);
		}

		void handle(TestMessage1 message)
		{
			std::cout << "StdOutMessageHandler " << message << std::endl;
		}

		void handle(TestMessage2 message)
		{
			std::cout << "StdOutMessageHandler " << message << std::endl;
		}

		void handle(TestMessage3 message)
		{
			std::cout << "StdOutMessageHandler " << message << std::endl;
		}
	};


}