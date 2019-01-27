/**
 * @file AnpanAI.h
 * @brief アンパンＡＩクラス
 * @author YanaP
 */
#ifndef __ANPANAI_H__
#define __ANPANAI_H__

#include "AnpanAIPacketData.h"
#include "Hate.h"
#include "WeakPtrDefine.h"

class Anpan;
class AnpanAIStateBase;
struct SkillItem;

/**
 * @class AnpanAI
 * @brief アンパンＡＩ
 */
class AnpanAI
{

public:

	/**
	 * @brief コンストラクタ
	 * @param[in] pInParent アンパン
	 */
	AnpanAI(Anpan *pInParent);

	/**
	 * @brief デストラクタ
	 */
	~AnpanAI();

	/**
	 * @fn void Poll(int DeltaTime)
	 * @brief 毎フレームの処理
	 * @param[in] DeltaTime 前フレームからの経過時間
	 */
	void Poll(int DeltaTime);

	/**
	 * @fn void ChangeState(AnpanAIStateBase *pNewState)
	 * @brief ステート切り替え
	 * @param[in] pNewState 切り替えるステート
	 */
	void ChangeState(AnpanAIStateBase *pNewState);

	/**
	 * @fn void CreateMovePacketData(const Vector3D &Position, int Time)
	 * @brief 移動パケットデータの生成
	 * @param[in] Position 座標
	 * @param[in] Time 移動時間
	 */
	void CreateMovePacketData(const Vector3D &Position, int Time);

	/**
	 * @fn shared_ptr<AnpanMovePacketData> SweepMovePacketData()
	 * @brief 移動パケットデータの取得
	 * @return 移動パケットデータのshared_ptr
	 */
	shared_ptr<AnpanMovePacketData> SweepMovePacketData();

	/**
	 * @fn void CreateRotatePacketData(const Rotation &Rot, int Time)
	 * @brief 回転パケットデータの生成
	 * @param[in] Rot 回転
	 * @param[in] TIme 回転時間
	 */
	void CreateRotatePacketData(const Rotation &Rot, int Time);

	/**
	 * @fn shared_ptr<AnpanRotatePacketData> SweepRotatePacketData()
	 * @brief 回転パケットデータの取得
	 * @return 回転パケットデータのshared_ptr
	 */
	shared_ptr<AnpanRotatePacketData> SweepRotatePacketData();

	/**
	 * @fn void SetSendStopPacket()
	 * @brief 停止パケットデータの設定.
	 */
	void SetSendStopPacket() { bIsNeedSendStopPacket = true; }

	/**
	 * @fn bool SweepSendStopPacketFlag()
	 * @brief 停止パケットの送信を取得
	 * @return 停止パケットを送る必要があるならtrueを返す。
	 */
	bool SweepSendStopPacketFlag();

	/**
	 * @fn const Hate &GetHate() const
	 * @brief ヘイト管理を取得
	 * @return ヘイト管理
	 */
	const Hate &GetHate() const { return HateManager; }

	/**
	 * @fn void Stop()
	 * @brief 停止
	 */
	void Stop();

	/**
	 * @fn void OnSkillReceived(CharacterPtr pCharacter, const SkillItem *pSkill)
	 * @brief スキルを食らった。
	 * @param[in] pCharacter スキル使用者
	 * @param[in] pSkill 食らったスキル
	 */
	void OnSkillReceived(CharacterPtr pCharacter, const SkillItem *pSkill);

private:

	// 親.
	Anpan *pParent;

	// ステート
	AnpanAIStateBase *pState;

	// 前のState
	AnpanAIStateBase *pPrevState;

	// 移動パケットデータ
	shared_ptr<AnpanMovePacketData> pMovePacketData;

	// 回転パケットデータ
	shared_ptr<AnpanRotatePacketData> pRotatePacketData;

	// ヘイト管理.
	Hate HateManager;

	// 停止パケットを送る必要があるか？
	bool bIsNeedSendStopPacket;

};

#endif		// #ifndef __ANPANAI_H__
