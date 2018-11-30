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
	Anpan(const Vector3D &InPosition, u32 InMasterId, int Hp, int Atk, int Def, int InExp, float InScaleRate);

	// デストラクタ
	virtual ~Anpan() {}

	// 毎フレームの処理.
	void Poll(int DeltaTime);

	// キャラクタタイプを取得.
	virtual u8 GetCharacterType() const { return CharacterType::Enemy; }

	// 攻撃.
	void AttackTo(CharacterBase *pTarget);

	// 倒したときに獲得できる経験値を取得.
	int GetExp() const { return Exp; }
	
	// 半径を取得.
	float GetRadius() const { return (BaseRadius * ScaleRate); }

	// マスタＩＤを取得.
	u32 GetMasterId() const { return MasterId; }
	
protected:

	// ダメージを受けた。
	virtual void OnDamaged(weak_ptr<CharacterBase> pAttacker, int DamageValue);

private:

	// 半径.
	static const float BaseRadius;
	
	// AI
	AnpanAI AI;

	// マスタＩＤ
	u32 MasterId;

	// 倒したときに獲得できる経験値.
	int Exp;

	// 拡縮倍率.
	float ScaleRate;

};

#endif		// #ifndef __ANPAN_H__
