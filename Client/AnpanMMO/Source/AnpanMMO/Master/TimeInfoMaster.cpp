#include "TimeInfoMaster.h"
#include "MemoryStream/MemoryStreamReader.h"
#include "Config.h"
#include "GenericPlatformFile.h"
#include "FileManagerGeneric.h"

const FString TimeInfoMaster::FileName = "TimeInfo.bin";

void TimeInfoMaster::Load()
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
	while (true)
	{
		TimeInfoItem Item;
		if (!Item.Serialize(&Reader)) { break; }
		Items.Add(Item.Id, Item);
	}

	delete[] pData;
}

TArray<TimeInfoItem> TimeInfoMaster::GetAll() const
{
	TArray<TimeInfoItem> ItemArray;
	for (auto KeyValue : Items)
	{
		ItemArray.Add(KeyValue.Value);
	}
	ItemArray.Sort([](const TimeInfoItem &A, const TimeInfoItem &B)
	{
		return (A.Id < B.Id);
	});
	return ItemArray;
}

const TimeInfoItem *TimeInfoMaster::Get(u32 Key) const
{
	if (!Items.Contains(Key)) { return nullptr; }
	return &Items[Key];
}
