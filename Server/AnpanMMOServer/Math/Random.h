#ifndef __RANDOM_H__
#define __RANDOM_H__

#include <boost/random.hpp>
#include <boost/random/random_device.hpp>

/**
 * 乱数クラス
 */
class Random : noncopyable
{

public:

	// デストラクタ
	~Random() {}

	// 範囲を指定して取得.
	template<class T>
	static T Range(T Min, T Max);

private:

	boost::random::random_device SeedGen;
	boost::random::mt19937 Gen;

	// ========== Singleton ============
private:

	// コンストラクタ
	Random();
	static Random Instance;

};

#endif		// #ifndef __RANDOM_H__
