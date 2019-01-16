/**
 * @file DebuffParalysis.h
 * @brief 麻痺デバフクラス
 * @author YanaP
 */
#ifndef __DEBUFFPARALYSIS_H__
#define __DEBUFFPARALYSIS_H__

#include "BuffBase.h"
#include "Master/BuffMaster.h"

/**
 * @class DebuffParalysis
 * @brief 麻痺デバフ
 */
class DebuffParalysis : public BuffBase
{

public:

	/**
	 * @brief コンストラクタ
	 * @param[in] Time 継続時間
	 * @param[in] pInCharacter キャラクタ
	 */
	DebuffParalysis(u32 Time, CharacterBase *pInCharacter);

	/**
	 * @brief デストラクタ
	 */
	virtual ~DebuffParalysis() {}

	/**
	 * @fn virtual u8 GetType() const
	 * @brief タイプを取得
	 * @return タイプ
	 */
	virtual u8 GetType() const { return BuffItem::PARALYSIS; }

};

#endif			// #ifndef __DEBUFFPARALYSIS_H__
