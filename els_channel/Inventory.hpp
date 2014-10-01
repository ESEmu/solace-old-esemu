#pragma once
#include "Item.hpp"
#include <map>

namespace els {

	class Inventory {
		
		private:
			std::map<int, Item> m_items;
			int m_equipped;
			short m_maxSlots[8];


		public:
			std::map<int, Item>* getInventory();
			void addItem(Item* item);
			void addNewItem(Item* item);
			Item* getItem(int uItemID);
			int getEquipped();
			void setEquipped(int equipped);
			short getMaxSlots(int invType);
			void setMaxSlots(int invType, int maxSlots);

	};


}