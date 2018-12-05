# コンパイラ
COMPILER  = gcc
# お好きなフラグを
CXXFLAGS    = -g -Wall -Werror
# ライブラリ関係の指定
ifeq "$(shell getconf LONG_BIT)" "64"
  LDFLAGS = -L/usr/local/lib -L/usr/lib -L./Lib
else
  LDFLAGS = -L/usr/local/lib -L/usr/lib -L./Lib
endif
LIBS      =
# インクルードパスの指定。これをちゃんとしておかないとDEPENDS(依存)ファイルがうまく作れない
INCLUDE   = -I../include -I/usr/local/include -I./
# 生成される実行ファイル
TARGETS   = AnpanMMOServer.out
# 生成されるバイナリファイルの出力ディレクトリ
TARGETDIR = ./
# ソースコードの位置
SRCROOT   = .
# 中間バイナリファイルの出力ディレクトリ
OBJROOT   = ./obj
# ソースディレクトリの中を(shellの)findコマンドで走破してサブディレクトリまでリスト化する
SRCDIRS  := $(shell find $(SRCROOT) -type d)
# ソースディレクトリを元にforeach命令で全cppファイルをリスト化する
SOURCES   = $(foreach dir, $(SRCDIRS), $(wildcard $(dir)/*.cpp))
# 上記のcppファイルのリストを元にオブジェクトファイル名を決定
OBJECTS   = $(addprefix $(OBJROOT)/, $(SOURCES:.cpp=.o))
# ソースディレクトリと同じ構造で中間バイナリファイルの出力ディレクトリをリスト化
OBJDIRS   = $(addprefix $(OBJROOT)/, $(SRCDIRS))
# 依存ファイル.dを.oファイルから作る
DEPENDS   = $(OBJECTS:.o=.d)

# 依存ファイルを元に実行ファイルを作る
$(TARGETS): $(OBJECTS) $(LIBS)
	$(COMPILER) -o $(TARGETDIR)/$@ $^ $(LDFLAGS) -g -lboost_system -lboost_random -lmysqlclient -llua -lscriptmodule -L/usr/lib/mysql/ -DBOOST_SYSTEM_NO_DEPRECATED

# 中間バイナリのディレクトリを掘りながら.cppを中間ファイル.oに
$(OBJROOT)/%.o: $(SRCROOT)/%.cpp
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	$(COMPILER) $(CXXFLAGS) -MD $(INCLUDE) -o $@ -c $<

# 依存関係の再生成
depend:
$(OBJROOT)/%.d: $(SRCROOT)/%.cpp
	@if [ ! -e `dirname $@` ]; then mkdir -p `dirname $@`; fi
	$(COMPILER) $(CXXFLAGS) -MM -MG $(INCLUDE) -o $@ -c $<

# クリーン
clean:
	@rm -rf obj

# リビルド
rebuild:
	@make clean
	@make

# 依存関係ファイル
-include $(DEPENDS)
