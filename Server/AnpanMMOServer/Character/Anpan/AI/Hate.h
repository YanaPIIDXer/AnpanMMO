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

	//! �����w�C�g
	int VolatileHate;

	//! �ݐσw�C�g
	int AccumulateHate;

	// �����w�C�g�����܂ł̎���.
	int VolatileHateDecayTimer;

	/**
	 * @fn int GetTotal() const
	 * @brief �w�C�g���v�l���擾
	 * @return �w�C�g���v�l
	 */
	int GetTotal() const { return (VolatileHate + AccumulateHate); }

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
	 * @param[in] �O�t���[������̌o�ߎ���.
	 */
	void Poll(u32 DeltaTime);

	/**
	 * @fn void Add(CharacterPtr pCharacter, int Value)
	 * @brief ����
	 * @param[in] pCharacter �L�����N�^�ւ�weak_ptr
	 * @param[in] VolatileHate �����w�C�g
	 * @param[in] AccumulateHate �ݐσw�C�g
	 */
	void Add(CharacterPtr pCharacter, int VolatileHate, int AccumulateHate);

	/**
	 * @fn CharacterPtr GetTop() const
	 * @brief ��ԏ�ɂ���L�������擾
	 * @return ��ԏ�ɂ���L����
	 */
	CharacterPtr GetTop() const;

private:

	// �����w�C�g��������.
	static const int VolatileHateDecayTime;

	// �w�C�g���X�g
	std::vector<HateUnit> HateList;


	// �\�[�g,
	void Sort();

};

#endif		// #ifndef __HATE_H__
