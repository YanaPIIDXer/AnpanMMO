#ifndef __WORLD_H__
#define __WORLD_H__

/**
 * ���[���h�N���X
 */
class World : noncopyable
{

public:

	// ���t���[���̏���.
	void Poll();

private:

	// ========== Singleton =========
public:

	static World &GetInstance() { return Instance; }

private:

	// �R���X�g���N�^
	World();
	static World Instance;

};

#endif		// #ifndef __WORLD_H__
