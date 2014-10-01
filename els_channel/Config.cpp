#include "Config.hpp"
#include <string>

namespace els {

	namespace Config {

		std::string version = "V4.1001.7";

		// General

		unsigned int expRate = 1;
		unsigned int edRate = 1;
		int startMap = 20001; // ruben

		// Database

		std::string sqlhost = "localhost";
		std::string sqluser = "root";
		std::string sqlpass = "";
		std::string sqldb = "els";

		//Net

		short channelPort = 9300;
		short gamePort = 9301;
		std::string serverName = "Server 1";
		std::string serverIP = "79.110.88.169";

		//Channels

		int channels = 1;
		std::string channelName[1] = { "Ruben1" };
		std::string channelIP[1] = { "79.110.88.169" };
	}
}