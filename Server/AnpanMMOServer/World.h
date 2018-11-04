#ifndef __WORLD_H__
#define __WORLD_H__

/**
 * ワールドクラス
 */
class World : noncopyable
{

public:

private:

	// ========== Singleton =========
public:

	static World &GetInstance() { return Instance; }

private:

	// コンストラクタ
	World();
	static World Instance;

};

#endif		// #ifndef __WORLD_H__
