/**
 * @file PlayerExp.h
 * @brief プレイヤー経験値クラス
 * @author YanaP
 */
#ifndef __PLAYEREXP_H__
#define __PLAYEREXP_H__

#include <boost/function.hpp>

/**
 * @class PlayerExp
 * @brief プレイヤーの経験値管理.
 */
class PlayerExp
{

public:

	/**
	 * @brief コンストラクタ
	 * @param[in] InExp 経験値
	 */
	PlayerExp(int InExp);

	/**
	 * @brief デストラクタ
	 */
	~PlayerExp() {}

	/**
	 * @fn void Add(int Value)
	 * @brief 増加
	 * @param[in] Value 増加量
	 */
	void Add(int Value);

	/**
	 * @fn int Get() const
	 * @brief 取得
	 * @return 経験値
	 */
	int Get() const { return Exp; }

	/**
	 * @fn void SetLevelUpCallback(const function<void()> &InLevelUpCallback)
	 * @brief レベルアップコールバックを設定
	 * @param[in] InLevelUpCallback レベルアップコールバック
	 */
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
