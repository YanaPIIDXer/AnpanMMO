// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class BuffBase;
class ACharacterBase;

/**
 * バフ管理.
 */
class ANPANMMO_API BuffManager
{

public:

	// コンストラクタ
	BuffManager();

	// デストラクタ
	~BuffManager();

	// 所有者を設定.
	void SetOwner(ACharacterBase *pInOwner) { pOwner = pInOwner; }

	// バフ追加.
	void Add(uint32 BuffId);

	// バフ消去.
	void Remove(uint8 Type);

	// 指定したバフがかかっているか？
	bool IsActive(uint8 Type) const { return Buffs.Contains(Type); }

private:

	// バフマップ
	TMap<uint8, BuffBase *> Buffs;

	// 所有者.
	TWeakObjectPtr<ACharacterBase> pOwner;

};
