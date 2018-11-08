#ifndef __ANPANAI_H__
#define __ANPANAI_H__

#include "AnpanAIPacketData.h"
#include "Hate.h"

class Anpan;
class AnpanAIStateBase;
class CharacterBase;

/**
 * アンパンＡＩクラス
 */
class AnpanAI
{

public:

	// コンストラクタ
	AnpanAI(Anpan *pInParent);

	// デストラクタ
	~AnpanAI();

	// 毎フレームの処理.
	void Poll(int DeltaTime);

	// ステート切り替え.
	void ChangeState(AnpanAIStateBase *pNewState);

	// 移動パケットデータの生成.
	void CreateMovePacketData(const Vector2D &Position, int Time);

	// 移動パケットデータの取得.
	shared_ptr<AnpanMovePacketData> SweepMovePacketData();

	// 回転パケットデータの生成.
	void CreateRotatePacketData(const Rotation &Rot, int Time);

	// 回転パケットデータの取得.
	shared_ptr<AnpanRotatePacketData> SweepRotatePacketData();

	// ダメージを受けた。
	void OnDamaged(weak_ptr<CharacterBase> pAttacker, int DamageValue);

	// ヘイト管理取得.
	const Hate &GetHate() const { return HateManager; }

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

};

#endif		// #ifndef __ANPANAI_H__
