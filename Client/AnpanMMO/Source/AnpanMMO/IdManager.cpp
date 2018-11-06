#include "IdManager.h"
#include "AnpanMMO.h"
#include <fstream>
#include <sstream>
#if PLATFORM_WINDOWS
#include <direct.h>
#else
#include <sys/stat.h>
#endif

const std::string IdManager::FileName = "Id.dat";
const int IdManager::IdLength = 32;

// �R���X�g���N�^
IdManager::IdManager(const std::string &InFilePath)
	: IdCache("")
	, FilePath(InFilePath)
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
	std::ifstream FileStream(FilePath + FileName);
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
	const char *pFilePath = FilePath.c_str();
	struct stat StatBuffer;
	if (stat(pFilePath, &StatBuffer) != 0)
	{
#if PLATFORM_WINDOWS
		mkdir(pFilePath);
#else
		mkdir(pFilePath, S_IRWXU | S_IRWXG | S_IRWXO);
#endif
	}
	std::ofstream FileStream(FilePath + FileName);
	FileStream << OutId;
}
