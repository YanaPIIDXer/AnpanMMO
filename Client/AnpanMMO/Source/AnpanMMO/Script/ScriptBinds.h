/**
 * @file ScriptBinds.h
 * @brief Luaにバインドする関数群定義。
 * @details クラスのメンバ関数がバインドできない為の処置。
 *			※ここに定義された関数はC++側からは呼び出さない事。
 * @author YanaP
 */
#ifndef __SCRIPTBINDS_H__
#define __SCRIPTBINDS_H__

struct lua_State;

/**
 * @fn int ShowMessage_Call(lua_State *pState)
 * @brief メッセージ表示
 * @details スクリプトにバインドされて呼び出される。
 * @param[in] pState Luaステート
 * @return 戻り値の数
 */
int ShowMessage_Call(lua_State *pState);

/**
 * @fn int PushSelection_Call(lua_State *pState)
 * @brief 選択肢をプッシュ
 * @details スクリプトにバインドされて呼び出される。
 * @param[in] pState Luaステート
 * @return 戻り値の数
 */
int PushSelection_Call(lua_State *pState);


/**
 * @fn int ShowSelection_Call(lua_State *pState)
 * @brief 選択肢表示
 * @details スクリプトにバインドされて呼び出される。
 * @param[in] pState Luaステート
 * @return 戻り値の数
 */
int ShowSelection_Call(lua_State *pState);

/**
 * @fn int SetFlag_Call(lua_State *pState)
 * @brief フラグをセット
 * @details スクリプトにバインドされて呼び出される。
 * @param[in] pState Luaステート
 * @return 戻り値の数
 */
int SetFlag_Call(lua_State *pState);

/**
 * @fn int GetFlag_Call(lua_State *pState)
 * @brief フラグを取得
 * @details スクリプトにバインドされて呼び出される。
 * @param[in] pState Luaステート
 * @return 戻り値の数
 */
int GetFlag_Call(lua_State *pState);

/**
 * @fn int IsQuestActive_Call(lua_State *pState)
 * @brief クエストが進行中か？
 * @details スクリプトにバインドされて呼び出される。
 * @param[in] pState Luaステート
 * @return 戻り値の数
 */
int IsQuestActive_Call(lua_State *pState);

/**
 * @fn int ProgressQuest_Call(lua_State *pState)
 * @brief クエストを進行
 * @details スクリプトにバインドされて呼び出される。
 * @param[in] pState Luaステート
 * @return 戻り値の数
 */
int ProgressQuest_Call(lua_State *pState);

/**
 * @fn int GetQuestStageNo_Call(lua_State *pState)
 * @brief クエストのステージ番号を取得
 * @details スクリプトにバインドされて呼び出される。
 * @param[in] pState Luaステート
 * @return 戻り値の数
 */
int GetQuestStageNo_Call(lua_State *pState);

/**
 * @fn int GetItemCount_Call(lua_State *pState)
 * @brief アイテムの個数を取得
 * @details スクリプトにバインドされて呼び出される。
 * @param[in] pState Luaステート
 * @return 戻り値の数
 */
int GetItemCount_Call(lua_State *pState);

/**
 * @fn int ConsumeItem_Call(lua_State *pState)
 * @brief アイテムを消費
 * @details スクリプトにバインドされて呼び出される。
 * @param[in] pState Luaステート
 * @return 戻り値の数
 */
int ConsumeItem_Call(lua_State *pState);

/**
 * @fn int AcceptQuest_Call(lua_State *pState)
 * @brief クエストを受注
 * @details スクリプトにバインドされて呼び出される。
 * @param[in] pState Luaステート
 * @return 戻り値の数
 */
int AcceptQuest_Call(lua_State *pState);

/**
 * @fn int IsQuestClear_Call(lua_State *pState)
 * @brief クエストをクリアしているか？
 * @details スクリプトにバインドされて呼び出される。
 * @param[in] pState Luaステート
 * @return 戻り値の数
 */
int IsQuestClear_Call(lua_State *pState);

#endif		// #ifndef __SCRIPTBINDS_H__
