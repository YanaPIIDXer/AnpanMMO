/**
 * @file PacketSaveItemShortcutResult.h
 * @brief アイテムショートカット保存結果
 * @author NativePacketGenerator
 */

#ifndef __PACKETSAVEITEMSHORTCUTRESULT_H__
#define __PACKETSAVEITEMSHORTCUTRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief アイテムショートカット保存結果
 */
class PacketSaveItemShortcutResult  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @returns �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::SaveItemShortcutResult; }

	enum ResultCode
	{
		//! 
		Success = 成功,
		//! 
		Error = エラー,
	};

	//! 
u8 Result;
	//! 
u32 ItemId1;
	//! 
u32 ItemId2;
	

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSaveItemShortcutResult()
	{
	}

	/**
	 * @brief �R���X�g���N�^
	 */
	PacketSaveItemShortcutResult(u8 InResult, u32 InItemId1, u32 InItemId2)
	{
		Result = InResult;
		ItemId1 = InItemId1;
		ItemId2 = InItemId2;
		
	}


	/**
	 * @fn bool Serialize(MemoryStreamInterface *pStream)
	 * @brief �V���A���C�Y
	 * @param in pStream �X�g���[��
	 * @retrns ����������true��Ԃ��B
	 */
	bool Serialize(MemoryStreamInterface *pStream)
	{
		pStream->Serialize(&Result);
		pStream->Serialize(&ItemId1);
		pStream->Serialize(&ItemId2);
		
		return true;
	}
};

#endif		// #ifndef __PACKETSAVEITEMSHORTCUTRESULT_H__
