#ifndef __SCRIPTEXECUTERBASE_H__
#define __SCRIPTEXECUTERBASE_H__

#include "lua.hpp"
#include "lauxlib.h"
#include "lualib.h"
#include <string>

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

	// �X�N���v�g���Z�b�g�B
	void SetScript(const char *pScript);

	// �X�N���v�g�̎��s���ĊJ.
	void Resume();

	// ���b�Z�[�W��\��.
	virtual void ShowMessage(const std::string &Message) = 0;

private:

	// Lua�X�e�[�g
	lua_State *pState;

	// �R���[�`���pState
	lua_State *pCoroutineState;


	// �֐����o�C���h�B
	void BindFunctions();

};

#endif		// #ifndef __SCRIPTEXECUTERBASE_H__
	