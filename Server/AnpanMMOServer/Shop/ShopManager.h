/**
 * @file ShopManager.h
 * @brief �V���b�v�Ǘ��N���X
 * @author YanaP
 */
#ifndef __SHOPMANAGER_H__
#define __SHOPMANAGER_H__

#include <vector>
#include <boost/unordered_map.hpp>

/**
 * @class ShopManager
 * @brief �V���b�v�Ǘ�
 * @detail �V���O���g���N���X
 */
class ShopManager : public boost::noncopyable
{

private:		// �ʖ���`.

	typedef std::vector<u32> ItemList;
	typedef boost::unordered_map<u32, ItemList *> ShopMap;

public:

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~ShopManager();

	/**
	 * @fn void Initialize()
	 * @brief ������
	 */
	void Initialize();

	/**
	 * @fn bool IsValidShop(u32 ShopId) const
	 * @brief �L���ȃV���b�v���H
	 * @param[in] ShopId �V���b�v�h�c
	 * @return �L���Ȃ�true��Ԃ��B
	 */
	bool IsValidShop(u32 ShopId) const { return (ShopData.find(ShopId) != ShopData.end()); }

	/**
	 * @bool IsSelling(u32 ShopId, u32 ItemId) const
	 * @brief �����Ă��邩�H
	 * @param[in] ShopId �V���b�v�h�c
	 * @param[in] ItemId �A�C�e���h�c
	 * @return �����Ă�����true��Ԃ��B
	 */
	bool IsSelling(u32 ShopId, u32 ItemId) const;

private:

	// �V���b�v�f�[�^
	ShopMap ShopData;

	// ========== Singleton ============-
public:

	/**
	 * @fn static ShopManager &GetInstance()
	 * @brief �V���O���g���C���X�^���X���擾
	 * @return �V���O���g���C���X�^���X
	 */
	static ShopManager &GetInstance() { return Instance; }

private:

	ShopManager();
	static ShopManager Instance;

};

#endif		// #ifndef __SHOPMANAGER_H__
