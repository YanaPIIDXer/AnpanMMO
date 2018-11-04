#ifndef __ANPAN_H__
#define __ANPAN_H__

#include "CharacterBase.h"

/**
 * アンパンクラス
 */
class Anpan : public CharacterBase
{

public:

	// コンストラクタ
	Anpan(const Vector2D &InPosition);

	// デストラクタ
	virtual ~Anpan() {}

private:

};

#endif		// #ifndef __ANPAN_H__
