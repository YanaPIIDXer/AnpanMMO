#ifndef __PACKETRECEIVER_H__
#define __PACKETRECEIVER_H__

#include <boost/function.hpp>
#include <boost/unordered_map.hpp>

class GameServerConnection;
class MemoryStreamInterface;

/**
 * パケットを受信するクラス
 */
class PacketReceiver
{

private:		// 別名定義.

	typedef function<bool(MemoryStreamInterface *)> PacketFunc;
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
	bool OnRecvLogInRequest(MemoryStreamInterface *pStream);

	// キャラクタ作成リクエストを受信した。
	bool OnRecvCreateCharacterRequest(MemoryStreamInterface *pStream);

	// キャラクタ情報リクエストを受信した。
	bool OnRecvCharacterDataRequest(MemoryStreamInterface *pStream);

	// キャラクタ保存リクエストを受信した。
	bool OnRecvCharacterDataSaveRequest(MemoryStreamInterface *pStream);

	// スキルリスト要求を受信した。
	bool OnRecvSkillListRequest(MemoryStreamInterface *pStream);

	// スキルリスト保存要求を受信した。
	bool OnRecvSaveSkillListRequest(MemoryStreamInterface *pStream);

	// スキルツリーリクエストを受信した。
	bool OnRecvSkillTreeRequest(MemoryStreamInterface *pStream);

	// スキルツリー保存要求を受信した
	bool OnRecvSkillTreeSaveRequest(MemoryStreamInterface *pStream);

	// スクリプトフラグ読み込みリクエストを受信した。
	bool OnRecvLoadScriptFlagRequest(MemoryStreamInterface *pStream);

	// スクリプトフラグ保存リクエストを受信した。
	bool OnRecvSaveScriptFlagRequest(MemoryStreamInterface *pStream);

	// アイテムリストリクエストを受信した。
	bool OnRecvItemListRequest(MemoryStreamInterface *pStream);

	// アイテム数変動を受信した。
	bool OnRecvItemCountChange(MemoryStreamInterface *pStream);

	// アイテムショートカット読み込みリクエストを受信した。
	bool OnRecvItemShortcutRequest(MemoryStreamInterface *pStream);

	// アイテムショートカット書き込みリクエストを受信した。
	bool OnRecvSaveItemShortcutRequest(MemoryStreamInterface *pStream);

	// ゴールド保存リクエストを受信した。
	bool OnRecvSaveGold(MemoryStreamInterface *pStream);

	// クエストデータリクエストを受信した。
	bool OnRecvQuestDataRequest(MemoryStreamInterface *pStream);

	// クエストデータ保存リクエストを受信した。
	bool OnRecvSaveQuestDataRequest(MemoryStreamInterface *pStream);

	// クエスト破棄リクエストを受信した。
	bool OnRecvRetireQuestDataRequest(MemoryStreamInterface *pStream);

	// アクティブクエスト保存リクエストを受信した。
	bool OnRecvSaveActiveQuestRequest(MemoryStreamInterface *pStream);

};

#endif		// #ifndef __PACKETRECEIVER_H__
