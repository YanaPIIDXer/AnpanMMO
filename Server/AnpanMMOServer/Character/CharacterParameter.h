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
	int Hp;

	//! 最大HP
	int MaxHp;

	//! 攻撃力.
	int Atk;

	//! 防御力.
	int Def;

};

#endif		// #ifndef __CHARACTERPARAMETER_H__
