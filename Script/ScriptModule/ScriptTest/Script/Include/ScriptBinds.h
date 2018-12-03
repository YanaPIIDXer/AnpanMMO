#ifndef __SCRIPTBINDS_H__
#define __SCRIPTBINDS_H__

/**
 * Luaにバインドする関数群定義。
 * クラスのメンバ関数がバインドできない為の処置。
 * ※ここに定義された関数はC++側からは呼び出さない事。
 */

<<<<<<< HEAD
#include "lua.hpp"
#include "lauxlib.h"
#include "lualib.h"
=======
struct lua_State;
>>>>>>> f1f4ab27137ad863d811b0c040c52513571dcbf8

// メッセージ表示.
int ShowMessage_Call(lua_State *pState);

#endif		// #ifndef __SCRIPTBINDS_H__
