// stdafx.h : 標準のシステム インクルード ファイルのインクルード ファイル、または
// 参照回数が多く、かつあまり変更されない、プロジェクト専用のインクルード ファイル
// を記述します。
//

#pragma once

#include <stdio.h>

#include <boost/asio.hpp>
#include "basic_repeating_timer.h"

using namespace boost;
using asio::ip::tcp;

#include "TypeDefs.h"
#include "Config.h"

// TODO: プログラムに必要な追加ヘッダーをここで参照してください
