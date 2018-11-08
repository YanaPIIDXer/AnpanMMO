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

# Linuxサーバについて
サーバプログラムをデプロイするLinuxサーバは、用意できたマシンのスペックが足らず、以下のようなスペックとなっております。  
**OS : Fedora Core 5**  
**gcc : gcc4.1.1**  
gccのバージョンが古い為、C++11が使えない点に注意してください。  

# 起動準備
サーバの起動には以下の準備が必要です。  
1.MySQLで**AnpanMMO**データベースを用意する。（使用するユーザに権限も与えておく事。）  
2.Serverディレクトリに移動し、**mysql -u {ユーザ名} -p{パスワード} -D AnpanMMO < AnpanMMO.sql**コマンドを実行し、テーブルを展開しておく。  
3.AnpanMMOServerディレクトリに移動し、**DBUserData.txt**を作成し、一行目にMySQLでログインするユーザ名を、二行目にパスワードを記述する。  
