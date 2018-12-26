/**
 * @file ClientStateBase.h
 * @brief クライアントステート基底クラス
 * @author YanaP
 */
#ifndef __CLIENTSTATEBASE_H__
#define __CLIENTSTATEBASE_H__

#include <map>
#include <boost/function.hpp>
#include "Packet/PacketID.h"

class Client;
class MemoryStreamInterface;

/**
 * @class ClientStateBase
 * @brief クライアントステート基底クラス
 */
class ClientStateBase
{

private:		// 別名定義.

	typedef boost::function<bool(Client *, MemoryStreamInterface *)> PacketFunc;
	typedef std::map<u8, PacketFunc> FunctionMap;

public:

	/**
	 * @brief コンストラクタ
	 * @param[in] pInParent クライアント
	 */
	ClientStateBase(Client *pInParent)
		: pParent(pInParent) {}

	/**
	 * @brief デストラクタ
	 */
	virtual ~ClientStateBase() {}

	/**
	 * @fn virtual void BeginState()
	 * @brief State開始時の処理
	 */
	virtual void BeginState() {}

	/**
	 * @fn void AnalyzePacket(u8 ID, MemoryStreamInterface *pStream)
	 * @brief パケット解析
	 * @param[in] ID パケットＩＤ
	 * @param[in] pStream ストリーム
	 */
	void AnalyzePacket(u8 ID, MemoryStreamInterface *pStream);
	
protected:

	/**
	 * @fn Client *GetParent() const
	 * @brief 親クライアントを取得
	 * @return 親クライアント
	 */
	Client *GetParent() const { return pParent; }

	/*
	 * @fn void AddPacketFunction(u8 ID, const PacketFunc &Func)
	 * @brief パケット解析関数を追加
	 * @param[in] ID パケットＩＤ
	 * @param[in] Func 解析関数
	 */
	void AddPacketFunction(u8 ID, const PacketFunc &Func)
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
