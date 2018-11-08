#ifndef __ANPANAISTATEBASE_H__
#define __ANPANAISTATEBASE_H__

#include "Math/Vector2D.h"
#include "Math/Rotation.h"

class Anpan;

/**
 * �A���p���`�h�X�e�[�g���N���X
 */
class AnpanAIStateBase
{

public:

	// �R���X�g���N�^
	AnpanAIStateBase(Anpan *pInParent);

	// �f�X�g���N�^
	virtual ~AnpanAIStateBase() = 0;

	// ���t���[���̏���.
	void Poll(int DeltaTime);

	// �ړ����H
	bool IsMoving() const { return (MoveTime > 0); }

	// �ړ�����擾.
	const Vector2D &GetMoveTarget() const { return MoveTarget; }

	// �ړ����Ԃ��擾.
	int GetMoveTime() const { return MoveTime; }

	// ��]���H
	bool IsRotating() const { return (RotateTime > 0); }

	// ��]����擾.
	const Rotation &GetRotateTarget() const { return RotateTarget; }

	// ��]���Ԃ��擾.
	int GetRotateTime() const { return RotateTime; }

protected:

	// �X�V����.
	virtual void Update(int DeltaTime) {}

	// �e���擾.
	Anpan *GetParent() { return pParent; }

	// �ړ���ݒ�.
	void SetMove(const Vector2D &InMoveTarget, int Time);

	// ��]��ݒ�.
	void SetRotate(const Rotation &InRotateTarget, int Time);

private:

	// �e.
	Anpan *pParent;

	// �ȑO�̍��W.
	Vector2D PrevPos;

	// �ړ���.
	Vector2D MoveTarget;

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
