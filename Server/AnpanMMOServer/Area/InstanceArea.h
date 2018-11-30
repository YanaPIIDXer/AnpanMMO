#ifndef __INSTANCEAREA_H__
#define __INSTANCEAREA_H__

#include "AreaBase.h"

struct AreaItem;

/**
 * インスタンスエリア
 */
class InstanceArea : public AreaBase
{

public:

	// コンストラクタ
	InstanceArea(u32 InUuid, const AreaItem *pItem);

	// デストラクタ
	virtual ~InstanceArea() {}

	// ID取得.
	virtual u32 GetId() const { return Uuid; }

	// 消去可能か？
	virtual bool IsAbleDelete() const;

	// インスタンスエリアか？
	virtual bool IsInstance() const { return true; }

private:

	// UUID
	u32 Uuid;

};

#endif		// #ifndef __INSTANCEAREA_H__
