// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "SkillMenu.h"
#include "Packet/PacketID.h"

// コンストラクタ
USkillMenu::USkillMenu(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
}

// パケットを受信した。
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
