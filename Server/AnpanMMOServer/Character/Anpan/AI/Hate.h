/**
 * @file Hate.h
 * @brief ヘイト管理クラス
 * @author YanaP
 */
#ifndef __HATE_H__
#define __HATE_H__

#include <vector>
#include "WeakPtrDefine.h"

class CharacterBase;

/**
 * @struct HateUnit
 * @brief ヘイト
 */
struct HateUnit
{

public:

	//! キャラクタ
	CharacterPtr pCharacter;

	//! ヘイト値.
	int HateValue;

};

// ソート用オペレータオーバーロード
bool operator >(const HateUnit &Left, const HateUnit &Right);
bool operator <(const HateUnit &Left, const HateUnit &Right);

/**
 * @class Hate
 * @brief ヘイト管理クラス
 */
class Hate
{

public:

	/**
	 * @brief コンストラクタ
	 */
	Hate();

	/**
	 * @brief デストラクタ
	 */
	~Hate() {}

	/**
	 * @fn void Poll()
	 * @brief 毎フレームの処理
	 */
	void Poll();

	/**
	 * @fn void Add(CharacterPtr pCharacter, int Value)
	 * @brief 増加
	 * @param[in] pCharacter キャラクタへのweak_ptr
	 * @param[in] Value 増加量
	 */
	void Add(CharacterPtr pCharacter, int Value);

	/**
	 * @fn CharacterPtr GetTop() const
	 * @brief 一番上にいるキャラを取得
	 * @return 一番上にいるキャラ
	 */
	CharacterPtr GetTop() const;

private:

	// ヘイトリスト
	std::vector<HateUnit> HateList;


	// ソート,
	void Sort();

};

#endif		// #ifndef __HATE_H__
