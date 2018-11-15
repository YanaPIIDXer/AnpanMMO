#include "AreaMaster.h"
#include "MemoryStream/MemoryStreamReader.h"
#include "Config.h"
#include "GenericPlatformFile.h"
#include "FileManagerGeneric.h"

const FString AreaMaster::FileName = "Area.bin";

void AreaMaster::Load()
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
		AreaItem Item;
		if (!Item.Serialize(&Reader)) { break; }
		Items.Add(Item.ID, Item);
	}
}

TArray<AreaItem> AreaMaster::GetAll() const
{
	TArray<AreaItem> ItemArray;
	for (auto KeyValue : Items)
	{
		ItemArray.Add(KeyValue.Value);
	}
	ItemArray.Sort([](const AreaItem &A, const AreaItem &B)
	{
		return (A.ID < B.ID);
	});
	return ItemArray;
}

const AreaItem *AreaMaster::Get(u32 Key) const
{
	if (!Items.Contains(Key)) { return nullptr; }
	return &Items[Key];
}
