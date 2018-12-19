#ifndef __SCRIPTEXECUTER_H__
#define __SCRIPTEXECUTER_H__

#include "ScriptExecuterBase.h"

class Client;

/**
 * スクリプト実行クラス
 */
class ScriptExecuter : public ScriptExecuterBase
{

public:

	// コンストラクタ
	ScriptExecuter();

	// デストラクタ
	virtual ~ScriptExecuter() {}

	// クライアントをセット。
	void SetClient(Client *pInClient) { pClient = pInClient; }

	// 読み込んで実行.
	void LoadAndRun(const std::string &FileName);

	// メッセージを表示.
	virtual void ShowMessage_Impl(const std::string &Message) {}

	// 選択肢がプッシュされた。
	virtual void PushSelection_Impl(const std::string &Message) {}

	// 選択肢表示.
	virtual void ShowSelection_Impl() {}

	// フラグをセット
	virtual void SetFlag(int Flag);

	// フラグを取得.
	virtual bool GetFlag(int Flag);

	// クエストが進行中か？
	virtual bool IsQuestActive(u32 QuestId);

	// クエスト進行.
	virtual void ProgressQuest(u32 QuestId);

	// クエストのステージ番号を取得.
	virtual u32 GetQuestStageNo(u32 QuestId);

	// アイテムの個数を取得.
	virtual u32 GetItemCount(u32 ItemId);

	// アイテム消費.
	virtual void ConsumeItem(u32 ItemId, u32 Count);

protected:

	// 実行エラー
	virtual void OnExecuteError(const std::string &ErrorMessage);

	// 処理が終了した。
	virtual void OnFinished();

	// デバッグメッセージを表示.
	virtual void ShowDebugMessage(const std::string &Message);

	// サーバモードか？
	virtual bool IsServer() const { return true; }


private:

	// クライアント
	Client *pClient;

};

#endif		// #ifndef __SCRIPTEXECUTER_H_
