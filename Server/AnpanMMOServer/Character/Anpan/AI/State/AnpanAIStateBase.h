/**
 * @file AnpanAIStateNonActive.h
 * @brief �A���p���`�h�X�e�[�g���N���X
 * @author YanaP
 */
#ifndef __ANPANAISTATEBASE_H__
#define __ANPANAISTATEBASE_H__

#include "Math/Vector3D.h"
#include "Math/Rotation.h"

class Anpan;
class AnpanAI;

/**
 * @class AnpanAIStateBase
 * @brief �A���p���`�h�X�e�[�g���N���X
 */
class AnpanAIStateBase
{

public:

	/** 
	 * @brief �R���X�g���N�^
	 * @param[in] pInParent �A���p��
	 */
	AnpanAIStateBase(Anpan *pInParent);

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~AnpanAIStateBase() = 0;

	/**
	 * @fn void Poll(int DeltaTime)
	 * @brief ���t���[���̏���
	 * @param[in] DeltaTime �O�t���[������̌o�ߎ���
	 */
	void Poll(int DeltaTime);

	/**
	 * @fn void SetAI(AnpanAI *pInAI)
	 * @brief AI��ݒ�
	 * @param[in] pInAI AI
	 */
	void SetAI(AnpanAI *pInAI) { pAI = pInAI; }

	/**
	 * @fn virtual void OnDamaged()
	 * @brief �_���[�W���󂯂�
	 */
	virtual void OnDamaged() {}

protected:

	/**
	 * @fn virtual void Update(int DeltaTime)
	 * @brief �X�V����
	 * @param[in] DeltaTime �O�t���[������̌o�ߎ���
	 */
	virtual void Update(int DeltaTime) {}

	/**
	 * @fn Anpan *GetParent()
	 * @brief �e���擾
	 * @return �A���p��
	 */
	Anpan *GetParent() { return pParent; }

	/**
	 * @fn AnpanAI *GetAI()
	 * @brief AI���擾
	 * @return AI
	 */
	AnpanAI *GetAI() { return pAI; }

	/**
	 * @fn void SetMove(const Vector3D &InMoveTarget, int Time)
	 * @brief �ړ���ݒ�
	 * @param[in] InMoveTarget �ړ���
	 * @param[in] Time �ړ�����
	 */
	void SetMove(const Vector3D &InMoveTarget, int Time);

	/**
	 * @fn void SetRotate(const Rotation &InRotateTarget, int Time)
	 * @brief ��]��ݒ�
	 * @param[in] InRotateTarget ��]
	 * @param[in] Time ��]����
	 */
	void SetRotate(const Rotation &InRotateTarget, int Time);

	/**
	 * @fn void Stop()
	 * @brief ��~
	 */
	void Stop();

	/**
	 * @fn bool IsMoving() const
	 * @brief �ړ����H
	 * @return �ړ����Ȃ�true��Ԃ��B
	 */
	bool IsMoving() const { return (MoveTime > 0); }

	/**
	 * @fn bool IsRotating() const
	 * @brief ��]���H
	 * @return ��]���Ȃ�true��Ԃ��B
	 */
	bool IsRotating() const { return (RotateTime > 0); }

private:

	// �e.
	Anpan *pParent;

	// AI
	AnpanAI *pAI;

	// �ȑO�̍��W.
	Vector3D PrevPos;

	// �ړ���.
	Vector3D MoveTarget;

	// �ړ�����.
	int MoveTime;

	// ��]�J�n����.
	int MoveStartTime;

	// �ȑO�̉�].
	Rotation PrevRotate;

	// ��]��.
	Rotation RotateTarget;

	// ��]����.
	int RotateTime;

	// ��]�J�n����.
	int RotateStartTime;


	// �ړ��X�V.
	void UpdateMove(int DeltaTime);

	// ��]�X�V.
	void UpdateRotate(int DeltaTime);

};

#endif		// #ifndef __ANPANAISTATEBASE_H__
