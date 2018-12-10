#ifndef __SKILLRECAST_H__
#define __SKILLRECAST_H__

#include <boost/unordered_map.hpp>

class CharacterBase;

/**
 * スキルリキャストタイム管理.
 */
class SkillRecastManager
{

private:		// 別名定義.

	typedef boost::unordered_map<u32, s32> RecastMap;

public:

	// コンストラクタ
	SkillRecastManager(CharacterBase *pInOwner);

	// デストラクタ
	~SkillRecastManager() {}

	// 毎フレームの処理.
	void Poll(s32 DeltaTime);

	// 追加。
	void Add(u32 SkillId);

	// リキャスト中か？
	bool IsRecast(u32 SkillId) const;

private:

	CharacterBase *pOwner;

	// リキャストリスト
	RecastMap RecastList;

};

#endif		// #ifndef __SKILLRECAST_H__
