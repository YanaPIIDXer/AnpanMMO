#ifndef __ITEMLIST_H__
#define __ITEMLIST_H__

#include <boost/unordered_map.hpp>

/**
 * アイテムリストクラス
 */
class ItemList
{

private:		// 別名定義.

	typedef boost::unordered_map<u32, u32> ItemMap;

public:

	// コンストラクタ
	ItemList();

	// デストラクタ
	~ItemList() {}

	// 追加.
	void Add(u32 ItemId, u32 Count);

	// 消費.
	void Subtract(u32 ItemId, u32 Count);

	// 個数を取得.
	u32 GetCount(u32 ItemId) const;

private:

	// アイテムマップ
	ItemMap Items;

};

#endif		// #ifndef __ITEMLIST_H__
