#include "NPCResourceMaster.h"
#include "MemoryStream/MemoryStreamReader.h"
#include "Config.h"
#include "GenericPlatformFile.h"
#include "FileManagerGeneric.h"

const FString NPCResourceMaster::FileName = "NPCResource.bin";

void NPCResourceMaster::Load()
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
			NPCResourceItem Item;
			if (!Item.Serialize(&Reader)) { break; }
			ItemDic.Add(Item.ID, Item);
		}
		Items.Add(i, ItemDic);
	}

	delete[] pData;
}

TArray<NPCResourceItem> NPCResourceMaster::GetAllSheetItem(int32 SheetIndex) const
{
	TArray<NPCResourceItem> ItemArray;
	if (!Items.Contains(SheetIndex)) { return ItemArray; }

	for (auto KeyValue : Items[SheetIndex])
	{
		ItemArray.Add(KeyValue.Value);
	}

	ItemArray.Sort([](const NPCResourceItem &A, const NPCResourceItem &B)
	{
		return (A.ID < B.ID);
	});
	return ItemArray;
}

TArray<NPCResourceItem> NPCResourceMaster::GetAll() const
{
	TArray<NPCResourceItem> ItemArray;
	for (auto KeyValue : Items)
	{
		for (auto KeyValue2 : KeyValue.Value)
		{
			ItemArray.Add(KeyValue2.Value);
		}
	}
	ItemArray.Sort([](const NPCResourceItem &A, const NPCResourceItem &B)
	{
		return (A.ID < B.ID);
	});
	return ItemArray;
}

const NPCResourceItem *NPCResourceMaster::Get(u32 Key, int32 SheetIndex) const
{
	if (!Items.Contains(SheetIndex)) { return nullptr; }
	if(!Items[SheetIndex].Contains(Key)) { return nullptr; }
	return &Items[SheetIndex][Key];
}
