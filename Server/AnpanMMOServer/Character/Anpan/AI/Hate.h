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

	//! 揮発ヘイト
	int VolatileHate;

	//! 累積ヘイト
	int AccumulateHate;

	// 揮発ヘイト減衰までの時間.
	int VolatileHateDecayTimer;

	/**
	 * @fn int GetTotal() const
	 * @brief ヘイト合計値を取得
	 * @return ヘイト合計値
	 */
	int GetTotal() const { return (VolatileHate + AccumulateHate); }

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
	 * @param[in] 前フレームからの経過時間.
	 */
	void Poll(u32 DeltaTime);

	/**
	 * @fn void Add(CharacterPtr pCharacter, int Value)
	 * @brief 増加
	 * @param[in] pCharacter キャラクタへのweak_ptr
	 * @param[in] VolatileHate 揮発ヘイト
	 * @param[in] AccumulateHate 累積ヘイト
	 */
	void Add(CharacterPtr pCharacter, int VolatileHate, int AccumulateHate);

	/**
	 * @fn CharacterPtr GetTop() const
	 * @brief 一番上にいるキャラを取得
	 * @return 一番上にいるキャラ
	 */
	CharacterPtr GetTop() const;

private:

	// 揮発ヘイト減衰時間.
	static const int VolatileHateDecayTime;

	// ヘイトリスト
	std::vector<HateUnit> HateList;


	// ソート,
	void Sort();

};

#endif		// #ifndef __HATE_H__
