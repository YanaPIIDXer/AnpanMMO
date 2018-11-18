#ifndef __ANPANAIPACKETDATA_H__
#define __ANPANAIPACKETDATA_H__

#include "Math/Vector3D.h"
#include "Math/Rotation.h"
#include "Packet/PacketMoveAnpan.h"
#include "Packet/PacketRotateAnpan.h"

// 移動パケットデータ
class AnpanMovePacketData
{

public:

	// コンストラクタ
	AnpanMovePacketData(u32 InUuid, const Vector3D &InPos, int InTime)
		: Uuid(InUuid)
		, Pos(InPos)
		, Time(InTime) {}

	// パケット生成.
	PacketMoveAnpan CreatePacket()
	{
		PacketMoveAnpan Packet(Uuid, Pos.X, Pos.Y, Time);
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

// 回転パケットデータ
class AnpanRotatePacketData
{

public:

	// コンストラクタ
	AnpanRotatePacketData(u32 InUuid, const Rotation &InRot, int InTime)
		: Uuid(InUuid)
		, Rot(InRot)
		, Time(InTime) {}

	// パケット生成.
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
