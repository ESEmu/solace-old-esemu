#include "MessageHandler.hpp"
#include "MessagePacket.hpp"

namespace els {

	namespace MessageHandler {

		void generalChatReq(Connection* conn) {

			conn->sendPacket(MessagePacket::generalChatAck().getPacket());

		}


	}



}