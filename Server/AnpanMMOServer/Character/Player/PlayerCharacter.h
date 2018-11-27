#ifndef __PLAYERCHARACTER_H__
#define __PLAYERCHARACTER_H__

#include "Character/CharacterBase.h"
#include "PlayerExp.h"
#include "Packet/CharacterType.h"

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

	// 名前を設定.
	void SetName(const std::string &InName) { Name = InName; }

	// 名前を取得.
	const std::string &GetName() const { return Name; }

	// キャラクタタイプを取得.
	virtual u8 GetCharacterType() const { return CharacterType::Player; }

private:

	// クライアント
	Client *pClient;

	// 経験値.
	PlayerExp Exp;

	// 名前.
	std::string Name;


	// レベルアップコールバック
	void OnLevelUp();

	// パラメータを保存.
	void SaveParameter();

};

#endif		// #ifndef __PLAYERCHARACTER_H__
