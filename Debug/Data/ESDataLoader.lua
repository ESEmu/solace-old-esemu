items = {}

--[[local function loadElswordData(destTbl, objName, funcName, indexField, dataFile)
 local newEnv = {}
 newEnv[objName] = {}
 newEnv[objName][funcName] = function(self, data)
  destTbl[data[indexField] ] = data
 end
 setmetatable(newEnv, {__index = function(tbl, idx) return _G[idx] end})
 local ldrFunc = loadfile(dataFile)
 setfenv(ldrFunc, newEnv)
 ldrFunc()
end
]]--

local function loadElswordData(destTbl, objName, funcName, indexField, dataFile)
 local newEnv = {}
 newEnv[objName] = {}
 newEnv[objName][funcName] = function(self, data)
  destTbl[data[indexField]] = data
 end
 setmetatable(newEnv, {__index = function(tbl, idx) return _G[idx] end})
 local s, err = loadfile(dataFile)
 if s then
  setfenv(s, newEnv)
  s, err = pcall(s)
 end
 if not s then
  print("Error when loading file " .. tostring(dataFile) .. ":" .. tostring(err))
 end
end

-- Loader functions. Because C++.

function loadItems()
	loadElswordData(items, "g_pItemManager", "AddItemTemplet", "m_ItemID", "Data/Item.lua")
end

-- Item functions, call using C++

local function itemExists(itemid)
	if (items[itemid] ~= nil) then
		return true
	end
	return false
end

function getEquipPosition(itemid)
	if (itemExists(itemid)) then
		return items[itemid].m_EqipPosition
	end
	return -1
end

function getItemType(itemid)
	if (itemExists(itemid)) then
		return items[itemid].m_ItemType
	end
	return -1
end



