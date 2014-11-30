#include "ChannelPacket.hpp"

namespace els {

	namespace ChannelPacket {

		PacketBuilder unknown_0x2EB() {

			PacketBuilder pb;
			pb
				.writeInt(0)
				.writeInt(1)
				.writeInt(1)
				.writeInt(0)
				.finishPacket(0x2EB);
			return pb;

		}

		PacketBuilder unknown_0x102(int number) {

			PacketBuilder pb;
			pb
				.writeInt(0)
				.writeInt(number)
				.writeLong(0)
				.writeLong(0)
				.writeInt(0)
				.finishPacket(0x102);
			return pb;
		}

		PacketBuilder unknown_0x429() {

			PacketBuilder pb;
			pb
				.writeLong(0)
				.finishPacket(0x429);
			
			return pb;
		}

		PacketBuilder unknown_0x1B9() {

			PacketBuilder pb;
			pb
				.writeLong(0)
				.writeByte(1)
				.writeLong(0)
				.writeLong(0)
				.writeInt(0)
				.finishPacket(0x1B9);

			return pb;

		}



		PacketBuilder unknown_0x233() {

			PacketBuilder pb;
			pb
				.writeLong(0)
				.writeInt(0)
				.finishPacket(0x233);

			return pb;

		}

		PacketBuilder unknown_0x23F() {

			PacketBuilder pb;
			pb
				.writeInt(0)
				.finishPacket(0x23F);
			return pb;

		}

		PacketBuilder unknown_0x235() {

			PacketBuilder pb;
			pb
				.writeInt(0)
				.finishPacket(0x235);

			return pb;

		}

		PacketBuilder useCoBoExpressAck(Player* player) {

			PacketBuilder pb;
			pb
				.writeInt(0)
				.writeInt(player->getED())
				.writeInt(player->getMap())
				.finishPacket(0x508);

			return pb;

		}

		PacketBuilder mapPlayerData(Player* player) {

			PacketBuilder pb;

			pb
				.writeInt(player->getParty()->getSize())
				.writeInt(0);

			pb
				.writeInt(player->getPlayerID())
				.writeElsString(player->getName())
				.writeByte((unsigned char)player->getUnitClass())
				.writeByte(player->getLevel())
				.writeByte(1);

			pb.writeInt(player->getInv()->getQuantity(9));
			for (auto equip : *player->getInv()->getInventory()) {

				if (equip.second.isEquipped()) {
					pb
						.writeLong(equip.second.getUniqueID())
						.writeInt(equip.second.getItemID())
						.writeByte(9)
						.writeShort(equip.second.getPosition())
						.writeInt(0); // attributes
				}

			}

			pb
				.writeInt(0)
				.writeLong(0x455B499A42883E77)
				.writeLong(0)
				.writeLong(0)
				.writeLong(0)
				.writeLong(0)
				.writeLong(0)
				.writeLong(0)
				.writeLong(0)
				.writeLong(0)
				.writeLong(0)
				.writeLong(0);

				pb.finishGamePacket(0x237);

			return pb;
		}

		PacketBuilder mapMovementData(Player* player, PacketReader* pr) {

			PacketBuilder pb;
			pb
				.writeInt(0)
				.writeInt(player->getPlayerID());
			
			int i;
			for (i = 0; i < pr->getLength(); i++) {
				pb.writeByte(pr->getPacket()[i]);
			}

			pb.finishGamePacket(0x23B);

			return pb;


		}

	}


}