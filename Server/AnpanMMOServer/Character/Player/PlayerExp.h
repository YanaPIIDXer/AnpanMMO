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
	 * @fn void Add(u32 Value)
	 * @brief 増加
	 * @param[in] Value 増加量
	 */
	void Add(u32 Value);

	/**
	 * @fn u32 Get() const
	 * @brief 取得
	 * @return 経験値
	 */
	u32 Get() const { return Exp; }

	/**
	 * @fn void SetLevelUpExp(u32 InLevelUpExp)
	 * @brief レベルアップに必要な経験値を設定。
	 * @param[in] InLevelUpExp レベルアップに必要な経験値
	 */
	void SetLevelUpExp(u32 InLevelUpExp) { LevelUpExp = InLevelUpExp; }

	/**
	 * @fn void SetLevelUpCallback(const function<void()> &InLevelUpCallback)
	 * @brief レベルアップコールバックを設定
	 * @param[in] InLevelUpCallback レベルアップコールバック
	 */
	void SetLevelUpCallback(const function<void()> &InLevelUpCallback) { LevelUpCallback = InLevelUpCallback; }

private:

	// 経験値
	u32 Exp;

	// レベルアップに必要な経験値.
	u32 LevelUpExp;

	// レベルアップコールバック
	function<void()> LevelUpCallback;

};

#endif		// #ifndef __PLAYEREXP_H__
