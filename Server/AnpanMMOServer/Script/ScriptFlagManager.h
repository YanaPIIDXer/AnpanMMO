#ifndef __SCRIPTFLAGMANAGER_H__
#define __SCRIPTFLAGMANAGER_H__

#include <boost/unordered_map.hpp>

/**
 * �X�N���v�g�t���O�Ǘ�.
 */
class ScriptFlagManager
{

private:		// �ʖ���`.

	typedef boost::unordered_map<s32, bool> FlagMap;

public:

	// �R���X�g���N�^
	ScriptFlagManager();

	// �f�X�g���N�^
	~ScriptFlagManager() {}

	// �Z�b�g
	void Set(int Key);

	// �擾.
	bool Get(int Key) const;

private:

	// �t���O�}�b�v
	FlagMap Flags;

};

#endif		// #ifndef __SCRIPTFLAGMANAGER_H__
