#include "IdManager.h"
#include "AnpanMMO.h"
#include <fstream>
#include <sstream>
#include <direct.h>

const std::string IdManager::FileName = "Id.dat";
const int IdManager::IdLength = 32;

// コンストラクタ
IdManager::IdManager(const std::string &InFilePath)
	: IdCache("")
	, FilePath(InFilePath)
{
}

// ID取得.
std::string IdManager::GetId()
{
	if (IdCache != "") { return IdCache; }

	std::string Id = "";
	if (!LoadId(Id))
	{
		// 生成.
		GenerateId(Id);
	}

	IdCache = Id;
	return Id;
}


// IDをロード
bool IdManager::LoadId(std::string &OutId)
{
	std::ifstream FileStream(FilePath + FileName);
	if (!FileStream) { return false; }

	FileStream >> OutId;
	return true;
}

// IDを生成.
void IdManager::GenerateId(std::string &OutId)
{
	std::stringstream StrStream;
	for (int i = 0; i < IdLength; i++)
	{
		char Ch = (FMath::RandRange(1, 100) < 50) ? 'A' : 'a';
		Ch += FMath::RandRange(0, 26);
		StrStream << Ch;
	}
	OutId = StrStream.str();

	// ファイルに保存.
	const char *pFilePath = FilePath.c_str();
	struct stat StatBuffer;
	if (stat(pFilePath, &StatBuffer) != 0)
	{
		mkdir(pFilePath);
	}
	std::ofstream FileStream(FilePath + FileName);
	FileStream << OutId;
}
