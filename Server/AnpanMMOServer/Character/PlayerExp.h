#ifndef __PLAYEREXP_H__
#define __PLAYEREXP_H__

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

private:

	// レベルアップに必要な経験値.
	static const int LevelUpExp;

	// 経験値
	int Exp;

};

#endif		// #ifndef __PLAYEREXP_H__
