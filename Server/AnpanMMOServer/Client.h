/**
 * @file Client.h
 * @brief クライアントクラス
 * @author YanaP
 */

#ifndef __CLIENT_H__
#define __CLIENT_H__

#include "TCPConnection.h"
#include "Packet/PacketID.h"
#include "Script/ScriptExecuter.h"
#include "Script/ScriptFlagManager.h"
#include "Quest/QuestManager.h"
#include "WeakPtrDefine.h"

class PacketBase;
class ClientStateBase;
class PlayerCharacter;
class MemoryStreamInterface;

/**
 * @class Client
 * @brief クライアントクラス
 */
class Client : public TCPConnection
{

public:

	/**
	 * @brief コンストラクタ
	 * @param[in] pInSocket ソケットのshared_ptr
	 */
	Client(const shared_ptr<tcp::socket> &pInSocket);

	/**
	 * @brief デストラクタ
	 */
	virtual ~Client();
	
	/**
	 * @fn void SendPacket(PacketBase *pPacket)
	 * @brief パケット送信.
	 * @param[in] pPacket パケット
	 */
	void SendPacket(PacketBase *pPacket);

	/**
	 * @fn void ChangeState(ClientStateBase *pNextState)
	 * @brief ステート切り替え
	 * @param[in] pNextState 遷移先のState
	 */
	void ChangeState(ClientStateBase *pNextState);

	/**
	 * @fn void SetUuid(u32 InUuid)
	 * @brief UUIDをセット
	 * @param[in] InUuid UUID
	 */
	void SetUuid(u32 InUuid) { Uuid = InUuid; }

	/**
	 * @fn u32 GetUuid()
	 * @brief UUIDを取得.
	 * @return u32 UUID
	 */
	u32 GetUuid() const { return Uuid; }

	/**
	 * @fn void SetCustomerId(u32 InCustomerId)
	 * @brief カスタマＩＤをセット
	 * @details UUIDとは異なる。
	 * @param[in] InCustomerId カスタマＩＤ
	 */
	void SetCustomerId(u32 InCustomerId) { CustomerId = InCustomerId; }

	/**
	 * @fn u32 GetCustomerId()
	 * @brief カスタマＩＤを取得.
	 * @return u32 カスタマＩＤ
	 */
	u32 GetCustomerId() const { return CustomerId; }

	/**
	 * @fn PlayerCharacterPtr GetCharacter()
	 * @brief キャラクタを取得.
	 * @details weak_ptrを返す。
	 * @return PlayerCharacterPtr キャラクタへのweak_ptr
	 */
	PlayerCharacterPtr GetCharacter() const { return pCharacter; }

	/**
	 * @fn void CreateCharacter(u32 CharacterId, const std::string &Name, u8 Job, u32 Level, int MaxHp, int Atk, int Def, int Exp, u32 Gold)
	 * @brief キャラクタを作成.
	 * @param[in] CharacterId キャラクタＩＤ
	 * @param[in] Name キャラクタ名.
	 * @param[in] Job ジョブ
	 * @param[in] Level レベル
	 * @param[in] MaxHp 最大ＨＰ
	 * @param[in] Atk 攻撃力.
	 * @param[in] Def 防御力.
	 * @param[in] Exp 経験値.
	 * @param[in] Gold ゴールド
	 */
	void CreateCharacter(u32 CharacterId, const std::string &Name, u8 Job, u32 Level, int MaxHp, int Atk, int Def, int Exp, u32 Gold);

	/**
	 * @fn void RecvPacket(u8 ID, MemoryStreamInterface *pStream)
	 * @brief パケット受信.
	 * @details 主に他サーバからのレスポンス受信時に使用する。
	 * @param[in] ID パケットＩＤ
	 * @param[in] pStream ストリーム
	 */
	void RecvPacket(u8 ID, MemoryStreamInterface *pStream);

	/**
	 * @fn ScriptExecuter *GetScript()
	 * @brief スクリプト制御オブジェクト取得.
	 * @return ScriptExecuter * スクリプト管理オブジェクトへのポインタ
	 */
	ScriptExecuter *GetScript() { return &Script; }

	/**
	 * @fn void SetScriptFlag(int Key)
	 * @brief スクリプトフラグを設定.
	 * @param[in] Key キー
	 */
	void SetScriptFlag(int Key);

	/**
	 * @fn const ScriptFlagManager &GetScriptFlagManager() const
	 * @brief スクリプトフラグ管理取得.
	 * @return const ScriptFlagManager & スクリプトフラグ管理.
	 */
	const ScriptFlagManager &GetScriptFlagManager() const { return FlagManager; }

	/**
	 * @fn void ConvertScriptFlagFromBitFields(u32 BitField1, u32 BitField2, u32 BitField3)
	 * @brief ビットフィールドからスクリプトフラグに変換.
	 * @param[in] BitField1 ビットフィールド１
	 * @param[in] BitField2 ビットフィールド２
	 * @param[in] BitField3 ビットフィールド３
	 */
	void ConvertScriptFlagFromBitFields(u32 BitField1, u32 BitField2, u32 BitField3);

	/**
	 * @fn const QuestManager &GetQuestManager() const
	 * @brief クエスト管理取得.
	 * @return const QuestManager & クエスト管理.
	 */
	const QuestManager &GetQuestManager() const { return QuestMgr; }

	/**
	 * @fn void AddQuestData(const QuestData &Data)
	 * @brief クエストデータ追加.
	 * @param[in] Data クエストデータ
	 */
	void AddQuestData(const QuestData &Data);

	/**
	 * @fn void AcceptQuest(u32 QuestId)
	 * @brief クエスト受注.
	 * @param[in] QuestId クエストＩＤ
	 */
	void AcceptQuest(u32 QuestId);

	/**
	 * @fn void ProgressQuest(u32 QuestId)
	 * @brief クエスト進行.
	 * @param[in] QuestId クエストＩＤ
	 */
	void ProgressQuest(u32 QuestId);

	/**
	 * @fn void OnKilledAnpan(u32 AreaId)
	 * @brief アンパン殺害.
	 * @details 殺害したエリアのＩＤを渡す。
	 * @param[in] AreaId 殺害したエリアＩＤ
	 */
	void OnKilledAnpan(u32 AreaId);

	/**
	 * @fn u8 RetireQuest(u32 QuestId)
	 * @brief クエスト破棄.
	 * @param[in] QuestId クエストＩＤ
	 * @return u8 リザルトコード
	 */
	u8 RetireQuest(u32 QuestId);

protected:

	/**
	 * @fn void OnRecvData(size_t Size)
	 * @brief データを受信した。
	 * @param[in] Size 受信したデータサイズ
	 */
	virtual void OnRecvData(size_t Size);

private:

	//! State
	shared_ptr<ClientStateBase> pState;

	//! Uuid
	u32 Uuid;

	//! カスタマＩＤ
	u32 CustomerId;

	//! キャラクタ
	shared_ptr<PlayerCharacter> pCharacter;

	//! スクリプト
	ScriptExecuter Script;

	//! スクリプトフラグ管理.
	ScriptFlagManager FlagManager;

	//! クエスト管理.
	QuestManager QuestMgr;

};

#endif		// #ifndef __CLIENT_H__
