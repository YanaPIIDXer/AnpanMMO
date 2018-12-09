#ifndef __SCRIPTFLAGMANAGER_H__
#define __SCRIPTFLAGMANAGER_H__

#include <boost/unordered_map.hpp>

/**
 * スクリプトフラグ管理.
 */
class ScriptFlagManager
{

private:		// 別名定義.

	typedef boost::unordered_map<s32, bool> FlagMap;

public:

	// コンストラクタ
	ScriptFlagManager();

	// デストラクタ
	~ScriptFlagManager() {}

	// セット
	void Set(int Key);

	// 取得.
	bool Get(int Key) const;

private:

	// フラグマップ
	FlagMap Flags;

};

#endif		// #ifndef __SCRIPTFLAGMANAGER_H__
