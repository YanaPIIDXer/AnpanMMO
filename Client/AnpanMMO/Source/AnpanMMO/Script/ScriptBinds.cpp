#include "ScriptBinds.h"
#include "ScriptExecuterBase.h"
#include "ExecuterPool.h"
#include "lua.hpp"
#include "lauxlib.h"
#include "lualib.h"

// メッセージ表示.
int ShowMessage_Call(lua_State *pState)
{
	long Id = (long)luaL_checknumber(pState, -2);
	const char *pMessage = luaL_checkstring(pState, -1);
	ScriptExecuterBase * pExecuter = ExecuterPool::GetInstance().Get(Id);
	if (pExecuter == NULL) { return 0; }

	if (pExecuter == NULL) { return 0; }

	pExecuter->ShowMessage_Impl(pMessage);
	return 0;
}

// 選択肢をプッシュ
int PushSelection_Call(lua_State *pState)
{
	long Id = (long)luaL_checknumber(pState, -2);
	const char *pMessage = luaL_checkstring(pState, -1);
	ScriptExecuterBase * pExecuter = ExecuterPool::GetInstance().Get(Id);
	if (pExecuter == NULL) { return 0; }

	pExecuter->PushSelection_Impl(pMessage);
	return 0;
}

// 選択肢を表示.
int ShowSelection_Call(lua_State *pState)
{
	long Id = (long)luaL_checknumber(pState, -1);
	ScriptExecuterBase * pExecuter = ExecuterPool::GetInstance().Get(Id);
	if (pExecuter == NULL) { return 0; }

	pExecuter->ShowSelection_Impl();
	return 0;
}

// フラグをセット
int SetFlag_Call(lua_State *pState)
{
	long Id = (long)luaL_checknumber(pState, -2);
	int Flag = (int)luaL_checknumber(pState, -1);
	ScriptExecuterBase * pExecuter = ExecuterPool::GetInstance().Get(Id);
	if (pExecuter == NULL) { return 0; }

	pExecuter->SetFlag(Flag);
	return 0;
}

// フラグを取得.
int GetFlag_Call(lua_State *pState)
{
	long Id = (long) luaL_checknumber(pState, -2);
	int Flag = (int)luaL_checknumber(pState, -1);
	ScriptExecuterBase * pExecuter = ExecuterPool::GetInstance().Get(Id);
	if (pExecuter == NULL)
	{
		lua_pushboolean(pState, false);
		return 1;
	}

	bool bFlag = pExecuter->GetFlag(Flag);
	lua_pushboolean(pState, bFlag);

	return 1;
}

// クエストが進行中か？
int IsQuestActive_Call(lua_State *pState)
{
	long Id = (long)luaL_checknumber(pState, -2);
	u32 QuestId = (u32)luaL_checknumber(pState, -1);
	ScriptExecuterBase * pExecuter = ExecuterPool::GetInstance().Get(Id);
	if (pExecuter == NULL)
	{
		lua_pushboolean(pState, false);
		return 1;
	}

	bool bIsActive = pExecuter->IsQuestActive(QuestId);
	lua_pushboolean(pState, bIsActive);

	return 1;
}

// クエスト進行.
int ProgressQuest_Call(lua_State *pState)
{
	long Id = (long)luaL_checknumber(pState, -2);
	u32 QuestId = (u32)luaL_checknumber(pState, -1);
	ScriptExecuterBase * pExecuter = ExecuterPool::GetInstance().Get(Id);
	if (pExecuter == NULL) { return 0; }

	pExecuter->ProgressQuest(QuestId);

	return 0;
}

// クエストのステージ番号を取得.
int GetQuestStageNo_Call(lua_State *pState)
{
	long Id = (long)luaL_checknumber(pState, -2);
	ScriptExecuterBase * pExecuter = ExecuterPool::GetInstance().Get(Id);
	if (pExecuter == NULL)
	{
		lua_pushnumber(pState, 0);
		return 1;
	}

	u32 QuestId = (u32)luaL_checknumber(pState, -1);
	u32 StageNo = pExecuter->GetQuestStageNo(QuestId);

	lua_pushnumber(pState, StageNo);
	return 1;
}

// アイテムの個数を取得.
int GetItemCount_Call(lua_State *pState)
{
	long Id = (long)luaL_checknumber(pState, -2);
	ScriptExecuterBase * pExecuter = ExecuterPool::GetInstance().Get(Id);
	if (pExecuter == NULL)
	{
		lua_pushnumber(pState, 0);
		return 1;
	}

	u32 ItemId = (u32)luaL_checknumber(pState, -1);
	u32 Count = pExecuter->GetItemCount(ItemId);

	lua_pushnumber(pState, Count);
	return 1;
}

// アイテムを消費.
int ConsumeItem_Call(lua_State *pState)
{
	long Id = (long)luaL_checknumber(pState, -3);
	u32 ItemId = (u32)luaL_checknumber(pState, -2);
	u32 Count = (u32)luaL_checknumber(pState, -1);
	ScriptExecuterBase * pExecuter = ExecuterPool::GetInstance().Get(Id);
	if (pExecuter == NULL) { return 0; }

	pExecuter->ConsumeItem(ItemId, Count);

	return 0;
}

// クエスト受注.
int AcceptQuest_Call(lua_State *pState)
{
	long Id = (long)luaL_checknumber(pState, -2);
	u32 QuestId = (u32)luaL_checknumber(pState, -1);
	ScriptExecuterBase * pExecuter = ExecuterPool::GetInstance().Get(Id);
	if (pExecuter == NULL) { return 0; }

	pExecuter->AccpetQuest(QuestId);

	return 0;
}
