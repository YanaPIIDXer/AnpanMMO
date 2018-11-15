#ifndef __AREAMANAGER_H__
#define __AREAMANAGER_H__

#include <boost/unordered_map.hpp>

class Area;

typedef weak_ptr<Area> AreaPtr;

/**
 * �G���A�}�l�[�W��
 */
class AreaManager : public noncopyable
{

private:		// �ʖ���`.

	typedef shared_ptr<Area> AreaSharedPtr;
	typedef unordered_map<u32, AreaSharedPtr> AreaMap;

public:

	// �f�X�g���N�^
	virtual ~AreaManager() {}

	// ������.
	void Initialize();

	// �擾.
	AreaPtr Get(u32 ID) const;

	// ���t���[���̏���.
	void Poll(int DeltaTime);

private:

	// �G���A�}�b�v
	AreaMap Areas;


	// ========== Singleton ===============

public:

	static AreaManager &GetInstance() { return Instance; }

private:

	AreaManager();
	static AreaManager Instance;

};

#endif		// #ifndef __AREAMANAGER_H__