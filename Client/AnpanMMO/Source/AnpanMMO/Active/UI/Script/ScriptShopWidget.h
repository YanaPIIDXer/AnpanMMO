// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UI/Menu/LayeredMenuWidgetBase.h"
#include "ScriptShopWidget.generated.h"

// �V���b�v�A�C�e��
// ���w���E���p�̗��������˂�B
USTRUCT(BlueprintType)
struct FShopItem
{

	GENERATED_USTRUCT_BODY()

public:

	// �A�C�e���h�c
	uint32 ItemId;

	// ���O.
	UPROPERTY(BlueprintReadOnly)
	FString Name;

	// �w�� or ���p���i.
	UPROPERTY(BlueprintReadOnly)
	int32 Gold;

};

struct ItemItem;
struct EquipItem;

/**
 * �X�N���v�g�F�V���b�v���.
 */
UCLASS()
class ANPANMMO_API UScriptShopWidget : public ULayeredMenuWidgetBase
{

	GENERATED_BODY()
	
public:

	// ����.
	static UScriptShopWidget *Create(UObject *pOuter);

	// �R���X�g���N�^
	UScriptShopWidget(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UScriptShopWidget() {}

	// �V���b�v�h�c��ݒ�.
	void SetShopId(uint32 InShopId) { ShopId = InShopId; }

	// �p�P�b�g����M�����B
	virtual void OnRecvPacket(uint8 ID, MemoryStreamInterface *pStream) override;

protected:

	// ������.
	UFUNCTION(BlueprintCallable, Category = "Shop")
	void Init();

	// �������C�x���g
	UFUNCTION(BlueprintNativeEvent, Category = "Shop")
	void OnInit(const TArray<FShopItem> &ShopItems, const TArray<FShopItem> &SellItems);
	void OnInit_Implementation(const TArray<FShopItem> &ShopItems, const TArray<FShopItem> &SellItems) {}

	// �A�C�e�����������擾.
	UFUNCTION(BlueprintPure, Category = "Shop")
	int32 GetHaveItemCount(const FShopItem &Item) const;

	// ���֐i�ށB
	UFUNCTION(BlueprintCallable, Category = "Shop")
	void ToNext();

	// ���݂̃S�[���h���擾.
	UFUNCTION(BlueprintPure, Category = "Shop")
	int32 GetCurrentGold() const { return CurrentGold; }

	// �w���p�P�b�g�𑗐M.
	UFUNCTION(BlueprintCallable, Category = "Shop")
	void SendBuy(const FShopItem &Item, int32 Count);

	// ���p�p�P�b�g�𑗐M.
	UFUNCTION(BlueprintCallable, Category = "Shop")
	void SendSell(const FShopItem &Item, int32 Count);

private:

	// �A�Z�b�g�̃p�X
	static const TCHAR *AssetPath;

	// �V���b�v�h�c
	uint32 ShopId;

	// ���݂̃S�[���h
	int32 CurrentGold;


	// ShopItem�𐶐�.
	FShopItem GenerateShopItem(uint32 ItemId, bool bBuy);
	FShopItem GenerateShopItem(const ItemItem *pItem, bool bBuy);
	FShopItem GenerateShopItem(const EquipItem *pItem, bool bBuy);

};
