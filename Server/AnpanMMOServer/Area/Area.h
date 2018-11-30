#ifndef __AREA_H__
#define __AREA_H__

#include "AreaBase.h"

struct AreaItem;

/**
 * エリアクラス
 */
class Area : public AreaBase
{

public:

	// コンストラクタ
	Area(const AreaItem *pItem);

	// デストラクタ
	virtual ~Area() {}

	// ID取得.
	virtual u32 GetId() const { return Id; }

	// 消去可能か？
	virtual bool IsAbleDelete() const { return false; }

private:

	// ID
	u32 Id;

};

#endif		// #ifndef __AREA_H__
