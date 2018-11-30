#ifndef __AREAMANAGER_H__
#define __AREAMANAGER_H__

#include <boost/unordered_map.hpp>
#include "AreaBase.h"

class Client;
class MemoryStreamInterface;

/**
 * �G���A�}�l�[�W��
 */
class AreaManager : public noncopyable
{

private:		// �ʖ���`.

	typedef shared_ptr<AreaBase> AreaSharedPtr;
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

	// �C���X�^���X�}�b�v�𐶐�.
	AreaPtr CreateInstanceArea(u32 AreaId);

private:

	// �G���A�}�b�v
	AreaMap Areas;

	// ���ɔ��s����C���X�^���X�}�b�v��UUID
	u32 NextInstanceAreaUuid;


	// ========== Singleton ===============

public:

	static AreaManager &GetInstance() { return Instance; }

private:

	AreaManager();
	static AreaManager Instance;

};

#endif		// #ifndef __AREAMANAGER_H__
