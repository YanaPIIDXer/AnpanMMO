#ifndef __CLIENT_H__
#define __CLIENT_H__

#include "TCPConnection.h"
#include "Packet/PacketID.h"
#include "Script/ScriptExecuter.h"
#include "Script/ScriptFlagManager.h"

class PacketBase;
class ClientStateBase;
class PlayerCharacter;
class MemoryStreamInterface;

/**
 * �N���C�A���g�N���X
 */
class Client : public TCPConnection
{

public:

	// �R���X�g���N�^
	Client(const shared_ptr<tcp::socket> &pInSocket);

	// �f�X�g���N�^
	virtual ~Client();
	
	// �p�P�b�g���M.
	void SendPacket(PacketBase *pPacket);

	// �X�e�[�g�؂�ւ�
	void ChangeState(ClientStateBase *pNextState);

	// UUID���Z�b�g
	void SetUuid(u32 InUuid) { Uuid = InUuid; }

	// UUID���擾.
	u32 GetUuid() const { return Uuid; }

	// �J�X�^�}�h�c���Z�b�g.
	void SetCustomerId(u32 InCustomerId) { CustomerId = InCustomerId; }

	// �J�X�^�}�h�c���擾.
	u32 GetCustomerId() const { return CustomerId; }

	// �L�����N�^�擾.
	weak_ptr<PlayerCharacter> GetCharacter() const { return pCharacter; }

	// �L�����N�^�쐬.
	void CreateCharacter(const std::string &Name, int MaxHp, int Atk, int Def, int Exp);

	// �p�P�b�g����M�B
	// ����ɕʃv���Z�X����̎�M���Ɏg�p�B
	void RecvPacket(PacketID ID, MemoryStreamInterface *pStream);

	// �X�N���v�g���擾.
	ScriptExecuter *GetScript() { return &Script; }

	// �X�N���v�g�t���O��ݒ�.
	void SetScriptFlag(int Key);

	// �t���O�Ǘ����擾.
	const ScriptFlagManager &GetScriptFlagManager() const { return FlagManager; }

	// �r�b�g�t�B�[���h����X�N���v�g�t���O�ɕϊ�.
	void ConvertScriptFlagFromBitFields(u32 BitField1, u32 BitField2, u32 BitField3);

protected:

	// �f�[�^����M�����B
	virtual void OnRecvData(size_t Size);

private:

	// State
	shared_ptr<ClientStateBase> pState;

	// Uuid
	u32 Uuid;

	// �J�X�^�}�h�c
	u32 CustomerId;

	// �L�����N�^
	shared_ptr<PlayerCharacter> pCharacter;

	// �X�N���v�g
	ScriptExecuter Script;

	// �X�N���v�g�t���O�Ǘ�.
	ScriptFlagManager FlagManager;

};

#endif		// #ifndef __CLIENT_H__
