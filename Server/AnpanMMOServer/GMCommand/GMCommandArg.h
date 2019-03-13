/**
 * @file GMCommandArg.h
 * @brief �f�l�R�}���h�̈���
 * @author YanaP
 */
#ifndef __GMCOMMANDARG_H__
#define __GMCOMMANDARG_H__

/**
 * @class GMCommandArg
 * @brief �f�l�R�}���h�̈���
 */
class GMCommandArg
{

public:

	/**
	 * @brief �R���X�g���N�^
	 * @param[in] InArg ����������
	 */
	GMCommandArg(const std::string &InArg);

	/**
	 * @brief �f�X�g���N�^
	 */
	~GMCommandArg() {}

	/**
	 * @fn const std::string &Get() const
	 * @brief �擾
	 * @return ����������
	 */
	const std::string &Get() const { return Arg; }

	/**
	 * @fn bool TryGetAsNumber(s32 &OutNumber) const
	 * @brief ���l�Ƃ��Ă̎擾�����݂�
	 * @param[out] OutNumber ���l�Ƃ��Ă̈���
	 * @return ����������true��Ԃ�
	 */
	bool TryGetAsNumber(s32 &OutNumber) const;

private:

	// ����������
	std::string Arg;

};

#endif		// #ifndef __GMCOMMANDARG_H__
