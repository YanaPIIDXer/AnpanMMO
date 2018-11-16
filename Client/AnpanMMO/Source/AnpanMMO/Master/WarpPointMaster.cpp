#include "WarpPointMaster.h"
#include "MemoryStream/MemoryStreamReader.h"
#include "Config.h"
#include "GenericPlatformFile.h"
#include "FileManagerGeneric.h"

const FString WarpPointMaster::FileName = "WarpPoint.bin";

void WarpPointMaster::Load()
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
		WarpPointItem Item;
		if (!Item.Serialize(&Reader)) { break; }
		Items.Add(Item.Id, Item);
	}
}

TArray<WarpPointItem> WarpPointMaster::GetAll() const
{
	TArray<WarpPointItem> ItemArray;
	for (auto KeyValue : Items)
	{
		ItemArray.Add(KeyValue.Value);
	}
	ItemArray.Sort([](const WarpPointItem &A, const WarpPointItem &B)
	{
		return (A.Id < B.Id);
	});
	return ItemArray;
}

const WarpPointItem *WarpPointMaster::Get(u32 Key) const
{
	if (!Items.Contains(Key)) { return nullptr; }
	return &Items[Key];
}
