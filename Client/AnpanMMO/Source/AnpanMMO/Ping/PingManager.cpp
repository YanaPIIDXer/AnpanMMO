// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "PingManager.h"
#include "Active/ActiveGameMode.h"
#include "Active/UI/MainHUD.h"
#include "Kismet/GameplayStatics.h"
#include "MMOGameInstance.h"
#include "UI/SimpleDialog.h"
#include "Packet/PacketPing.h"

const float PingManager::Interval = 5.0f;

// �R���X�g���N�^
PingManager::PingManager()
	: Timer(Interval)
	, pGameMode(nullptr)
	, bRecvPing(true)
{
}

// ���t���[���̏���.
void PingManager::Poll(float DeltaTime)
{
	Timer -= DeltaTime;
	if (Timer <= 0.0f)
	{
		if (bRecvPing)
		{
			UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(pGameMode.Get()));
			check(pInst != nullptr);

			PacketPing Packet;
			pInst->SendPacket(&Packet);
			
			bRecvPing = false;
		}
		else
		{
			USimpleDialog *pDialog = USimpleDialog::Show(pGameMode.Get(), "Connection Timeout...");
			pDialog->OnDialogOK.AddDynamic(pGameMode->GetMainHUD(), &UMainHUD::OnLogOut);
		}
		Timer += Interval;
	}
}

// Ping����M�����B
void PingManager::OnRecvPing(MemoryStreamInterface *pStream)
{
	PacketPing Packet;
	Packet.Serialize(pStream);

	bRecvPing = true;
}
