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

-- Loader functions

function loadItems()
	loadElswordData(items, "g_pItemManager", "AddItemTemplet", "m_ItemID", "Data/Item.lua")
end

-- Item functions

function getEquipPosition(itemid)
  return items[itemid] and items[itemid].m_EqipPosition or -1
end

function getItemLevel(itemid)
  return items[itemid] and items[itemid].m_UseLevel or 0
end

function getItemType(itemid)
	return items[itemid] and items[itemid].m_ItemType or -1
end

function getItemGrade(itemid)
	return items[itemid] and items[itemid].m_ItemGrade or -1
end

function isDecorative(itemid)
	return (items[itemid] and items[itemid].m_bFashion) == true
end
