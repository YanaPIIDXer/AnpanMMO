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

	// ビットフィールドに変換.
	void ToBitField(u32 &OutBitField1, u32 &OutBitField2, u32 &OutBitField3) const;

	// ビットフィールドから変換.
	void FromBitField(u32 BitField1, u32 BitField2, u32 BitField3);

private:

	// フラグマップ
	FlagMap Flags;

};

#endif		// #ifndef __SCRIPTFLAGMANAGER_H__
