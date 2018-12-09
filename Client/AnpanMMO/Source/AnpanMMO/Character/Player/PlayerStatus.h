// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

/**
 * �v���C���[�X�e�[�^�X
 */
class ANPANMMO_API PlayerStatus
{

public:

	// �R���X�g���N�^
	PlayerStatus();

	// �f�X�g���N�^
	~PlayerStatus() {}

	// Uuid�Z�b�g
	void SetUuid(uint32 InUuid) { Uuid = InUuid; }

	// �Z�b�g
	void Set(int32 InMaxHp, int32 InAtk, int32 InDef)
	{
		MaxHp = InMaxHp;
		Atk = InAtk;
		Def = InDef;
	}

	// �o���l�Z�b�g
	void SetExp(int32 InExp) { Exp = InExp; }

	// ���O���Z�b�g
	void SetName(const FString &InName) { Name = InName; }

	// ���O���擾.
	const FString &GetName() const { return Name; }

	// Uuid�擾.
	uint32 GetUuid() const { return Uuid; }

	// �W���u���Z�b�g
	void SetJob(u8 InJob) { Job = InJob; }

	// �W���u���擾.
	u8 GetJob() const { return Job; }

	// �ő�HP�擾.
	int32 GetMaxHp() const { return MaxHp; }

	// �U���͎擾.
	int32 GetAtk() const { return Atk; }

	// �h��͎擾.
	int32 GetDef() const { return Def; }

	// �o���l�擾.
	int32 GetExp() const { return Exp; }

private:

	// Uuid
	uint32 Uuid;

	// ���O.
	FString Name;

	// �W���u
	u8 Job;

	// �ő�HP
	int32 MaxHp;

	// �U����.
	int32 Atk;

	// �h���.
	int32 Def;

	// �o���l.
	int32 Exp;

};
