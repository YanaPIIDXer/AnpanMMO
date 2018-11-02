#include "AnpanMMO.h"
#include "IdManager.h"
#include <fstream>
#include <sstream>

const std::string IdManager::FileName = "Id.dat";
const int IdManager::IdLength = 32;

// �R���X�g���N�^
IdManager::IdManager(const std::string &InFilePath)
	: IdCache("")
	, FilePath(InFilePath + FileName)
{
}

// ID�擾.
std::string IdManager::GetId()
{
	if (IdCache != "") { return IdCache; }

	std::string Id = "";
	if (!LoadId(Id))
	{
		// ����.
		GenerateId(Id);
	}

	IdCache = Id;
	return Id;
}


// ID�����[�h
bool IdManager::LoadId(std::string &OutId)
{
	std::ifstream FileStream(FilePath);
	if (!FileStream) { return false; }

	FileStream >> OutId;
	return true;
}

// ID�𐶐�.
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

	// �t�@�C���ɕۑ�.
	std::ofstream FileStream(FilePath);
	FileStream << OutId;
}
