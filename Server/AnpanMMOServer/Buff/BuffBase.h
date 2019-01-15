/**
 * @file BuffBase.h
 * @brief バフ基底クラス
 * @author YanaP
 */
#ifndef __BUFFBASE_H__
#define __BUFFBASE_H__

class CharacterBase;

/**
 * @class BuffBase
 * @brief バフ基底クラス
 */
class BuffBase
{

public:

	/**
	 * @brief コンストラクタ
	 * @param[in] Time 継続時間
	 * @param[in] pInCharacter キャラクタ
	 */
	BuffBase(u32 Time, CharacterBase *pInCharacter);

	/**
	 * @brief デストラクタ
	 */
	virtual ~BuffBase() {}

	/**
	 * @fn void Poll(u32 DeltaTime)
	 * @brief 毎フレームの処理
	 * @param[in] DeltaTime 前フレームからの経過時間
	 */
	void Poll(u32 DeltaTime);

	/**
	 * @fn bool IsFinished() const
	 * @brief 終了しているか？
	 * @return 終了していればtrueを返す
	 */
	bool IsFinished() const { return (LastTime <= 0); }

	/**
	 * @fn virtual u8 GetType() const
	 * @brief タイプを取得
	 * @return タイプ
	 */
	virtual u8 GetType() const = 0;

protected:

	/**
	 * @fn virtual void Update(u32 DeltaTime) = 0
	 * @brief 毎フレームの処理
	 * @param[in] DeltaTime 前フレームからの経過時間
	 */
	virtual void Update(u32 DeltaTime) {}

	/**
	 * @fn CharacterBase *GetCharacter()
	 * @brief キャラクタ取得
	 * @return キャラクタ
	 */
	CharacterBase *GetCharacter() { return pCharacter; }

private:

	// 残り時間.
	s32 LastTime;

	// キャラクタ
	CharacterBase *pCharacter;

};

#endif		// #ifndef __BUFFBASE_H__
