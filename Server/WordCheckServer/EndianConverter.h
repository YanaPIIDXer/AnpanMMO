/**
 * @file EndianConverter.h
 * @brief エンディアン変換
 * @author YanaP
 */
#ifndef __ENDIANCONVERTER_H__
#define __ENDIANCONVERTER_H__

/**
 * @class EndianConverter
 * @brief エンディアン変換
 */
class EndianConverter
{

public:

	/**
	 * @fn static bool IsLittleEndian()
	 * @brief リトルエンディアン？
	 * @return リトルエンディアンならtrueを返す。
	 */
	static bool IsLittleEndian()
	{
		int x = 1;
		char ch = (*(char *)&x);
		return (ch != 0);
	}

	/**
	 * @fn static s16 Convert(s16 Value, bool bForce = false)
	 * @brief 符号付き１６ビット変換
	 * @param[in] Value 変換前の値
	 * @param[in] bForce エンディアン関係なく強制的に変換するか？
	 * @return 変換後の値
	 */
	static s16 Convert(s16 Value, bool bForce = false)
	{
		if (IsLittleEndian() || bForce)
		{
			Value = (((Value << 8) & 0xFF00) | ((Value >> 8) & 0x00FF));
		}
		return Value;

	}

	/**
	 * @fn static u16 Convert(u16 Value, bool bForce = false)
	 * @brief 符号なし１６ビット変換
	 * @param[in] Value 変換前の値
	 * @param[in] bForce エンディアン関係なく強制的に変換するか？
	 * @return 変換後の値
	 */
	static u16 Convert(u16 Value, bool bForce = false)
	{
		if (IsLittleEndian() || bForce)
		{
			Value = (((Value << 8) & 0xFF00) | ((Value >> 8) & 0x00FF));
		}
		return Value;

	}

	/**
	 * @fn static s32 Convert(s32 Value, bool bForce = false)
	 * @brief 符号付き３２ビット変換
	 * @param[in] Value 変換前の値
	 * @param[in] bForce エンディアン関係なく強制的に変換するか？
	 * @return 変換後の値
	 */
	static s32 Convert(s32 Value, bool bForce = false)
	{
		if (IsLittleEndian() || bForce)
		{
			s16 Low, High;
			High = (Value & 0xFFFF0000) >> 16;
			Low = Value & 0x0000FFFF;
			Value = (Convert(Low, bForce) << 16) | Convert(High, bForce);
		}
		return Value;

	}

	/**
	 * @fn static u32 Convert(u32 Value, bool bForce = false)
	 * @brief 符号なし３２ビット変換
	 * @param[in] Value 変換前の値
	 * @param[in] bForce エンディアン関係なく強制的に変換するか？
	 * @return 変換後の値
	 */
	static u32 Convert(u32 Value, bool bForce = false)
	{
		if (IsLittleEndian() || bForce)
		{
			u16 Low, High;
			High = (Value & 0xFFFF0000) >> 16;
			Low = Value & 0x0000FFFF;
			Value = (Convert(Low, bForce) << 16) | Convert(High, bForce);
		}
		return Value;
	}

	/**
	 * @fn static float Convert(float Value, bool bForce = false)
	 * @brief float変換
	 * @param[in] Value 変換前の値
	 * @param[in] bForce エンディアン関係なく強制的に変換するか？
	 * @return 変換後の値
	 */
	static float Convert(float Value, bool bForce = false)
	{
		union FloatConv
		{
			u32 u;
			float f;
		};
		
		FloatConv Conv;

		Conv.f = Value;
		Conv.u = Convert(Conv.u, bForce);

		return Conv.f;
	}

private:

	//暗黙で定義されるものの封印
	EndianConverter();
	EndianConverter(const EndianConverter &Arg);
	EndianConverter operator =(const EndianConverter &Arg);

};

#endif		//#ifndef __ENDIANCONVERTER_H__
