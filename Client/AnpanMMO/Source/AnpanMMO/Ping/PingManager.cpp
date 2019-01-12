// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#include "PingManager.h"
#include "Active/ActiveGameMode.h"
#include "Active/UI/MainHUD.h"
#include "Kismet/GameplayStatics.h"
#include "MMOGameInstance.h"
#include "UI/SimpleDialog.h"
#include "Packet/PacketPing.h"

const float PingManager::Interval = 10.0f;

// �R���X�g���N�^
PingManager::PingManager()
	: Timer(Interval)
	, pGameMode(nullptr)
	, bRecvPing(true)
	, bIsActive(true)
{
}

// ���t���[���̏���.
void PingManager::Poll(float DeltaTime)
{
	if (!bIsActive) { return; }

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
			bIsActive = false;
		}
		Timer += Interval;
	}
}

// Ping����M�����B
bool PingManager::OnRecvPing(MemoryStreamInterface *pStream)
{
	PacketPing Packet;
	if (!Packet.Serialize(pStream)) { return false; }

	bRecvPing = true;
	return true;
}
