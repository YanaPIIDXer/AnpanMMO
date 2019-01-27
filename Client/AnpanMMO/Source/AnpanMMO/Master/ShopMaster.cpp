#include "ShopMaster.h"
#include "MemoryStream/MemoryStreamReader.h"
#include "Config.h"
#include "GenericPlatformFile.h"
#include "FileManagerGeneric.h"

const FString ShopMaster::FileName = "Shop.bin";

void ShopMaster::Load()
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
			ShopItem Item;
			if (!Item.Serialize(&Reader)) { break; }
			ItemDic.Add(Item.AutoKey, Item);
		}
		Items.Add(i, ItemDic);
	}

	delete[] pData;
}

TArray<ShopItem> ShopMaster::GetAllSheetItem(int32 SheetIndex) const
{
	TArray<ShopItem> ItemArray;
	if (!Items.Contains(SheetIndex)) { return ItemArray; }

	for (auto KeyValue : Items[SheetIndex])
	{
		ItemArray.Add(KeyValue.Value);
	}

	ItemArray.Sort([](const ShopItem &A, const ShopItem &B)
	{
		return (A.AutoKey < B.AutoKey);
	});
	return ItemArray;
}

TArray<ShopItem> ShopMaster::GetAll() const
{
	TArray<ShopItem> ItemArray;
	for (auto KeyValue : Items)
	{
		for (auto KeyValue2 : KeyValue.Value)
		{
			ItemArray.Add(KeyValue2.Value);
		}
	}
	ItemArray.Sort([](const ShopItem &A, const ShopItem &B)
	{
		return (A.AutoKey < B.AutoKey);
	});
	return ItemArray;
}

TArray<const ShopItem *> ShopMaster::CollectItems(u32 Key, int32 SheetIndex) const
{
	TArray<const ShopItem *> Result;
	if(!Items.Contains(SheetIndex)) { return Result; }

	for(const auto &KeyValue : Items[SheetIndex])
	{
		if(KeyValue.Value.ID == Key)
		{
			Result.Add(&KeyValue.Value);
		}
	}
	return Result;
}
