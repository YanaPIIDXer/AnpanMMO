#ifndef __SKILLRECAST_H__
#define __SKILLRECAST_H__

#include <boost/unordered_map.hpp>
#include <boost/function.hpp>

class CharacterBase;

/**
 * �X�L�����L���X�g�^�C���Ǘ�.
 */
class SkillRecastManager
{

private:		// �ʖ���`.

	typedef boost::unordered_map<u32, s32> RecastMap;
	typedef boost::function<void(u32)> RecastFinishedFunction;

public:

	// �R���X�g���N�^
	SkillRecastManager(CharacterBase *pInOwner);

	// �f�X�g���N�^
	~SkillRecastManager() {}

	// ���t���[���̏���.
	void Poll(s32 DeltaTime);

	// �ǉ��B
	void Add(u32 SkillId);

	// ���L���X�g�����H
	bool IsRecast(u32 SkillId) const;

	// ���L���X�g�������������ɑ��点�鏈����ݒ�.
	void SetRecastFinishedFunction(const RecastFinishedFunction &Func) { RecastFinishedFunc = Func; }

private:

	CharacterBase *pOwner;

	// ���L���X�g���X�g
	RecastMap RecastList;

	// ���L���X�g�������ɑ��点�鏈��.
	RecastFinishedFunction RecastFinishedFunc;

};

#endif		// #ifndef __SKILLRECAST_H__
