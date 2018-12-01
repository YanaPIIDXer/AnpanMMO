# boostライブラリ
サーバプログラムではboostライブラリを使用しています。  
バージョンは**1.68**です。  
あらかじめboostライブラリをインストールしておき、以下のようにパスを通しておいてください。  
**BOOST_INCLUDE:{BoostDir}\include\boost-1_68**  
**BOOST_LIB:{BoostDir}\lib**  

# MySQLコネクタ
以下のURLから**32Bit版を**ダウンロードしてください。  
http://download.nust.na/pub6/mysql/downloads/connector/c/index.html  
ダウンロードしたものを展開し、以下の通りパスを通してください。  
**MYSQL_C_INCLUDE:{ConnectorRoot}\include**  
**MYSQL_C_LIB:{ConnectorRoot}\lib**

# Lua
以下のURLから**32Bit版を**ダウンロードしてください。
https://sourceforge.net/projects/luabinaries/files/5.3.4/Windows%20Libraries/Static/  
ダウンロードしたものを展開し、以下の通りパスを通してください。  
**LUA_INCLUDE:{LuaRoot}/include**  
**LUA_LIB:{LuaRoot}**

# Linuxサーバについて
サーバプログラムをデプロイするLinuxサーバは、用意できたマシンのスペックが足らず、以下のようなスペックとなっております。  
**OS : Fedora Core 5**  
**gcc : gcc4.1.1**  
gccのバージョンが古い為、C++11が使えない点に注意してください。  

# 起動準備
サーバの起動には以下の準備が必要です。  
1.MySQLで**AnpanMMO**データベースを用意する。（使用するユーザに権限も与えておく事。）  
2.Serverディレクトリに移動し、**mysql -u {ユーザ名} -p{パスワード} -D AnpanMMO < AnpanMMO.sql**コマンドを実行し、テーブルを展開しておく。  
3.CacheServerディレクトリに移動し、**DBUserData.txt**を作成し、一行目にMySQLでログインするユーザ名を、二行目にパスワードを記述する。
3.同様に**AnpanMMOMaster**データベースを用意し、使用するユーザに権限を与えておく。
4.AnpanMMOServerディレクトリ内に**MasterDBUserData.txt**を作成し、一行目にAnpanMMOMasterデータベースを参照するユーザ名を、二行目にパスワードを記述する。  
5.4の作業と同様に、WordCheckServerディレクトリ内にも**MasterDBUserData.txt**を作成し、AnpanMMOMasterデータベースを参照するユーザ名を一行目に、パスワードを二行目に記述する。

# サーバ起動について注意点
ゲームサーバ（AnpanMMOServer）は、起動時にキャッシュサーバとワードチェックサーバに接続するため、起動時にキャッシュサーバとワードチェックサーバが起動していないと起動できません。  
※Linuxの場合はServerディレクトリにあるAllBuild.shを実行するだけで自動的にキャッシュサーバ→ワードチェックサーバ→ゲームサーバの順に起動します。（※本来はビルドを行うためのスクリプトです。）　
