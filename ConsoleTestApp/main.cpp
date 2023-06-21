#include <TemplatedMessenger/Messenger.hpp>
#include <string>
#include <variant>
#include <iostream>
#include "Messages.hpp"
#include "StdErrMessageHandler.hpp"
#include "StdOutMessageHandler.hpp"

using namespace TemplatedMessenger;
using namespace ConsoleTestApp;


Messenger<Messages> messenger;

int main(int cargs, char** vargs)
{
	{
		auto recipientStdOut = std::make_shared<StdOutMessageHandler>();
		auto recipientStdErr = std::make_shared<StdErrMessageHandler>();
		messenger.Register(recipientStdOut);
		messenger.Register(recipientStdErr);

		messenger.send(TestMessage1{ 1.2 });
		messenger.send(TestMessage2{ 3 });
		messenger.send(TestMessage3{ "String Message" });
	}

	messenger.send(TestMessage3{ "all my recipients are gone" });
	std::cout << "Number of Active Recipients " << messenger.count_recipients() << std::endl;
}