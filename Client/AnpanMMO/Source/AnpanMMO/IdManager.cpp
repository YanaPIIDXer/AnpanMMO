#include "AnpanMMO.h"
#include "IdManager.h"
#include <fstream>
#include <sstream>

const std::string IdManager::FileName = "Id.dat";
const int IdManager::IdLength = 32;

// コンストラクタ
IdManager::IdManager(const std::string &InFilePath)
	: IdCache("")
	, FilePath(InFilePath + FileName)
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
	std::ifstream FileStream(FilePath);
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
	std::ofstream FileStream(FilePath);
	FileStream << OutId;
}
