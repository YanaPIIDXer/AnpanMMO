#ifndef __TICKMANAGER_H__
#define __TICKMANAGER_H__

#include <boost/function.hpp>
#include <vector>

/**
 * 時間を伴うフレーム処理管理.
 */
class TickManager
{

private:		// 別名定義.

	typedef boost::function<void(int)> TickFunction;

public:

	// デストラクタ
	~TickManager() {}

	// 毎フレームの処理.
	void Poll();

	// 追加.
	void Add(const TickFunction &Function);

private:

	// 以前の時間.
	int PrevTime;

	// 関数リスト
	std::vector<TickFunction> Functions;

	// ========== Singleton ============
public:

	static TickManager &GetInstance() { return Instance; }

private:

	// コンストラクタ
	TickManager();
	static TickManager Instance;
};

#endif		// #ifndef __TICKMANAGER_H__
