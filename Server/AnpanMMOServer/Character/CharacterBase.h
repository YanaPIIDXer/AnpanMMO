#ifndef __CHARACTERBASE_H__
#define __CHARACTERBASE_H__

#include "CharacterParameter.h"
#include "Math/Vector2D.h"
#include "Math/Rotation.h"

/**
 * キャラクタ基底クラス
 */
class CharacterBase
{

public:

	// コンストラクタ
	CharacterBase();

	// デストラクタ
	virtual ~CharacterBase() {}

	// パラメータ取得.
	const CharacterParameter &GetParameter() const { return Parameter; }

	// 移動.
	void Move(float X, float Y, float Rotation);

	// 座標取得.
	const Vector2D &GetPosition() const { return Position; }

	// 回転取得.
	const Rotation &GetRotation() const { return Rot; }

	// 死んでいる？
	bool IsDead() const { return (Parameter.Hp <= 0); }

	// ダメージ
	void ApplyDamage(int Value);

protected:

	// 座標.
	Vector2D Position;

	// 回転.
	Rotation Rot;


	// パラメータ設定.
	void SetParameter(int Hp, int MaxHp, int Atk, int Def)
	{
		Parameter.Hp = Hp;
		Parameter.MaxHp = MaxHp;
		Parameter.Atk = Atk;
		Parameter.Def = Def;
	}

	// パラメータ追加.
	void AddParameter(int MaxHp, int Atk, int Def)
	{
		Parameter.MaxHp += MaxHp;
		Parameter.Atk += Atk;
		Parameter.Def += Def;
	}

	// 座標設定.
	void SetPosition(const Vector2D &InPosition) { Position = InPosition; }

	// 回転を設定.
	void SetRotation(float Value) { Rot.Set(Value); }

private:

	// パラメータ
	CharacterParameter Parameter;

};

#endif		// #ifndef __CHARACTERBASE_H__
