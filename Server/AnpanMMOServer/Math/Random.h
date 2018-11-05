#ifndef __RANDOM_H__
#define __RANDOM_H__

#include <boost/random.hpp>
#include <boost/random/random_device.hpp>

/**
 * �����N���X
 */
class Random : noncopyable
{

public:

	// �f�X�g���N�^
	~Random() {}

	// �͈͂��w�肵�Ď擾.
	template<class T>
	static T Range(T Min, T Max);

private:

	boost::random::random_device SeedGen;
	boost::random::mt19937 Gen;

	// ========== Singleton ============
private:

	// �R���X�g���N�^
	Random();
	static Random Instance;

};

#endif		// #ifndef __RANDOM_H__
