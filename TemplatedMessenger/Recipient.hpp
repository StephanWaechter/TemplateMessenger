#pragma once

namespace TemplatedMessenger
{
	template<class MessageTypes> class Recipient
	{
	public:
		virtual void Recive(MessageTypes const message) = 0;
	};
};