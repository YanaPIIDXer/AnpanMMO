#ifndef __CHARACTERBASE_H__
#define __CHARACTERBASE_H__

#include "CharacterParameter.h"

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

protected:

	// パラメータ設定.
	void SetParameter(int Hp, int MaxHp, int Atk, int Def)
	{
		Parameter.Hp = Hp;
		Parameter.MaxHp = MaxHp;
		Parameter.Atk = Atk;
		Parameter.Def = Def;
	}

private:

	// パラメータ
	CharacterParameter Parameter;

};

#endif		// #ifndef __CHARACTERBASE_H__
