/**
 * @file CharacterParameter.h
 * @brief キャラクタパラメータ
 * @author YanaP
 */
#ifndef __CHARACTERPARAMETER_H__
#define __CHARACTERPARAMETER_H__

/**
 * @class CharacterParameter
 * @brief キャラクタパラメータ
 */
class CharacterParameter
{

public:

	/**
	 * @brief コンストラクタ
	 */
	CharacterParameter();

	/**
	 * @brief デストラクタ
	 */
	~CharacterParameter() {}

	/**
	 * @fn void Set(u32 InLevel, u32 InHp, u32 InMaxHp, u32 InStr, u32 InDef, u32 InInt, u32 InMnd, u32 InVit)
	 * @brief パラメータをセット
	 * @param[in] InLevel レベル
	 * @param[in] InHp 現在のＨＰ
	 * @param[in] InMaxHp 最大ＨＰ
	 * @param[in] InStr STR
	 * @param[in] InDef DEF
	 * @param[in] InInt INT
	 * @param[in] InMnd MND
	 * @param[in] InVit VIT
	 */
	void Set(u32 InLevel, u32 InHp, u32 InMaxHp, u32 InStr, u32 InDef, u32 InInt, u32 InMnd, u32 InVit);

	/**1
	 * @fn u32 GetLevel() const
	 * @brief レベル取得
	 * @return レベル
	 */
	u32 GetLevel() const { return Level; }

	/**
	 * @fn u32 GetHp() const
	 * @brief 現在ＨＰ取得
	 * @return 現在ＨＰ
	 */
	u32 GetHp() const { return Hp; }

	/**
	 * @fn u32 GetMaxHp() const
	 * @brief 最大ＨＰ取得
	 * @return 最大ＨＰ
	 */
	u32 GetMaxHp() const { return MaxHp; }

	/**
	 * @fn u32 GetNaturalStr() const
	 * @brief STR取得
	 * @return STR
	 */
	u32 GetStr() const { return Str; }

	/**
	 * @fn u32 GetNaturalDef() const
	 * @brief DEF取得
	 * @return DEF
	 */
	u32 GetDef() const { return Def; }

	/**
	 * @fn u32 GetNaturalInt() const
	 * @brief INT取得
	 * @return INT
	 */
	u32 GetInt() const { return Int; }

	/**
	 * @fn u32 GetNaturalMnd() const
	 * @brief MND取得
	 * @return MND
	 */
	u32 GetMnd() const { return Mnd; }

	/**
	 * @fn u32 GetNaturalVit() const
	 * @brief VIT取得
	 * @return VIT
	 */
	u32 GetVit() const { return Vit; }

	/**
	 * @fn u32 GetNaturalStr() const
	 * @brief 装備を考慮しない純粋なSTR取得
	 * @return 装備を考慮しない純粋なSTR
	 */
	u32 GetNaturalStr() const { return Str; }

	/**
	 * @fn u32 GetNaturalDef() const
	 * @brief 装備を考慮しない純粋なDEF取得
	 * @return 装備を考慮しない純粋なDEF
	 */
	u32 GetNaturalDef() const { return Def; }

	/**
	 * @fn u32 GetNaturalInt() const
	 * @brief 装備を考慮しない純粋なINT取得
	 * @return 装備を考慮しない純粋なINT
	 */
	u32 GetNaturalInt() const { return Int; }

	/**
	 * @fn u32 GetNaturalMnd() const
	 * @brief 装備を考慮しない純粋なMND取得
	 * @return 装備を考慮しない純粋なMND
	 */
	u32 GetNaturalMnd() const { return Mnd; }

	/**
	 * @fn u32 GetNaturalVit() const
	 * @brief 装備を考慮しない純粋なVIT取得
	 * @return 装備を考慮しない純粋なVIT
	 */
	u32 GetNaturalVit() const { return Vit; }

	/**
	 * @fn void AddHp(u32 Value)
	 * @brief ＨＰ増加
	 * @param[in] Value 増加値
	 */
	void AddHp(u32 Value);

	/**
	 * @fn void SubtractHp(u32 Value)
	 * @brief ＨＰ減算
	 * @param[in] Value 減算値
	 */
	void SubtractHp(u32 Value);

	/**
	 * @fn void SetHp(u32 Value)
	 * @brief ＨＰをセット
	 * @param[in] Value 値
	 */
	void SetHp(u32 Value)
	{
		Hp = Value;
		if (Hp > MaxHp)
		{
			Hp = MaxHp;
		}
	}

private:

	// レベル
	u32 Level;

	// HP
	u32 Hp;

	// 最大HP
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

};

#endif		// #ifndef __CHARACTERPARAMETER_H__
