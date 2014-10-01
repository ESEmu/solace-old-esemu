#pragma once

#include <string>
#include <vector>
#include <iostream>

extern "C" {
	#include "lua.h"
	#include "lauxlib.h"
	#include "lualib.h"
}

namespace els {
	
	namespace LuaScript {
		
		void init();
		lua_State* getLuaState();

	}

}