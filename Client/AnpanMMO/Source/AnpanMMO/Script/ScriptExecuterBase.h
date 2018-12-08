#ifndef __SCRIPTEXECUTERBASE_H__
#define __SCRIPTEXECUTERBASE_H__

#include <string>
#include "lua.hpp"
#include "lauxlib.h"
#include "lualib.h"

/**
 * �X�N���v�g���s���N���X
 */
class ANPANMMO_API ScriptExecuterBase
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

	// �I�����Ă��邩�H
	bool IsFinished() const { return bIsFinished; }

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

	// �������I�������B
	virtual void OnFinished() = 0;
	
	// �f�o�b�O���b�Z�[�W��\��.
	virtual void ShowDebugMessage(const std::string &Message) = 0;

	// �T�[�o���[�h���H
	virtual bool IsServer() const = 0;

private:

	// Lua�X�e�[�g
	lua_State *pState;

	// �R���[�`���pState
	lua_State *pCoroutineState;

	// �R���[�`���̎Q��.
	int CoroutineRef;

	// �X�N���v�g���i�[���ꂽ�f�B���N�g��
	std::string ScriptDir;

	// ID
	long Id;

	// �I�����Ă��邩�H
	bool bIsFinished;


	// �֐��Q���o�C���h�B
	void BindFunctions();

	// �֐����o�C���h�B
	void BindFunction(lua_CFunction Func, const char *pName);

	// State�𐶐�.
	void CreateState();

	// State��Close
	void CloseState();

	// �T�[�o���[�h�œ������Ă��鎞�͓������Ȃ����̂��R�����g�A�E�g
	void CommentOutWithServerMode(std::string &Code);

	// �֐��̃R�����g�A�E�g
	void CommentOutFunction(std::string &Code, const std::string &FunctionName);

};

#endif		// #ifndef __SCRIPTEXECUTERBASE_H__
