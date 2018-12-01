#ifndef __TIMEMANAGER_H__
#define __TIMEMANAGER_H__

/**
 * 時間管理.
 */
class TimeManager : public noncopyable
{

public:

	// デストラクタ
	virtual ~TimeManager() {}

	//初期化.
	void Initialize();

	// 毎フレームの処理.
	void Poll(int DeltaTime);

	// マスタＩＤ取得.
	u32 GetMasterId() const { return MasterId; }

private:

	// 時間帯変化インターバル
	static const int TimeZoneChangeInterval;

	// 現在の時間帯.
	u8 CurrentTimeZone;

	// 時間帯変化タイマー
	int TimeZoneChangeTimer;

	// マスタＩＤ
	u32 MasterId;

	// タイムゾーンを設定.
	void SetTimeZone(u8 NewTimeZone);

	// ========= Singleton =============
public:

	static TimeManager &GetInstance() { return Instance; }

private:

	TimeManager();
	static TimeManager Instance;

};

#endif		// #ifndef __TIMEMANAGER_H__
