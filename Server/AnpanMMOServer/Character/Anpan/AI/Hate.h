#ifndef __HATE_H__
#define __HATE_H__

#include <vector>

class CharacterBase;

// ヘイト
struct HateUnit
{

public:

	// キャラクタ
	weak_ptr<CharacterBase> pCharacter;

	// ヘイト値.
	int HateValue;

};

// ソート用オペレータオーバーロード
bool operator >(const HateUnit &Left, const HateUnit &Right);
bool operator <(const HateUnit &Left, const HateUnit &Right);

/**
 * ヘイト管理クラス
 */
class Hate
{

public:

	// コンストラクタ
	Hate();

	// デストラクタ
	~Hate() {}

	// 毎フレームの処理.
	void Poll();

	// 増加.
	void Add(weak_ptr<CharacterBase> pCharacter, int Value);

	// 一番上にいるキャラを取得.
	weak_ptr<CharacterBase> GetTop() const;

private:

	// ヘイトリスト
	std::vector<HateUnit> HateList;


	// ソート,
	void Sort();

};

#endif		// #ifndef __HATE_H__
