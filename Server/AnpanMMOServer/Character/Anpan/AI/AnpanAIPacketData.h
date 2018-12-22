/**
 * @file AnpanAIPacketData.h
 * @brief アンパンＡＩのパケットデータ
 * @author YanaP
 */
#ifndef __ANPANAIPACKETDATA_H__
#define __ANPANAIPACKETDATA_H__

#include "Math/Vector3D.h"
#include "Math/Rotation.h"
#include "Packet/PacketMoveAnpan.h"
#include "Packet/PacketRotateAnpan.h"

/**
 * @class AnpanMovePacketData
 * @brief アンパン移動パケットデータ
 */
class AnpanMovePacketData
{

public:

	/**
	 * @brief コンストラクタ
	 * @param[in] InUuid UUID
	 * @param[in] InPos 座標
	 * @param[in] InTime 移動時間
	 */
	AnpanMovePacketData(u32 InUuid, const Vector3D &InPos, int InTime)
		: Uuid(InUuid)
		, Pos(InPos)
		, Time(InTime) {}

	/**
	 * @brief デストラクタ
	 */
	~AnpanMovePacketData() {}

	/**
	 * @fn PacketMoveAnpan CreatePacket()
	 * @brief パケット生成
	 * @return パケット
	 */
	PacketMoveAnpan CreatePacket()
	{
		PacketMoveAnpan Packet(Uuid, Pos.X, Pos.Y, Pos.Z, Time);
		return Packet;
	}

private:

	// UUID
	u32 Uuid;

	// 座標
	Vector3D Pos;

	// 時間.
	int Time;

};

/**
 * @class AnpanRotatePacketData
 * @brief アンパン回転パケットデータ
 */
class AnpanRotatePacketData
{

public:

	/**
	 * @brief コンストラクタ
	 * @param[in] InUuid UUID
	 * @param[in] InRot 回転
	 * @param[in] InTime 回転時間
	 */
	AnpanRotatePacketData(u32 InUuid, const Rotation &InRot, int InTime)
		: Uuid(InUuid)
		, Rot(InRot)
		, Time(InTime) {}

	/**
	 * @brief デストラクタ
	 */
	~AnpanRotatePacketData() {}

	/**
	 * @fn PacketRotateAnpan CreatePacket()
	 * @brief パケット生成
	 * @return パケット
	 */
	PacketRotateAnpan CreatePacket()
	{
		PacketRotateAnpan Packet(Uuid, Rot.Get(), Time);
		return Packet;
	}

private:

	// UUID
	u32 Uuid;

	// 回転.
	Rotation Rot;

	// 時間.
	int Time;

};

#endif		// #ifndef __ANPANAIPACKETDATA_H__
