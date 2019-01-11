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

	/**
	 * @enum EID
	 * パケットＩＤ
	 */
	enum EID
	{
		//! ログインリクエストパケット
		CacheLogInRequest = 0x40,
		//! ログインリクエスト結果パケット
		CacheLogInResult = 0x41,
		//! キャラクタ作成リクエストパケット
		CacheCreateCharacterRequest = 0x42,
		//! キャラクタ作成結果パケット
		CacheCreateCharacterResult = 0x43,
		//! キャラクタ情報リクエストパケット
		CacheCharacterDataRequest = 0x44,
		//! キャラクタ情報レスポンスパケット
		CacheCharacterDataResult = 0x45,
		//! スキルリストリクエストパケット
		CacheSkillListRequest = 0x46,
		//! スキルリストレスポンスパケット
		CacheSkillListResponse = 0x47,
		//! スクリプトフラグリクエストパケット
		CacheScriptFlagRequest = 0x48,
		//! スクリプトフラグレスポンスパケット
		CacheScriptFlagResponse = 0x49,
		//! スクリプトフラグ保存リクエストパケット
		CacheScriptFlagSaveRequest = 0x4A,
		//! スキルリスト保存リクエストパケット
		CacheSaveSkillListRequest = 0x4B,
		//! スキルリスト保存レスポンスパケット
		CacheSaveSkillListResponse = 0x4C,
		//! スキルツリーリクエストパケット
		CacheSkillTreeRequest = 0x4D,
		//! スキルツリーレスポンスパケット
		CacheSkillTreeResponse = 0x4E,
		//! スキルツリー開放パケット
		CacheOpenSkillTree = 0x4F,
		//! キャラクタ保存リクエストパケット
		CacheCharacterDataSave = 0x50,
		//! ゴールド保存リクエストパケット
		CacheGoldSave = 0x51,
		//! アイテムリストリクエストパケット
		CacheItemListRequest = 0x52,
		//! アイテムリストレスポンスパケット
		CacheItemListResponse = 0x53,
		//! アイテム数変化リクエストパケット
		CacheItemCountChangeRequest = 0x54,
		//! アイテムショートカットリクエストパケット
		CacheItemShortcutRequest = 0x55,
		//! アイテムショートカットレスポンスパケット
		CacheItemShortcutResponse = 0x56,
		//! アイテムショートカット保存リクエストパケット
		CacheSaveItemShortcutRequest = 0x57,
		//! アイテムショートカット保存レスポンスパケット
		CacheSaveItemShortcutResponse = 0x58,
		//! クエストデータリクエストパケット
		CacheQuestDataRequest = 0x59,
		//! クエストデータレスポンスパケット
		CacheQuestDataResponse = 0x5A,
		//! クエストデータ保存リクエストパケット
		CacheSaveQuestDataRequest = 0x5B,
		//! クエスト破棄リクエストパケット
		CacheQuestRetireRequest = 0x5C,
		//! アクティブクエスト保存リクエストパケット
		CacheSaveActiveQuestRequest = 0x5D,
		//! 装備保存リクエストパケット
		CacheSaveEquipRequest = 0x5E,
		//! 装備保存レスポンスパケット
		CacheSaveEquipResponse = 0x5F,
		
	};
};

#endif		// #ifndef __CACHESERVERPACKETID_H__
