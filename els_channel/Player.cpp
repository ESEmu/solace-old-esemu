#include "Player.hpp"
#include "Inventory.hpp"
#include "World.hpp"
#include <iostream>


namespace els {

	Player::Player(int accid, int playerid, std::string name, std::string ip, std::string createDate, std::string lastLogin, int hp, int attack, int mattack, int def, int mdef, int map) :
		m_accountID(accid), m_playerID(playerid), m_name(name), m_ip(ip), m_creationDate(createDate), m_lastLogin(lastLogin),
		m_maxHP(hp), m_baseAttack(attack), m_baseMagicattack(mattack), m_baseDef(def), m_baseMagicDef(mdef), m_map(map) { }

	Player::~Player() {
		/*
		std::cout << "CALLED!" << std::endl;
		if (m_map >= 20000 && m_map <= 20008 || m_map >= 30000 && m_map <= 30007)
			// replace this with something like (isValidMap)
			World::getMap(m_map)->removePlayer(m_playerID);
		*/
	}

	int Player::getAccountID() {
		return m_accountID;
	}

	int Player::getPlayerID() {
		return m_playerID;
	}

	std::string Player::getName() {
		return m_name;
	}

	std::string Player::getIP() {
		return m_ip;
	}

	std::string Player::getCreationDate() {
		return m_creationDate;
	}

	std::string Player::getLastLogin() {
		return m_lastLogin;
	}

	unsigned char Player::getLevel() {
		return m_level;
	}

	int Player::getED() {
		return m_ed;
	}

	int Player::getEXP() {
		return m_exp;
	}

	int Player::getAP() {
		return m_ap;
	}

	Constants::unitType Player::getUnitType() {
		return m_unitType;
	}

	Constants::unitClass Player::getUnitClass() {
		return m_unitClass;
	}

	int Player::getMaxHP() {
		return m_maxHP;
	}

	int Player::getBaseAttack() {
		return m_baseAttack;
	}

	int Player::getBaseMagicAttack() {
		return m_baseMagicattack;
	}

	int Player::getBaseDef() {
		return m_baseDef;
	}

	int Player::getBaseMagicDef() {
		return m_baseMagicDef;
	}

	int Player::getMap() {
		return m_map;
	}

	int Player::getCurDungeon() {
		return m_curDungeon;
	}

	int Player::getCurPVPMatch() {
		return m_curPVPmatch;
	}

	Inventory* Player::getInv() {
		return &m_inv;
	}

	SkillInventory* Player::getSkillInv() {
		return &m_skillInv;
	}

	Party* Player::getParty() {
		return m_party;
	}

	void Player::setName(std::string name) {
		m_name = name;
	}

	void Player::setLevel(unsigned char level) {
		m_level = level;
	}

	void Player::setED(int ed) {
		m_ed = ed;
	}

	void Player::setEXP(int exp) {
		m_exp = exp;
	}

	void Player::setAP(int ap) {
		m_ap = ap;
	}

	void Player::setUnitType(Constants::unitType unitType) {
		m_unitType = unitType;
	}

	void Player::setUnitClass(Constants::unitClass unitClass) {
		m_unitClass = unitClass;
	}
	
	void Player::setMaxHP(int hp) {
		m_maxHP = hp;
	}
	
	void Player::setBaseAttack(int attack) {
		m_baseAttack = attack;
	}

	void Player::setBaseMagicAttack(int mattack) {
		m_baseMagicattack = mattack;
	}

	void Player::setBaseDef(int def) {
		m_baseDef = def;
	}

	void Player::setBaseMagicDef(int mdef) {
		m_baseMagicDef = mdef;
	}

	void Player::setMap(int map) {
		m_map = map;
	}

	void Player::setInventory(Inventory* inv) {
		m_inv = *inv;
	}

	void Player::setCurDungeon(int dungeon) {
		m_curDungeon = dungeon;
	}

	void Player::setCurPVPMatch(int match) {
		m_curPVPmatch = match;
	}

	void Player::setParty(Party* party) {
		m_party = party;
	}

}