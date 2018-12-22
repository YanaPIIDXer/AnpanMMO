/**
 * @file Hate.h
 * @brief �w�C�g�Ǘ��N���X
 * @author YanaP
 */
#ifndef __HATE_H__
#define __HATE_H__

#include <vector>
#include "WeakPtrDefine.h"

class CharacterBase;

/**
 * @struct HateUnit
 * @brief �w�C�g
 */
struct HateUnit
{

public:

	//! �L�����N�^
	CharacterPtr pCharacter;

	//! �w�C�g�l.
	int HateValue;

};

// �\�[�g�p�I�y���[�^�I�[�o�[���[�h
bool operator >(const HateUnit &Left, const HateUnit &Right);
bool operator <(const HateUnit &Left, const HateUnit &Right);

/**
 * @class Hate
 * @brief �w�C�g�Ǘ��N���X
 */
class Hate
{

public:

	/**
	 * @brief �R���X�g���N�^
	 */
	Hate();

	/**
	 * @brief �f�X�g���N�^
	 */
	~Hate() {}

	/**
	 * @fn void Poll()
	 * @brief ���t���[���̏���
	 */
	void Poll();

	/**
	 * @fn void Add(CharacterPtr pCharacter, int Value)
	 * @brief ����
	 * @param[in] pCharacter �L�����N�^�ւ�weak_ptr
	 * @param[in] Value ������
	 */
	void Add(CharacterPtr pCharacter, int Value);

	/**
	 * @fn CharacterPtr GetTop() const
	 * @brief ��ԏ�ɂ���L�������擾
	 * @return ��ԏ�ɂ���L����
	 */
	CharacterPtr GetTop() const;

private:

	// �w�C�g���X�g
	std::vector<HateUnit> HateList;


	// �\�[�g,
	void Sort();

};

#endif		// #ifndef __HATE_H__
