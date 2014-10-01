#include "LoginPacket.hpp"
#include "PacketBuilder.hpp"
#include "Config.hpp"

namespace els {

	namespace LoginPacket {

		PacketBuilder serverAck(unsigned long long hmac_key, unsigned long long des_key) {
			std::cout << "SEND: SERVERACK" << std::endl;

			// SERVER_ACK
			// This packet is an exception

			PacketBuilder pb;
			pb
				.writeHeaderLong(0)
				.writeHeaderLong(-1)
				.writeHeaderLong(-1)
				.writeHeaderShort(1)
				.writeHeaderInt(0x26)
				.writeHeaderShort(0x0D)
				.writeHeaderByte(0x5B)
				.writeHeaderInt(8)
				.writeHeaderLong(hmac_key)
				.writeHeaderInt(8)
				.writeHeaderLong(des_key)
				.writeHeaderInt(1)
				.writeHeaderLong(0)
				.writeHeaderByte(1)
				.writeHeaderByte(2)
				.writeHeaderByte(2);
				
			return pb;
		}

		PacketBuilder loginAck() {

			std::cout << "SEND: 0x2D9" << std::endl;

			PacketBuilder pb;
			pb
				.writeShort(0)
				.writeByte(0x61)
				.writeByte(0x99)
				.writeInt(0)
				.finishPacket(0x2D9);
				
			return pb;
		}

		PacketBuilder sendSerial(std::string serial, std::string lastLogin, std::string user, std::string serial2, int accid) {

			std::cout << "SEND: 0x281 A" << std::endl;

			PacketBuilder pb;
			pb
				.writeLong(0)
				.writeInt(accid)
				.writeElsString(serial)
				.writeInt(0)
				.writeElsString(user)
				.writeElsString(serial2)
				.writeElsString(lastLogin)
				.finishPacket(0x281);

			return pb;
		}

		PacketBuilder sendSerial(std::string serial, std::string user, int accid) {

			std::cout << "SEND: 0x281 B" << std::endl;

			PacketBuilder pb;
			pb
				.writeLong(0)
				.writeInt(accid)
				.writeElsString(serial)
				.writeInt(0)
				.writeElsString(user)
				.writeInt(0)
				.finishPacket(0x281);

			return pb;

		}

		PacketBuilder serverListAck() {

			std::cout << "SEND: 0x4F4" << std::endl;

			PacketBuilder pb;
			pb
				.writeInt(0)
				.finishPacket(0x4F4);

			return pb;

		}

		PacketBuilder channelListAck() {

			std::cout << "SEND: 0x40" << std::endl;

			PacketBuilder pb;
			pb
				.writeInt(0)
				.finishPacket(0x40);

			return pb;

		}

		PacketBuilder serverList() {

			std::cout << "SEND: 0x4F5" << std::endl;

			PacketBuilder pb;
			pb
				.writeInt(1)
				.writeLong(0)
				.writeInt(0)
				.writeElsString(Config::serverName)
				.writeElsString(Config::serverIP)
				.writeInt(0x24B824B9)
				.writeByte(1)
				.finishPacket(0x4F5);

			return pb;

		}

		PacketBuilder channelList() {

			std::cout << "SEND: 0x41" << std::endl;

			PacketBuilder pb;
			pb
				.writeLong(Config::channels);

			int i;
			for (i = 1; i <= Config::channels; i++) {
				pb
					.writeInt(i)
					.writeInt(i * 3)
					.writeInt(i)
					.writeElsString(Config::channelName[i - 1])
					.writeInt(0)
					.writeElsString(Config::channelIP[i - 1])
					.writeInt(0x24542455)
					.writeInt(0x5DC)
					.writeInt(0xCC) // server load?
					.writeLong(0)
					.writeByte(1);
			}

			pb.writeInt(Config::channels);

			for (i = 1; i <= Config::channels; i++) {
				pb
					.writeInt(i)
					.writeByte(1)
					.writeInt(1)
					.writeInt(0x46)
					.writeLong(0);
			}

			pb.finishPacket(0x41);

			return pb;

		}

		PacketBuilder terminateConnectionAck() {

			std::cout << "SEND: 0x245" << std::endl;
			
			PacketBuilder pb;
			pb.finishPacket(0x245);

			return pb;

		}

	}

}