#include "LoginServerHandler.hpp"
#include "LoginHandler.hpp"
#include <iostream>

namespace els {

	namespace LoginServerHandler {

		void handlePacket(PacketReader pr, Connection* c) {
			
			pr.skipBytes(32);
			unsigned short header = pr.readShort();
			pr.skipBytes(5);

			std::printf("RECV: 0x%x\n", header);

			switch (header) {
				case 0x280: // user_login
					LoginHandler::userLogin(pr, c);
					break;
				case 0x4F3:
					LoginHandler::serverListReq(c);
					break;
				case 0x3F:
					LoginHandler::channelListReq(c);
					break;
				case 0x244:
					LoginHandler::terminateConnection(c);
					break;

			}

		}

	}
}