#ifndef __ANPAN_H__
#define __ANPAN_H__

#include "Character/CharacterBase.h"
#include "AI/AnpanAI.h"

/**
 * アンパンクラス
 */
class Anpan : public CharacterBase
{

public:

	// コンストラクタ
	Anpan(const Vector2D &InPosition, int Hp, int Atk, int Def);

	// デストラクタ
	virtual ~Anpan() {}
	
	// 毎フレームの処理.
	void Poll(int DeltaTime);

private:

	// AI
	AnpanAI AI;

};

#endif		// #ifndef __ANPAN_H__
