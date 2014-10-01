#pragma once
#include "Connection.hpp"
#include "PacketReader.hpp"

namespace els {

	namespace InventoryHandler {

		void invDataReq(Connection* conn);
		void moveItemReq(PacketReader pr, Connection* conn);


	}


}