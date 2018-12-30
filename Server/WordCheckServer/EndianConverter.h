/**
 * @file EndianConverter.h
 * @brief �G���f�B�A���ϊ�
 * @author YanaP
 */
#ifndef __ENDIANCONVERTER_H__
#define __ENDIANCONVERTER_H__

/**
 * @class EndianConverter
 * @brief �G���f�B�A���ϊ�
 */
class EndianConverter
{

public:

	/**
	 * @fn static bool IsLittleEndian()
	 * @brief ���g���G���f�B�A���H
	 * @return ���g���G���f�B�A���Ȃ�true��Ԃ��B
	 */
	static bool IsLittleEndian()
	{
		int x = 1;
		char ch = (*(char *)&x);
		return (ch != 0);
	}

	/**
	 * @fn static s16 Convert(s16 Value, bool bForce = false)
	 * @brief �����t���P�U�r�b�g�ϊ�
	 * @param[in] Value �ϊ��O�̒l
	 * @param[in] bForce �G���f�B�A���֌W�Ȃ������I�ɕϊ����邩�H
	 * @return �ϊ���̒l
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
	 * @brief �����Ȃ��P�U�r�b�g�ϊ�
	 * @param[in] Value �ϊ��O�̒l
	 * @param[in] bForce �G���f�B�A���֌W�Ȃ������I�ɕϊ����邩�H
	 * @return �ϊ���̒l
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
	 * @brief �����t���R�Q�r�b�g�ϊ�
	 * @param[in] Value �ϊ��O�̒l
	 * @param[in] bForce �G���f�B�A���֌W�Ȃ������I�ɕϊ����邩�H
	 * @return �ϊ���̒l
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
	 * @brief �����Ȃ��R�Q�r�b�g�ϊ�
	 * @param[in] Value �ϊ��O�̒l
	 * @param[in] bForce �G���f�B�A���֌W�Ȃ������I�ɕϊ����邩�H
	 * @return �ϊ���̒l
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
	 * @brief float�ϊ�
	 * @param[in] Value �ϊ��O�̒l
	 * @param[in] bForce �G���f�B�A���֌W�Ȃ������I�ɕϊ����邩�H
	 * @return �ϊ���̒l
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

	//�ÖقŒ�`�������̂̕���
	EndianConverter();
	EndianConverter(const EndianConverter &Arg);
	EndianConverter operator =(const EndianConverter &Arg);

};

#endif		//#ifndef __ENDIANCONVERTER_H__
