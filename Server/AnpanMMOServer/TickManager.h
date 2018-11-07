#ifndef __TICKMANAGER_H__
#define __TICKMANAGER_H__

#include <boost/function.hpp>
#include <vector>

/**
 * ���Ԃ𔺂��t���[�������Ǘ�.
 */
class TickManager
{

private:		// �ʖ���`.

	typedef boost::function<void(int)> TickFunction;

public:

	// �f�X�g���N�^
	~TickManager() {}

	// ���t���[���̏���.
	void Poll();

	// �ǉ�.
	void Add(const TickFunction &Function);

private:

	// �ȑO�̎���.
	int PrevTime;

	// �֐����X�g
	std::vector<TickFunction> Functions;

	// ========== Singleton ============
public:

	static TickManager &GetInstance() { return Instance; }

private:

	// �R���X�g���N�^
	TickManager();
	static TickManager Instance;
};

#endif		// #ifndef __TICKMANAGER_H__
