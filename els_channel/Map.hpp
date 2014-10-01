#pragma once

#include "Player.hpp"
#include <set>

namespace els {

	class Map {

		private:
			int m_id;
			std::set<Player*> m_players;
			std::set<Party*> m_parties;

		public:
			Map(int id);
			Map() { }
			~Map() { }
			int getID();
			std::set<Player*>* getPlayers();
			void addPlayer(Player* player);
			void removePlayer(Player* player);
			void addParty(Party* party);
			void delParty(Party* party);
			std::set<Party*>* getParties();


	};


}