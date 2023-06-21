#pragma once
#include "Recipient.hpp"
#include <queue>
#include <list>
#include <memory>

namespace TemplatedMessenger
{
	template<class MessageTypes> class Messenger
	{
	public:
		using Recipient = Recipient<MessageTypes>;
		void Register(std::weak_ptr<Recipient> recipient)
		{
			recipients_.push_back(recipient);
		}

		void Unregister(std::weak_ptr<Recipient> const& recipient)
		{
			recipients_.remove(recipient);
		}

		void send(MessageTypes const message)
		{
			// TODO: Store iterator in range based loop and remove after loop end so we only iterate once;
			recipients_.remove_if([](auto& recipient) { return recipient.lock() == nullptr; });
			for (auto& recipient : recipients_)
			{
				auto ptr = recipient.lock();
				if(ptr)
				{
					ptr->Recive(message);
				}
			};
		}

		inline int count_recipients() { return recipients_.size(); }
	private:
		std::list<std::weak_ptr<Recipient>> recipients_;
	};
}