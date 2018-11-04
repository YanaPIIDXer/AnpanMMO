#ifndef __CLIENTSTATEBASE_H__
#define __CLIENTSTATEBASE_H__

#include <map>
#include <boost/function.hpp>
#include "Packet/PacketID.h"

class Client;
class MemoryStreamInterface;

/**
 * クライアントステート基底クラス
 */
class ClientStateBase
{

private:		// 別名定義.

	typedef boost::function<void(MemoryStreamInterface *)> PacketFunc;
	typedef std::map<PacketID, PacketFunc> FunctionMap;

public:

	// コンストラクタ
	ClientStateBase(Client *pInParent)
		: pParent(pInParent) {}

	// デストラクタ
	virtual ~ClientStateBase() {}

	// 開始時の処理.
	virtual void BeginState() {}

	// パケット解析.
	void AnalyzePacket(PacketID ID, MemoryStreamInterface *pStream);
	
protected:

	// 親を取得.
	Client *GetParent() const { return pParent; }

	// パケット解析関数を追加.
	void AddPacketFunction(PacketID ID, const PacketFunc &Func)
	{
		PacketFunctions[ID] = Func;
	}

private:

	// 親.
	Client *pParent;

	// パケット解析関数群.
	FunctionMap PacketFunctions;

};

#endif		// #ifndef __CLIENTSTATEBASE_H__
