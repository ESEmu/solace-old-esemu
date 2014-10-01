#include "InventoryHandler.hpp"
#include "InventoryPacket.hpp"

namespace els {

	namespace InventoryHandler {

		void invDataReq(Connection* conn) {

			// 0x32 to send inv data
			
			// end with 0x31
			conn->sendPacket(InventoryPacket::invDataEnd().getPacket());

		}

		void moveItemReq(PacketReader pr, Connection* conn) {

			int srcInv = pr.readByte();
			int srcSlot = pr.readInt();
			int dstInv = pr.readByte();
			int dstSlot = pr.readInt();

			// checks if necessary, skipping first




		}

	}


}