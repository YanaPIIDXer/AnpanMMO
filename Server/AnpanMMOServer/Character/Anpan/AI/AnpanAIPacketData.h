/**
 * @file AnpanAIPacketData.h
 * @brief �A���p���`�h�̃p�P�b�g�f�[�^
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
 * @brief �A���p���ړ��p�P�b�g�f�[�^
 */
class AnpanMovePacketData
{

public:

	/**
	 * @brief �R���X�g���N�^
	 * @param[in] InUuid UUID
	 * @param[in] InPos ���W
	 * @param[in] InTime �ړ�����
	 */
	AnpanMovePacketData(u32 InUuid, const Vector3D &InPos, int InTime)
		: Uuid(InUuid)
		, Pos(InPos)
		, Time(InTime) {}

	/**
	 * @brief �f�X�g���N�^
	 */
	~AnpanMovePacketData() {}

	/**
	 * @fn PacketMoveAnpan CreatePacket()
	 * @brief �p�P�b�g����
	 * @return �p�P�b�g
	 */
	PacketMoveAnpan CreatePacket()
	{
		PacketMoveAnpan Packet(Uuid, Pos.X, Pos.Y, Pos.Z, Time);
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

/**
 * @class AnpanRotatePacketData
 * @brief �A���p����]�p�P�b�g�f�[�^
 */
class AnpanRotatePacketData
{

public:

	/**
	 * @brief �R���X�g���N�^
	 * @param[in] InUuid UUID
	 * @param[in] InRot ��]
	 * @param[in] InTime ��]����
	 */
	AnpanRotatePacketData(u32 InUuid, const Rotation &InRot, int InTime)
		: Uuid(InUuid)
		, Rot(InRot)
		, Time(InTime) {}

	/**
	 * @brief �f�X�g���N�^
	 */
	~AnpanRotatePacketData() {}

	/**
	 * @fn PacketRotateAnpan CreatePacket()
	 * @brief �p�P�b�g����
	 * @return �p�P�b�g
	 */
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
