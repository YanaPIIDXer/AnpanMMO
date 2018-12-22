// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "TimeManager.h"
#include "SkyControl.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "Packet/PacketTime.h"
#include "Packet/PacketTimeChange.h"

// �R���X�g���N�^
TimeManager::TimeManager()
	: pSky(nullptr)
	, CurrentMasterId(1)
{
}

// �V�����Z�b�g�B
void TimeManager::SetSkyControl(ASkyControl *pInSky)
{
	pSky = pInSky;
	pSky->SetTime(CurrentMasterId);
}

// �J�n���̎��Ԃ��󂯎�����B
bool TimeManager::OnRecvTime(MemoryStreamInterface *pStream)
{
	PacketTime Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	CurrentMasterId = Packet.MasterId;
	if (pSky != nullptr)
	{
		pSky->SetTime(Packet.MasterId);
	}

	return true;
}

// ���ԕϓ����󂯎�����B
bool TimeManager::OnRecvTimeChange(MemoryStreamInterface *pStream)
{
	PacketTimeChange Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	CurrentMasterId = Packet.MasterId;
	if (pSky != nullptr)
	{
		pSky->TimeChange(Packet.MasterId);
	}

	return true;
}
