/**
 * @file ScriptBinds.h
 * @brief Lua�Ƀo�C���h����֐��Q��`�B
 * @details �N���X�̃����o�֐����o�C���h�ł��Ȃ��ׂ̏��u�B
 *			�������ɒ�`���ꂽ�֐���C++������͌Ăяo���Ȃ����B
 * @author YanaP
 */
#ifndef __SCRIPTBINDS_H__
#define __SCRIPTBINDS_H__

struct lua_State;

/**
 * @fn int ShowMessage_Call(lua_State *pState)
 * @brief ���b�Z�[�W�\��
 * @details �X�N���v�g�Ƀo�C���h����ČĂяo�����B
 * @param[in] pState Lua�X�e�[�g
 * @return �߂�l�̐�
 */
int ShowMessage_Call(lua_State *pState);

/**
 * @fn int PushSelection_Call(lua_State *pState)
 * @brief �I�������v�b�V��
 * @details �X�N���v�g�Ƀo�C���h����ČĂяo�����B
 * @param[in] pState Lua�X�e�[�g
 * @return �߂�l�̐�
 */
int PushSelection_Call(lua_State *pState);


/**
 * @fn int ShowSelection_Call(lua_State *pState)
 * @brief �I�����\��
 * @details �X�N���v�g�Ƀo�C���h����ČĂяo�����B
 * @param[in] pState Lua�X�e�[�g
 * @return �߂�l�̐�
 */
int ShowSelection_Call(lua_State *pState);

/**
 * @fn int SetFlag_Call(lua_State *pState)
 * @brief �t���O���Z�b�g
 * @details �X�N���v�g�Ƀo�C���h����ČĂяo�����B
 * @param[in] pState Lua�X�e�[�g
 * @return �߂�l�̐�
 */
int SetFlag_Call(lua_State *pState);

/**
 * @fn int GetFlag_Call(lua_State *pState)
 * @brief �t���O���擾
 * @details �X�N���v�g�Ƀo�C���h����ČĂяo�����B
 * @param[in] pState Lua�X�e�[�g
 * @return �߂�l�̐�
 */
int GetFlag_Call(lua_State *pState);

/**
 * @fn int IsQuestActive_Call(lua_State *pState)
 * @brief �N�G�X�g���i�s�����H
 * @details �X�N���v�g�Ƀo�C���h����ČĂяo�����B
 * @param[in] pState Lua�X�e�[�g
 * @return �߂�l�̐�
 */
int IsQuestActive_Call(lua_State *pState);

/**
 * @fn int ProgressQuest_Call(lua_State *pState)
 * @brief �N�G�X�g��i�s
 * @details �X�N���v�g�Ƀo�C���h����ČĂяo�����B
 * @param[in] pState Lua�X�e�[�g
 * @return �߂�l�̐�
 */
int ProgressQuest_Call(lua_State *pState);

/**
 * @fn int GetQuestStageNo_Call(lua_State *pState)
 * @brief �N�G�X�g�̃X�e�[�W�ԍ����擾
 * @details �X�N���v�g�Ƀo�C���h����ČĂяo�����B
 * @param[in] pState Lua�X�e�[�g
 * @return �߂�l�̐�
 */
int GetQuestStageNo_Call(lua_State *pState);

/**
 * @fn int GetItemCount_Call(lua_State *pState)
 * @brief �A�C�e���̌����擾
 * @details �X�N���v�g�Ƀo�C���h����ČĂяo�����B
 * @param[in] pState Lua�X�e�[�g
 * @return �߂�l�̐�
 */
int GetItemCount_Call(lua_State *pState);

/**
 * @fn int ConsumeItem_Call(lua_State *pState)
 * @brief �A�C�e��������
 * @details �X�N���v�g�Ƀo�C���h����ČĂяo�����B
 * @param[in] pState Lua�X�e�[�g
 * @return �߂�l�̐�
 */
int ConsumeItem_Call(lua_State *pState);

/**
 * @fn int AcceptQuest_Call(lua_State *pState)
 * @brief �N�G�X�g����
 * @details �X�N���v�g�Ƀo�C���h����ČĂяo�����B
 * @param[in] pState Lua�X�e�[�g
 * @return �߂�l�̐�
 */
int AcceptQuest_Call(lua_State *pState);

/**
 * @fn int IsQuestClear_Call(lua_State *pState)
 * @brief �N�G�X�g���N���A���Ă��邩�H
 * @details �X�N���v�g�Ƀo�C���h����ČĂяo�����B
 * @param[in] pState Lua�X�e�[�g
 * @return �߂�l�̐�
 */
int IsQuestClear_Call(lua_State *pState);

#endif		// #ifndef __SCRIPTBINDS_H__
