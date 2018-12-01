// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "Anpan.generated.h"

class AnpanData;
class AAnpanController;

/**
 * �A���p���N���X
 */
UCLASS()
class ANPANMMO_API AAnpan : public ACharacterBase
{

	GENERATED_BODY()
	
public:	

	// ����.
	static AAnpan *Spawn(UWorld *pWorld, const AnpanData &Data);

	// �R���X�g���N�^
	AAnpan(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~AAnpan() {}

	// �J�n���̏���.
	virtual void BeginPlay() override;

	// �R���g���[���ƕR�t����ꂽ�B
	virtual void PossessedBy(AController *NewController) override;

	// UUID�擾.
	uint32 GetUuid() const { return Uuid; }

	// �ړ�.
	void Move(float X, float Y, float Z, int32 Time);

	// ��].
	void Rotate(float Rotation, int32 Time);

	// ��~.
	void Stop(float X, float Y, float Z, float Rotation);

protected:

	// �����̍��W���擾.
	UFUNCTION(BlueprintPure, Category = "Anpan")
	FVector GetFootPosition() const;


	// �g�k�{��.
	UPROPERTY(BlueprintReadOnly, Category = "Anpan")
	float ScaleRate;

private:

	// ���a��l.
	static const float BaseRadius;

	// ���b�V���̃p�X
	static const TCHAR *MeshPath;

	// Blueprint�̃p�X
	static const TCHAR *BlueprintPath;

	// ���b�V��Component
	UPROPERTY()
	UStaticMeshComponent *pMeshComponent;

	// �R���g���[��
	TWeakObjectPtr<AAnpanController> pController;

	// UUID
	uint32 Uuid;
	
};
