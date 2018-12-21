/**
 * @file $FILE_NAME$
 * @brief パケットＩＤ定義.
 * @author NativePacketGenerator
 */

#ifndef __CACHESERVERPACKETID_H__
#define __CACHESERVERPACKETID_H__

/**
 * @brief パケットＩＤ定義.
 */
class CachePacketID
{

public:

	enum EID
	{
		//! ログインリクエスト
		CacheLogInRequest = 0x40,
		//! ログインリクエスト結果
		CacheLogInResult = 0x41,
		//! キャラクタ作成リクエスト
		CacheCreateCharacterRequest = 0x42,
		//! キャラクタ作成結果
		CacheCreateCharacterResult = 0x43,
		//! キャラクタ情報リクエスト
		CacheCharacterDataRequest = 0x44,
		//! キャラクタ情報レスポンス
		CacheCharacterDataResult = 0x45,
		//! スキルリストリクエスト
		CacheSkillListRequest = 0x46,
		//! スキルリストレスポンス
		CacheSkillListResponse = 0x47,
		//! スクリプトフラグリクエスト
		CacheScriptFlagRequest = 0x48,
		//! スクリプトフラグレスポンス
		CacheScriptFlagResponse = 0x49,
		//! スクリプトフラグ保存リクエスト
		CacheScriptFlagSaveRequest = 0x4A,
		//! スキルリスト保存リクエスト
		CacheSaveSkillListRequest = 0x4B,
		//! スキルリスト保存レスポンス
		CacheSaveSkillListResponse = 0x4C,
		//! スキルツリーリクエスト
		CacheSkillTreeRequest = 0x4D,
		//! スキルツリーレスポンス
		CacheSkillTreeResponse = 0x4E,
		//! スキルツリー開放
		CacheOpenSkillTree = 0x4F,
		//! キャラクタ保存リクエスト
		CacheCharacterDataSave = 0x50,
		//! ゴールド保存リクエスト
		CacheGoldSave = 0x51,
		//! アイテムリストリクエスト
		CacheItemListRequest = 0x52,
		//! アイテムリストレスポンス
		CacheItemListResponse = 0x53,
		//! アイテム数変化リクエスト
		CacheItemCountChangeRequest = 0x54,
		//! アイテムショートカットリクエスト
		CacheItemShortcutRequest = 0x55,
		//! アイテムショートカットレスポンス
		CacheItemShortcutResponse = 0x56,
		//! アイテムショートカット保存リクエスト
		CacheSaveItemShortcutRequest = 0x57,
		//! アイテムショートカット保存レスポンス
		CacheSaveItemShortcutResponse = 0x58,
		//! クエストデータリクエスト
		CacheQuestDataRequest = 0x59,
		//! クエストデータレスポンス
		CacheQuestDataResponse = 0x5A,
		//! クエストデータ保存リクエスト
		CacheSaveQuestDataRequest = 0x5B,
		//! クエスト破棄リクエスト
		CacheQuestRetireRequest = 0x5C,
		//! アクティブクエスト保存リクエスト
		CacheSaveActiveQuestRequest = 0x5D,
		
	};
};

#endif		// #ifndef __CACHESERVERPACKETID_H__
