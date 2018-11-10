#ifndef __PLAYERCHARACTER_H__
#define __PLAYERCHARACTER_H__

#include "Character/CharacterBase.h"
#include "PlayerExp.h"
#include "Packet/CharacterType.h"

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
	virtual ~PlayerCharacter();

	// クライアント取得.
	Client *GetClient() const { return pClient; }

	// 経験値追加.
	void AddExp(int Value) { Exp.Add(Value); }

	// 経験値取得.
	int GetExp() const { return Exp.Get(); }

	// キャラクタタイプを取得.
	virtual u8 GetCharacterType() const { return CharacterType::Player; }

private:

	// クライアント
	Client *pClient;

	// 経験値.
	PlayerExp Exp;


	// レベルアップコールバック
	void OnLevelUp();

	// パラメータを保存.
	void SaveParameter();

};

#endif		// #ifndef __PLAYERCHARACTER_H__
