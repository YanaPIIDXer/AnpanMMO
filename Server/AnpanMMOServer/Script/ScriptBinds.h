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

// �N�G�X�g�i�s.
int ProgressQuest_Call(lua_State *pState);

// �N�G�X�g�̃X�e�[�W�ԍ����擾.
int GetQuestStageNo_Call(lua_State *pState);

// �A�C�e���̌����擾.
int GetItemCount_Call(lua_State *pState);

// �A�C�e��������.
int ConsumeItem_Call(lua_State *pState);

// �N�G�X�g��.
int AcceptQuest_Call(lua_State *pState);

// �N�G�X�g���N���A���Ă��邩�H
int IsQuestClear_Call(lua_State *pState);

#endif		// #ifndef __SCRIPTBINDS_H__
