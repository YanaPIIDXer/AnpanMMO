/**
 * @file GMCommandParser.h
 * @brief �f�l�R�}���h��̓N���X
 * @author YanaP
 */
#ifndef __GMCOMMANDPARSER_H__
#define __GMCOMMANDPARSER_H__

#include "GMCommandArg.h"

/**
 * @class GMCommandParser
 * @brief �f�l�R�}���h���
 */
class GMCommandParser
{

public:

	/**
	 * @brief �R���X�g���N�^
	 * @param[in] InCommand �R�}���h
	 */
	GMCommandParser(const std::string &InCommand);

	/**
	 * @brief �f�X�g���N�^
	 */
	~GMCommandParser() {}

	/**
	 * @fn bool IsCommand() const
	 * @brief �R�}���h���H
	 * @return �R�}���h�Ȃ�true��Ԃ��B
	 */
	bool IsCommand() const { return (Command.length() > 1 && Command[0] == '#'); }

	/**
	 * @fn u8 GetCommandType() const
	 * @brief �R�}���h�̎�ނ��擾
	 * @return �R�}���h�̎��
	 */
	u8 GetCommandType() const;

	/**
	 * @fn std::vector<std::string> GetArgList() const
	 * @brief �������X�g���擾
	 * @return �������X�g
	 */
	std::vector<GMCommandArg> GetArgList() const;

private:

	// �R�}���h
	std::string Command;

};

#endif			// #ifndef __GMCOMMANDPARSER_H___