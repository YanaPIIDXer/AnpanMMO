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
 * キャラクタ基底クラス
 */
class CharacterBase : public enable_shared_from_this<CharacterBase>
{

public:

	// コンストラクタ
	CharacterBase();

	// デストラクタ
	virtual ~CharacterBase() {}

	// 毎フレームの処理.
	void Poll(s32 DeltaTime);

	// パラメータ取得.
	const CharacterParameter &GetParameter() const { return Parameter; }

	// 座標を設定.
	void SetPosition(const Vector3D &MoveTarget);

	// 回転を設定.
	void SetRotate(const Rotation &TargetRotation);

	// 座標取得.
	const Vector3D &GetPosition() const { return Position; }

	// 回転取得.
	const Rotation &GetRotation() const { return Rot; }

	// 死んでいる？
	bool IsDead() const { return (Parameter.Hp <= 0); }

	// ダメージ
	void ApplyDamage(CharacterPtr pAttacker, int Value);

	// 回復.
	void Heal(int Value);

	// 正面ベクトルを取得.
	Vector3D GetCenterVec() const;

	// UUIDをセット。
	void SetUuid(u32 InUuid) { Uuid = InUuid; }

	// UUIDを取得.
	u32 GetUuid() const { return Uuid; }

	// レベルを取得.
	u32 GetLevel() const { return Parameter.Level; }

	// キャラクタタイプを取得.
	virtual u8 GetCharacterType() const = 0;

	// 移動.
	void Move(const Vector3D &MoveValue);

	// 回転.
	void Rotate(float RotateValue);

	// リスポン
	void Respawn();

	// エリアをセット。
	void SetArea(const AreaPtr &pInArea) { pArea = pInArea; }

	// エリアを取得.
	AreaPtr GetArea() const { return pArea; }

	// スキル使用.
	void UseSkill(u32 SkillId, CharacterPtr pTarget);

	// リキャスト開始.
	void StartRecast(u32 SkillId);

	// スキル使用中か？
	bool IsSkillActive() const { return Skill.IsActive(); }

	// スキルキャスト中か？
	bool IsSkillCasting() const { return Skill.IsCasting(); }

	// リキャスト中か？
	bool IsRecasting(u32 SkillId) const { return Recast.IsRecast(SkillId); }

	// 倒した時の経験値取得.
	virtual int GetExp() const { return 0; }

	// ドロップＩＤ取得.
	virtual u32 GetDropId() const { return 0; }

protected:

	// 座標.
	Vector3D Position;

	// 回転.
	Rotation Rot;

	// スキル制御.
	SkillControl Skill;

	// スキルリキャスト管理.
	SkillRecastManager Recast;


	// パラメータ設定.
	void SetParameter(u32 Level, int Hp, int MaxHp, int Atk, int Def)
	{
		Parameter.Level = Level;
		Parameter.Hp = Hp;
		Parameter.MaxHp = MaxHp;
		Parameter.Atk = Atk;
		Parameter.Def = Def;
	}

	// レベルアップ
	void LevelUp(int MaxHp, int Atk, int Def)
	{
		Parameter.Level++;
		Parameter.MaxHp += MaxHp;
		Parameter.Atk += Atk;
		Parameter.Def += Def;
	}

	// ダメージを受けた。
	virtual void OnDamaged(weak_ptr<CharacterBase> pAttacker, int DamageValue) {}

	// 毎フレームの処理.
	virtual void Update(s32 DeltaTime) {}

private:

	// パラメータ
	CharacterParameter Parameter;

	// UUID
	u32 Uuid;

	// エリア
	AreaPtr pArea;

};

#endif		// #ifndef __CHARACTERBASE_H__
