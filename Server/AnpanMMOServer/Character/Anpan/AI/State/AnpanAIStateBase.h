#ifndef __ANPANAISTATEBASE_H__
#define __ANPANAISTATEBASE_H__

class Anpan;

/**
 * アンパンＡＩステート基底クラス
 */
class AnpanAIStateBase
{

public:

	// コンストラクタ
	AnpanAIStateBase(Anpan *pInParent);

	// デストラクタ
	virtual ~AnpanAIStateBase() = 0;

	// 毎フレームの処理.
	virtual void Poll(int DeltaTime) {}

protected:

	// 親を取得.
	Anpan *GetParent() { return pParent; }

private:

	// 親.
	Anpan *pParent;

};

#endif		// #ifndef __ANPANAISTATEBASE_H__
