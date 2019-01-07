/**
 * @file CharacterParameter.h
 * @brief キャラクタパラメータ
 * @author YanaP
 */
#ifndef __CHARACTERPARAMETER_H__
#define __CHARACTERPARAMETER_H__

/**
 * @struct CharacterParameter
 * @brief キャラクタパラメータ
 */
struct CharacterParameter
{

	//! レベル
	u32 Level;

	//! HP
	u32 Hp;

	//! 最大HP
	u32 MaxHp;

	//! STR
	u32 Str;

	//! DEF
	u32 Def;

	//! INT
	u32 Int;

	//! MND
	u32 Mnd;

	//! VIT
	u32 Vit;

};

#endif		// #ifndef __CHARACTERPARAMETER_H__
