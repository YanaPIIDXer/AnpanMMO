/**
 * @file PlayerCharacter.h
 * @brief プレイヤーキャラクタクラス
 * @author YanaP
 */
#ifndef __PLAYERCHARACTER_H__
#define __PLAYERCHARACTER_H__

#include "Character/CharacterBase.h"
#include "PlayerExp.h"
#include "Skill/SkillTree/SkillTree.h"
#include "WeakPtrDefine.h"
#include "Packet/CharacterType.h"
#include "Item/ItemList.h"
#include "Equip/EquipData.h"

class Client;
class ItemData;

/**
 * @class PlayerCharacter
 * @brief プレイヤーキャラクタ
 */
class PlayerCharacter : public CharacterBase
{

public:

	/**
	 * @brief コンストラクタ
	 * @param[in] pInClient クライアント
	 * @param[in] InCharacterId キャラクタＩＤ
	 * @param[in] InJob ジョブ
	 * @param[in] Level レベル
	 * @param[in] InExp 経験値
	 * @param[in] InGold ゴールド
	 * @oaran[in] RightEquipId 右手装備ＩＤ
	 * @param[in] LeftEquipId 左手装備ＩＤ
	 */
	PlayerCharacter(Client *pInClient, u32 InCharacterId, u8 InJob, u32 Level, u32 InExp, u32 InGold, u32 RightEquipId, u32 LeftEquipId);

	/**
	 * @brief デストラクタ
	 */
	virtual ~PlayerCharacter();

	/**
	 * @fn Client *GetClient() const
	 * @brief クライアント取得
	 * @return クライアント
	 */
	Client *GetClient() const { return pClient; }

	/**
	 * @fn void AddExp(int Value)
	 * @brief 経験値増加
	 * @param[in] Value 増加量
	 */
	void AddExp(int Value) { Exp.Add(Value); }

	/**
	 * @fn int GetExp() const
	 * @brief 経験値取得
	 * @return 経験値
	 */
	int GetExp() const { return Exp.Get(); }

	/**
	 * @fn void SetName(const std::string &InName)
	 * @brief 名前を設定
	 * @param[in] InName 名前
	 */
	void SetName(const std::string &InName) { Name = InName; }

	/**
	 * @fn const std::string &GetName() const
	 * @brief 名前を取得
	 * @return 名前
	 */
	const std::string &GetName() const { return Name; }

	/**
	 * @fn u32 GetCharacterId() const
	 * @brief キャラクタＩＤ取得
	 * @return キャラクタＩＤ
	 */
	u32 GetCharacterId() const { return CharacterId; }

	/**
	 * @fn u8 GetJob() const
	 * @brief ジョブを取得
	 * @return ジョブ
	 */
	u8 GetJob() const { return Job; }

	/**
	 * @fn virtual u8 GetCharacterType() const
	 * @brief キャラクタタイプを取得
	 * @return キャラクタタイプ
	 */
	virtual u8 GetCharacterType() const { return CharacterType::Player; }

	/**
	 * @fn void SetParty(const PartyPtr &pInParty)
	 * @brief パーティを設定
	 * @param[in] pInParty パーティへのweak_ptr
	 */
	void SetParty(const PartyPtr &pInParty) { pParty = pInParty; }

	/**
	 * @fn PartyPtr GetParty() const
	 * @brief パーティを取得
	 * @return パーティへのweak_ptr
	 */
	PartyPtr GetParty() const { return pParty; }

	/**
	 * @fn void OnMoved()
	 * @brief 移動した
	 */
	void OnMoved();

	/**
	 * @fn void OnAreaChange()
	 * @brief エリアが切り替わった
	 */
	void OnAreaChange();

	/**
	 * @fn 832 GetGold() const
	 * @brief ゴールドを取得
	 * @return ゴールド
	 */
	u32 GetGold() const { return Gold; }

	/**
	 * @fn void AddGold(u32 Value)
	 * @brief ゴールドを増加
	 * @param[in] Value 増加量
	 */
	void AddGold(u32 Value);

	/**
	 * @fn void SubtractGold(u32 Value)
	 * @brief ゴールドを消費
	 * @param[in] Value 消費量
	 */
	void SubtractGold(u32 Value);

	/**
	 * @fn void InitializeSkillTree(const FlexArray<u32> &OpenedNodes)
	 * @brief スキルツリー初期化
	 * @param[in] OpenedNodes 開いているノード
	 */
	void InitializeSkillTree(const FlexArray<u32> &OpenedNodes);

	/**
	 * @fn const SkillTree &GetSkillTree() const
	 * @brief スキルツリー取得
	 * @return スキルツリー
	 */
	const SkillTree &GetSkillTree() const { return Tree; }

	/**
	 * @fn u8 OpenSkillTree(u32 NodeId)
	 * @brief スキルツリーのノードを開く
	 * @param[in] NodeId ノードＩＤ
	 * @return リザルトコード
	 */
	u8 OpenSkillTree(u32 NodeId);

	/**
	 * @fn void OnRecvItemList(const FlexArray<ItemData> &List)
	 * @brief アイテムリストを受信した
	 * @param[in] List アイテムリスト
	 */
	void OnRecvItemList(const FlexArray<ItemData> &List);

	/**
	 * @fn void UseItem(u32 ItemId, CharacterPtr pTarget)
	 * @brief アイテム使用
	 * @param[in] ItemId アイテムＩＤ
	 * @param[in] pTarget ターゲットへのweak_ptr
	 */
	void UseItem(u32 ItemId, CharacterPtr pTarget);

	/**
	 * @fn void AddItem(u32 ItemId, u32 Count)
	 * @brief アイテム増加
	 * @param[in] ItemId アイテムＩＤ
	 * param[in] Count 個数
	 */
	void AddItem(u32 ItemId, u32 Count);

	/**
	 * @fn void SubtractItem(u32 ItemId, u32 Count)
	 * @brief アイテム消費
	 * @param[in] ItemId アイテムＩＤ
	 * @param[in] Count 個数
	 */
	void SubtractItem(u32 ItemId, u32 Count);

	/**
	 * @fn const ItemList &GetItemList() const
	 * @brief アイテムリスト取得
	 * @return アイテムリスト
	 */
	const ItemList &GetItemList() const { return Items; }

	/**
	 * @fn void ChangeEquip(u32 RightEquipId, u32 LeftEquipId)
	 * @brief 装備切り替え
	 * @param[in] RightEquipId 右手装備ＩＤ
	 * @param[in] LeftEquipId 左手装備ＩＤ
	 */
	void ChangeEquip(u32 RightEquipId, u32 LeftEquipId);

private:

	// クライアント
	Client *pClient;

	// 経験値.
	PlayerExp Exp;

	// キャラクタＩＤ
	u32 CharacterId;

	// 名前.
	std::string Name;

	// ジョブ
	u8 Job;

	// ゴールド
	u32 Gold;

	// パーティ
	PartyPtr pParty;

	// スキルツリー
	SkillTree Tree;

	// アイテムリスト
	ItemList Items;

	// 右手装備.
	EquipData RightEquip;

	// 左手装備.
	EquipData LeftEquip;

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

	// アイテムを使用した。
	void OnUsedItem(u32 ItemId);

	// 殺害した。
	void OnKilled(CharacterBase *pKilledCharacter);

	// ドロップアイテムを取得。
	void GetDrop(u32 DropId);

};

#endif		// #ifndef __PLAYERCHARACTER_H__
