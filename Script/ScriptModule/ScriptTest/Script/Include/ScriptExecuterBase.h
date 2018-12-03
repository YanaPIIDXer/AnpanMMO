#ifndef __SCRIPTEXECUTERBASE_H__
#define __SCRIPTEXECUTERBASE_H__

#include "lua.hpp"
#include "lauxlib.h"
#include "lualib.h"

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

	// �e�X�g���s.
	void ExecuteTest();

	// ���b�Z�[�W��\��.
	virtual void ShowMessage() = 0;

private:

	// Lua�X�e�[�g
	lua_State *pState;

};

#endif		// #ifndef __SCRIPTEXECUTERBASE_H__
	