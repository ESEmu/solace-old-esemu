#include "ItemDataProvider.hpp"
#include "LuaScript.hpp"

namespace els {

	namespace ItemDataProvider {

		void init() {

			std::cout << "Loading Items..." << std::endl;

			lua_getglobal(LuaScript::getLuaState(), "loadItems");
			
			if (lua_pcall(LuaScript::getLuaState(), 0, 0, 0) != 0) {
				std::cout << "Failed to load items" << std::endl;
			}
			
		}

	}

}