#ifndef __ANPANAISTATENONACTIVE_H__
#define __ANPANAISTATENONACTIVE_H__

#include "AnpanAIStateBase.h"

/**
 * アンパンＡＩステート：ノンアクティブ状態.
 */
class AnpanAIStateNonActive : public AnpanAIStateBase
{

public:
	
	// コンストラクタ
	AnpanAIStateNonActive(Anpan *pInParent);

	// デストラクタ
	virtual ~AnpanAIStateNonActive() {}

	// 毎フレームの処理.
	virtual void Poll(int DeltaTime);

private:

};

#endif		// #ifndef __ANPANAISTATENONACTIVE_H__
