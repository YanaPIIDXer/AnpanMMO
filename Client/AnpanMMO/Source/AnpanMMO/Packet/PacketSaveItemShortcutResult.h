/**
 * @file PacketSaveItemShortcutResult.h
 * @brief �A�C�e���V���[�g�J�b�g�ۑ�����
 * @author NativePacketGenerator
 */

#ifndef __PACKETSAVEITEMSHORTCUTRESULT_H__
#define __PACKETSAVEITEMSHORTCUTRESULT_H__

#include "PacketBase.h"
#include "MemoryStream/MemoryStreamInterface.h"
#include "PacketID.h"


/**
 * @brief �A�C�e���V���[�g�J�b�g�ۑ�����
 */
class PacketSaveItemShortcutResult  : public PacketBase
{

public:

	/**
	 * @fn u8 GetPacketID() const
	 * @brief �p�P�b�g�h�c�擾.
	 * @return �p�P�b�g�h�c
	 */
	virtual u8 GetPacketID() const { return PacketID::SaveItemShortcutResult; }

	enum ResultCode
	{
		//! ����
		Success,
		//! �G���[
		Error,
	};

	//! ����
	u8 Result;
	//! �A�C�e���h�c�P
	u32 ItemId1;
	//! �A�C�e���h�c�Q
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
	 * @param[in] pStream �X�g���[��
	 * @return ����������true��Ԃ��B
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
