#include "Map.hpp"
#include <cassert>

namespace els {

	Map::Map(int id) : m_id(id) { }

	int Map::getID() {
		return m_id;
	}

	std::set<Player*>* Map::getPlayers() {
		return &m_players;
	}

	void Map::addPlayer(Player* player) {
		m_players.insert(player);
	}

	void Map::removePlayer(Player* player) {
		m_players.erase(player);
	}

	void Map::addParty(Party* party) {
		m_parties.insert(party);
	}

	void Map::delParty(Party* party) {
		if (m_parties.find(party) != m_parties.end()) {
			m_parties.erase(party);
		}
	}

	std::set<Party*>* Map::getParties() {
		return &m_parties;
	}

}