#ifndef __CHARACTERBASE_H__
#define __CHARACTERBASE_H__

#include "CharacterParameter.h"
#include "Math/Vector2D.h"

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

	// 座標取得.
	const Vector2D &GetPosition() const { return Position; }

	// 死んでいる？
	bool IsDead() const { return (Parameter.Hp <= 0); }

protected:

	// パラメータ設定.
	void SetParameter(int Hp, int MaxHp, int Atk, int Def)
	{
		Parameter.Hp = Hp;
		Parameter.MaxHp = MaxHp;
		Parameter.Atk = Atk;
		Parameter.Def = Def;
	}

	// 座標設定.
	void SetPosition(const Vector2D &InPosition) { Position = InPosition; }

private:

	// パラメータ
	CharacterParameter Parameter;

	// 座標.
	Vector2D Position;

};

#endif		// #ifndef __CHARACTERBASE_H__
