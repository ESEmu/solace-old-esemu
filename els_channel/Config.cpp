#include "Config.hpp"
#include <string>

namespace els {

	namespace Config {

		std::string version = "V4.1112.6";

		// General

		unsigned int expRate = 1;
		unsigned int edRate = 1;
		int startMap = 20001; // ruben

		// Database

		std::string sqlhost = "37.187.250.78";
		std::string sqluser = "game";
		std::string sqlpass = "QIQluZVV78Fep2hS";
		std::string sqldb = "els";

		//Net

		short channelPort = 9300;
		short gamePort = 9301;
		std::string serverName = "Server 1";
		//std::string serverIP = "79.110.88.169";
		std::string serverIP = "37.187.250.78";

		//Channels

		int channels = 1;
		std::string channelName[1] = { "ESEmu1" };
		//std::string channelIP[1] = { "79.110.88.169" };
		std::string channelIP[1] = { "37.187.250.78" };

	}
}