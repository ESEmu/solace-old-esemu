#include "InventoryPacket.hpp"

namespace els {

	namespace InventoryPacket {

		PacketBuilder invDataEnd() {

			PacketBuilder pb;
			pb
				.writeInt(0)
				.writeByte(1)
				.writeByte(1)
				.finishPacket(0x31);

			return pb;
		}


	}


}