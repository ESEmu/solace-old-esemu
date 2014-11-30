#include "PVPPacket.hpp"
#include "PVP.hpp"

namespace els {

	namespace PVPPacket {

		PacketBuilder pvpQueueAck() {
			
			PacketBuilder pb;
			pb
				.writeInt(0)
				.finishPacket(0x343);

			return pb;
		}

		PacketBuilder pvpQueue() {

			PacketBuilder pb;
			pb
				.writeInt(90) // estimated waiting time. 1min 30s. 2000s is unk
				.finishPacket(0x344);

			return pb;
		}

		PacketBuilder pvpStartReq() {

			PacketBuilder pb;
			pb
				.writeLong(0x105)
				.finishPacket(0x349);

			return pb;

		}

		PacketBuilder pvpCountdown(int count) {

			PacketBuilder pb;
			pb
				.writeLong(0)
				.writeByte(count)
				.writeByte(0)
				.finishPacket(0x38E);

			return pb;
		}

		PacketBuilder pvpLoadAck() {

			PacketBuilder pb;
			pb
				.writeInt(0)
				.finishPacket(0x96);

			return pb;
		}

		PacketBuilder pvpLoad(Player* player, int load) {

			PacketBuilder pb;
			pb
				.writeInt(0)
				.writeInt(player->getPlayerID())
				.writeInt(load)
				.finishPacket(0x97);

			return pb;

		}

		PacketBuilder pvpLoadDone() {
			
			PacketBuilder pb;
			pb.finishPacket(0x98);
			return pb;

		}


	}



}