#include "World.hpp"
#include <thread>
#include <mutex>

namespace els {

	namespace World {

		bool hasClient(std::string ip) {
			if (m_clients.find(ip) != m_clients.end()) return true;
			else return false;
		}

		std::pair<Connection*, GameConnection*>* getClient(std::string ip) {
			return &m_clients[ip];
		}

		void addClient(std::string ip, Connection* conn) {
			m_clients.insert(make_pair(ip, std::make_pair(conn, nullptr)));
		}

		void addMap(Map map) {
			m_world.insert(std::make_pair(map.getID(), map));
		}

		Map* getMap(int mapid) {
			auto it = m_world.find(mapid);
			if (it != m_world.end()) return &it->second;
			else return nullptr;
		}

		std::mutex pmtx;

		long long addParty(Party* party) {
			pmtx.lock();
			m_partyCount++;
			long long a = m_partyCount;
			m_parties.insert(std::make_pair(m_partyCount, *party));
			m_parties[a].setID(m_partyCount);
			pmtx.unlock();
			return a;
		}

		void delParty(long long pid) {
			m_parties.erase(pid);
		}

		Party* getParty(long long pid) {
			return &m_parties[pid];
		}

	}


}