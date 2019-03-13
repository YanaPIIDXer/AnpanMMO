/**
 * @file GMCommandType.h
 * @brief �f�l�R�}���h�̎�ޒ�`
 * @author YanaP
 */
#ifndef __GMCOMMANDTYPE_H__
#define __GMCOMMANDTYPE_H__

/**
 * @class EGOCommandType
 * @brief �f�l�R�}���h�̎��
 */
class EGMCommandType
{

public:

	/**
	 * @enum EType
	 * @brief ���
	 */
	enum EType
	{
		//! �����ȃR�}���h
		Invalid,

		//! �A�C�e���ǉ�
		AddItem,

		//! �o���l�ǉ�
		AddExp,

		//! GM���b�Z�[�W
		GMMessage,
	};

};

#endif			// #ifndef __GMCOMMANDTYPE_H__
