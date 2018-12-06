#ifndef __EXECUTERPOOL_H__
#define __EXECUTERPOOL_H__

#include <map>

struct lua_State;
class ScriptExecuterBase;

/**
 * �X�N���v�g���s�I�u�W�F�N�g�v�[��
 * Lua�̓����o�֐����o�C���h�o���Ȃ��ׁA������������邽�߂̃N���X�B
 * �T�[�o�̏ꍇ�AExecuter��������������邽�߁ASingleton�ł̑Ώ��ł͖�肪�o��B
 */
class ExecuterPool
{

public:

	// �f�X�g���N�^
	~ExecuterPool() {}

	// �o�^.
	void Register(ScriptExecuterBase *pExecuter, lua_State *pState);

	// �擾.
	ScriptExecuterBase *Get(lua_State *pState);

	// �폜.
	void Remove(lua_State *pState);

private:

	// �v�[��
	std::map<lua_State *, ScriptExecuterBase *> Pool;

	// ======= Singleton =========
public:

	static ExecuterPool &GetInstance() { return Instance; }

private:

	ExecuterPool();
	static ExecuterPool Instance;

};

#endif		// #ifndef __EXECUTERPOOL_H__
