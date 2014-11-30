#include "Config.hpp"
#include <string>

namespace els {

	namespace Config {

		std::string version = "V4.1112.6";

		// Database

		std::string sqlhost = "37.187.250.78";
		std::string sqluser = "game";
		std::string sqlpass = "QIQluZVV78Fep2hS";
		std::string sqldb = "els";

		//Net

		short loginport = 9400;
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