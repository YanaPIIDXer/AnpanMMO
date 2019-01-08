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
			$ITEM_STRUCT_NAME$ Item;
			if (!Item.Serialize(&Reader)) { break; }
			ItemDic.Add(Item.$KEY_NAME$, Item);
		}
		Items.Add(i, ItemDic);
	}

	delete[] pData;
}

TArray<$ITEM_STRUCT_NAME$> $CLASS_NAME$::GetAll() const
{
	TArray<$ITEM_STRUCT_NAME$> ItemArray;
	for (auto KeyValue : Items)
	{
		for (auto KeyValue2 : KeyValue.Value)
		{
			ItemArray.Add(KeyValue2.Value);
		}
	}
	ItemArray.Sort([](const $ITEM_STRUCT_NAME$ &A, const $ITEM_STRUCT_NAME$ &B)
	{
		return (A.$KEY_NAME$ < B.$KEY_NAME$);
	});
	return ItemArray;
}

$GET_ITEM_FUNCTION$
