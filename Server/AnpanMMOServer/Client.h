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
	void SetUuid(int InUuid) { Uuid = InUuid; }

	// UUIDを取得.
	int GetUuid() const { return Uuid; }

	// キャラクタ取得.
	PlayerCharacter *GetCharacter() const { return pCharacter; }

	// キャラクタ作成.
	void CreateCharacter(int MaxHp, int Atk, int Def);

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

	// 送信バッファ
	asio::streambuf SendBuffer;

	// State
	shared_ptr<ClientStateBase> pState;

	// Uuid
	int Uuid;

	// キャラクタ
	PlayerCharacter *pCharacter;


	// 受信開始.
	void AsyncRecv(u8 *pBuffer, int Offset);

	// 受信した。
	void OnRecv(const boost::system::error_code &ErrorCode, size_t Size);

	// 送信.
	void AsyncSend(const u8 *pBuffer, int Size);

	// 送信した。
	void OnSend(const boost::system::error_code &ErrorCode, size_t Size);

};

#endif		// #ifndef __CLIENT_H__
