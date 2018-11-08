#ifndef __HATE_H__
#define __HATE_H__

#include <vector>

class CharacterBase;

// �w�C�g
struct HateUnit
{

public:

	// �L�����N�^
	weak_ptr<CharacterBase> pCharacter;

	// �w�C�g�l.
	int HateValue;

};

// �\�[�g�p�I�y���[�^�I�[�o�[���[�h
bool operator >(const HateUnit &Left, const HateUnit &Right);
bool operator <(const HateUnit &Left, const HateUnit &Right);

/**
 * �w�C�g�Ǘ��N���X
 */
class Hate
{

public:

	// �R���X�g���N�^
	Hate();

	// �f�X�g���N�^
	~Hate() {}

	// ���t���[���̏���.
	void Poll();

	// ����.
	void Add(weak_ptr<CharacterBase> pCharacter, int Value);

	// ��ԏ�ɂ���L�������擾.
	weak_ptr<CharacterBase> GetTop() const;

private:

	// �w�C�g���X�g
	std::vector<HateUnit> HateList;


	// �\�[�g,
	void Sort();

};

#endif		// #ifndef __HATE_H__
