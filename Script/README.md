# スクリプトモジュールビルド環境構築
１：https://www.kunihikokaneko.com/cc/wintoolchain/mingw.html  
上記URLを参考にMinGWをインストールし、MinGU経由でgccをインストールしてください。（環境変数PATHにパスも通しておくこと。）  
２：https://qiita.com/tokikaze0604/items/e13c04192762f8d4ec85
上記URLを参考にmakeをインストールしてください。（これもパスを通しておくこと。）  
3:{VisualStudioインストールディレクトリ}\Common7\IDEにパスを通してください。

# スクリプトモジュールのビルド＆デプロイ
バッチファイルで自動化しています。  
ScriptModuleディレクトリ内のBuildAndDeploy.batを叩くことでビルドが行われ、サーバ・クライアント双方にヘッダファイルとライブラリファイルがコピーされます。  


# スクリプトについて
実際にゲーム（或いはサーバ）上で実行されるスクリプトはGitでは無くSVNで管理します。（GitHubでオープンにはしません。）
