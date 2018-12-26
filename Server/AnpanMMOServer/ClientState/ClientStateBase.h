/**
 * @file ClientStateBase.h
 * @brief �N���C�A���g�X�e�[�g���N���X
 * @author YanaP
 */
#ifndef __CLIENTSTATEBASE_H__
#define __CLIENTSTATEBASE_H__

#include <map>
#include <boost/function.hpp>
#include "Packet/PacketID.h"

class Client;
class MemoryStreamInterface;

/**
 * @class ClientStateBase
 * @brief �N���C�A���g�X�e�[�g���N���X
 */
class ClientStateBase
{

private:		// �ʖ���`.

	typedef boost::function<bool(Client *, MemoryStreamInterface *)> PacketFunc;
	typedef std::map<u8, PacketFunc> FunctionMap;

public:

	/**
	 * @brief �R���X�g���N�^
	 * @param[in] pInParent �N���C�A���g
	 */
	ClientStateBase(Client *pInParent)
		: pParent(pInParent) {}

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~ClientStateBase() {}

	/**
	 * @fn virtual void BeginState()
	 * @brief State�J�n���̏���
	 */
	virtual void BeginState() {}

	/**
	 * @fn void AnalyzePacket(u8 ID, MemoryStreamInterface *pStream)
	 * @brief �p�P�b�g���
	 * @param[in] ID �p�P�b�g�h�c
	 * @param[in] pStream �X�g���[��
	 */
	void AnalyzePacket(u8 ID, MemoryStreamInterface *pStream);
	
protected:

	/**
	 * @fn Client *GetParent() const
	 * @brief �e�N���C�A���g���擾
	 * @return �e�N���C�A���g
	 */
	Client *GetParent() const { return pParent; }

	/*
	 * @fn void AddPacketFunction(u8 ID, const PacketFunc &Func)
	 * @brief �p�P�b�g��͊֐���ǉ�
	 * @param[in] ID �p�P�b�g�h�c
	 * @param[in] Func ��͊֐�
	 */
	void AddPacketFunction(u8 ID, const PacketFunc &Func)
	{
		PacketFunctions[ID] = Func;
	}

private:

	// �e.
	Client *pParent;

	// �p�P�b�g��͊֐��Q.
	FunctionMap PacketFunctions;

};

#endif		// #ifndef __CLIENTSTATEBASE_H__
