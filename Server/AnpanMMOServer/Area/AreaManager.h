#ifndef __AREAMANAGER_H__
#define __AREAMANAGER_H__

#include <boost/unordered_map.hpp>
#include "AreaBase.h"

class Client;
class MemoryStreamInterface;

/**
 * エリアマネージャ
 */
class AreaManager : public noncopyable
{

private:		// 別名定義.

	typedef shared_ptr<AreaBase> AreaSharedPtr;
	typedef unordered_map<u32, AreaSharedPtr> AreaMap;

public:

	// デストラクタ
	virtual ~AreaManager() {}

	// 初期化.
	void Initialize();

	// 取得.
	AreaPtr Get(u32 ID) const;

	// 毎フレームの処理.
	void Poll(int DeltaTime);

private:

	// エリアマップ
	AreaMap Areas;


	// ========== Singleton ===============

public:

	static AreaManager &GetInstance() { return Instance; }

private:

	AreaManager();
	static AreaManager Instance;

};

#endif		// #ifndef __AREAMANAGER_H__
