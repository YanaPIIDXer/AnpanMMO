/**
 * @file $FILE_NAME$
 * @brief パケットＩＤ定義.
 * @author NativePacketGenerator
 */

#ifndef __WORDCHECKSERVERPACKETID_H__
#define __WORDCHECKSERVERPACKETID_H__

/**
 * @brief パケットＩＤ定義.
 */
class WordCheckPacketID
{

public:

	/**
	 * @enum EID
	 * パケットＩＤ
	 */
	enum EID
	{
		//! ワードチェック要求パケット
		WordCheckChatRequest = 0x80,
		//! ワードチェック結果パケット
		WordCheckChatResult = 0x81,
		
	};
};

#endif		// #ifndef __WORDCHECKSERVERPACKETID_H__
