/**
 * @file GMCommandArg.cpp
 * @brief ＧＭコマンドの引数
 * @author YanaP
 */
#include "stdafx.h"
#include "GMCommandArg.h" 
#include <boost/lexical_cast.hpp>

// コンストラクタ
GMCommandArg::GMCommandArg(const std::string &InArg)
	: Arg(InArg)
{
}

// 数値としての取得を試みる
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
