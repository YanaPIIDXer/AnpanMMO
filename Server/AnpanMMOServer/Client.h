#ifndef __CLIENT_H__
#define __CLIENT_H__

#include "TCPConnection.h"
#include "Packet/PacketID.h"
#include "Script/ScriptExecuter.h"
#include "Script/ScriptFlagManager.h"
#include "Quest/QuestManager.h"

class PacketBase;
class ClientStateBase;
class PlayerCharacter;
class MemoryStreamInterface;

/**
 * クライアントクラス
 */
class Client : public TCPConnection
{

public:

	// コンストラクタ
	Client(const shared_ptr<tcp::socket> &pInSocket);

	// デストラクタ
	virtual ~Client();
	
	// パケット送信.
	void SendPacket(PacketBase *pPacket);

	// ステート切り替え
	void ChangeState(ClientStateBase *pNextState);

	// UUIDをセット
	void SetUuid(u32 InUuid) { Uuid = InUuid; }

	// UUIDを取得.
	u32 GetUuid() const { return Uuid; }

	// カスタマＩＤをセット.
	void SetCustomerId(u32 InCustomerId) { CustomerId = InCustomerId; }

	// カスタマＩＤを取得.
	u32 GetCustomerId() const { return CustomerId; }

	// キャラクタ取得.
	weak_ptr<PlayerCharacter> GetCharacter() const { return pCharacter; }

	// キャラクタ作成.
	void CreateCharacter(u32 CharacterId, const std::string &Name, u8 Job, u32 Level, int MaxHp, int Atk, int Def, int Exp, u32 Gold);

	// パケットを受信。
	// ※主に別プロセスからの受信時に使用。
	void RecvPacket(u8 ID, MemoryStreamInterface *pStream);

	// スクリプトを取得.
	ScriptExecuter *GetScript() { return &Script; }

	// スクリプトフラグを設定.
	void SetScriptFlag(int Key);

	// フラグ管理を取得.
	const ScriptFlagManager &GetScriptFlagManager() const { return FlagManager; }

	// ビットフィールドからスクリプトフラグに変換.
	void ConvertScriptFlagFromBitFields(u32 BitField1, u32 BitField2, u32 BitField3);

	// クエスト管理を取得.
	const QuestManager &GetQuestManager() const { return QuestMgr; }

	// クエストデータ追加.
	void AddQuestData(const QuestData &Data);

protected:

	// データを受信した。
	virtual void OnRecvData(size_t Size);

private:

	// State
	shared_ptr<ClientStateBase> pState;

	// Uuid
	u32 Uuid;

	// カスタマＩＤ
	u32 CustomerId;

	// キャラクタ
	shared_ptr<PlayerCharacter> pCharacter;

	// スクリプト
	ScriptExecuter Script;

	// スクリプトフラグ管理.
	ScriptFlagManager FlagManager;

	// クエスト管理.
	QuestManager QuestMgr;

};

#endif		// #ifndef __CLIENT_H__
