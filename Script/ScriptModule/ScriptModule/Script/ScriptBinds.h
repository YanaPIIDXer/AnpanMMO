#ifndef __SCRIPTBINDS_H__
#define __SCRIPTBINDS_H__

/**
 * Luaにバインドする関数群定義。
 * クラスのメンバ関数がバインドできない為の処置。
 * ※ここに定義された関数はC++側からは呼び出さない事。
 */

struct lua_State;

// メッセージ表示.
int ShowMessage_Call(lua_State *pState);

// 選択肢プッシュ
int PushSelection_Call(lua_State *pState);

// 選択肢を表示.
int ShowSelection_Call(lua_State *pState);

// フラグをセット。
int SetFlag_Call(lua_State *pState);

// フラグを取得.
int GetFlag_Call(lua_State *pState);

// クエストが進行中か？
int IsQuestActive_Call(lua_State *pState);

#endif		// #ifndef __SCRIPTBINDS_H__
