#ifndef __ROTATION_H__
#define __ROTATION_H__

// ��]�������N���X
class Rotation
{

public:

	// �R���X�g���N�^
	Rotation();
	Rotation(float InValue);

	// �f�X�g���N�^
	~Rotation() {}

	// �擾.
	float Get() const { return Value; }

	// �Z�b�g.
	void Set(float InValue);

	// �I�y���[�^�I�[�o�[���[�h
	float operator +(float InValue);
	float operator -(float InValue);
	void operator +=(float InValue);
	void operator -=(float InValue);

private:

	// �l.
	float Value;


	// �ۂߍ��ݏ���.
	float Coax(float InValue);

};

#endif		// #ifndef __ROTATION_H__
