#ifndef __SERVERPORT_H__
#define __SERVERPORT_H__

/**
 * 各種サーバのポート
 * ※各種サーバで使い回すソースコード
 */
class ServerPort
{

public:

	// ゲームサーバ
	static const int GameServer;

	// キャッシュサーバ
	static const int CacheServer;

	// ワードチェックサーバ
	static const int WordCheckServer;

};

#endif		// #ifndef __SERVERPORT_H__
