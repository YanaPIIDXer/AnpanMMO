/**
 * @file AIGenerator.h
 * @brief ＡＩ機構構築クラス
 * @author YanaP
 */
#ifndef __AIGENERATOR_H__
#define __AIGENERATOR_H__

#include <boost/unordered_map.hpp>
#include "WeakPtrDefine.h"

/**
 * @struct AIAction
 * @brief AIの行動
 */
struct AIAction
{
	//! 行動
	u8 Action;

	//! 行動の値
	u32 Value;

	//! 次の行動
	AIActionPtr pNextAction;
};

/**
 * @class AIGenerator
 * @brief ＡＩ機構構築
 * @detail シングルトンクラス
 */
class AIGenerator : public boost::noncopyable
{

private:		// 別名定義.

	typedef shared_ptr<AIAction> AIActionSharedPtr;
	typedef boost::unordered_map<int, std::vector<AIActionSharedPtr>> ActionMap;

public:

	/**
	 * @brief デストラクタ
	 */
	virtual ~AIGenerator() {}

	/**
	 * @fn void Initialize()
	 * @brief 初期化
	 */
	void Initialize();

	/**
	 * @fn const AIActionPtr Get(u32 Id) const
	 * @brief 取得
	 * @param[in] Id ＡＩのＩＤ
	 * @return ＡＩアクションの先頭
	 */
	const AIActionPtr Get(u32 Id) const;

private:

	// 行動マップ
	ActionMap Actions;

	// ========== Singleton ===============
public:

	/**
	 * @fn static AIGenerator &GetInstance()
	 * @brief シングルトンインスタンスを取得
	 * @return シングルトンインスタンス
	 */
	static AIGenerator &GetInstance() { return Instance; }

private:

	AIGenerator();
	static AIGenerator Instance;

};

#endif		// #ifndef __AIGENERATOR_H__
