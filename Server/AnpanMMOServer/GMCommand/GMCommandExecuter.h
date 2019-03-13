/**
 * @file GMCommandExecuter.h
 * @brief �f�l�R�}���h���s�N���X
 * @author YanaP
 */
#ifndef __GMCOMMANDEXECUTER_H__
#define __GMCOMMANDEXECUTER_H__

#include "GMCommandParser.h"
class Client;

/**
 * @class GMCommandExecuter
 * @brief �f�l�R�}���h���s
 */
class GMCommandExecuter
{

public:		// �萔��`

	/**
	 * @enum EResult
	 * @brief ���s����
	 */
	enum EResult
	{
		//! ����
		Success,

		//! �����ȃR�}���h
		InvalidCommand,

		//! �����Ȉ���
		InvalidArg,

		//! �����ȃA�C�e��
		InvalidItem,
	};

public:

	/**
	 * @brief �R���X�g���N�^
	 * @param[in] pInClient �N���C�A���g
	 * @param[in] InParser �p�[�T
	 */
	GMCommandExecuter(Client *pInClient, const GMCommandParser &InParser);

	/**
	 * @brief �f�X�g���N�^
	 */
	~GMCommandExecuter() {}

	/**
	 * @fn u8 Execute()
	 * @brief ���s
	 * @return ���s����
	 */
	u8 Execute();

private:

	// �N���C�A���g
	Client *pClient;

	// �p�[�T
	GMCommandParser Parser;


	// �A�C�e���ǉ�.
	u8 AddItem(const std::vector<GMCommandArg> &Args);

	// �o���l�ǉ�.
	u8 AddExp(const std::vector<GMCommandArg> &Args);

	// �f�l���b�Z�[�W���M.
	u8 SendGMMessage(const std::vector<GMCommandArg> &Args);

};

#endif		// #ifndef __GMCOMMANDEXECUTER_H__
