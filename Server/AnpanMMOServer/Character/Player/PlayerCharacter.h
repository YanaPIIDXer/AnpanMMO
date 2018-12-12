#ifndef __PLAYERCHARACTER_H__
#define __PLAYERCHARACTER_H__

#include "Character/CharacterBase.h"
#include "PlayerExp.h"
#include "WeakPtrDefine.h"
#include "Packet/CharacterType.h"

class Client;

/**
 * プレイヤーキャラクタ
 */
class PlayerCharacter : public CharacterBase
{

public:

	// コンストラクタ
	PlayerCharacter(Client *pInClient, u8 Job, int MaxHp, int Atk, int Def, int InExp, u32 InGold);

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

	// ジョブを取得.
	u8 GetJob() const { return Job; }

	// キャラクタタイプを取得.
	virtual u8 GetCharacterType() const { return CharacterType::Player; }

	// パーティを設定.
	void SetParty(const PartyPtr &pInParty) { pParty = pInParty; }

	// パーティを取得.
	PartyPtr GetParty() const { return pParty; }

	// 移動した。
	void OnMoved();

	// エリアが切り替わった。
	void OnAreaChange();

	// ゴールド取得.
	u32 GetGold() const { return Gold; }

	// ゴールドを追加.
	void AddGold(u32 Value);

	// ゴールドを消費.
	void SubtractGold(u32 Value);

private:

	// クライアント
	Client *pClient;

	// 経験値.
	PlayerExp Exp;

	// 名前.
	std::string Name;

	// ジョブ
	u8 Job;

	// ゴールド
	u32 Gold;

	// パーティ
	PartyPtr pParty;

	// セーブするエリアＩＤ
	u32 SaveAreaId;

	// セーブする座標.
	Vector3D SavePosition;


	// レベルアップコールバック
	void OnLevelUp();

	// パラメータを保存.
	void SaveParameter();

	// スキルがキャンセルされた。
	void OnSkillCanceled(u8 Reason);

	// リキャストが完了した。
	void OnSkillRecastFinished(u32 SkillId);

};

#endif		// #ifndef __PLAYERCHARACTER_H__
