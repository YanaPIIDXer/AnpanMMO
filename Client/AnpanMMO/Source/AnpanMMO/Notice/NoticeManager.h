// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Packet/NoticeData.h"

class MemoryStreamInterface;

DECLARE_DELEGATE_TwoParams(FOnRecvNotice, int32, const NoticeData &);

// �ʒm���.
struct NoticeInformation
{

public:

	// UUID
	uint32 Uuid;

	// �ʒm�f�[�^
	NoticeData Data;

};

/**
 * �ʒm�}�l�[�W��
 */
class ANPANMMO_API NoticeManager
{

public:

	// �R���X�g���N�^
	NoticeManager();

	// �f�X�g���N�^
	~NoticeManager() {}

	// �ʒm���X�g����M�����B
	bool OnRecvNoticeList(MemoryStreamInterface *pStream);

	// �ʒm����M�����B
	bool OnRecvNotice(MemoryStreamInterface *pStream);

	// �ʒm���X�g���擾.
	TArray<NoticeInformation> GetNoticeList() const;

	// �ʒm������.
	void RemoveNotice(uint32 Uuid);


	// �ʒm����M��������delegate
	FOnRecvNotice OnRecvNoticeDelegate;

private:

	// �ʒm���X�g
	TMap<int32, NoticeData> NoticeList;

	// ���Ɋ���U����UUID
	int32 NextUuid;


	// �ʒm��ǉ�.
	void AddNotice(const NoticeData &Data);

};
