#ifndef __PACKETRECEIVER_H__
#define __PACKETRECEIVER_H__

#include <boost/function.hpp>
#include <boost/unordered_map.hpp>
#include "Packet/PacketID.h"

class GameServerConnection;
class MemoryStreamInterface;

/**
 * パケットを受信するクラス
 */
class PacketReceiver
{

private:		// 別名定義.

	typedef function<void(MemoryStreamInterface *)> PacketFunc;
	typedef unordered_map<u8, PacketFunc> PacketFuncMap;

public:

	// コンストラクタ
	PacketReceiver(GameServerConnection *pInParent);

	// デストラクタ
	~PacketReceiver() {}

	// パケット受信.
	void RecvPacket(u8 ID, MemoryStreamInterface *pStream);

private:

	// 親.
	GameServerConnection *pParent;

	// パケット受信関数マップ
	PacketFuncMap PacketFuncs;


	// パケット受信関数を追加.
	void AddPacketFunc(u8 ID, const PacketFunc &Func);

	// ログインリクエストを受信した。
	void OnRecvLogInRequest(MemoryStreamInterface *pStream);

	// キャラクタ作成リクエストを受信した。
	void OnRecvCreateCharacterRequest(MemoryStreamInterface *pStream);

	// キャラクタ情報リクエストを受信した。
	void OnRecvCharacterDataRequest(MemoryStreamInterface *pStream);

	// キャラクタ保存リクエストを受信した。
	void OnRecvCharacterDataSaveRequest(MemoryStreamInterface *pStream);

	// スキルリスト要求を受信した。
	void OnRecvSkillListRequest(MemoryStreamInterface *pStream);

	// スキルリスト保存要求を受信した。
	void OnRecvSaveSkillListRequest(MemoryStreamInterface *pStream);

	// スキルツリーリクエストを受信した。
	void OnRecvSkillTreeRequest(MemoryStreamInterface *pStream);

	// スキルツリー保存要求を受信した
	void OnRecvSkillTreeSaveRequest(MemoryStreamInterface *pStream);

	// スクリプトフラグ読み込みリクエストを受信した。
	void OnRecvLoadScriptFlagRequest(MemoryStreamInterface *pStream);

	// スクリプトフラグ保存リクエストを受信した。
	void OnRecvSaveScriptFlagRequest(MemoryStreamInterface *pStream);

	// アイテムリストリクエストを受信した。
	void OnRecvItemListRequest(MemoryStreamInterface *pStream);

	// アイテム数変動を受信した。
	void OnRecvItemCountChange(MemoryStreamInterface *pStream);

	// アイテムショートカット読み込みリクエストを受信した。
	void OnRecvItemShortcutRequest(MemoryStreamInterface *pStream);

	// アイテムショートカット書き込みリクエストを受信した。
	void OnRecvSaveItemShortcutRequest(MemoryStreamInterface *pStream);

	// ゴールド保存リクエストを受信した。
	void OnRecvSaveGold(MemoryStreamInterface *pStream);

	// クエストデータリクエストを受信した。
	void OnRecvQuestDataRequest(MemoryStreamInterface *pStream);

	// クエストデータ保存リクエストを受信した。
	void OnRecvSaveQuestDataRequest(MemoryStreamInterface *pStream);

	// クエスト破棄リクエストを受信した。
	void OnRecvRetireQuestDataRequest(MemoryStreamInterface *pStream);

	// アクティブクエスト保存リクエストを受信した。
	void OnRecvSaveActiveQuestRequest(MemoryStreamInterface *pStream);

};

#endif		// #ifndef __PACKETRECEIVER_H__
