#ifndef __ANPANAI_H__
#define __ANPANAI_H__

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

private:

	// 親.
	Anpan *pParent;

	// ステート
	AnpanAIStateBase *pState;

};

#endif		// #ifndef __ANPANAI_H__
