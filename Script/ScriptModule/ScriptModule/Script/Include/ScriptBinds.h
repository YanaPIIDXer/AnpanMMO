#ifndef __SCRIPTBINDS_H__
#define __SCRIPTBINDS_H__

/**
 * Lua�Ƀo�C���h����֐��Q��`�B
 * �N���X�̃����o�֐����o�C���h�ł��Ȃ��ׂ̏��u�B
 * �������ɒ�`���ꂽ�֐���C++������͌Ăяo���Ȃ����B
 */

struct lua_State;

// ���b�Z�[�W�\��.
int ShowMessage_Call(lua_State *pState);

#endif		// #ifndef __SCRIPTBINDS_H__
