#ifndef __WORDCHECKER_H__
#define __WORDCHECKER_H__

#include "Master/NGWordMaster.h"

/**
 * ワードチェッククラス
 */
class WordChecker
{

public:

	// デストラクタ
	~WordChecker() {}

	// マスタの読み込み
	bool LoadMaster();

private:

	// マスタ読み込み情報ファイル名.
	static const std::string MasterDBInfoFileName;

	// NGワードマスタ
	NGWordMaster NGWords;

	// ========== Singleton ==========

public:

	static WordChecker &GetInstance() { return Instance; }

private:

	WordChecker() {}
	static WordChecker Instance;

};

#endif		// #ifndef __WORDCHECKER_H__
