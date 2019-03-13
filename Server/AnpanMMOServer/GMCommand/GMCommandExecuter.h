/**
 * @file GMCommandExecuter.h
 * @brief ＧＭコマンド実行クラス
 * @author YanaP
 */
#ifndef __GMCOMMANDEXECUTER_H__
#define __GMCOMMANDEXECUTER_H__

#include "GMCommandParser.h"
class Client;

/**
 * @class GMCommandExecuter
 * @brief ＧＭコマンド実行
 */
class GMCommandExecuter
{

public:		// 定数定義

	/**
	 * @enum EResult
	 * @brief 実行結果
	 */
	enum EResult
	{
		//! 成功
		Success,

		//! 無効なコマンド
		InvalidCommand,

		//! 無効な引数
		InvalidArg,

		//! 無効なアイテム
		InvalidItem,
	};

public:

	/**
	 * @brief コンストラクタ
	 * @param[in] pInClient クライアント
	 * @param[in] InParser パーサ
	 */
	GMCommandExecuter(Client *pInClient, const GMCommandParser &InParser);

	/**
	 * @brief デストラクタ
	 */
	~GMCommandExecuter() {}

	/**
	 * @fn u8 Execute()
	 * @brief 実行
	 * @return 実行結果
	 */
	u8 Execute();

private:

	// クライアント
	Client *pClient;

	// パーサ
	GMCommandParser Parser;


	// アイテム追加.
	u8 AddItem(const std::vector<GMCommandArg> &Args);

	// 経験値追加.
	u8 AddExp(const std::vector<GMCommandArg> &Args);

	// ＧＭメッセージ送信.
	u8 SendGMMessage(const std::vector<GMCommandArg> &Args);

};

#endif		// #ifndef __GMCOMMANDEXECUTER_H__
