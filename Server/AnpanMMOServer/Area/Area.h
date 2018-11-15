#ifndef __AREA_H__
#define __AREA_H__

struct AreaItem;

/**
 * エリアクラス
 */
class Area
{

public:

	// コンストラクタ
	Area(const AreaItem *pInItem);

	// デストラクタ
	~Area() {}
	
private:

	// マスタデータ
	const AreaItem *pItem;

};

#endif		// #ifndef __AREA_H__
