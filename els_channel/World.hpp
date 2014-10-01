#pragma once
#include <map>
#include "Map.hpp"
#include "Party.hpp"

namespace els {
	
	class Player;
	class Connection;
	class GameConnection;

	namespace World {
		
		// Clients
		static std::map<std::string, std::pair<Connection*, GameConnection*> > m_clients;
		bool hasClient(std::string ip);
		std::pair<Connection*, GameConnection*>* getClient(std::string ip);
		void addClient(std::string ip, Connection* conn);

		// World
		static std::map<int, Map> m_world;
		void addMap(Map map);
		Map* getMap(int mapid);

		// Parties
		static long long m_partyCount = 0;
		static std::map<long long, Party> m_parties;
		long long addParty(Party* party);
		void delParty(long long pid);
		Party* getParty(long long pid);

		// Dungeons
		
		// Fields

	}

}