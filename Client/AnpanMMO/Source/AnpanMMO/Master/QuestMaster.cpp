#include "QuestMaster.h"
#include "MemoryStream/MemoryStreamReader.h"
#include "Config.h"
#include "GenericPlatformFile.h"
#include "FileManagerGeneric.h"

const FString QuestMaster::FileName = "Quest.bin";

void QuestMaster::Load()
{
	FString FilePath = Config::GetMasterDirectory() + "\\" + FileName;

	IPlatformFile &File = FPlatformFileManager::Get().GetPlatformFile();
	IFileHandle *pFileHandle = File.OpenRead(*FilePath);
	int32 DataSize = pFileHandle->Size();
	uint8 *pData = new uint8[DataSize];
	bool bReadResult = pFileHandle->Read(pData, DataSize);
	check(bReadResult);
	pFileHandle->Flush();
	delete pFileHandle;

	MemoryStreamReader Reader(pData, DataSize);
	Items.Empty();
	int32 SheetCount = 0;
	int32 DataCount = 0;
	Reader.Serialize(&SheetCount);
	Reader.Serialize(&DataCount);
	for (int32 i = 0; i < SheetCount; i++)
	{
		ItemMap ItemDic;
		for (int32 j = 0; j < DataCount; j++)
		{
			QuestItem Item;
			if (!Item.Serialize(&Reader)) { break; }
			ItemDic.Add(Item.Id, Item);
		}
		Items.Add(i, ItemDic);
	}

	delete[] pData;
}

TArray<QuestItem> QuestMaster::GetAllSheetItem(int32 SheetIndex) const
{
	TArray<QuestItem> ItemArray;
	if (!Items.Contains(SheetIndex)) { return ItemArray; }

	for (auto KeyValue : Items[SheetIndex])
	{
		ItemArray.Add(KeyValue.Value);
	}

	ItemArray.Sort([](const QuestItem &A, const QuestItem &B)
	{
		return (A.Id < B.Id);
	});
	return ItemArray;
}

TArray<QuestItem> QuestMaster::GetAll() const
{
	TArray<QuestItem> ItemArray;
	for (auto KeyValue : Items)
	{
		for (auto KeyValue2 : KeyValue.Value)
		{
			ItemArray.Add(KeyValue2.Value);
		}
	}
	ItemArray.Sort([](const QuestItem &A, const QuestItem &B)
	{
		return (A.Id < B.Id);
	});
	return ItemArray;
}

const QuestItem *QuestMaster::Get(u32 Key, int32 SheetIndex) const
{
	if (!Items.Contains(SheetIndex)) { return nullptr; }
	if(!Items[SheetIndex].Contains(Key)) { return nullptr; }
	return &Items[SheetIndex][Key];
}
