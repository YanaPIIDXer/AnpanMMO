/**
 * @file GMCommandArg.cpp
 * @brief �f�l�R�}���h�̈���
 * @author YanaP
 */
#include "stdafx.h"
#include "GMCommandArg.h" 
#include <boost/lexical_cast.hpp>

// �R���X�g���N�^
GMCommandArg::GMCommandArg(const std::string &InArg)
	: Arg(InArg)
{
}

// ���l�Ƃ��Ă̎擾�����݂�
bool GMCommandArg::TryGetAsNumber(s32 &OutNumber) const
{
	try
	{
		OutNumber = lexical_cast<s32>(Arg);
	}
	catch (bad_lexical_cast)
	{
		return false;
	}

	return true;
}
