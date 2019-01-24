/**
 * @file ScriptterBase.h
 * @brief �X�N���v�g���s���N���X
 * @author YanaP
 */
#ifndef __SCRIPTEXECUTERBASE_H__
#define __SCRIPTEXECUTERBASE_H__

#include <string>
#include "TypeDefs.h"
#include "lua.hpp"
#include "lauxlib.h"
#include "lualib.h"

/**
 * @class ANPANMMO_API ScriptExecuterBase
 * @brief �X�N���v�g���s���N���X
 */
class ANPANMMO_API ScriptExecuterBase
{

public:

	/**
	 * @brief �R���X�g���N�^
	 */
	ScriptExecuterBase();

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~ScriptExecuterBase();

	/**
	 * @fn void SetScriptDir(const char *pScriptDir)
	 * @brief �X�N���v�g���i�[���ꂽ�f�B���N�g����ݒ�
	 * @param[in] pScriptDir �X�N���v�g���i�[���ꂽ�f�B���N�g��
	 */
	void SetScriptDir(const char *pScriptDir) { ScriptDir = pScriptDir; }

	/**
	 * @fn void ExecuteScript(const char *pScript)
	 * @brief �X�N���v�g�����s
	 * @param[in] pScript �X�N���v�g�R�[�h
	 */
	void ExecuteScript(const char *pScript);

	/**
	 * @fn void Resume()
	 * @brief �X�N���v�g�̎��s���ĊJ
	 */
	void Resume();

	/**
	 * @fn bool IsFinished() const
	 * @brief �I�����Ă��邩�H
	 * @return �I�����Ă�����true��Ԃ�
	 */
	bool IsFinished() const { return bIsFinished; }

	/**
	 * @virtual void ShowMessage_Impl(const std::string &Message)
	 * @brief ���b�Z�[�W��\��
	 * @details �X�N���v�g���o�R���ČĂ΂��B
	 * @param[in] Message ���b�Z�[�W
	 */
	virtual void ShowMessage_Impl(const std::string &Message) = 0;

	/**
	 * @fn virtual void PushSelection_Impl(const std::string &Message)
	 * @brief �I�������v�b�V��
	 * @details �X�N���v�g���o�R���ČĂ΂��B
	 * @param[in] Message ���b�Z�[�W
	 */
	virtual void PushSelection_Impl(const std::string &Message) = 0;

	/**
	 * @fn virtual void ShowSelection_Impl
	 * @brief �I������\��
	 * @details �X�N���v�g���o�R���ČĂ΂��B
	 */
	virtual void ShowSelection_Impl() = 0;

	/**
	 * @fn void OnSelectedSelection(int Index)
	 * @brief �I�������I�����ꂽ
	 * @param[in] Index �I�����ꂽ�I�����̃C���f�b�N�X
	 */
	void OnSelectedSelection(int Index);

	/**
	 * @fn virtual void SetFlag(int Flag)
	 * @brief �t���O���Z�b�g
	 * @details �X�N���v�g���o�R���ČĂ΂��B
	 * @param[in] �t���O�h�c
	 */
	virtual void SetFlag(int Flag) = 0;

	/**
	 * @fn virtual bool GetFlag(int Flag)
	 * @brief �t���O���擾
	 * @details �X�N���v�g���o�R���ČĂ΂��B
	 * @param[in] �t���O�h�c
	 * @return �t���O�������Ă����true��Ԃ��B
	 */
	virtual bool GetFlag(int Flag) = 0;

	/**
	 * @fn virtual bool IsQuestActive(u32 QusetId)
	 * @brief �N�G�X�g���i�s�����H
	 * @details �X�N���v�g���o�R���ČĂ΂��B
	 * @param[in] QuestId �N�G�X�g�h�c
	 * @return �i�s���Ȃ�true��Ԃ��B
	 */
	virtual bool IsQuestActive(u32 QuestId) = 0;

	/**
	 * @fn virtual void ProgressQuest(u32 QuestId)
	 * @brief �N�G�X�g�i�s
	 * @details �X�N���v�g���o�R���ČĂ΂��B
	 * @params[in] QuestId �N�G�X�g�h�c
	 */
	virtual void ProgressQuest(u32 QuestId) = 0;

	/**
	 * @fn virtual u32 GetQuestStageNo(u32 QuestId)
	 * @brief �N�G�X�g�̃X�e�[�W�ԍ����擾
	 * @details �X�N���v�g���o�R���ČĂ΂��B
	 * @param[in] QuestId �N�G�X�g�h�c
	 * @return �N�G�X�g�̃X�e�[�W�ԍ�
	 */
	virtual u32 GetQuestStageNo(u32 QuestId) = 0;

	/**
	 * @fn virtual u32 GetItemCount(u32 ItemId)
	 * @brief �A�C�e�������擾
	 * @details �X�N���v�g���o�R���ČĂ΂��B
	 * @param[in] ItemId �A�C�e���h�c
	 * @return �A�C�e���̌�
	 */
	virtual u32 GetItemCount(u32 ItemId) = 0;

	/**
	 * @fn virtual void ConsumeItem(u32 ItemId, u32 Count)
	 * @brief �A�C�e��������
	 * @details �X�N���v�g���o�R���ČĂ΂��B
	 * @param[in] ItemId �A�C�e���h�c
	 * @param[in] Count ��
	 */
	virtual void ConsumeItem(u32 ItemId, u32 Count) = 0;

	/**
	 * @fn virtual void AcceptQuest(u32 QuestId)
	 * @brief �N�G�X�g��
	 * @details �X�N���v�g���o�R���ČĂ΂��B
	 * @param[in] QuestId �N�G�X�g�h�c
	 */
	virtual void AcceptQuest(u32 QuestId) = 0;

	/**
	 * @fn virtual bool IsQuestClear(u32 QuestId)
	 * @brief �N�G�X�g���N���A���Ă��邩�H
	 * @details �X�N���v�g���o�R���ČĂ΂��B
	 * @param[in] QuestId �N�G�X�g�h�c
	 * @return �N���A���Ă�����true��Ԃ��B
	 */
	virtual bool IsQuestClear(u32 QuestId) = 0;

	/**
	 * @fn virtual void ShowShop_Impl(u32 ShopId)
	 * @brief �V���b�v��ʂ�\��
	 * @details �X�N���v�g���o�R���ČĂ΂��B
	 * @param[in] ShopId �V���b�v�h�c
	 */
	virtual void ShowShop_Impl(u32 ShopId) = 0;

protected:

	/**
	 * @fn virtual void onExecuteError(const std::string &ErrorMessage)
	 * @brief ���s�G���[�R�[���o�b�N
	 * @param[in] ErrorMessage �G���[���b�Z�[�W
	 */
	virtual void OnExecuteError(const std::string &ErrorMessage) = 0;

	/**
	 * @fn virtual void OnFinished()
	 * @brief �I���R�[���o�b�N
	 */
	virtual void OnFinished() = 0;
	
	/**
	 * @fn virtual void ShowDebugMessage(const std::string Message)
	 * @brief �f�o�b�O���b�Z�[�W��\��
	 * @param[in] Message ���b�Z�[�W
	 */
	virtual void ShowDebugMessage(const std::string &Message) = 0;

	/**
	 * @fn virtual bool IsServer() const
	 * @brief �T�[�o���[�h���H
	 * @details �T�[�o�ł͎g�p���Ȃ��@�\�𕕈󂷂邽�߂Ɏg�p�B
	 * @return �T�[�o���ŋN�����Ă����true��Ԃ��B
	 */
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
