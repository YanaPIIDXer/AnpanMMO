#include "$HEADER_FILE_NAME$"
#include "MemoryStream/MemoryStreamReader.h"
#include "Config.h"
#include "GenericPlatformFile.h"
#include "FileManagerGeneric.h"

const FString $CLASS_NAME$::FileName = "$BINARY_FILE_NAME$";

void $CLASS_NAME$::Load()
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
	while (true)
	{
		$ITEM_STRUCT_NAME$ Item;
		if (!Item.Serialize(&Reader)) { break; }
		Items.Add(Item.$KEY_NAME$, Item);
	}
}

TArray<$ITEM_STRUCT_NAME$> $CLASS_NAME$::GetAll() const
{
	TArray<$ITEM_STRUCT_NAME$> ItemArray;
	for (auto KeyValue : Items)
	{
		ItemArray.Add(KeyValue.Value);
	}
	ItemArray.Sort([](const $ITEM_STRUCT_NAME$ &A, const $ITEM_STRUCT_NAME$ &B)
	{
		return (A.$KEY_NAME$ < B.$KEY_NAME$);
	});
	return ItemArray;
}

const $ITEM_STRUCT_NAME$ *$CLASS_NAME$::Get($KEY_TYPE$ Key) const
{
	if (!Items.Contains(Key)) { return nullptr; }
	return &Items[Key];
}
