#include "MapDataProvider.hpp"
#include <fstream>
#include <utility>
#include <iostream>

namespace els {

	namespace MapDataProvider {

		void loadMaps() {

			std::cout << "Loading Maps..." << std::endl;
			/*
			std::ifstream fin("Data/World/Map.txt");
			int id;

			while (fin >> id) {
				Map map(id);
				World::addMap(map);
			}
			*/
			for (int i = 20000; i < 20008; i++) {
				Map map(i);
				World::addMap(map);
			}

			for (int i = 30000; i < 30007; i++) {
				Map map(i);
				World::addMap(map);
			}

			//fin.close();

		}

	}

}