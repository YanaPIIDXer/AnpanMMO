/**
 * @file ShopManager.h
 * @brief ショップ管理クラス
 * @author YanaP
 */
#ifndef __SHOPMANAGER_H__
#define __SHOPMANAGER_H__

#include <vector>
#include <boost/unordered_map.hpp>

/**
 * @class ShopManager
 * @brief ショップ管理
 * @detail シングルトンクラス
 */
class ShopManager : public boost::noncopyable
{

private:		// 別名定義.

	typedef std::vector<u32> ItemList;
	typedef boost::unordered_map<u32, ItemList *> ShopMap;

public:

	/**
	 * @brief デストラクタ
	 */
	virtual ~ShopManager();

	/**
	 * @fn void Initialize()
	 * @brief 初期化
	 */
	void Initialize();

	/**
	 * @fn bool IsValidShop(u32 ShopId) const
	 * @brief 有効なショップか？
	 * @param[in] ShopId ショップＩＤ
	 * @return 有効ならtrueを返す。
	 */
	bool IsValidShop(u32 ShopId) const { return (ShopData.find(ShopId) != ShopData.end()); }

	/**
	 * @bool IsSelling(u32 ShopId, u32 ItemId) const
	 * @brief 売っているか？
	 * @param[in] ShopId ショップＩＤ
	 * @param[in] ItemId アイテムＩＤ
	 * @return 売られていたらtrueを返す。
	 */
	bool IsSelling(u32 ShopId, u32 ItemId) const;

private:

	// ショップデータ
	ShopMap ShopData;

	// ========== Singleton ============-
public:

	/**
	 * @fn static ShopManager &GetInstance()
	 * @brief シングルトンインスタンスを取得
	 * @return シングルトンインスタンス
	 */
	static ShopManager &GetInstance() { return Instance; }

private:

	ShopManager();
	static ShopManager Instance;

};

#endif		// #ifndef __SHOPMANAGER_H__
