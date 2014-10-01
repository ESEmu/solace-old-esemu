#include "MessagePacket.hpp"

namespace els {

	namespace MessagePacket {

		PacketBuilder generalChatAck() {

			PacketBuilder pb;
			pb
				.writeInt(0)
				.finishPacket(0x89);

			return pb;

		}

	}


}