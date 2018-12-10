#ifndef __SKILLSTATEBASE_H__
#define __SKILLSTATEBASE_H__

class SkillControl;

/**
 * スキルステート基底クラス
 */
class SkillStateBase
{

public:

	// コンストラクタ
	SkillStateBase(SkillControl *pInControl);

	// デストラクタ
	virtual ~SkillStateBase() = 0;

	// 毎フレームの処理.
	virtual void Poll(s32 DeltaTime) {}

protected:

	// スキルコントロールを取得.
	SkillControl *GetControl() const { return pControl; }

private:

	// スキルコントロール
	SkillControl *pControl;

};

#endif		// #ifndef __SKILLSTATEBASE_H__
