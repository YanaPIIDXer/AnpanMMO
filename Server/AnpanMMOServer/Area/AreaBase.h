/**
 * @file AreaBase.h
 * @brief �G���A���N���X
 * @author YanaP
 */

#ifndef __AREABASE_H__
#define __AREABASE_H__

#include <boost/enable_shared_from_this.hpp>
#include "PlayerManager.h"
#include "AnpanManager.h"
#include "HeightMap.h"

struct AreaItem;
class PacketBase;
class CharacterBase;

/**
 * @brief �G���A���N���X
 */
class AreaBase : public enable_shared_from_this<AreaBase>
{

public:

	/**
	 * @brief �R���X�g���N�^
	 * @param[in] pItem �G���A�}�X�^�A�C�e��
	 */
	AreaBase(const AreaItem *pItem);

	/**
	 * @brief �f�X�g���N�^
	 */
	virtual ~AreaBase() {}

	/**
	 * @fn virtual void Initialize
	 * @brief ������
	 */
	virtual void Initialize() {}

	/**
	 * @fn void Poll(int DeltaTime)
	 * @brief ���t���[���̏���
	 * @param[in] �O�t���[������̌o�ߎ���
	 */
	void Poll(int DeltaTime);

	/**
	 * @fn void AddPlayerCharacter(const PlayerCharacterPtr &pPlayer)
	 * @brief �v���C���[�L�����ǉ�
	 * @param[in] pPlayer �v���C���[�L�����ւ�weak_ptr
	 */
	void AddPlayerCharacter(const PlayerCharacterPtr &pPlayer);

	/**
	 * @fn void RemovePlayerCharacter(u32 Uuid)
	 * @brief �v���C���[�L�����폜
	 * @param[in] Uuid �v���C���[�L�����̂t�t�h�c
	 */
	void RemovePlayerCharacter(u32 Uuid);

	/**
	 * @fn void OnRecvMove(u32 Uuid, float X, float Y, float Z, float Rotation)
	 * @brief �ړ�����M����
	 * @param[in] Uuid �v���C���[�L�����̂t�t�h�c
	 * @param[in] X �w���W
	 * @param[in] Y �x���W
	 * @param[in] Z �y���W
	 * @param[in] Rotation ��]
	 */
	void OnRecvMove(u32 Uuid, float X, float Y, float Z, float Rotation);

	/**
	 * @fn void OnRecvSkillUse(u32 Uuid, u32 SkillId, u8 TargetType, u32 TargetUuid)
	 * @brief �X�L���g�p����M�����B
	 * @param[in] Uuid �v���C���[�L�����̂t�t�h�c
	 * @param[in] SkillId �X�L���h�c
	 * @param[in] TargetType �^�[�Q�b�g�^�C�v
	 * @param[in] TargetUuid �^�[�Q�b�g�̂t�t�h�c
	 */
	void OnRecvSkillUse(u32 Uuid, u32 SkillId, u8 TargetType, u32 TargetUuid);

	/**
	 * @fn void OnRecvUseItem(u32 Uuid, u32 ItemId, u8 TargetType, u32 TargetUuid)
	 * @brief �A�C�e���g�p����M�����B
	 * @param[in] Uuid �v���C���[�L�����̂t�t�h�c
	 * @param[in] ItemId �A�C�e���h�c
	 * @param[in] TargetType �^�[�Q�b�g�^�C�v
	 * @param[in] TargetUuid �^�[�Q�b�g�̂t�t�h�c
	 */
	void OnRecvItemUse(u32 Uuid, u32 ItemId, u8 TargetType, u32 TargetUuid);

	/**
	 * @fn void BroadcastPacket(PacketBase *pPacket, Client *pIgnoreClient = NULL)
	 * @brief �p�P�b�g�̃u���[�h�L���X�g
	 * @details �G���A���ɂ���v���C���[�S���Ƀp�P�b�g���o���T���B
	 * @param[in] pPacket �p�P�b�g
	 * @param[in] pIgnoreClient ���O����N���C�A���g
	 */
	void BroadcastPacket(PacketBase *pPacket, Client *pIgnoreClient = NULL);

	/**
	 * @fn void BroadcastPacketWithRange(PacketBase *pPacket, const Vector3D &Center, float Range, Client *pIgnoreClient = NULL)
	 * @brief �͈͂��w�肵���p�P�b�g�̃u���[�h�L���X�g
	 * @details �͈͓��ɂ���v���C���[�S���Ƀp�P�b�g���o���T���B
	 * @param[in] pPacket �p�P�b�g
	 * @param[in] Center ���S���W
	 * @param[in] Range ���a
	 * @param[in] pIgnoreClient ���O����N���C�A���g
	 */
	void BroadcastPacketWithRange(PacketBase *pPacket, const Vector3D &Center, float Range, Client *pIgnoreClient = NULL);

	/**
	 * @fn float GetHeight(float X, float Y) const
	 * @brief �������擾
	 * @details �n�C�g�}�b�v���Q�Ƃ��č�����Ԃ�
	 * @param[in] X �w���W
	 * @param[in] Y �x���W
	 * @return ����
	 */
	float GetHeight(float X, float Y) const;

	/**
	 * @fn bool CheckMovable(const Vector3D &Start, const Vector3D &End, float ClimbableHeight, Vector3D &OutHit) const
	 * @brief �ړ��ł��邩�ǂ������`�F�b�N
	 * @details ���C�L���X�g�ɂ��`�F�b�N
	 * @param[in] Start �`�F�b�N�J�n�n�_
	 * @param[in] End �`�F�b�N�I���n�_
	 * @param[in] float ClimbableHeight �o�邱�Ƃ��ł��鍂��
	 * @param[out] OutHit ���C�����������n�_
	 * @return �ړ��\�Ȃ�true��Ԃ�
	 */
	bool CheckMovable(const Vector3D &Start, const Vector3D &End, float ClimbableHeight, Vector3D &OutHit) const;

	/**
	 * @fn virtual u32 GetId() const = 0
	 * @brief ID���擾
	 * @details �}�X�^�̂h�c�Ƃ͈قȂ�\��������B�}�X�^�h�c���擾�������ꍇ��GetMasterId�֐����g�p����B
	 * @return ID
	 */
	virtual u32 GetId() const = 0;

	/**
	 * @fn u32 GetMasterId() const
	 * @brief �}�X�^�h�c���擾
	 * @return �}�X�^�h�c
	 */
	u32 GetMasterId() const { return MasterId; }

	/**
	 * @fn virtual bool IsAbleDelete() const
	 * @brief �����\���H
	 * @return �����\�Ȃ�true��Ԃ��B
	 */
	virtual bool IsAbleDelete() const = 0;

	/**
	 * @fn virtual bool IsInstance() const
	 * @brief �C���X�^���X�G���A���H
	 * @return �C���X�^���X�G���A�Ȃ�true��Ԃ��B
	 */
	virtual bool IsInstance() const { return false; }

	/**
	 * @fn void CollectCircle(const Vector3D &Center, float Radius, u8 TargetType, std::vector<CharacterBase *> &OutTargets)
	 * @brief �~�`�Ń^�[�Q�b�g���擾
	 * @param[in] Center ���S���W
	 * @param[in] Radius ���a
	 * @param[in] TargetType �^�[�Q�b�g�^�C�v
	 * @param[out] OutTargets �^�[�Q�b�g���X�g
	 */
	void CollectCircle(const Vector3D &Center, float Radius, u8 TargetType, std::vector<CharacterBase *> &OutTargets);

	/**
	 * @fn void CollectBox(const Vector3D &Center, float Width, float Height, u8 TargetType, std::vector<CharacterBase *> &OutTargets)
	 * @brief ��`�Ń^�[�Q�b�g���擾
	 * @param[in] Center ���S���W
	 * @param[in] Width ��
	 * @param[in] Height ����
	 * @param[in] TargetType �^�[�Q�b�g�^�C�v
	 * @param[out] OutTargets �^�[�Q�b�g���X�g
	 */
	void CollectBox(const Vector3D &Center, float Width, float Height, u8 TargetType, std::vector<CharacterBase *> &OutTargets);

protected:

	//! �v���C���[�Ǘ�.
	PlayerManager PlayerMgr;

	//! �A���p���Ǘ�.
	AnpanManager AnpanMgr;


	/**
	 * @fn virtual void Update()
	 * @brief �X�V����
	 */
	virtual void Update() {}

private:

	// �n�C�g�}�b�v
	HeightMap HeightData;

	//! �}�X�^�h�c
	u32 MasterId;


	// �A���p�����������ꂽ�B
	void OnSpawnAnpan(u32 Uuid, AnpanPtr pAnpan);

};

#endif		// #ifndef __AREABASE_H__
