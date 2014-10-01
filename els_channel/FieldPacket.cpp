#include "FieldPacket.hpp"
#include "MapDataProvider.hpp"
#include "Config.hpp"
#include "World.hpp"

namespace els {

	namespace FieldPacket {

		PacketBuilder playerList(Player* player) { // 0x372

			PacketBuilder pb;
			pb
				.writeInt(0)
				.writeInt(player->getMap())
				.writeInt(1)
				.writeShort(0)
				.writeInt(1)
				.writeByte(0)
				.writeShort(7)
				.writeByte(0)
				.writeShort(7)
				.writeByte(0)
				.writeInt(8)
				.writeInt(0)
				.writeByte(0)
				.writeInt(6)
				.writeByte(1)
				.writeShort(0)
				.writeInt(4)

				// number of players
				.writeByte((int)World::getMap(player->getMap())->getPlayers()->size())
				.writeElsString(Config::serverIP)
				.writeShort(0x238D) // server port o.o
				.writeShort(0)
				.writeByte(0)
				.writeInt(-1)
				.writeLong(0)
				.writeLong(1)
				.writeLong(0)
				.writeByte(0)
				.writeInt(player->getMap())
				.writeInt(0)
				.writeInt(0)
				.writeByte(0x0C) // ???
				.writeShort(5)
				.writeShort(1) // ???
				.writeShort(0); // ???

			// INCOMPLETE


			return pb;
		}


	}


}