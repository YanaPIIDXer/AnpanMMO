#ifndef __SKILLSTATENUTRAL_H__
#define __SKILLSTATENUTRAL_H__

#include "SkillStateBase.h"

/**
 * スキルステート：何もしていない
 */
class SkillStateNutral : public SkillStateBase
{

public:

	// コンストラクタ
	SkillStateNutral(SkillControl *pInControl);

	// デストラクタ
	virtual ~SkillStateNutral() {}

};


#endif		// #ifndef __SKILLSTATENUTRAL_H__
