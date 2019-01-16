/**
 * @file BuffManager.h
 * @brief �o�t�Ǘ��N���X
 * @author YanaP
 */
#ifndef __BUFFMANAGER_H__
#define __BUFFMANAGER_H__

#include <boost/unordered_map.hpp>

class BuffBase;
class CharacterBase;

/**
 * @class BuffManager
 * @brief �o�t�Ǘ�
 */
class BuffManager
{

private:		// �ʖ���`.

	typedef boost::unordered_map<u8, BuffBase *> BuffMap;

public:

	/**
	 * @brief �R���X�g���N�^
	 */
	BuffManager(CharacterBase *pInOwner);

	/**
	 * @brief �f�X�g���N�^
	 */
	~BuffManager();

	/**
	 * @fn void Poll(u32 DeltaTime)
	 * @brief ���t���[���̏���
	 * @param[in] DeltaTime �O�t���[������̌o�ߎ���
	 */
	void Poll(u32 DeltaTime);

	/**
	 * @fn void AddBuff(u32 BuffId)
	 * @brief �o�t�ǉ��B
	 * @param[in] �o�t�h�c
	 */
	void AddBuff(u32 BuffId);

	/**
	 * @fn bool IsActive(u8 Type) const
	 * @brief �w�肵���o�t�i�f�o�t�j���������Ă��邩�H
	 * @param[in] Type �o�t�i�f�o�t�j�^�C�v
	 * @return �������Ă����true��Ԃ��B
	 */
	bool IsActive(u8 Type) const { return (Buffs.find(Type) != Buffs.end()); }

private:

	// �o�t���X�g
	BuffMap Buffs;

	// ���L��.
	CharacterBase *pOwner;

};

#endif		// #ifndef __BUFFMANAGER_H__
