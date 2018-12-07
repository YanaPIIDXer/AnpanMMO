#include "NPCConditionMaster.h"
#include "MemoryStream/MemoryStreamReader.h"
#include "Config.h"
#include "GenericPlatformFile.h"
#include "FileManagerGeneric.h"

const FString NPCConditionMaster::FileName = "NPCCondition.bin";

void NPCConditionMaster::Load()
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
		NPCConditionItem Item;
		if (!Item.Serialize(&Reader)) { break; }
		Items.Add(Item.ID, Item);
	}

	delete[] pData;
}

TArray<NPCConditionItem> NPCConditionMaster::GetAll() const
{
	TArray<NPCConditionItem> ItemArray;
	for (auto KeyValue : Items)
	{
		ItemArray.Add(KeyValue.Value);
	}
	ItemArray.Sort([](const NPCConditionItem &A, const NPCConditionItem &B)
	{
		return (A.ID < B.ID);
	});
	return ItemArray;
}

const NPCConditionItem *NPCConditionMaster::Get(u32 Key) const
{
	if (!Items.Contains(Key)) { return nullptr; }
	return &Items[Key];
}
