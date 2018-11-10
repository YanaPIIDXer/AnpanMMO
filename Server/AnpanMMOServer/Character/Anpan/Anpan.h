#ifndef __ANPAN_H__
#define __ANPAN_H__

#include "Character/CharacterBase.h"
#include "AI/AnpanAI.h"
#include "Packet/CharacterType.h"

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

	// キャラクタタイプを取得.
	virtual u8 GetCharacterType() const { return CharacterType::Enemy; }

protected:

	// ダメージを受けた。
	virtual void OnDamaged(weak_ptr<CharacterBase> pAttacker, int DamageValue);

private:

	// AI
	AnpanAI AI;

	// UUID
	u32 Uuid;

};

#endif		// #ifndef __ANPAN_H__
