#ifndef __SCRIPTEXECUTER_H__
#define __SCRIPTEXECUTER_H__

#include "lua.hpp"
#include "lauxlib.h"
#include "lualib.h"

/**
 * �X�N���v�g���s�N���X
 */
class ScriptExecuter
{

public:

	// �f�X�g���N�^
	~ScriptExecuter();

	// �e�X�g���s.
	void ExecuteTest();

private:

	// Lua�X�e�[�g
	lua_State *pState;

	// ======== Singleton ==========
public:

	static ScriptExecuter &GetInstnace() { return Instance; }

private:

	ScriptExecuter();
	static ScriptExecuter Instance;

};

#endif		// #ifndef __SCRIPTEXECUTER_H__
	