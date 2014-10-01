#include "Inventory.hpp"
#include "Item.hpp"
#include <utility>

namespace els {

	std::map<int, Item>* Inventory::getInventory() {
		return &m_items;
	}

	void Inventory::addItem(Item* item) {
		m_items.insert(std::make_pair(item->getItemID(), *item));
	}

	void Inventory::addNewItem(Item* item) {
		m_items.insert(std::make_pair(item->getItemID(), *item));
		// add db entry
	}

	Item* Inventory::getItem(int uItemID) {
		std::map<int, Item>::iterator item = m_items.find(uItemID);
		if (item != m_items.end()) {
			return &item->second;
		}
		else return nullptr;
	}

	int Inventory::getEquipped() {
		return m_equipped;
	}

	void Inventory::setEquipped(int equipped) {
		m_equipped = equipped;
	}

	short Inventory::getMaxSlots(int invType) {
		if (invType < 8 && invType != 0) {
			return m_maxSlots[invType];
		}
		else return -1;
	}

	void Inventory::setMaxSlots(int invType, int maxSlots) {
		if (invType < 8 && invType != -1) {
			m_maxSlots[invType] = maxSlots;
		}
	}

}