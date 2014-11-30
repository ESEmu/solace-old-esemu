#include "PacketBuilder.hpp"
#include "Connection.hpp"

#pragma once

namespace els {

	namespace PVPPacket {

		PacketBuilder pvpQueueAck();
		PacketBuilder pvpQueue();
		PacketBuilder pvpStartReq();
		PacketBuilder pvpCountdown(int count);
		PacketBuilder pvpLoadAck();
		PacketBuilder pvpLoad(Player* player, int load);
		PacketBuilder pvpLoadDone();
		//PacketBuilder pvpEnter(Player* player);
		//PacketBuilder unknown_0x38D();

	}


}