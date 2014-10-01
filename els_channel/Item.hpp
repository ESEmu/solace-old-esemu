#pragma once
#include <string>
#include "Constants.hpp"

namespace els {

	class Item {
		
		private:
			int m_uniqueID;
			int m_itemID;
			int m_quantity;
			bool m_isEquip;
			int m_endurance;
			bool m_decorative;
			bool m_equipped;
			short m_pos;
			std::string m_expiry;

		public:
			Item(int uid, int itemid, int quantity, int endurance, bool decorative, bool equipped, bool isEquip, short pos, std::string expiry);
			~Item() { }
			int getUniqueID();
			int getItemID();
			int getQuantity();
			bool isEquip();
			int getEndurance();
			bool isDecorative();
			bool isEquipped();
			short getPosition();
			std::string getExpiry();
			void setQuantity(int quantity);
			void setEquipped(bool equipped);
			void setPosition(short pos);

	};

}