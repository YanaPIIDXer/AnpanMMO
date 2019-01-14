// Copyright 2018 - 2019 YanaPIIDXer All Rights Reserved.

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

	// マスタＵＲＬ
	static const FString MasterURL;

	// マスタディレクトリを取得.
	static FString GetMasterDirectory();

	// スクリプトＵＲＬ
	static const FString ScriptURL;

	// スクリプトディレクトリを取得.
	static FString GetScriptDirectory();

private:

	// DLCのURL
	static const FString DLCURL;

public:

	// DLCのURLを取得
	static FString GetDLCURL();

	// DLCディレクトリを取得.
	static FString GetDLCDirectory();

};
