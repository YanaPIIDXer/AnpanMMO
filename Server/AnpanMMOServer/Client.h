#ifndef __CLIENT_H__
#define __CLIENT_H__

#include "MemoryBuffer.h"

class PacketBase;
class ClientStateBase;
class PlayerCharacter;

/**
 * クライアントクラス
 */
class Client
{

public:

	// コンストラクタ
	Client(const shared_ptr<tcp::socket> &pInSocket);

	// デストラクタ
	~Client();

	// 接続されているか？
	bool IsConnected() const { return bIsConnected; }

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

private:

	enum
	{
		RecvDataSize = 1024,
	};

	// Socket
	shared_ptr<tcp::socket> pSocket;

	// 接続されているか？
	bool bIsConnected;

	// 受信バッファ.
	MemoryBuffer RecvBuffer;

	// 受信データ
	array<u8, RecvDataSize> RecvData;

	// State
	shared_ptr<ClientStateBase> pState;

	// Uuid
	u32 Uuid;

	// カスタマＩＤ
	u32 CustomerId;

	// キャラクタ
	shared_ptr<PlayerCharacter> pCharacter;


	// 受信開始.
	void AsyncRecv(u8 *pBuffer, int Offset);

	// 受信した。
	void OnRecv(const boost::system::error_code &ErrorCode, size_t Size);

	// 送信.
	void AsyncSend(const u8 *pBuffer, int Size);

	// 送信した。
	void OnSend(const boost::system::error_code &ErrorCode, size_t Size, shared_ptr<asio::streambuf> SendBuffer);

};

#endif		// #ifndef __CLIENT_H__
