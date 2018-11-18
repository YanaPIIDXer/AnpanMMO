#ifndef __ANPANAIPACKETDATA_H__
#define __ANPANAIPACKETDATA_H__

#include "Math/Vector3D.h"
#include "Math/Rotation.h"
#include "Packet/PacketMoveAnpan.h"
#include "Packet/PacketRotateAnpan.h"

// �ړ��p�P�b�g�f�[�^
class AnpanMovePacketData
{

public:

	// �R���X�g���N�^
	AnpanMovePacketData(u32 InUuid, const Vector3D &InPos, int InTime)
		: Uuid(InUuid)
		, Pos(InPos)
		, Time(InTime) {}

	// �p�P�b�g����.
	PacketMoveAnpan CreatePacket()
	{
		PacketMoveAnpan Packet(Uuid, Pos.X, Pos.Y, Time);
		return Packet;
	}

private:

	// UUID
	u32 Uuid;

	// ���W
	Vector3D Pos;

	// ����.
	int Time;

};

// ��]�p�P�b�g�f�[�^
class AnpanRotatePacketData
{

public:

	// �R���X�g���N�^
	AnpanRotatePacketData(u32 InUuid, const Rotation &InRot, int InTime)
		: Uuid(InUuid)
		, Rot(InRot)
		, Time(InTime) {}

	// �p�P�b�g����.
	PacketRotateAnpan CreatePacket()
	{
		PacketRotateAnpan Packet(Uuid, Rot.Get(), Time);
		return Packet;
	}

private:

	// UUID
	u32 Uuid;

	// ��].
	Rotation Rot;

	// ����.
	int Time;

};

#endif		// #ifndef __ANPANAIPACKETDATA_H__
