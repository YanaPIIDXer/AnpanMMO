/**
 * @file GMCommandParser.h
 * @brief ＧＭコマンド解析クラス
 * @author YanaP
 */

#ifndef __GMCOMMANDPARSER_H__
#define __GMCOMMANDPARSER_H__

/**
 * @class GMCommandParser
 * @brief ＧＭコマンド解析
 */
class GMCommandParser
{

public:

	/**
	 * @brief コンストラクタ
	 * @param[in] InCommand コマンド
	 */
	GMCommandParser(const std::string &InCommand);

	/**
	 * @brief デストラクタ
	 */
	~GMCommandParser() {}

	/**
	 * @fn bool IsCommand() const
	 * @brief コマンドか？
	 * @return コマンドならtrueを返す。
	 */
	bool IsCommand() const { return (Command[0] == '#'); }

private:

	// コマンド
	std::string Command;

};

#endif			// #ifndef __GMCOMMANDPARSER_H___
