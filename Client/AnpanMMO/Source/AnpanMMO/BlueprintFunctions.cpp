// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "BlueprintFunctions.h"
#include "UI/SimpleDialog.h"
#include "UI/YesNoDialog.h"
#include "Particles/Emitter.h"
#include "Kismet/GameplayStatics.h"
#include "MMOGameInstance.h"
#include "Master/MasterData.h"
#include "Packet/PacketRespawnRequest.h"

// 単純なダイアログを表示.
USimpleDialog *UBlueprintFunctions::ShowSimpleDialog(UObject *pOuter, const FString &DisplayText, int32 ZOrder)
{
	USimpleDialog *pDialog = USimpleDialog::Show(pOuter, DisplayText, ZOrder);
	return pDialog;
}

// はい・いいえのダイアログを表示.
UYesNoDialog *UBlueprintFunctions::ShowYesNoDialog(UObject *pOuter, const FString &DisplayText, int32 ZOrder)
{
	UYesNoDialog *pDialog = UYesNoDialog::Show(pOuter, DisplayText, ZOrder);
	return pDialog;
}

// エフェクト生成.
AEmitter *UBlueprintFunctions::SpawnEffect(UObject *pWorldContext, UParticleSystem *pParticle, const FVector &Position, const FRotator &Rotation)
{
	FActorSpawnParameters Param;
	Param.bNoFail = true;
	Param.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	UWorld *pWorld = pWorldContext->GetWorld();
	AEmitter *pEmitter = pWorld->SpawnActor<AEmitter>(AEmitter::StaticClass(), Position, Rotation, Param);
	check(pEmitter != nullptr);
	
	pEmitter->SetTemplate(pParticle);
	pEmitter->Activate();

	return pEmitter;
}

// ランダムなベクトルを取得.
FVector UBlueprintFunctions::GetRandomVector(float Min, float Max)
{
	FVector Vec;
	Vec.X = FMath::RandRange(Min, Max);
	Vec.Y = FMath::RandRange(Min, Max);
	Vec.Z = FMath::RandRange(Min, Max);
	return Vec;
}

// リスポンリクエスト送信.
void UBlueprintFunctions::SendRespawnRequest(UObject *pWorldContext)
{
	UMMOGameInstance *pInst = Cast<UMMOGameInstance>(UGameplayStatics::GetGameInstance(pWorldContext));
	check(pInst != nullptr);

	PacketRespawnRequest Packet;
	pInst->SendPacket(&Packet);
}

// スキル名を取得.
FString UBlueprintFunctions::GetSkillName(int32 SkillId)
{
	const SkillItem *pItem = MasterData::GetInstance().GetSkillMaster().Get(SkillId);
	if (pItem == nullptr) { return ""; }
	return pItem->Name;
}

// リキャストタイムを取得.
int32 UBlueprintFunctions::GetRecastTime(int32 SkillId)
{
	const SkillItem *pItem = MasterData::GetInstance().GetSkillMaster().Get(SkillId);
	if (pItem == nullptr) { return 0; }
	return pItem->RecastTime;
}

// アイテムのリキャストタイムを取得.
int32 UBlueprintFunctions::GetItemRecastTime(int32 ItemId)
{
	const ItemItem *pItem = MasterData::GetInstance().GetItemMaster().Get(ItemId);
	if (pItem == nullptr) { return 0; }
	return GetRecastTime(pItem->SkillId);
}

// アイテムＩＤからスキルＩＤを取得.
int32 UBlueprintFunctions::GetSkillIdFromItemId(int32 ItemId)
{
	const ItemItem *pItem = MasterData::GetInstance().GetItemMaster().Get(ItemId);
	if (pItem == nullptr) { return 0; }
	return pItem->SkillId;
}

// アイテム名取得.
FString UBlueprintFunctions::GetItemName(int32 ItemId)
{
	const ItemItem *pItem = MasterData::GetInstance().GetItemMaster().Get(ItemId);
	if (pItem == nullptr) { return ""; }
	return pItem->Name;
}

// 有効なアイテムか？
bool UBlueprintFunctions::IsValidItem(int32 ItemId)
{
	const ItemItem *pItem = MasterData::GetInstance().GetItemMaster().Get(ItemId);
	return (pItem != nullptr);
}

// エリア名を取得.
FString UBlueprintFunctions::GetAreaName(int32 AreaId)
{
	const AreaItem *pItem = MasterData::GetInstance().GetAreaMaster().Get(AreaId);
	if (pItem == nullptr) { return ""; }
	return pItem->Name;
}

// NPC名を取得.
FString UBlueprintFunctions::GetNPCName(int32 NPCId)
{
	const NPCItem *pItem = MasterData::GetInstance().GetNPCMaster().Get(NPCId);
	if (pItem == nullptr) { return ""; }
	return pItem->Name;
}
