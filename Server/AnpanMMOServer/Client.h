/**
 * @file Client.h
 * @brief �N���C�A���g�N���X
 * @author YanaP
 */

#ifndef __CLIENT_H__
#define __CLIENT_H__

#include "TCPConnection.h"
#include "Packet/PacketID.h"
#include "Script/ScriptExecuter.h"
#include "Script/ScriptFlagManager.h"
#include "Quest/QuestManager.h"
#include "WeakPtrDefine.h"

class PacketBase;
class ClientStateBase;
class PlayerCharacter;
class MemoryStreamInterface;

/**
 * @class Client
 * @brief �N���C�A���g�N���X
 */
class Client : public TCPConnection
{

public:

	/**
	 * @brief �R���X�g���N�^
	 * @param[in] pInSocket �\�P�b�g��shared_ptr
	 */
	Client(const shared_ptr<tcp::socket> &pInSocket);

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~Client();
	
	/**
	 * @fn void SendPacket(PacketBase *pPacket)
	 * @brief �p�P�b�g���M.
	 * @param[in] pPacket �p�P�b�g
	 */
	void SendPacket(PacketBase *pPacket);

	/**
	 * @fn void ChangeState(ClientStateBase *pNextState)
	 * @brief �X�e�[�g�؂�ւ�
	 * @param[in] pNextState �J�ڐ��State
	 */
	void ChangeState(ClientStateBase *pNextState);

	/**
	 * @fn void SetUuid(u32 InUuid)
	 * @brief UUID���Z�b�g
	 * @param[in] InUuid UUID
	 */
	void SetUuid(u32 InUuid) { Uuid = InUuid; }

	/**
	 * @fn u32 GetUuid()
	 * @brief UUID���擾.
	 * @return u32 UUID
	 */
	u32 GetUuid() const { return Uuid; }

	/**
	 * @fn void SetCustomerId(u32 InCustomerId)
	 * @brief �J�X�^�}�h�c���Z�b�g
	 * @details UUID�Ƃ͈قȂ�B
	 * @param[in] InCustomerId �J�X�^�}�h�c
	 */
	void SetCustomerId(u32 InCustomerId) { CustomerId = InCustomerId; }

	/**
	 * @fn u32 GetCustomerId()
	 * @brief �J�X�^�}�h�c���擾.
	 * @return u32 �J�X�^�}�h�c
	 */
	u32 GetCustomerId() const { return CustomerId; }

	/**
	 * @fn PlayerCharacterPtr GetCharacter()
	 * @brief �L�����N�^���擾.
	 * @details weak_ptr��Ԃ��B
	 * @return PlayerCharacterPtr �L�����N�^�ւ�weak_ptr
	 */
	PlayerCharacterPtr GetCharacter() const { return pCharacter; }

	/**
	 * @fn void CreateCharacter(u32 CharacterId, const std::string &Name, u8 Job, u32 Level, int MaxHp, int Atk, int Def, int Exp, u32 Gold)
	 * @brief �L�����N�^���쐬.
	 * @param[in] CharacterId �L�����N�^�h�c
	 * @param[in] Name �L�����N�^��.
	 * @param[in] Job �W���u
	 * @param[in] Level ���x��
	 * @param[in] MaxHp �ő�g�o
	 * @param[in] Atk �U����.
	 * @param[in] Def �h���.
	 * @param[in] Exp �o���l.
	 * @param[in] Gold �S�[���h
	 */
	void CreateCharacter(u32 CharacterId, const std::string &Name, u8 Job, u32 Level, int MaxHp, int Atk, int Def, int Exp, u32 Gold);

	/**
	 * @fn void RecvPacket(u8 ID, MemoryStreamInterface *pStream)
	 * @brief �p�P�b�g��M.
	 * @details ��ɑ��T�[�o����̃��X�|���X��M���Ɏg�p����B
	 * @param[in] ID �p�P�b�g�h�c
	 * @param[in] pStream �X�g���[��
	 */
	void RecvPacket(u8 ID, MemoryStreamInterface *pStream);

	/**
	 * @fn ScriptExecuter *GetScript()
	 * @brief �X�N���v�g����I�u�W�F�N�g�擾.
	 * @return ScriptExecuter * �X�N���v�g�Ǘ��I�u�W�F�N�g�ւ̃|�C���^
	 */
	ScriptExecuter *GetScript() { return &Script; }

	/**
	 * @fn void SetScriptFlag(int Key)
	 * @brief �X�N���v�g�t���O��ݒ�.
	 * @param[in] Key �L�[
	 */
	void SetScriptFlag(int Key);

	/**
	 * @fn const ScriptFlagManager &GetScriptFlagManager() const
	 * @brief �X�N���v�g�t���O�Ǘ��擾.
	 * @return const ScriptFlagManager & �X�N���v�g�t���O�Ǘ�.
	 */
	const ScriptFlagManager &GetScriptFlagManager() const { return FlagManager; }

	/**
	 * @fn void ConvertScriptFlagFromBitFields(u32 BitField1, u32 BitField2, u32 BitField3)
	 * @brief �r�b�g�t�B�[���h����X�N���v�g�t���O�ɕϊ�.
	 * @param[in] BitField1 �r�b�g�t�B�[���h�P
	 * @param[in] BitField2 �r�b�g�t�B�[���h�Q
	 * @param[in] BitField3 �r�b�g�t�B�[���h�R
	 */
	void ConvertScriptFlagFromBitFields(u32 BitField1, u32 BitField2, u32 BitField3);

	/**
	 * @fn const QuestManager &GetQuestManager() const
	 * @brief �N�G�X�g�Ǘ��擾.
	 * @return const QuestManager & �N�G�X�g�Ǘ�.
	 */
	const QuestManager &GetQuestManager() const { return QuestMgr; }

	/**
	 * @fn void AddQuestData(const QuestData &Data)
	 * @brief �N�G�X�g�f�[�^�ǉ�.
	 * @param[in] Data �N�G�X�g�f�[�^
	 */
	void AddQuestData(const QuestData &Data);

	/**
	 * @fn void AcceptQuest(u32 QuestId)
	 * @brief �N�G�X�g��.
	 * @param[in] QuestId �N�G�X�g�h�c
	 */
	void AcceptQuest(u32 QuestId);

	/**
	 * @fn void ProgressQuest(u32 QuestId)
	 * @brief �N�G�X�g�i�s.
	 * @param[in] QuestId �N�G�X�g�h�c
	 */
	void ProgressQuest(u32 QuestId);

	/**
	 * @fn void OnKilledAnpan(u32 AreaId)
	 * @brief �A���p���E�Q.
	 * @details �E�Q�����G���A�̂h�c��n���B
	 * @param[in] AreaId �E�Q�����G���A�h�c
	 */
	void OnKilledAnpan(u32 AreaId);

	/**
	 * @fn u8 RetireQuest(u32 QuestId)
	 * @brief �N�G�X�g�j��.
	 * @param[in] QuestId �N�G�X�g�h�c
	 * @return u8 ���U���g�R�[�h
	 */
	u8 RetireQuest(u32 QuestId);

protected:

	/**
	 * @fn void OnRecvData(size_t Size)
	 * @brief �f�[�^����M�����B
	 * @param[in] Size ��M�����f�[�^�T�C�Y
	 */
	virtual void OnRecvData(size_t Size);

private:

	//! State
	shared_ptr<ClientStateBase> pState;

	//! Uuid
	u32 Uuid;

	//! �J�X�^�}�h�c
	u32 CustomerId;

	//! �L�����N�^
	shared_ptr<PlayerCharacter> pCharacter;

	//! �X�N���v�g
	ScriptExecuter Script;

	//! �X�N���v�g�t���O�Ǘ�.
	ScriptFlagManager FlagManager;

	//! �N�G�X�g�Ǘ�.
	QuestManager QuestMgr;

};

#endif		// #ifndef __CLIENT_H__
