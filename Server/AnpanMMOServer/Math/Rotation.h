#ifndef __ROTATION_H__
#define __ROTATION_H__

// 回転を扱うクラス
class Rotation
{

public:

	// コンストラクタ
	Rotation();
	Rotation(float InValue);

	// デストラクタ
	~Rotation() {}

	// 取得.
	float Get() const { return Value; }

	// セット.
	void Set(float InValue);

	// オペレータオーバーロード
	float operator +(float InValue);
	float operator -(float InValue);
	void operator +=(float InValue);
	void operator -=(float InValue);

private:

	// 値.
	float Value;


	// 丸め込み処理.
	float Coax(float InValue);

};

#endif		// #ifndef __ROTATION_H__
