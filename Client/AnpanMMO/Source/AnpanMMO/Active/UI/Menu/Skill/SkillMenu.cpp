// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "SkillMenu.h"
#include "Packet/PacketID.h"

// �R���X�g���N�^
USkillMenu::USkillMenu(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// �p�P�b�g����M�����B
void USkillMenu::OnRecvPacket(uint8 ID)
{
	switch (ID)
	{
		case PacketID::SkillTreeOpenResult:
		case PacketID::SaveSkillListResponse:

			RefleshMenu();
			break;
	}
}
