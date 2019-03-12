/**
 * @file GMCommandParser.h
 * @brief �f�l�R�}���h��̓N���X
 * @author YanaP
 */

#ifndef __GMCOMMANDPARSER_H__
#define __GMCOMMANDPARSER_H__

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
	bool IsCommand() const { return (Command[0] == '#'); }

private:

	// �R�}���h
	std::string Command;

};

#endif			// #ifndef __GMCOMMANDPARSER_H___
