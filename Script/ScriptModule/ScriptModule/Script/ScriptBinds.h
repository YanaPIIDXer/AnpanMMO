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

// �I�����v�b�V��
int PushSelection_Call(lua_State *pState);

// �I������\��.
int ShowSelection_Call(lua_State *pState);

// �t���O���Z�b�g�B
int SetFlag_Call(lua_State *pState);

// �t���O���擾.
int GetFlag_Call(lua_State *pState);

// �N�G�X�g���i�s�����H
int IsQuestActive_Call(lua_State *pState);

#endif		// #ifndef __SCRIPTBINDS_H__
