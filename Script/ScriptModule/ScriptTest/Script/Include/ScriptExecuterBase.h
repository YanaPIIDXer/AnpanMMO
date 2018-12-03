#ifndef __SCRIPTEXECUTER_H__
#define __SCRIPTEXECUTER_H__

#include "lua.hpp"
#include "lauxlib.h"
#include "lualib.h"

/**
 * �X�N���v�g���s�N���X
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

private:

	// Lua�X�e�[�g
	lua_State *pState;

};

#endif		// #ifndef __SCRIPTEXECUTER_H__
	