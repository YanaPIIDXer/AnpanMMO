#ifndef __BITMAP_H__
#define __BITMAP_H__

#include <fstream>
#include "EndianConverter.h"

// ストリームから読み込み。
template <typename T>
static void ReadFromStream(std::ifstream &FileStream, T *pData)
{
	FileStream.read((char *)pData, sizeof(T));
	if (!EndianConverter::IsLittleEndian())
	{
		// リトルエンディアン→ビックエンディアン
		*pData = EndianConverter::Convert(*pData, true);
	}
}

// ビットマップファイルヘッダ
struct BitmapFileHeader
{
	// ファイルタイプ
	u16 FileType;

	// ファイルサイズ
	u32 FileSize;

	// 予約領域.
	u16 Reserved1;
	u16 Reserved2;

	// ファイル先頭から画像データまでのオフセット
	u32 Offset;


	// 読み込み
	bool Read(std::ifstream &FileStream)
	{
		ReadFromStream(FileStream, &FileType);
		ReadFromStream(FileStream, &FileSize);
		ReadFromStream(FileStream, &Reserved1);
		ReadFromStream(FileStream, &Reserved2);
		ReadFromStream(FileStream, &Offset);
		
		return !FileStream.eof();
	}
};

// ビットマップ情報ヘッダ
struct BitmapInfoData
{
	// 情報ヘッダサイズ
	u32 Size;

	// 画像の幅.
	s32 Width;

	// 画像の高さ
	s32 Height;

	// プレーン数.
	u16 Planes;
	
	// 色ビット数.
	u16 BitCount;

	// 圧縮形式.
	u32 Compression;

	// 画像データサイズ
	u32 ImageSize;

	// 水平解像度.
	s32 XPixelPerMeter;

	// 垂直解像度.
	s32 YPixelPerMeter;

	// 格納パレット数.
	u32 UsedColors;

	// 重要色数.
	u32 ImportantColors;


	// 読み込み
	bool Read(std::ifstream &FileStream)
	{
		ReadFromStream(FileStream, &Size);
		ReadFromStream(FileStream, &Width);
		ReadFromStream(FileStream, &Height);
		ReadFromStream(FileStream, &Planes);
		ReadFromStream(FileStream, &BitCount);
		ReadFromStream(FileStream, &Compression);
		ReadFromStream(FileStream, &ImageSize);
		ReadFromStream(FileStream, &XPixelPerMeter);
		ReadFromStream(FileStream, &YPixelPerMeter);
		ReadFromStream(FileStream, &UsedColors);
		ReadFromStream(FileStream, &ImportantColors);

		return !FileStream.eof();
	}

};

// 32bitカラーデータ
struct Color32
{

	// 赤.
	u8 R;

	// 緑.
	u8 G;

	// 青.
	u8 B;

};

/**
 * ビットマップクラス
 */
class Bitmap
{

public:

	// コンストラクタ
	Bitmap();

	// デストラクタ
	~Bitmap();

	// ロード
	bool Load(const std::string &FilePath);

	// 色を取得.
	Color32 GetColor(int X, int Y) const;

private:

	// 赤のカラーマスク
	static const u32 RColorMask;

	// 緑のカラーマスク
	static const u32 GColorMask;

	// 青のカラーマスク
	static const u32 BColorMask;

	// ファイルヘッダ
	BitmapFileHeader FileHeader;

	// 情報ヘッダ
	BitmapInfoData InfoData;

	// カラーデータ
	Color32 *pColorData;

};

#endif		// #ifndef __BITMAP_H__
