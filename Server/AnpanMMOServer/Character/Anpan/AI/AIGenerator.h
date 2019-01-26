/**
 * @file AIGenerator.h
 * @brief �`�h�@�\�\�z�N���X
 * @author YanaP
 */
#ifndef __AIGENERATOR_H__
#define __AIGENERATOR_H__

#include <boost/unordered_map.hpp>
#include "WeakPtrDefine.h"

/**
 * @struct AIAction
 * @brief AI�̍s��
 */
struct AIAction
{
	//! �s��
	u8 Action;

	//! �s���̒l
	u32 Value;

	//! ���̍s��
	AIActionPtr pNextAction;
};

/**
 * @class AIGenerator
 * @brief �`�h�@�\�\�z
 * @detail �V���O���g���N���X
 */
class AIGenerator : public boost::noncopyable
{

private:		// �ʖ���`.

	typedef shared_ptr<AIAction> AIActionSharedPtr;
	typedef boost::unordered_map<int, std::vector<AIActionSharedPtr>> ActionMap;

public:

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~AIGenerator() {}

	/**
	 * @fn void Initialize()
	 * @brief ������
	 */
	void Initialize();

	/**
	 * @fn const AIActionPtr Get(u32 Id) const
	 * @brief �擾
	 * @param[in] Id �`�h�̂h�c
	 * @return �`�h�A�N�V�����̐擪
	 */
	const AIActionPtr Get(u32 Id) const;

private:

	// �s���}�b�v
	ActionMap Actions;

	// ========== Singleton ===============
public:

	/**
	 * @fn static AIGenerator &GetInstance()
	 * @brief �V���O���g���C���X�^���X���擾
	 * @return �V���O���g���C���X�^���X
	 */
	static AIGenerator &GetInstance() { return Instance; }

private:

	AIGenerator();
	static AIGenerator Instance;

};

#endif		// #ifndef __AIGENERATOR_H__
