#ifndef __SCRIPTBINDS_H__
#define __SCRIPTBINDS_H__

/**
 * Lua�Ƀo�C���h����֐��Q��`�B
 * �N���X�̃����o�֐����o�C���h�ł��Ȃ��ׂ̏��u�B
 * �������ɒ�`���ꂽ�֐���C++������͌Ăяo���Ȃ����B
 */

<<<<<<< HEAD
#include "lua.hpp"
#include "lauxlib.h"
#include "lualib.h"
=======
struct lua_State;
>>>>>>> f1f4ab27137ad863d811b0c040c52513571dcbf8

// ���b�Z�[�W�\��.
int ShowMessage_Call(lua_State *pState);

#endif		// #ifndef __SCRIPTBINDS_H__
