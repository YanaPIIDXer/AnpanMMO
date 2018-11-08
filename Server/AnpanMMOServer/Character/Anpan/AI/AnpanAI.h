#ifndef __ANPANAI_H__
#define __ANPANAI_H__

class Anpan;

/**
 * アンパンＡＩクラス
 */
class AnpanAI
{

public:

	// コンストラクタ
	AnpanAI(Anpan *pInParent);

	// デストラクタ
	~AnpanAI() {}

private:

	// 親.
	Anpan *pParent;

};

#endif		// #ifndef __ANPANAI_H__
