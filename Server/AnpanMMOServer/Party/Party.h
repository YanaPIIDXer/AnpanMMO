#ifndef __PARTY_H__
#define __PARTY_H__

#include <boost/unordered_map.hpp>
#include "WeakPtrDefine.h"

/**
 * パーティクラス
 */
class Party : public enable_shared_from_this<Party>
{

private:		// 別名定義.

	typedef boost::unordered_map<u32, PlayerCharacterPtr> MemberMap;

public:

	// コンストラクタ
	Party(u32 InUuid);

	// デストラクタ
	~Party() {}

	// 参加.
	bool Join(PlayerCharacterPtr pPlayer);

	// 脱退.
	void Dissolution(u32 Uuid);

	// メンバリスト取得.
	std::vector<PlayerCharacterPtr> GetMemberList() const;

	// メンバが最大か？
	bool IsMaximumMember() const { return (MemberList.size() >= MaximumMember); }

	// 削除してもいいか？
	bool IsAbleDelete() const;

	// UUIDを取得.
	u32 GetUuid() const { return Uuid; }

private:

	// メンバ最大数.
	static const u32 MaximumMember;

	// メンバマップ
	MemberMap MemberList;

	// UUID
	u32 Uuid;

};

#endif		// #ifndef __PARTY_H__
