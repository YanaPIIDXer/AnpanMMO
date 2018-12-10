#include "SkillMaster.h"
#include "MemoryStream/MemoryStreamReader.h"
#include "Config.h"
#include "GenericPlatformFile.h"
#include "FileManagerGeneric.h"

const FString SkillMaster::FileName = "Skill.bin";

void SkillMaster::Load()
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
		SkillItem Item;
		if (!Item.Serialize(&Reader)) { break; }
		Items.Add(Item.ID, Item);
	}

	delete[] pData;
}

TArray<SkillItem> SkillMaster::GetAll() const
{
	TArray<SkillItem> ItemArray;
	for (auto KeyValue : Items)
	{
		ItemArray.Add(KeyValue.Value);
	}
	ItemArray.Sort([](const SkillItem &A, const SkillItem &B)
	{
		return (A.ID < B.ID);
	});
	return ItemArray;
}

const SkillItem *SkillMaster::Get(u32 Key) const
{
	if (!Items.Contains(Key)) { return nullptr; }
	return &Items[Key];
}
