/**
 * @file CharacterParameter.h
 * @brief �L�����N�^�p�����[�^
 * @author YanaP
 */
#ifndef __CHARACTERPARAMETER_H__
#define __CHARACTERPARAMETER_H__

#include "Equip/EquipData.h"

/**
 * @class CharacterParameter
 * @brief �L�����N�^�p�����[�^
 */
class CharacterParameter
{

public:

	/**
	 * @brief �R���X�g���N�^
	 */
	CharacterParameter();

	/**
	 * @brief �f�X�g���N�^
	 */
	~CharacterParameter() {}

	/**
	 * @fn void Set(u32 InLevel, u32 InHp, u32 InMaxHp, u32 InStr, u32 InDef, u32 InInt, u32 InMnd, u32 InVit)
	 * @brief �p�����[�^���Z�b�g
	 * @param[in] InLevel ���x��
	 * @param[in] InHp ���݂̂g�o
	 * @param[in] InMaxHp �ő�g�o
	 * @param[in] InStr STR
	 * @param[in] InDef DEF
	 * @param[in] InInt INT
	 * @param[in] InMnd MND
	 * @param[in] InVit VIT
	 */
	void Set(u32 InLevel, u32 InHp, u32 InMaxHp, u32 InStr, u32 InDef, u32 InInt, u32 InMnd, u32 InVit);

	/**1
	 * @fn u32 GetLevel() const
	 * @brief ���x���擾
	 * @return ���x��
	 */
	u32 GetLevel() const { return Level; }

	/**
	 * @fn u32 GetHp() const
	 * @brief ���݂g�o�擾
	 * @return ���݂g�o
	 */
	u32 GetHp() const { return Hp; }

	/**
	 * @fn u32 GetMaxHp() const
	 * @brief �ő�g�o�擾
	 * @return �ő�g�o
	 */
	u32 GetMaxHp() const { return MaxHp; }

	/**
	 * @fn u32 GetNaturalStr() const
	 * @brief STR�擾
	 * @return STR
	 */
	u32 GetStr() const { return Str; }

	/**
	 * @fn u32 GetNaturalDef() const
	 * @brief DEF�擾
	 * @return DEF
	 */
	u32 GetDef() const { return Def; }

	/**
	 * @fn u32 GetNaturalInt() const
	 * @brief INT�擾
	 * @return INT
	 */
	u32 GetInt() const { return Int; }

	/**
	 * @fn u32 GetNaturalMnd() const
	 * @brief MND�擾
	 * @return MND
	 */
	u32 GetMnd() const { return Mnd; }

	/**
	 * @fn u32 GetNaturalVit() const
	 * @brief VIT�擾
	 * @return VIT
	 */
	u32 GetVit() const { return Vit; }

	/**
	 * @fn u32 GetNaturalStr() const
	 * @brief �������l�����Ȃ�������STR�擾
	 * @return �������l�����Ȃ�������STR
	 */
	u32 GetNaturalStr() const { return Str; }

	/**
	 * @fn u32 GetNaturalDef() const
	 * @brief �������l�����Ȃ�������DEF�擾
	 * @return �������l�����Ȃ�������DEF
	 */
	u32 GetNaturalDef() const { return Def; }

	/**
	 * @fn u32 GetNaturalInt() const
	 * @brief �������l�����Ȃ�������INT�擾
	 * @return �������l�����Ȃ�������INT
	 */
	u32 GetNaturalInt() const { return Int; }

	/**
	 * @fn u32 GetNaturalMnd() const
	 * @brief �������l�����Ȃ�������MND�擾
	 * @return �������l�����Ȃ�������MND
	 */
	u32 GetNaturalMnd() const { return Mnd; }

	/**
	 * @fn u32 GetNaturalVit() const
	 * @brief �������l�����Ȃ�������VIT�擾
	 * @return �������l�����Ȃ�������VIT
	 */
	u32 GetNaturalVit() const { return Vit; }

	/**
	 * @fn void AddHp(u32 Value)
	 * @brief �g�o����
	 * @param[in] Value �����l
	 */
	void AddHp(u32 Value);

	/**
	 * @fn void SubtractHp(u32 Value)
	 * @brief �g�o���Z
	 * @param[in] Value ���Z�l
	 */
	void SubtractHp(u32 Value);

	/**
	 * @fn void SetHp(u32 Value)
	 * @brief �g�o���Z�b�g
	 * @param[in] Value �l
	 */
	void SetHp(u32 Value)
	{
		Hp = Value;
		if (Hp > MaxHp)
		{
			Hp = MaxHp;
		}
	}

	/**
	 * @fn void ChangeEquip(u32 RightEquipId, u32 LeftEquipId)
	 * @brief �����؂�ւ�
	 * @param[in] RightEquipId �E�葕���h�c
	 * @param[in] LeftEquipId ���葕���h�c
	 */
	void ChangeEquip(u32 RightEquipId, u32 LeftEquipId);

	/**
	 * @fn const EquipData &GetRightEquip() const
	 * @brief �E�葕�������擾
	 * @return �E�葕�����
	 */
	const EquipData &GetRightEquip() const { return RightEquip; }

	/**
	 * @fn const EquipData &GetLeftEquip() const
	 * @brief ���葕�������擾
	 * @return ���葕�����
	 */
	const EquipData &GetLeftEquip() const { return LeftEquip; }

private:

	// ���x��
	u32 Level;

	// HP
	u32 Hp;

	// �ő�HP
	u32 MaxHp;

	// STR
	u32 Str;

	// DEF
	u32 Def;

	// INT
	u32 Int;

	// MND
	u32 Mnd;

	// VIT
	u32 Vit;

	// �E�葕��.
	EquipData RightEquip;

	// ���葕��.
	EquipData LeftEquip;

};

#endif		// #ifndef __CHARACTERPARAMETER_H__
