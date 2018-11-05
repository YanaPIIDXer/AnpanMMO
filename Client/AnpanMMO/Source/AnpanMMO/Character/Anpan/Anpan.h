// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Character/CharacterBase.h"
#include "Anpan.generated.h"

class AnpanData;

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

private:

	// ���b�V���̃p�X
	static const TCHAR *MeshPath;

	// ���b�V��Component
	UPROPERTY()
	UStaticMeshComponent *pMeshComponent;

	// HP
	int Hp;

	// �ő�HP
	int MaxHp;
	
};
