#ifndef __SKILLSTATEBASE_H__
#define __SKILLSTATEBASE_H__

class SkillControl;

// スキルステートの種類.
enum ESkillStateType
{
	// 何もしていない
	Nutral,

	// キャスト中.
	Cast,

	// オート移動.
	AutoMove,
};

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

	// ステートタイプを取得.
	virtual ESkillStateType GetStateType() = 0;

protected:

	// スキルコントロールを取得.
	SkillControl *GetControl() const { return pControl; }

private:

	// スキルコントロール
	SkillControl *pControl;

};

#endif		// #ifndef __SKILLSTATEBASE_H__
