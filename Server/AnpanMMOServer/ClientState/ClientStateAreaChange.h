#ifndef __CLIENTSTATEAREACHANGE_H__
#define __CLIENTSTATEAREACHANGE_H__

#include "ClientStateBase.h"
#include "Math/Vector2D.h"

/**
 * �G���A�؂�ւ��҂��X�e�[�g
 */
class ClientStateAreaChange : public ClientStateBase
{

public:

	// �R���X�g���N�^
	ClientStateAreaChange(Client *pInParent, u32 InAreaId, const Vector2D &InPosition);

	// �f�X�g���N�^
	virtual ~ClientStateAreaChange() {}

private:

	// �G���A�h�c
	u32 AreaId;

	// ���W.
	Vector2D Position;


	// �Q�[��������������M�����B
	void OnRecvGameReady(MemoryStreamInterface *pStream);

};

#endif		// #ifndef __CLIENTSTATEAREACHANGE_H__