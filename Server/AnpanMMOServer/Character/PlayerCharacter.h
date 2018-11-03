#ifndef __PLAYERCHARACTER_H__
#define __PLAYERCHARACTER_H__

#include "CharacterBase.h"

/**
 * プレイヤーキャラクタ
 */
class PlayerCharacter : public CharacterBase
{

public:

	// コンストラクタ
	PlayerCharacter(int MaxHp, int Atk, int Def);

	// デストラクタ
	virtual ~PlayerCharacter() {}

private:

};

#endif		// #ifndef __PLAYERCHARACTER_H__
