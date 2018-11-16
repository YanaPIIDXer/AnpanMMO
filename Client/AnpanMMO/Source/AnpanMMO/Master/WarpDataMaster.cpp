#include "WarpDataMaster.h"
#include "MemoryStream/MemoryStreamReader.h"
#include "Config.h"
#include "GenericPlatformFile.h"
#include "FileManagerGeneric.h"

const FString WarpDataMaster::FileName = "WarpData.bin";

void WarpDataMaster::Load()
{
	FString FilePath = Config::GetMasterDirectory() + "\\" + FileName;

	IPlatformFile &File = FPlatformFileManager::Get().GetPlatformFile();
	IFileHandle *pFileHandle = File.OpenRead(*FilePath);
	uint8 Data[2048];
	pFileHandle->Read(Data, 2048);
	int DataSize = pFileHandle->Size();
	pFileHandle->Flush();
	delete pFileHandle;

	MemoryStreamReader Reader(Data, DataSize);
	Items.Empty();
	while (true)
	{
		WarpDataItem Item;
		if (!Item.Serialize(&Reader)) { break; }
		Items.Add(Item.AutoKey, Item);
	}
}

TArray<WarpDataItem> WarpDataMaster::GetAll() const
{
	TArray<WarpDataItem> ItemArray;
	for (auto KeyValue : Items)
	{
		ItemArray.Add(KeyValue.Value);
	}
	ItemArray.Sort([](const WarpDataItem &A, const WarpDataItem &B)
	{
		return (A.AutoKey < B.AutoKey);
	});
	return ItemArray;
}

TArray<const WarpDataItem *> WarpDataMaster::CollectItems(u32 Key) const
{
	TArray<const WarpDataItem *> Result;
	for(const auto &KeyValue : Items)
	{
		if(KeyValue.Value.ID == Key)
		{
			Result.Add(&KeyValue.Value);
		}
	}
	return Result;
}
