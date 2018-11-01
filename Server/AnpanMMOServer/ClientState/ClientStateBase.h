#ifndef __CLIENTSTATEBASE_H__
#define __CLIENTSTATEBASE_H__

class Client;
class MemoryStreamInterface;
enum PacketID;

/**
 * クライアントステート基底クラス
 */
class ClientStateBase
{

public:

	// コンストラクタ
	ClientStateBase(Client *pInParent)
		: pParent(pInParent) {}

	// デストラクタ
	virtual ~ClientStateBase() {}

	// パケット解析.
	virtual void AnalyzePacket(PacketID ID, MemoryStreamInterface *pStream) {}
	
protected:

	// 親を取得.
	Client *GetParent() const { return pParent; }

private:

	// 親.
	Client *pParent;

};

#endif		// #ifndef __CLIENTSTATEBASE_H__
