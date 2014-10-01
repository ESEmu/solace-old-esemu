#include "ChannelHandler.hpp"
#include "ChannelPacket.hpp"
#include "CharacterPacket.hpp"
#include "World.hpp"
#include <iomanip>

namespace els {

	namespace ChannelHandler {

		void unknown_0x232(Connection* conn) {

			conn->sendPacket(ChannelPacket::unknown_0x2EB().getPacket());
			conn->sendPacket(ChannelPacket::unknown_0x102(0x30E58).getPacket());
			conn->sendPacket(ChannelPacket::unknown_0x102(0x123AE).getPacket());
			conn->sendPacket(ChannelPacket::unknown_0x429().getPacket());
			conn->sendPacket(ChannelPacket::unknown_0x1B9().getPacket());
			conn->sendPacket(ChannelPacket::unknown_0x233().getPacket());
			conn->sendPacket(CharacterPacket::unknown_0x3A0().getPacket());

		}

		void unknown_0x234(Connection* conn) {

			conn->sendPacket(ChannelPacket::unknown_0x23F().getPacket());
			conn->sendPacket(ChannelPacket::unknown_0x235().getPacket());
			//conn->sendPacket(CharacterPacket::unknown_0x39F().getPacket());

		}

		void packetError(PacketReader pr, Connection* conn) {

			for (int i = 0; i < pr.getLength(); i++) {
				std::cout << std::setbase(16) << std::setw(2) << std::setfill('0') << static_cast<int>(pr.getPacket()[i]) << " ";
			}

		}

		void useCoBoExpress(PacketReader pr, Connection* conn) {

			int map = pr.readInt();
			// deduct ed if using this is not free.
			conn->getPlayer()->setMap(map);
			conn->sendPacket(ChannelPacket::useCoBoExpressAck(conn->getPlayer()).getPacket());

		}

		void gameConnStartReq(PacketReader pr, GameConnection* conn) {
			
			// don't really need to read the packet
			Player* player = World::getClient(conn->getSocket().remote_endpoint().address().to_string())->first->getPlayer();
			conn->setPlayer(player);

			// do checks
			auto parties = World::getMap(player->getMap())->getParties();

			for (auto party : *parties) {
				if (party->getLeader()->getPlayerID() != player->getPlayerID())
					conn->sendPacket(ChannelPacket::mapPartyData(party).getPacket());
			}
			
		}



	}

}