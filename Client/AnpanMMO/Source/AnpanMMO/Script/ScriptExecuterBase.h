/**
 * @file ScriptterBase.h
 * @brief スクリプト実行基底クラス
 * @author YanaP
 */
#ifndef __SCRIPTEXECUTERBASE_H__
#define __SCRIPTEXECUTERBASE_H__

#include <string>
#include "TypeDefs.h"
#include "lua.hpp"
#include "lauxlib.h"
#include "lualib.h"

/**
 * @class ANPANMMO_API ScriptExecuterBase
 * @brief スクリプト実行基底クラス
 */
class ANPANMMO_API ScriptExecuterBase
{

public:

	/**
	 * @brief コンストラクタ
	 */
	ScriptExecuterBase();

	/**
	 * @brief デストラクタ
	 */
	virtual ~ScriptExecuterBase();

	/**
	 * @fn void SetScriptDir(const char *pScriptDir)
	 * @brief スクリプトが格納されたディレクトリを設定
	 * @param[in] pScriptDir スクリプトが格納されたディレクトリ
	 */
	void SetScriptDir(const char *pScriptDir) { ScriptDir = pScriptDir; }

	/**
	 * @fn void ExecuteScript(const char *pScript)
	 * @brief スクリプトを実行
	 * @param[in] pScript スクリプトコード
	 */
	void ExecuteScript(const char *pScript);

	/**
	 * @fn void Resume()
	 * @brief スクリプトの実行を再開
	 */
	void Resume();

	/**
	 * @fn bool IsFinished() const
	 * @brief 終了しているか？
	 * @return 終了していたらtrueを返す
	 */
	bool IsFinished() const { return bIsFinished; }

	/**
	 * @virtual void ShowMessage_Impl(const std::string &Message)
	 * @brief メッセージを表示
	 * @details スクリプトを経由して呼ばれる。
	 * @param[in] Message メッセージ
	 */
	virtual void ShowMessage_Impl(const std::string &Message) = 0;

	/**
	 * @fn virtual void PushSelection_Impl(const std::string &Message)
	 * @brief 選択肢をプッシュ
	 * @details スクリプトを経由して呼ばれる。
	 * @param[in] Message メッセージ
	 */
	virtual void PushSelection_Impl(const std::string &Message) = 0;

	/**
	 * @fn virtual void ShowSelection_Impl
	 * @brief 選択肢を表示
	 * @details スクリプトを経由して呼ばれる。
	 */
	virtual void ShowSelection_Impl() = 0;

	/**
	 * @fn void OnSelectedSelection(int Index)
	 * @brief 選択肢が選択された
	 * @param[in] Index 選択された選択肢のインデックス
	 */
	void OnSelectedSelection(int Index);

	/**
	 * @fn virtual void SetFlag(int Flag)
	 * @brief フラグをセット
	 * @details スクリプトを経由して呼ばれる。
	 * @param[in] フラグＩＤ
	 */
	virtual void SetFlag(int Flag) = 0;

	/**
	 * @fn virtual bool GetFlag(int Flag)
	 * @brief フラグを取得
	 * @details スクリプトを経由して呼ばれる。
	 * @param[in] フラグＩＤ
	 * @return フラグが立っていればtrueを返す。
	 */
	virtual bool GetFlag(int Flag) = 0;

	/**
	 * @fn virtual bool IsQuestActive(u32 QusetId)
	 * @brief クエストが進行中か？
	 * @details スクリプトを経由して呼ばれる。
	 * @param[in] QuestId クエストＩＤ
	 * @return 進行中ならtrueを返す。
	 */
	virtual bool IsQuestActive(u32 QuestId) = 0;

	/**
	 * @fn virtual void ProgressQuest(u32 QuestId)
	 * @brief クエスト進行
	 * @details スクリプトを経由して呼ばれる。
	 * @params[in] QuestId クエストＩＤ
	 */
	virtual void ProgressQuest(u32 QuestId) = 0;

	/**
	 * @fn virtual u32 GetQuestStageNo(u32 QuestId)
	 * @brief クエストのステージ番号を取得
	 * @details スクリプトを経由して呼ばれる。
	 * @param[in] QuestId クエストＩＤ
	 * @return クエストのステージ番号
	 */
	virtual u32 GetQuestStageNo(u32 QuestId) = 0;

	/**
	 * @fn virtual u32 GetItemCount(u32 ItemId)
	 * @brief アイテム数を取得
	 * @details スクリプトを経由して呼ばれる。
	 * @param[in] ItemId アイテムＩＤ
	 * @return アイテムの個数
	 */
	virtual u32 GetItemCount(u32 ItemId) = 0;

	/**
	 * @fn virtual void ConsumeItem(u32 ItemId, u32 Count)
	 * @brief アイテムを消費
	 * @details スクリプトを経由して呼ばれる。
	 * @param[in] ItemId アイテムＩＤ
	 * @param[in] Count 個数
	 */
	virtual void ConsumeItem(u32 ItemId, u32 Count) = 0;

	/**
	 * @fn virtual void AcceptQuest(u32 QuestId)
	 * @brief クエスト受注
	 * @details スクリプトを経由して呼ばれる。
	 * @param[in] QuestId クエストＩＤ
	 */
	virtual void AcceptQuest(u32 QuestId) = 0;

	/**
	 * @fn virtual bool IsQuestClear(u32 QuestId)
	 * @brief クエストをクリアしているか？
	 * @details スクリプトを経由して呼ばれる。
	 * @param[in] QuestId クエストＩＤ
	 * @return クリアしていたらtrueを返す。
	 */
	virtual bool IsQuestClear(u32 QuestId) = 0;

	/**
	 * @fn virtual void ShowShop_Impl(u32 ShopId)
	 * @brief ショップ画面を表示
	 * @details スクリプトを経由して呼ばれる。
	 * @param[in] ShopId ショップＩＤ
	 */
	virtual void ShowShop_Impl(u32 ShopId) = 0;

protected:

	/**
	 * @fn virtual void onExecuteError(const std::string &ErrorMessage)
	 * @brief 実行エラーコールバック
	 * @param[in] ErrorMessage エラーメッセージ
	 */
	virtual void OnExecuteError(const std::string &ErrorMessage) = 0;

	/**
	 * @fn virtual void OnFinished()
	 * @brief 終了コールバック
	 */
	virtual void OnFinished() = 0;
	
	/**
	 * @fn virtual void ShowDebugMessage(const std::string Message)
	 * @brief デバッグメッセージを表示
	 * @param[in] Message メッセージ
	 */
	virtual void ShowDebugMessage(const std::string &Message) = 0;

	/**
	 * @fn virtual bool IsServer() const
	 * @brief サーバモードか？
	 * @details サーバでは使用しない機能を封印するために使用。
	 * @return サーバ側で起動していればtrueを返す。
	 */
	virtual bool IsServer() const = 0;

private:

	// Luaステート
	lua_State *pState;

	// コルーチン用State
	lua_State *pCoroutineState;

	// コルーチンの参照.
	int CoroutineRef;

	// スクリプトが格納されたディレクトリ
	std::string ScriptDir;

	// ID
	long Id;

	// 終了しているか？
	bool bIsFinished;


	// 関数群をバインド。
	void BindFunctions();

	// 関数をバインド。
	void BindFunction(lua_CFunction Func, const char *pName);

	// Stateを生成.
	void CreateState();

	// StateをClose
	void CloseState();

	// サーバモードで動かしている時は動かさないものをコメントアウト
	void CommentOutWithServerMode(std::string &Code);

	// 関数のコメントアウト
	void CommentOutFunction(std::string &Code, const std::string &FunctionName);

};

#endif		// #ifndef __SCRIPTEXECUTERBASE_H__
