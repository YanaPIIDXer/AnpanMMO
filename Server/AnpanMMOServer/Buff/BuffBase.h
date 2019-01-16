/**
 * @file BuffBase.h
 * @brief �o�t���N���X
 * @author YanaP
 */
#ifndef __BUFFBASE_H__
#define __BUFFBASE_H__

class CharacterBase;

/**
 * @class BuffBase
 * @brief �o�t���N���X
 */
class BuffBase
{

public:

	/**
	 * @brief �R���X�g���N�^
	 * @param[in] Time �p������
	 * @param[in] pInCharacter �L�����N�^
	 */
	BuffBase(u32 Time, CharacterBase *pInCharacter);

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~BuffBase() {}

	/**
	 * @fn void Poll(u32 DeltaTime)
	 * @brief ���t���[���̏���
	 * @param[in] DeltaTime �O�t���[������̌o�ߎ���
	 */
	void Poll(u32 DeltaTime);

	/**
	 * @fn bool IsFinished() const
	 * @brief �I�����Ă��邩�H
	 * @return �I�����Ă����true��Ԃ�
	 */
	bool IsFinished() const { return (LastTime <= 0); }

	/**
	 * @fn virtual u8 GetType() const
	 * @brief �^�C�v���擾
	 * @return �^�C�v
	 */
	virtual u8 GetType() const = 0;

protected:

	/**
	 * @fn virtual void Update(u32 DeltaTime) = 0
	 * @brief ���t���[���̏���
	 * @param[in] DeltaTime �O�t���[������̌o�ߎ���
	 */
	virtual void Update(u32 DeltaTime) {}

	/**
	 * @fn CharacterBase *GetCharacter()
	 * @brief �L�����N�^�擾
	 * @return �L�����N�^
	 */
	CharacterBase *GetCharacter() { return pCharacter; }

private:

	// �c�莞��.
	s32 LastTime;

	// �L�����N�^
	CharacterBase *pCharacter;

};

#endif		// #ifndef __BUFFBASE_H__
