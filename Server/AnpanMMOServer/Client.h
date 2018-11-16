#ifndef __CLIENT_H__
#define __CLIENT_H__

#include "TCPConnection.h"

class PacketBase;
class ClientStateBase;
class PlayerCharacter;

/**
 * クライアントクラス
 */
class Client : public TCPConnection
{

public:

	// コンストラクタ
	Client(const shared_ptr<tcp::socket> &pInSocket);

	// デストラクタ
	~Client();
	
	// パケット送信.
	void SendPacket(PacketBase *pPacket);

	// ステート切り替え
	void ChangeState(ClientStateBase *pNextState);

	// UUIDをセット
	void SetUuid(u32 InUuid) { Uuid = InUuid; }

	// UUIDを取得.
	int GetUuid() const { return Uuid; }

	// カスタマＩＤをセット.
	void SetCustomerId(u32 InCustomerId) { CustomerId = InCustomerId; }

	// カスタマＩＤを取得.
	u32 GetCustomerId() const { return CustomerId; }

	// キャラクタ取得.
	weak_ptr<PlayerCharacter> GetCharacter() const { return pCharacter; }

	// キャラクタ作成.
	void CreateCharacter(int MaxHp, int Atk, int Def, int Exp);

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

};

#endif		// #ifndef __CLIENT_H__
