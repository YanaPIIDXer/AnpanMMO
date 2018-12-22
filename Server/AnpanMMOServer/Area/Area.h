/**
 * @file Area.h
 * @brief エリアクラス
 * @author YanaP
 */
#ifndef __AREA_H__
#define __AREA_H__

#include "AreaBase.h"

struct AreaItem;

/**
 * @class Area
 * @brief エリアクラス
 */
class Area : public AreaBase
{

public:

	/**
	 * @brief コンストラクタ
	 * @param[in] pItem エリアマスタアイテム
	 */
	Area(const AreaItem *pItem);

	/**
	 * @brief デストラクタ
	 */
	virtual ~Area() {}

	/**
	 * @fn virtual u32 GetId() const
	 * @brief ID取得.
	 * @return ID
	 * @details エリアマスタのＩＤと同一。
	 */
	virtual u32 GetId() const { return Id; }

	/**
	 * @fn virtual bool IsAbleDelete() const
	 * @brief 消去可能か？
	 * @return 消去してはいけないので常にfalseを返す。
	 */
	virtual bool IsAbleDelete() const { return false; }

private:

	// ID
	u32 Id;

};

#endif		// #ifndef __AREA_H__
