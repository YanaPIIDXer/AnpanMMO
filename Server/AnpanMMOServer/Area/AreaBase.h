/**
 * @file AreaBase.h
 * @brief エリア基底クラス
 * @author YanaP
 */

#ifndef __AREABASE_H__
#define __AREABASE_H__

#include <boost/enable_shared_from_this.hpp>
#include "PlayerManager.h"
#include "AnpanManager.h"
#include "HeightMap.h"

struct AreaItem;
class PacketBase;
class CharacterBase;

/**
 * @brief エリア基底クラス
 */
class AreaBase : public enable_shared_from_this<AreaBase>
{

public:

	/**
	 * @brief コンストラクタ
	 * @param[in] pItem エリアマスタアイテム
	 */
	AreaBase(const AreaItem *pItem);

	/**
	 * @brief デストラクタ
	 */
	virtual ~AreaBase() {}

	/**
	 * @fn virtual void Initialize
	 * @brief 初期化
	 */
	virtual void Initialize() {}

	/**
	 * @fn void Poll(int DeltaTime)
	 * @brief 毎フレームの処理
	 * @param[in] 前フレームからの経過時間
	 */
	void Poll(int DeltaTime);

	/**
	 * @fn void AddPlayerCharacter(const PlayerCharacterPtr &pPlayer)
	 * @brief プレイヤーキャラ追加
	 * @param[in] pPlayer プレイヤーキャラへのweak_ptr
	 */
	void AddPlayerCharacter(const PlayerCharacterPtr &pPlayer);

	/**
	 * @fn void RemovePlayerCharacter(u32 Uuid)
	 * @brief プレイヤーキャラ削除
	 * @param[in] Uuid プレイヤーキャラのＵＵＩＤ
	 */
	void RemovePlayerCharacter(u32 Uuid);

	/**
	 * @fn void OnRecvMove(u32 Uuid, float X, float Y, float Z, float Rotation)
	 * @brief 移動を受信した
	 * @param[in] Uuid プレイヤーキャラのＵＵＩＤ
	 * @param[in] X Ｘ座標
	 * @param[in] Y Ｙ座標
	 * @param[in] Z Ｚ座標
	 * @param[in] Rotation 回転
	 */
	void OnRecvMove(u32 Uuid, float X, float Y, float Z, float Rotation);

	/**
	 * @fn void OnRecvSkillUse(u32 Uuid, u32 SkillId, u8 TargetType, u32 TargetUuid)
	 * @brief スキル使用を受信した。
	 * @param[in] Uuid プレイヤーキャラのＵＵＩＤ
	 * @param[in] SkillId スキルＩＤ
	 * @param[in] TargetType ターゲットタイプ
	 * @param[in] TargetUuid ターゲットのＵＵＩＤ
	 */
	void OnRecvSkillUse(u32 Uuid, u32 SkillId, u8 TargetType, u32 TargetUuid);

	/**
	 * @fn void OnRecvUseItem(u32 Uuid, u32 ItemId, u8 TargetType, u32 TargetUuid)
	 * @brief アイテム使用を受信した。
	 * @param[in] Uuid プレイヤーキャラのＵＵＩＤ
	 * @param[in] ItemId アイテムＩＤ
	 * @param[in] TargetType ターゲットタイプ
	 * @param[in] TargetUuid ターゲットのＵＵＩＤ
	 */
	void OnRecvItemUse(u32 Uuid, u32 ItemId, u8 TargetType, u32 TargetUuid);

	/**
	 * @fn void BroadcastPacket(PacketBase *pPacket, Client *pIgnoreClient = NULL)
	 * @brief パケットのブロードキャスト
	 * @details エリア内にいるプレイヤー全員にパケットをバラ撒く。
	 * @param[in] pPacket パケット
	 * @param[in] pIgnoreClient 除外するクライアント
	 */
	void BroadcastPacket(PacketBase *pPacket, Client *pIgnoreClient = NULL);

	/**
	 * @fn void BroadcastPacketWithRange(PacketBase *pPacket, const Vector3D &Center, float Range, Client *pIgnoreClient = NULL)
	 * @brief 範囲を指定したパケットのブロードキャスト
	 * @details 範囲内にいるプレイヤー全員にパケットをバラ撒く。
	 * @param[in] pPacket パケット
	 * @param[in] Center 中心座標
	 * @param[in] Range 半径
	 * @param[in] pIgnoreClient 除外するクライアント
	 */
	void BroadcastPacketWithRange(PacketBase *pPacket, const Vector3D &Center, float Range, Client *pIgnoreClient = NULL);

	/**
	 * @fn float GetHeight(float X, float Y) const
	 * @brief 高さを取得
	 * @details ハイトマップを参照して高さを返す
	 * @param[in] X Ｘ座標
	 * @param[in] Y Ｙ座標
	 * @return 高さ
	 */
	float GetHeight(float X, float Y) const;

	/**
	 * @fn bool CheckMovable(const Vector3D &Start, const Vector3D &End, float ClimbableHeight, Vector3D &OutHit) const
	 * @brief 移動できるかどうかをチェック
	 * @details レイキャストによるチェック
	 * @param[in] Start チェック開始地点
	 * @param[in] End チェック終了地点
	 * @param[in] float ClimbableHeight 登ることができる高さ
	 * @param[out] OutHit レイが当たった地点
	 * @return 移動可能ならtrueを返す
	 */
	bool CheckMovable(const Vector3D &Start, const Vector3D &End, float ClimbableHeight, Vector3D &OutHit) const;

	/**
	 * @fn virtual u32 GetId() const = 0
	 * @brief IDを取得
	 * @details マスタのＩＤとは異なる可能性がある。マスタＩＤを取得したい場合はGetMasterId関数を使用する。
	 * @return ID
	 */
	virtual u32 GetId() const = 0;

	/**
	 * @fn u32 GetMasterId() const
	 * @brief マスタＩＤを取得
	 * @return マスタＩＤ
	 */
	u32 GetMasterId() const { return MasterId; }

	/**
	 * @fn virtual bool IsAbleDelete() const
	 * @brief 消去可能か？
	 * @return 消去可能ならtrueを返す。
	 */
	virtual bool IsAbleDelete() const = 0;

	/**
	 * @fn virtual bool IsInstance() const
	 * @brief インスタンスエリアか？
	 * @return インスタンスエリアならtrueを返す。
	 */
	virtual bool IsInstance() const { return false; }

	/**
	 * @fn void CollectCircle(const Vector3D &Center, float Radius, u8 TargetType, std::vector<CharacterBase *> &OutTargets)
	 * @brief 円形でターゲットを取得
	 * @param[in] Center 中心座標
	 * @param[in] Radius 半径
	 * @param[in] TargetType ターゲットタイプ
	 * @param[out] OutTargets ターゲットリスト
	 */
	void CollectCircle(const Vector3D &Center, float Radius, u8 TargetType, std::vector<CharacterBase *> &OutTargets);

	/**
	 * @fn void CollectBox(const Vector3D &Center, float Width, float Height, u8 TargetType, std::vector<CharacterBase *> &OutTargets)
	 * @brief 矩形でターゲットを取得
	 * @param[in] Center 中心座標
	 * @param[in] Width 幅
	 * @param[in] Height 高さ
	 * @param[in] TargetType ターゲットタイプ
	 * @param[out] OutTargets ターゲットリスト
	 */
	void CollectBox(const Vector3D &Center, float Width, float Height, u8 TargetType, std::vector<CharacterBase *> &OutTargets);

protected:

	//! プレイヤー管理.
	PlayerManager PlayerMgr;

	//! アンパン管理.
	AnpanManager AnpanMgr;


	/**
	 * @fn virtual void Update()
	 * @brief 更新処理
	 */
	virtual void Update() {}

private:

	// ハイトマップ
	HeightMap HeightData;

	//! マスタＩＤ
	u32 MasterId;


	// アンパンが生成された。
	void OnSpawnAnpan(u32 Uuid, AnpanPtr pAnpan);

};

#endif		// #ifndef __AREABASE_H__
