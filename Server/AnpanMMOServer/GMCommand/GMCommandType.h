/**
 * @file GMCommandType.h
 * @brief ＧＭコマンドの種類定義
 * @author YanaP
 */
#ifndef __GMCOMMANDTYPE_H__
#define __GMCOMMANDTYPE_H__

/**
 * @class EGOCommandType
 * @brief ＧＭコマンドの種類
 */
class EGMCommandType
{

public:

	/**
	 * @enum EType
	 * @brief 種類
	 */
	enum EType
	{
		//! 無効なコマンド
		Invalid,

		//! アイテム追加
		AddItem,

		//! 経験値追加
		AddExp,

		//! GMメッセージ
		GMMessage,
	};

};

#endif			// #ifndef __GMCOMMANDTYPE_H__
