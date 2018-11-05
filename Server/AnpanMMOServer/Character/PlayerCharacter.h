#ifndef __PLAYERCHARACTER_H__
#define __PLAYERCHARACTER_H__

#include "CharacterBase.h"
#include "PlayerExp.h"

class PlayerCharacter;
typedef weak_ptr<PlayerCharacter> PlayerCharacterPtr;
class Client;

/**
 * プレイヤーキャラクタ
 */
class PlayerCharacter : public CharacterBase
{

public:

	// コンストラクタ
	PlayerCharacter(Client *pInClient, int MaxHp, int Atk, int Def, int InExp);

	// デストラクタ
	virtual ~PlayerCharacter() {}

	// クライアント取得.
	Client *GetClient() const { return pClient; }

private:

	// クライアント
	Client *pClient;

	// 経験値.
	PlayerExp Exp;


	// レベルアップコールバック
	void OnLevelUp();

};

#endif		// #ifndef __PLAYERCHARACTER_H__
