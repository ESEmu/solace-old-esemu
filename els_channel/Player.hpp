#pragma once

#include "Inventory.hpp"
#include "SkillInventory.hpp"
#include "Constants.hpp"
#include <string>

namespace els {

	class Party;

	class Player {

		private:
			int m_accountID;
			int m_playerID;
			std::string m_name;
			std::string m_ip;
			std::string m_creationDate;
			std::string m_lastLogin;

			unsigned char m_level;
			int m_ed;
			int m_exp;
			int m_ap;
			Constants::unitType m_unitType;
			Constants::unitClass m_unitClass;

			int m_maxHP;
			int m_baseAttack;
			int m_baseMagicattack;
			int m_baseDef;
			int m_baseMagicDef;

			int m_map;
			int m_curDungeon;
			int m_curPVPmatch;

			Inventory m_inv;
			SkillInventory m_skillInv;
			
			Party* m_party;

		public:
			Player(int accid, int playerid, std::string name, std::string ip, std::string createDate, std::string lastLogin, int hp, int attack, int mattack, int def, int mdef, int map);
			Player() { }
			~Player();
			int getAccountID();
			int getPlayerID();
			std::string getName();
			std::string getIP();
			std::string getCreationDate();
			std::string getLastLogin();
			unsigned char getLevel();
			int getED();
			int getEXP();
			int getAP();
			Constants::unitType getUnitType();
			Constants::unitClass getUnitClass();
			int getMaxHP();
			int getBaseAttack();
			int getBaseMagicAttack();
			int getBaseDef();
			int getBaseMagicDef();
			int getMap();
			int getCurDungeon();
			int getCurPVPMatch();
			Inventory* getInv();
			SkillInventory* getSkillInv();
			Party* getParty();
			void setName(std::string name);
			void setLevel(unsigned char level);
			void setED(int ed);
			void setEXP(int exp);
			void setAP(int ap);
			void setUnitType(Constants::unitType unitType);
			void setUnitClass(Constants::unitClass unitClass);
			void setMaxHP(int hp);
			void setBaseAttack(int attack);
			void setBaseMagicAttack(int mattack);
			void setBaseDef(int def);
			void setBaseMagicDef(int mdef);
			void setMap(int map);
			void setCurDungeon(int dungeon);
			void setCurPVPMatch(int match);
			void setInventory(Inventory* inv);
			void setParty(Party* party);

			
		
	};

}