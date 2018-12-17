#ifndef __ITEMLIST_H__
#define __ITEMLIST_H__

#include <boost/unordered_map.hpp>

/**
 * �A�C�e�����X�g�N���X
 */
class ItemList
{

private:		// �ʖ���`.

	typedef boost::unordered_map<u32, u32> ItemMap;

public:

	// �R���X�g���N�^
	ItemList();

	// �f�X�g���N�^
	~ItemList() {}

	// �ǉ�.
	void Add(u32 ItemId, u32 Count);

	// ����.
	void Subtract(u32 ItemId, u32 Count);

	// �����擾.
	u32 GetCount(u32 ItemId) const;

private:

	// �A�C�e���}�b�v
	ItemMap Items;

};

#endif		// #ifndef __ITEMLIST_H__
