#ifndef __IDMANAGER_H__
#define __IDMANAGER_H__

#include <string>

/**
 * IDのローカル管理.
 */
class IdManager
{

public:

	// コンストラクタ
	IdManager(const std::string &InFilePath);

	// デストラクタ
	~IdManager() {}

	// ID取得.
	std::string GetId();

private:

	// IDのキャッシュ.
	std::string IdCache;

	// ファイルパス
	std::string FilePath;

	// ファイル名.
	static const std::string FileName;

	// IDの長さ
	static const int IdLength;


	// IDをロード
	bool LoadId(std::string &OutId);

	// IDを生成.
	void GenerateId(std::string &OutId);

};

#endif		// #ifndef __IDMANAGER_H__
