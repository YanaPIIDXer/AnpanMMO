/**
 * @file CharacterBase.h
 * @brief キャラクタ基底クラス
 * @author YanaP
 */
#ifndef __CHARACTERBASE_H__
#define __CHARACTERBASE_H__

#include <boost/enable_shared_from_this.hpp>
#include "CharacterParameter.h"
#include "Math/Vector3D.h"
#include "Math/Rotation.h"
#include "Area/AreaBase.h"
#include "Skill/SkillControl.h"
#include "Skill/SkillRecastManager.h"

/**
 * @class CharacterBase
 * @brief キャラクタ基底クラス
 */
class CharacterBase : public enable_shared_from_this<CharacterBase>
{

public:

	/**
	 * @brief コンストラクタ
	 */
	CharacterBase();

	/**
	 * @brief デストラクタ
	 */
	virtual ~CharacterBase() {}

	/**
	 * @fn void Poll(s32 DeltaTime)
	 * @brief 毎フレームの処理
	 * @param[in] DeltaTime 前フレームからの経過時間
	 */
	void Poll(s32 DeltaTime);

	/**
	 * @fn const CharacterParameter &GetParameter() const
	 * @brief パラメータ取得
	 * @return パラメータ
	 */
	const CharacterParameter &GetParameter() const { return Parameter; }

	/**
	 * @fn void SetPosition(const Vector3D &MoveTarget)
	 * @brief 座標を設定
	 * @param[in] MoveTarget 移動先座標
	 */
	void SetPosition(const Vector3D &MoveTarget);

	/**
	 * @fn void SetRotate(const Rotation &TargetRotation)
	 * @brief 回転を設定
	 * @param[in] TargetRotation 回転
	 */
	void SetRotate(const Rotation &TargetRotation);

	/**
	 * @fn const Vector3D &GetPosition() const
	 * @brief 座標を取得
	 * @return 座標
	 */
	const Vector3D &GetPosition() const { return Position; }

	/**
	 * @fn const Rotation &GetRotation() const
	 * @brief 回転を取得
	 * @return 回転
	 */
	const Rotation &GetRotation() const { return Rot; }

	/**
	 * @fn bool IsDead() const
	 * @brief 死んでいる？
	 * @return 死んでいるならtrue
	 */
	bool IsDead() const { return (Parameter.GetHp() <= 0); }

	/**
	 * @fn void ApplyDamage(CharacterPtr pAttacker, u32 Value)
	 * @brief ダメージを与える
	 * @param[in] pAttacker ダメージを与えたキャラクタのweak_ptr
	 * @param[in] Value ダメージ量
	 */
	void ApplyDamage(CharacterPtr pAttacker, u32 Value);

	/**
	 * @fn void Heal(u32 Value)
	 * @brief 回復
	 * @param[in] Value 回復量
	 */
	void Heal(u32 Value);

	/**
	 * @fn Vector3D GetCenterVec() const
	 * @brief 正面ベクトルを取得
	 * @return 正面ベクトル
	 */
	Vector3D GetCenterVec() const;

	/**
	 * @fn void SetUuid(u32 InUuid)
	 * @brief UUIDをセット
	 * @param[in] InUuid UUID
	 */
	void SetUuid(u32 InUuid) { Uuid = InUuid; }

	/**
	 * @fn u32 GetUuid() const
	 * @brief UUIDを取得
	 * @return UUID
	 */
	u32 GetUuid() const { return Uuid; }

	/**
	 * @fn u32 GetLevel() const
	 * @brief レベルを取得
	 * @return レベル
	 */
	u32 GetLevel() const { return Parameter.GetLevel(); }

	/**
	 * @fn virtual u8 GetCharacterType() const
	 * @brief キャラクタタイプを取得
	 * @return キャラクタタイプ
	 */
	virtual u8 GetCharacterType() const = 0;

	/**
	 * @fn void Move(const vector3D &MoveValue)
	 * @brief 移動
	 * @param[in] MoveValue 移動量
	 */
	void Move(const Vector3D &MoveValue);

	/**
	 * @fn void Rotate(float RotateValue)
	 * @brief 回転
	 * @param[in] RotateValue 回転量
	 */
	void Rotate(float RotateValue);

	/**
	 * @fn void Respawn()
	 * @brief リスポン
	 */
	void Respawn();

	/**
	 * @fn void SetArea(const AreaPtr &pInArea)
	 * @brief エリアを設定
	 * @param[in] pInArea エリアへのweak_ptr
	 */
	void SetArea(const AreaPtr &pInArea) { pArea = pInArea; }

	/**
	 * @fn AreaPtr GetArea() const
	 * @brief エリアを取得
	 * @return エリアへのwaek_ptr
	 */
	AreaPtr GetArea() const { return pArea; }

	/**
	 * @fn void UseSkill(u32 SkillId, CharacterPtr pTarget)
	 * @brief スキル使用
	 * @param[in] SkillId スキルＩＤ
	 * @param[in] pTarget ターゲットキャラへのweak_ptr
	 */
	void UseSkill(u32 SkillId, CharacterPtr pTarget);

	/**
	 * @fn void StartRecast(u32 SkillId)
	 * @brief リキャスト開始
	 * @param[in] SkillId スキルＩＤ
	 */
	void StartRecast(u32 SkillId);

	/**
	 * @fn bool IsSkillActive() const
	 * @brief スキル使用中か？
	 * @return スキル使用中ならtrueを返す
	 */
	bool IsSkillActive() const { return Skill.IsActive(); }

	/**
	 * @fn bool IsSkillCasting() const
	 * @brief スキルキャスト中か？
	 * @return キャスト中ならtrueを返す。
	 */
	bool IsSkillCasting() const { return Skill.IsCasting(); }

	/**
	 * @fn bool IsRecasting(u32 SkillId) const
	 * @brief リキャスト中か？
	 * @param[in] SkillId スキルＩＤ
	 * @return リキャスト中ならtrueを返す
	 */
	bool IsRecasting(u32 SkillId) const { return Recast.IsRecast(SkillId); }

	/**
	 * @fn virtual int GetExp() const
	 * @brief 倒した時の経験値取得
	 * @return 倒した時の経験値
	 */
	virtual int GetExp() const { return 0; }

	/**
	 * @fn virtual u32 GetDropId() const
	 * @brief ドロップＩＤを取得
	 * @return ドロップＩＤ
	 */
	virtual u32 GetDropId() const { return 0; }

protected:

	//! 座標.
	Vector3D Position;

	//! 回転.
	Rotation Rot;

	//! スキル制御.
	SkillControl Skill;

	//! スキルリキャスト管理.
	SkillRecastManager Recast;


	/**
	 * @fn void SetParameter(u32 Level, u32 Hp, u32 MaxHp, u32 Str, u32 Def, u32 Int, u32 Mnd, u32 Vit)
	 * @brief パラメータを設定
	 * @param[in] Level レベル
	 * @param[in] Hp ＨＰ
	 * @param[in] MaxHp 最大ＨＰ
	 * @param[in] Str STR
	 * @param[in] Def DEF
	 * @param[in] Int INT
	 * @param[in] Mnd MND
	 * @param[in] Vit VIT
	 * @param[in] bIsVitAffectMaxHp VITが最大ＨＰに影響するか？
	 */
	void SetParameter(u32 Level, u32 Hp, u32 MaxHp, u32 Str, u32 Def, u32 Int, u32 Mnd, u32 Vit, bool bIsVitAffectMaxHp)
	{
		Parameter.Set(Level, Hp, MaxHp, Str, Def, Int, Mnd, Vit, bIsVitAffectMaxHp);
	}

	/**
	 * @fn virtual void OnDamaged(weak_ptr<CharacterBase> pAttacker, int DamageValue)
	 * @brief ダメージを受けた
	 * @param[in] pAttacker 攻撃者へのweak_ptr
	 * @param[in] DamageValue ダメージ量
	 */
	virtual void OnDamaged(weak_ptr<CharacterBase> pAttacker, int DamageValue) {}

	/**
	 * @fn virtual void Update(s32 DeltaTime)
	 * @brief 毎フレームの処理
	 * @param[in] DeltaTime 前フレームからの経過時間
	 */
	virtual void Update(s32 DeltaTime) {}

	/**
	 * @fn void ChangeEquipData(u32 RightEquipId, u32 LeftEquipId)
	 * @brief 装備切り替え
	 * @param[in] RightEquipId 右手装備ＩＤ
	 * @param[in] LeftEquipId 左手装備ＩＤ
	 */
	void ChangeEquipData(u32 RightEquipId, u32 LeftEquipId);

private:

	// パラメータ
	CharacterParameter Parameter;

	// UUID
	u32 Uuid;

	// エリア
	AreaPtr pArea;

};

#endif		// #ifndef __CHARACTERBASE_H__
