#ifndef __SCRIPTEXECUTERBASE_H__
#define __SCRIPTEXECUTERBASE_H__

#include <string>

struct lua_State;

/**
 * �X�N���v�g���s���N���X
 */
class ScriptExecuterBase
{

public:

	// �R���X�g���N�^
	ScriptExecuterBase();

	// �f�X�g���N�^
	virtual ~ScriptExecuterBase();

	// �X�N���v�g���i�[���ꂽ�f�B���N�g����ݒ�B
	void SetScriptDir(const char *pScriptDir) { ScriptDir = pScriptDir; }

	// �X�N���v�g�����s�B
	void ExecuteScript(const char *pScript);

	// �X�N���v�g�̎��s���ĊJ.
	void Resume();

	// ���b�Z�[�W��\��.
	virtual void ShowMessage_Impl(const std::string &Message) = 0;

	// �I�������v�b�V�����ꂽ�B
	virtual void PushSelection_Impl(const std::string &Message) = 0;

	// �I�����\��.
	virtual void ShowSelection_Impl() = 0;

	// �I�������I�����ꂽ�B
	void OnSelectedSelection(int Index);

	// �t���O���Z�b�g
	virtual void SetFlag(const char *pFlagName) = 0;

	// �t���O���擾.
	virtual bool GetFlag(const char *pFlagName) = 0;

protected:

	// ���s�G���[
	virtual void OnExecuteError(const std::string &ErrorMessage) = 0;

private:

	// Lua�X�e�[�g
	lua_State *pState;

	// �R���[�`���pState
	lua_State *pCoroutineState;

	// �R���[�`���̎Q��.
	int CoroutineRef;

	// �X�N���v�g���i�[���ꂽ�f�B���N�g��
	std::string ScriptDir;


	// �֐����o�C���h�B
	void BindFunctions();

	// ========= Singleton���ǂ� =============
public:

	static ScriptExecuterBase *GetInstance() { return pInstance; }

private:

	static ScriptExecuterBase *pInstance;

};

#endif		// #ifndef __SCRIPTEXECUTERBASE_H__