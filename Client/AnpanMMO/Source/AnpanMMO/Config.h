// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

/**
 * 定数定義.
 */
class ANPANMMO_API Config
{

public:

	// サーバホスト
	static const FString ServerHost;

	// サーバポート
	static const int ServerPort;

	// IDファイルのファイルパス取得.
	static FString GetIdFilePath();

};
