#ifndef __ANPANAI_H__
#define __ANPANAI_H__

#include "AnpanAIPacketData.h"

class Anpan;
class AnpanAIStateBase;

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
	AnpanMovePacketData *SweepMovePacketData();

	// 回転パケットデータの生成.
	void CreateRotatePacketData(const Rotation &Rot, int Time);

	// 回転パケットデータの取得.
	AnpanRotatePacketData *SweepRotatePacketData();

private:

	// 親.
	Anpan *pParent;

	// ステート
	AnpanAIStateBase *pState;

	// 移動パケットデータ
	AnpanMovePacketData *pMovePacketData;

	// 回転パケットデータ
	AnpanRotatePacketData *pRotatePacketData;

};

#endif		// #ifndef __ANPANAI_H__
