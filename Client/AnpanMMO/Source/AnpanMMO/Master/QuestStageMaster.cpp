#include "QuestStageMaster.h"
#include "MemoryStream/MemoryStreamReader.h"
#include "Config.h"
#include "GenericPlatformFile.h"
#include "FileManagerGeneric.h"

const FString QuestStageMaster::FileName = "QuestStage.bin";

void QuestStageMaster::Load()
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
			QuestStageItem Item;
			if (!Item.Serialize(&Reader)) { break; }
			ItemDic.Add(Item.Id, Item);
		}
		Items.Add(i, ItemDic);
	}

	delete[] pData;
}

TArray<QuestStageItem> QuestStageMaster::GetAllSheetItem(int32 SheetIndex) const
{
	TArray<QuestStageItem> ItemArray;
	if (!Items.Contains(SheetIndex)) { return ItemArray; }

	for (auto KeyValue : Items[SheetIndex])
	{
		ItemArray.Add(KeyValue.Value);
	}

	ItemArray.Sort([](const QuestStageItem &A, const QuestStageItem &B)
	{
		return (A.Id < B.Id);
	});
	return ItemArray;
}

TArray<QuestStageItem> QuestStageMaster::GetAll() const
{
	TArray<QuestStageItem> ItemArray;
	for (auto KeyValue : Items)
	{
		for (auto KeyValue2 : KeyValue.Value)
		{
			ItemArray.Add(KeyValue2.Value);
		}
	}
	ItemArray.Sort([](const QuestStageItem &A, const QuestStageItem &B)
	{
		return (A.Id < B.Id);
	});
	return ItemArray;
}

const QuestStageItem *QuestStageMaster::Get(u32 Key, int32 SheetIndex) const
{
	if (!Items.Contains(SheetIndex)) { return nullptr; }
	if(!Items[SheetIndex].Contains(Key)) { return nullptr; }
	return &Items[SheetIndex][Key];
}
