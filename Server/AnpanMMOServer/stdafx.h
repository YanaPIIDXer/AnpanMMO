// stdafx.h : 標準のシステム インクルード ファイルのインクルード ファイル、または
// 参照回数が多く、かつあまり変更されない、プロジェクト専用のインクルード ファイル
// を記述します。
//

#ifndef __STDAFX_H__
#define __STDAFX_H__

#define _WIN32_WINNT 0x0501

#include <stdio.h>

#include <boost/asio.hpp>
#include "basic_repeating_timer.h"

using namespace boost;
using asio::ip::tcp;

#include "TypeDefs.h"

// スクリプトモジュールがクライアントとの互換性を持つためのおまじない
#define SCRIPTMODULE_API

// TODO: プログラムに必要な追加ヘッダーをここで参照してください

#endif		// #ifndef __STDAFX_H__
