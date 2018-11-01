# NativePacketGeneratorについて

NativePacketGeneratorは、Excelファイルに記述した書式に基づいて自動でパケットを生成するツールです。  

必要な情報をExcelファイルに記述し、NativePacketGenerator.exeを実行するだけで、クライアント・サーバの両方にパケットソースが追加される仕組みになっています。  

パケットを定義するためのExcelファイルはPacketDataディレクトリに格納します。  

記述するフォーマットについては既存のファイルを参考にしてください。（気が向いたらREADME.mdに追記します。。。）  

基底クラスを指定しなければ、通常のクラス（構造体に近い？）を出力することも出来ます。
