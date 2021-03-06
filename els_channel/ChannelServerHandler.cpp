#include "ChannelServerHandler.hpp"
#include "AuthHandler.hpp"
#include "CharacterHandler.hpp"
#include "ChannelHandler.hpp"
#include "DungeonHandler.hpp"
#include "FieldHandler.hpp"
#include "InventoryHandler.hpp"
#include "MessageHandler.hpp"
#include "SkillHandler.hpp"
#include "PVPHandler.hpp"
#include <iomanip>

namespace els {

	namespace ChannelServerHandler {

		void handlePacket(PacketReader pr, Connection* c) {

			pr.skipBytes(32);
			unsigned short header = pr.readShort();
			pr.setLength(pr.readInt());
			pr.skipBytes(1);

			std::printf("RECV: 0x%x\n", header);
			std::cout << std::endl;

			switch (header) {
				case 0x27F: // user_login
					AuthHandler::userLogin(pr, c);
					break;
				case 0x4C3:
					AuthHandler::serverListReq(c);
					break;
				case 0x490:
					AuthHandler::channelListReq(c);
					break;
				case 0x1A:
					AuthHandler::verCheckReq(pr, c);
					break;
				case 0x1E:
					AuthHandler::channelLoginReq(pr, c);
					break;
				case 0x33:
					AuthHandler::unknown_0x33(c);
					break;
				case 0x1FC:
					AuthHandler::dateReq(c);
					break;
				case 0x37:
					AuthHandler::channelIPReq(c);
					break;
				case 0x485:
					AuthHandler::channelApproveReq(c);
					break;
				case 0x48E:
					AuthHandler::unknown_0x48D(c);
					break;
				case 0x48B:
					AuthHandler::checkCharNameReq(pr, c);
					break;
				case 0x489:
					AuthHandler::createCharReq(pr, c);
					break;
				case 0x240:
					AuthHandler::terminateConnection(c);
					break;
				case 0x28:
					CharacterHandler::playerDataReq(pr, c);
					break;
				case 0x30:
					InventoryHandler::invDataReq(c);
					break;
				case 0x232:
					std::cout << "MAP ID: " << pr.readInt() << std::endl;
					ChannelHandler::unknown_0x232(c);
					break;
				case 0x234:
					ChannelHandler::unknown_0x234(c);
					break;

				// PVP
				case 0x342:
					PVPHandler::pvpQueueReq(pr, c);
					break;
				case 0x345:
					PVPHandler::pvpQueueCancel(c);
					break;
				case 0x34A:
					PVPHandler::pvpApproveReq(pr, c);
					break;
				case 0x95:
					PVPHandler::pvpLoadReq(pr, c);
					break;

				// dungeon
				case 0x5D:
					DungeonHandler::tutorialReq(pr, c);
					break;
				case 0x8E:
					DungeonHandler::tutorialStartReq(c);
					break;
				//case 0x95: // used for PVP too o-o
				//	DungeonHandler::dungeonLoadReq(pr, c);
				//	break;
				case 0xB7:
					DungeonHandler::unknown_0xB7(c);
					break;
				case 0xBA:
					DungeonHandler::unknown_0xBA(c);
					break;
				case 0xBE:
					DungeonHandler::unknown_0xBE(pr, c);
					break;
				case 0xC1:
					DungeonHandler::unknown_0xC1(pr, c);
					break;
				case 0xC4:
					DungeonHandler::unknown_0xC4(pr, c);
					break;
				case 0xB1:
					DungeonHandler::unknown_0xB1(pr, c);
					break;

				// Storyline Dungeons
				case 0x389:
					DungeonHandler::dungeonListReq(pr, c);
					break;
				case 0x37C:
					DungeonHandler::dungeonEntryReq(pr, c);
					break;
				case 0x470:
					DungeonHandler::dungeonStageClear(c);
					break;
				case 0xB4:
					//DungeonHandler::dungeonDestroyObject(pr, c);
					break;

				//field
				case 0x371:
					FieldHandler::moveToField(pr, c);
					break;

				// inventory

				case 0x10A:
					InventoryHandler::moveItemReq(pr, c);
					break;
				case 0x110:
					InventoryHandler::discardItemReq(pr, c);
					break;
				case 0x562:
					InventoryHandler::openShopReq(pr, c);
					break;
				case 0x3D0:
					InventoryHandler::upgradeEquipEnq(c);
					break;
				case 0x1CF:
					InventoryHandler::upgradeEquipReq(pr, c);
					break;
				case 0x211:
					InventoryHandler::enchantEquipReq(pr, c);
					break;
				case 0x193:
					InventoryHandler::repairEquipReq(pr, c);
					break;
				case 0xF0:
					InventoryHandler::buyItemReq(pr, c);
					break;


				// skills
				case 0x127:
					SkillHandler::distributeSP(pr, c);
					break;
				case 0x129:
					SkillHandler::modifySkillSlots(pr, c);
					break;

				// world
				case 0x507:
					ChannelHandler::useCoBoExpress(pr, c);
					break;

				// messages
				case 0x88:
					MessageHandler::generalChatReq(c);
					break;
				
				// etc
				case 0xE9: // shit went wrong
					ChannelHandler::packetError(pr, c);
					break;
				case 0x238: // send 0x23B
					ChannelHandler::mapMovement(pr, c);
					break;
				default:
					std::printf("Unhandled: 0x%x\n", header);
			}

		}

		void handlePacket(PacketReader pr, GameConnection* c) {
			pr.skipBytes(24);
			unsigned short header = pr.readShort();
			pr.setLength(pr.readInt());
			pr.skipBytes(1);

			std::printf("RECV: 0x%x\n", header);

			switch (header) {
				case 0x239:
					ChannelHandler::gameConnStartReq(pr, c);
					break;

				default:
					std::printf("Unhandled: 0x%x\n", header);
			}

		}

	}

}