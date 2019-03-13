/**
 * @file GMCommandArg.h
 * @brief ＧＭコマンドの引数
 * @author YanaP
 */
#ifndef __GMCOMMANDARG_H__
#define __GMCOMMANDARG_H__

/**
 * @class GMCommandArg
 * @brief ＧＭコマンドの引数
 */
class GMCommandArg
{

public:

	/**
	 * @brief コンストラクタ
	 * @param[in] InArg 引数文字列
	 */
	GMCommandArg(const std::string &InArg);

	/**
	 * @brief デストラクタ
	 */
	~GMCommandArg() {}

	/**
	 * @fn const std::string &Get() const
	 * @brief 取得
	 * @return 引数文字列
	 */
	const std::string &Get() const { return Arg; }

	/**
	 * @fn bool TryGetAsNumber(s32 &OutNumber) const
	 * @brief 数値としての取得を試みる
	 * @param[out] OutNumber 数値としての引数
	 * @return 成功したらtrueを返す
	 */
	bool TryGetAsNumber(s32 &OutNumber) const;

private:

	// 引数文字列
	std::string Arg;

};

#endif		// #ifndef __GMCOMMANDARG_H__
