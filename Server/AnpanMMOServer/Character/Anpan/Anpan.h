/**
 * @file Anpan.h
 * @brief アンパンクラス
 * @author YanaP
 */
#ifndef __ANPAN_H__
#define __ANPAN_H__

#include "Character/CharacterBase.h"
#include "AI/AnpanAI.h"
#include "WeakPtrDefine.h"
#include "Packet/CharacterType.h"

/**
 * @class Anpan
 * @brief アンパンクラス
 */
class Anpan : public CharacterBase
{

public:

	/**
	 * @brief コンストラクタ
	 * @param[in] InPosition 座標
	 * @param[in] InMasterId マスタＩＤ
	 */
	Anpan(const Vector3D &InPosition, u32 InMasterId);

	/**
	 * @brief デストラクタ
	 */
	virtual ~Anpan() {}

	/**
	 * @fn virtual u8 GetCharacterType() const
	 * @brief キャラクタタイプを取得
	 * @return キャラクタタイプ
	 */
	virtual u8 GetCharacterType() const { return CharacterType::Enemy; }

	/**
	 * @fn void AttackTo(CharacterPtr pTarget, u32 SkillId)
	 * @brief 攻撃
	 * @param[in] pTarget 攻撃対象へのweak_ptr
	 * @param[in] SkillId スキルＩＤ
	 */
	void AttackTo(CharacterPtr pTarget, u32 SkillId);

	/**
	 * @fn virtual int GetExp() const
	 * @brief 倒した時の経験値を取得
	 * @return 倒した時の経験値
	 */
	virtual int GetExp() const { return Exp; }
	
	/**
	 * @fn float GetRadius() const
	 * @brief 半径を取得
	 * @return 半径
	 */
	float GetRadius() const { return (BaseRadius * ScaleRate); }

	/**
	 * @fn u32 GetMasterId()
	 * @brief マスタＩＤを取得
	 * @return マスタＩＤ
	 */
	u32 GetMasterId() const { return MasterId; }

	/**
	 * @fn virtual u32 GetDropId() const
	 * @brief ドロップＩＤを取得
	 * @return ドロップＩＤ
	 */
	virtual u32 GetDropId() const { return DropId; }

	/**
	 * @fn virtual void OnBuffAdded(u32 BuffId)
	 * @brief バフが追加された。
	 * @param[in] BuffId バフＩＤ
	 */
	virtual void OnBuffAdded(u32 BuffId);

protected:

	/**
	 * @fn virtual void Update(int DeltaTime)s
	 * @brief 毎フレームの処理
	 * @param[in] 前フレームからの経過時間
	 */
	virtual void Update(int DeltaTime);

	/**
	 * @fn virtual void OnDamaged(CharacterPtr pAttacker, int DamageValue)
	 * @brief ダメージを受けた
	 * @param[in] pAttacker ダメージを与えたキャラへのweak_ptr
	 * @param[in] int DamageValue ダメージ量
	 */
	virtual void OnDamaged(CharacterPtr pAttacker, int DamageValue);

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

	// ドロップＩＤ
	u32 DropId;

};

#endif		// #ifndef __ANPAN_H__
