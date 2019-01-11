/**
 * @file EquipData.h
 * @brief �����f�[�^
 * @author YanaP
 */
#ifndef __EQUIPDATA_H__
#define __EQUIPDATA_H__

/**
 * @class EquipData
 * @brief �����f�[�^
 */
class EquipData
{

public:

	/**
	 * @brief �R���X�g���N�^
	 */
	EquipData();

	// �f�X�g���N�^
	~EquipData() {}

	/**
	 * @fn void Set(u32 InEquipId)
	 * @brief �Z�b�g
	 * @param[in] InEquipId �����h�c
	 */
	void Set(u32 InEquipId);

	/**
	 * @fn u32 GetEquipId() const
	 * @brief �����h�c�擾
	 * @return �����h�c
	 */
	u32 GetEquipId() const { return EquipId; }

	/**
	 * @fn u32 GetStr() const
	 * @brief STR�擾
	 * @return STR
	 */
	u32 GetStr() const { return Str; }

	/**
	 * @fn u32 GetDef() const
	 * @brief DEF�擾
	 * @return DEF
	 */
	u32 GetDef() const { return Def; }

	/**
	 * @fn u32 GetInt() const
	 * @brief INT�擾
	 * @return INT
	 */
	u32 GetInt() const { return Int; }

	/**
	 * @fn u32 GetMnd() const
	 * @brief MND�擾
	 * @return MND
	 */
	u32 GetMnd() const { return Mnd; }

	/**
	 * @fn u32 GetVit() const
	 * @brief VIT�擾
	 * @return VIT
	 */
	u32 GetVit() const { return Vit; }

	/**
	 * @fn void Reset()
	 * @brief ���Z�b�g
	 */
	void Reset();

private:

	// �����h�c
	u32 EquipId;

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

};

#endif		// #ifndef __EQUIPDATA_H__
