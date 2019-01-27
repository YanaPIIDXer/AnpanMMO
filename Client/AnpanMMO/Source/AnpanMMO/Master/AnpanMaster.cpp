#include "AnpanMaster.h"
#include "MemoryStream/MemoryStreamReader.h"
#include "Config.h"
#include "GenericPlatformFile.h"
#include "FileManagerGeneric.h"

const FString AnpanMaster::FileName = "Anpan.bin";

void AnpanMaster::Load()
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
			AnpanItem Item;
			if (!Item.Serialize(&Reader)) { break; }
			ItemDic.Add(Item.ID, Item);
		}
		Items.Add(i, ItemDic);
	}

	delete[] pData;
}

TArray<AnpanItem> AnpanMaster::GetAllSheetItem(int32 SheetIndex) const
{
	TArray<AnpanItem> ItemArray;
	if (!Items.Contains(SheetIndex)) { return ItemArray; }

	for (auto KeyValue : Items[SheetIndex])
	{
		ItemArray.Add(KeyValue.Value);
	}

	ItemArray.Sort([](const AnpanItem &A, const AnpanItem &B)
	{
		return (A.ID < B.ID);
	});
	return ItemArray;
}

TArray<AnpanItem> AnpanMaster::GetAll() const
{
	TArray<AnpanItem> ItemArray;
	for (auto KeyValue : Items)
	{
		for (auto KeyValue2 : KeyValue.Value)
		{
			ItemArray.Add(KeyValue2.Value);
		}
	}
	ItemArray.Sort([](const AnpanItem &A, const AnpanItem &B)
	{
		return (A.ID < B.ID);
	});
	return ItemArray;
}

const AnpanItem *AnpanMaster::Get(u32 Key, int32 SheetIndex) const
{
	if (!Items.Contains(SheetIndex)) { return nullptr; }
	if(!Items[SheetIndex].Contains(Key)) { return nullptr; }
	return &Items[SheetIndex][Key];
}
