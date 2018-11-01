#ifndef __ENDIANCONVERTER_H__
#define __ENDIANCONVERTER_H__

//エンディアン変換
class EndianConverter
{

public:

	// リトルエンディアン？
	static bool IsLittleEndian()
	{
		int x = 1;
		return (*(char *)&x);
	}

	//符号付き１６ビット変換
	static s16 Convert( s16 Value )
	{
		if (IsLittleEndian())
		{
			Value = ((Value << 8) & 0xFF00 | (Value >> 8) & 0x00FF);
		}
		return Value;

	}
	
	//符号無し１６ビット変換
	static u16 Convert( u16 Value )
	{
		if (IsLittleEndian())
		{
			Value = ((Value << 8) & 0xFF00 | (Value >> 8) & 0x00FF);
		}
		return Value;

	}

	//符号付き３２ビット変換
	static s32 Convert( s32 Value )
	{
		if (IsLittleEndian())
		{
			s16 Low, High;
			High = (Value & 0xFFFF0000) >> 16;
			Low = Value & 0x0000FFFF;
			Value = (Convert(Low) << 16) | Convert(High);
		}
		return Value;

	}
	
	//符号無し３２ビット変換
	static u32 Convert( u32 Value )
	{
		if (IsLittleEndian())
		{
			u16 Low, High;
			High = (Value & 0xFFFF0000) >> 16;
			Low = Value & 0x0000FFFF;
			Value = (Convert(Low) << 16) | Convert(High);
		}
		return Value;
	}

	// float変換
	static float Convert( float Value )
	{

		union FloatConv
		{

			u32 u;
			float f;

		};
		
		FloatConv Conv;

		Conv.f = Value;
		Conv.u = Convert(Conv.u);

		return Conv.f;

	}

private:

	//暗黙で定義されるものの封印
	EndianConverter();
	EndianConverter( const EndianConverter &Arg );
	EndianConverter operator =( const EndianConverter &Arg );

};

#endif		//#ifndef __ENDIANCONVERTER_H__