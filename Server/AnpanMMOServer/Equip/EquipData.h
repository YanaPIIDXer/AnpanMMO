/**
 * @file EquipData.h
 * @brief 装備データ
 * @author YanaP
 */
#ifndef __EQUIPDATA_H__
#define __EQUIPDATA_H__

/**
 * @class EquipData
 * @brief 装備データ
 */
class EquipData
{

public:

	/**
	 * @brief コンストラクタ
	 */
	EquipData();

	// デストラクタ
	~EquipData() {}

	/**
	 * @fn void Set(u32 InEquipId)
	 * @brief セット
	 * @param[in] InEquipId 装備ＩＤ
	 */
	void Set(u32 InEquipId);

	/**
	 * @fn u32 GetEquipId() const
	 * @brief 装備ＩＤ取得
	 * @return 装備ＩＤ
	 */
	u32 GetEquipId() const { return EquipId; }

	/**
	 * @fn u32 GetStr() const
	 * @brief STR取得
	 * @return STR
	 */
	u32 GetStr() const { return Str; }

	/**
	 * @fn u32 GetDef() const
	 * @brief DEF取得
	 * @return DEF
	 */
	u32 GetDef() const { return Def; }

	/**
	 * @fn u32 GetInt() const
	 * @brief INT取得
	 * @return INT
	 */
	u32 GetInt() const { return Int; }

	/**
	 * @fn u32 GetMnd() const
	 * @brief MND取得
	 * @return MND
	 */
	u32 GetMnd() const { return Mnd; }

	/**
	 * @fn u32 GetVit() const
	 * @brief VIT取得
	 * @return VIT
	 */
	u32 GetVit() const { return Vit; }

	/**
	 * @fn void Reset()
	 * @brief リセット
	 */
	void Reset();

private:

	// 装備ＩＤ
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
