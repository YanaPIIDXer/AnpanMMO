/**
 * @file ClientStateAreaChange.h
 * @brief �N���C�A���g�X�e�[�g�F�G���A�؂�ւ�
 * @author YanaP
 */
#ifndef __CLIENTSTATEAREACHANGE_H__
#define __CLIENTSTATEAREACHANGE_H__

#include "ClientStateBase.h"
#include "Math/Vector3D.h"

/**
 * �G���A�؂�ւ��҂��X�e�[�g
 */
class ClientStateAreaChange : public ClientStateBase
{

public:

	/**
	 * @brief �R���X�g���N�^
	 * @param[in] pInParent �N���C�A���g
	 */
	ClientStateAreaChange(Client *pInParent, u32 InAreaId, const Vector3D &InPosition);

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~ClientStateAreaChange() {}

private:

	// �G���A�h�c
	u32 AreaId;

	// ���W.
	Vector3D Position;


	// Ping����M�����B
	bool OnRecvPing(MemoryStreamInterface *pStream);

	// �Q�[��������������M�����B
	bool OnRecvGameReady(MemoryStreamInterface *pStream);

};

#endif		// #ifndef __CLIENTSTATEAREACHANGE_H__
