#ifndef __PLAYEREXP_H__
#define __PLAYEREXP_H__

#include <boost/function.hpp>

/**
 * プレイヤーの経験値管理.
 */
class PlayerExp
{

public:

	// コンストラクタ
	PlayerExp(int InExp);

	// デストラクタ
	~PlayerExp() {}

	// 経験値追加.
	void Add(int Value);

	// 取得.
	int Get() const { return Exp; }

	// レベルアップコールバックを設定.
	void SetLevelUpCallback(const function<void()> &InLevelUpCallback) { LevelUpCallback = InLevelUpCallback; }

private:

	// レベルアップに必要な経験値.
	static const int LevelUpExp;

	// 経験値
	int Exp;

	// レベルアップコールバック
	function<void()> LevelUpCallback;

};

#endif		// #ifndef __PLAYEREXP_H__
