#ifndef __ANPAN_H__
#define __ANPAN_H__

#include "Character/CharacterBase.h"
#include "AI/AnpanAI.h"

/**
 * アンパンクラス
 */
class Anpan : public CharacterBase
{

public:

	// コンストラクタ
	Anpan(const Vector2D &InPosition, int Hp, int Atk, int Def);

	// デストラクタ
	virtual ~Anpan() {}

	// 毎フレームの処理.
	void Poll(int DeltaTime);

	// UUIDをセット。
	void SetUuid(u32 InUuid) { Uuid = InUuid; }

	// UUIDを取得.
	u32 GetUuid() const { return Uuid; }

private:

	// AI
	AnpanAI AI;

	// UUID
	u32 Uuid;

};

#endif		// #ifndef __ANPAN_H__
