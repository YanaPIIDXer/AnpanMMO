#ifndef __ANPANAISTATEACTIVE_H__
#define __ANPANAISTATEACTIVE_H__

#include "AnpanAIStateBase.h"

class CharacterBase;

/**
 * アンパンＡＩステート：アクティブ状態.
 */
class AnpanAIStateActive : public AnpanAIStateBase
{
	
public:

	// コンストラクタ
	AnpanAIStateActive(Anpan *pInParent);

	// デストラクタ
	virtual ~AnpanAIStateActive() {}

protected:

	// 更新.
	virtual void Update(int DeltaTime);

private:

	// 現在のターゲット
	weak_ptr<CharacterBase> pCurrentTarget;

	// 移動タイマー
	int MoveTimer;

};


#endif		// #ifndef __ANPANAISTATEACTIVE_H__
