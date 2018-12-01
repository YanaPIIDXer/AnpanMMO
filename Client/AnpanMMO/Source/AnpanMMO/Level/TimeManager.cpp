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
void TimeManager::OnRecvTime(MemoryStreamInterface *pStream)
{
	PacketTime Packet;
	Packet.Serialize(pStream);

	CurrentMasterId = Packet.MasterId;
	if (pSky != nullptr)
	{
		pSky->SetTime(Packet.MasterId);
	}
}

// ���ԕϓ����󂯎�����B
void TimeManager::OnRecvTimeChange(MemoryStreamInterface *pStream)
{
	PacketTimeChange Packet;
	Packet.Serialize(pStream);

	CurrentMasterId = Packet.MasterId;
	if (pSky != nullptr)
	{
		pSky->TimeChange(Packet.MasterId);
	}
}
