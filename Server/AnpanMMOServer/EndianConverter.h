#ifndef __ENDIANCONVERTER_H__
#define __ENDIANCONVERTER_H__

//�G���f�B�A���ϊ�
class EndianConverter
{

public:

	// ���g���G���f�B�A���H
	static bool IsLittleEndian()
	{
		int x = 1;
		char ch = (*(char *)&x);
		return (ch != 0);
	}

	//�����t���P�U�r�b�g�ϊ�
	static s16 Convert(s16 Value, bool bForce = false)
	{
		if (IsLittleEndian() || bForce)
		{
			Value = ((Value << 8) & 0xFF00 | (Value >> 8) & 0x00FF);
		}
		return Value;

	}
	
	//���������P�U�r�b�g�ϊ�
	static u16 Convert(u16 Value, bool bForce = false)
	{
		if (IsLittleEndian() || bForce)
		{
			Value = ((Value << 8) & 0xFF00 | (Value >> 8) & 0x00FF);
		}
		return Value;

	}

	//�����t���R�Q�r�b�g�ϊ�
	static s32 Convert(s32 Value, bool bForce = false)
	{
		if (IsLittleEndian() || bForce)
		{
			s16 Low, High;
			High = (Value & 0xFFFF0000) >> 16;
			Low = Value & 0x0000FFFF;
			Value = (Convert(Low) << 16) | Convert(High);
		}
		return Value;

	}
	
	//���������R�Q�r�b�g�ϊ�
	static u32 Convert(u32 Value, bool bForce = false)
	{
		if (IsLittleEndian() || bForce)
		{
			u16 Low, High;
			High = (Value & 0xFFFF0000) >> 16;
			Low = Value & 0x0000FFFF;
			Value = (Convert(Low) << 16) | Convert(High);
		}
		return Value;
	}

	// float�ϊ�
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

	//�ÖقŒ�`�������̂̕���
	EndianConverter();
	EndianConverter(const EndianConverter &Arg);
	EndianConverter operator =(const EndianConverter &Arg);

};

#endif		//#ifndef __ENDIANCONVERTER_H__
