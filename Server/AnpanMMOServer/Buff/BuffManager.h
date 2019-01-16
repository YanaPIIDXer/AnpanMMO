/**
 * @file BuffManager.h
 * @brief バフ管理クラス
 * @author YanaP
 */
#ifndef __BUFFMANAGER_H__
#define __BUFFMANAGER_H__

#include <boost/unordered_map.hpp>

class BuffBase;
class CharacterBase;

/**
 * @class BuffManager
 * @brief バフ管理
 */
class BuffManager
{

private:		// 別名定義.

	typedef boost::unordered_map<u8, BuffBase *> BuffMap;

public:

	/**
	 * @brief コンストラクタ
	 */
	BuffManager(CharacterBase *pInOwner);

	/**
	 * @brief デストラクタ
	 */
	~BuffManager();

	/**
	 * @fn void Poll(u32 DeltaTime)
	 * @brief 毎フレームの処理
	 * @param[in] DeltaTime 前フレームからの経過時間
	 */
	void Poll(u32 DeltaTime);

	/**
	 * @fn void AddBuff(u32 BuffId)
	 * @brief バフ追加。
	 * @param[in] バフＩＤ
	 */
	void AddBuff(u32 BuffId);

	/**
	 * @fn bool IsActive(u8 Type) const
	 * @brief 指定したバフ（デバフ）がかかっているか？
	 * @param[in] Type バフ（デバフ）タイプ
	 * @return かかっていればtrueを返す。
	 */
	bool IsActive(u8 Type) const { return (Buffs.find(Type) != Buffs.end()); }

private:

	// バフリスト
	BuffMap Buffs;

	// 所有者.
	CharacterBase *pOwner;

};

#endif		// #ifndef __BUFFMANAGER_H__
