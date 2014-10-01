#include "Item.hpp"
#include "Constants.hpp"

namespace els {

	Item::Item(int uid, int itemid, int quantity, int endurance, bool decorative, bool equipped, bool isEquip, short pos, std::string expiry) :
		m_uniqueID(uid), m_itemID(itemid), m_quantity(quantity), m_endurance(endurance), m_decorative(decorative),
		m_equipped(equipped), m_isEquip(isEquip), m_pos(pos), m_expiry(expiry)
	{}

	int Item::getUniqueID() {
		return m_uniqueID;
	}

	int Item::getItemID() {
		return m_itemID;
	}

	int Item::getQuantity() {
		return m_quantity;
	}

	bool Item::isEquip() {
		return m_isEquip;
	}

	int Item::getEndurance() {
		return m_endurance;
	}

	bool Item::isDecorative() {
		return m_decorative;
	}

	bool Item::isEquipped() {
		return m_equipped;
	}

	short Item::getPosition() {
		return m_pos;
	}
	
	std::string Item::getExpiry() {
		return m_expiry;
	}

	void Item::setQuantity(int quantity) {
		m_quantity = quantity;
	}

	void Item::setEquipped(bool equipped) {
		m_equipped = equipped;
	}

	void Item::setPosition(short pos) {
		m_pos = pos;
	}

}