#include "DungeonHandler.hpp"
#include "Connection.hpp"
#include "PacketReader.hpp"
#include "CharacterPacket.hpp"
#include "DungeonPacket.hpp"
#include "DungeonDataProvider.hpp"
#include <string>
#include <chrono>
#include <thread>

namespace els {

	namespace DungeonHandler {

		void tutorialReq(PacketReader pr, Connection* conn) {

			pr.skipBytes(36);
			std::string serial = pr.readElsString();
			pr.skipBytes(26);
			int dungeonID = pr.readInt();
			
			conn->getPlayer()->setCurDungeon(dungeonID);

			conn->sendPacket(DungeonPacket::tutorialAck(serial, dungeonID, conn->getPlayer()).getPacket());

		}

		void tutorialStartReq(Connection* conn) {

			conn->sendPacket(DungeonPacket::tutorialStartAck().getPacket());
			conn->sendPacket(DungeonPacket::tutorialStartAck2(conn->getPlayer()).getPacket());
			conn->sendPacket(DungeonPacket::unknown_0x3A0(conn->getPlayer()).getPacket());
			conn->sendPacket(DungeonPacket::unknown_0x3A0(conn->getPlayer()).getPacket());
		}

		void dungeonLoadReq(PacketReader pr, Connection* conn) {

			int load = pr.readInt();

			conn->sendPacket(DungeonPacket::dungeonLoadAck().getPacket());
			conn->sendPacket(DungeonPacket::dungeonLoad(conn->getPlayer(), load).getPacket());

			if (load == 100) {
				conn->sendPacket(DungeonPacket::unknown_0x97().getPacket());
				conn->sendPacket(DungeonPacket::unknown_0x35A().getPacket());
				conn->sendPacket(DungeonPacket::dungeonEnter(conn->getPlayer()).getPacket());
			}

		}

		void unknown_0xB7(Connection* conn) {

			conn->sendPacket(CharacterPacket::unknown_0xF6(conn->getPlayer(), 11000).getPacket());
			conn->sendPacket(DungeonPacket::unknown_0xB8().getPacket());
			conn->sendPacket(DungeonPacket::unknown_0xB9().getPacket());

		}

		void unknown_0xBA(Connection* conn) {

			conn->sendPacket(DungeonPacket::unknown_0xBB().getPacket());
			conn->sendPacket(DungeonPacket::unknown_0xBC(conn->getPlayer()).getPacket());
			conn->sendPacket(DungeonPacket::unknown_0xBD().getPacket());

		}

		void unknown_0xBE(PacketReader pr, Connection* conn) {

			int d1 = pr.readByte();

			conn->sendPacket(DungeonPacket::unknown_0xBF().getPacket());
			conn->sendPacket(DungeonPacket::unknown_0xC0(d1).getPacket());

		}

		void unknown_0xC1(PacketReader pr, Connection* conn) {

			int d1 = pr.readByte();

			conn->sendPacket(DungeonPacket::unknown_0xC2().getPacket());
			conn->sendPacket(DungeonPacket::unknown_0xC3(d1).getPacket());

		}

		void unknown_0xC4(PacketReader pr, Connection* conn) {

			int d1 = pr.readShort(); // might be dungeon stage

			conn->sendPacket(DungeonPacket::unknown_0xC5().getPacket());
			conn->sendPacket(DungeonPacket::unknown_0xC6(d1).getPacket());

		}

		void unknown_0xB1(PacketReader pr, Connection* conn) {

			pr.skipBytes(8);
			int n1 = pr.readInt();
			int n2 = pr.readInt();
			pr.skipBytes(50);
			int n3 = pr.readInt();
			pr.skipBytes(17);
			int n4 = pr.readInt();

			conn->sendPacket(DungeonPacket::unknown_0xB2().getPacket());
			conn->sendPacket(DungeonPacket::unknown_0xB3(n1, n2, n3, n4).getPacket());

		}




		void dungeonListReq(PacketReader pr, Connection* conn) {

			int reg = pr.readInt();
			pr.skipBytes(4);
			int dID = pr.readInt();

			std::cout << "Region: " << reg << std::endl;
			std::cout << "DungeonID: " << dID << std::endl;
			conn->sendPacket(DungeonPacket::dungeonList(reg, dID).getPacket());
		}

		void dungeonEntryReq(PacketReader pr, Connection* conn) {

			int dID = pr.readInt();

			conn->sendPacket(DungeonPacket::dungeonEntryAck().getPacket());

			for (int i = 3; i > 0; i--) {
				conn->sendPacket(DungeonPacket::dungeonStartCountdown(i).getPacket());
				std::this_thread::sleep_for(std::chrono::seconds(1));
			}

			conn->sendPacket(DungeonPacket::dungeonPartyData(conn->getPlayer(), dID).getPacket());

		}

		void dungeonStageClear(Connection* conn) {

			conn->sendPacket(DungeonPacket::dungeonStageClearAck().getPacket());

		}
	}


}