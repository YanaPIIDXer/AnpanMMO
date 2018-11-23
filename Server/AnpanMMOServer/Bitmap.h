#ifndef __BITMAP_H__
#define __BITMAP_H__

#include <fstream>
#include "EndianConverter.h"

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
		FileStream.read((char *) &FileType, sizeof(FileType));
		FileStream.read((char *) &FileSize, sizeof(FileSize));
		FileStream.read((char *)&Reserved1, sizeof(Reserved1));
		FileStream.read((char *)&Reserved2, sizeof(Reserved2));
		FileStream.read((char *)&Offset, sizeof(Offset));
		
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
		FileStream.read((char *)&Size, sizeof(Size));		
		FileStream.read((char *)&Width, sizeof(Width));
		FileStream.read((char *)&Height, sizeof(Height));
		FileStream.read((char *)&Planes, sizeof(Planes));
		FileStream.read((char *)&BitCount, sizeof(BitCount));
		FileStream.read((char *)&Compression, sizeof(Compression));
		FileStream.read((char *)&ImageSize, sizeof(ImageSize));
		FileStream.read((char *)&XPixelPerMeter, sizeof(XPixelPerMeter));
		FileStream.read((char *)&YPixelPerMeter, sizeof(YPixelPerMeter));
		FileStream.read((char *)&UsedColors, sizeof(UsedColors));
		FileStream.read((char *)&ImportantColors, sizeof(ImportantColors));

		return !FileStream.eof();
	}

};

// ビットフィールド
struct BitmapBitField
{
	// 赤.
	u32 RField;

	// 緑.
	u32 GField;

	// 青.
	u32 BField;
};

// ビットマップパレットデータ
struct BitmapPaletteData
{
	// 赤.
	u8 R;

	// 緑.
	u8 G;

	// 青.
	u8 B;

	// 予約領域.
	u8 Reserved;


	// 読み込み
	bool Read(std::ifstream &FileStream)
	{
		FileStream.read((char *)&R, sizeof(R));
		FileStream.read((char *)&G, sizeof(G));
		FileStream.read((char *)&B, sizeof(B));
		FileStream.read((char *)&Reserved, sizeof(Reserved));
		return !FileStream.eof();
	}
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

private:

	// ファイルヘッダ
	BitmapFileHeader FileHeader;

	// 情報ヘッダ
	BitmapInfoData InfoData;

	// ビットフィールド
	BitmapBitField BitField;

	// カラーパレットデータ
	BitmapPaletteData *pColorPalette;

};

#endif		// #ifndef __BITMAP_H__
