// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerHPGauge.generated.h"

/**
 * �v���C���[�g�o�Q�[�W
 */
UCLASS()
class ANPANMMO_API UPlayerHPGauge : public UUserWidget
{

	GENERATED_BODY()

public:

	// �R���X�g���N�^
	UPlayerHPGauge(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~UPlayerHPGauge() {}

	// ���t���[���̏���.
	virtual void NativeTick(const FGeometry &InGeometry, float InDeltaTime) override;

	// ������.
	UFUNCTION(BlueprintCallable, Category = "HPGauge")
	void Init(int32 InCurrentHp, int32 InMaxHp);

	// ���X�|�������B
	UFUNCTION(BlueprintCallable, Category = "HPGauge")
	void Respawn();
	
	// �_���[�W���󂯂��B
	UFUNCTION(BlueprintCallable, Category = "HPGauge")
	void Damaged(int32 Value);

	// �񕜂����B
	UFUNCTION(BlueprintCallable, Category = "HpGauge")
	void Healed(int32 Value);

	// ���x���A�b�v
	UFUNCTION(BlueprintCallable, Category = "HPGauge")
	void LevelUp(int32 InMaxHp);

protected:

	// �v���O���X�o�[�Ƀu�`���ރ��[�g
	UPROPERTY(BlueprintReadOnly, Category = "HPGauge")
	float ProgressRate;

private:

	// �ω�����.
	static const float MutateTime;

	// ���݂̂g�o
	int32 CurrentHp;

	// �ȑO�̂g�o
	int32 PrevHp;

	// �ő�g�o
	int32 MaxHp;

	// ���݂̎���.
	float CurrentTime;
	
};
