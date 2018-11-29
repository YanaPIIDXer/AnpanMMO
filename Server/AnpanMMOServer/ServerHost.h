#ifndef __SERVERHOST_H__
#define __SERVERHOST_H__

/**
 * 他サーバのホスト
 * ※各種サーバで使い回すコード
 */
class ServerHost
{

public:

	// キャッシュサーバホスト
	static const std::string CacheServerHost;

	// ワードチェックサーバホスト
	static const std::string WordCheckServerHost;

	// ゲームサーバポート
	static const int GameServerPort;

	// キャッシュサーバポート
	static const int CacheServerPort;

	// ワードチェックサーバポート
	static const int WordCheckServerPort;

};

#endif		// #ifndef __SERVERHOST_H__
