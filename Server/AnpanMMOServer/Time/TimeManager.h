#ifndef __TIMEMANAGER_H__
#define __TIMEMANAGER_H__

/**
 * ���ԊǗ�.
 */
class TimeManager : public noncopyable
{

public:

	// �f�X�g���N�^
	virtual ~TimeManager() {}

	//������.
	void Initialize();

	// ���t���[���̏���.
	void Poll(int DeltaTime);

	// �}�X�^�h�c�擾.
	u32 GetMasterId() const { return MasterId; }

private:

	// ���ԑѕω��C���^�[�o��
	static const int TimeZoneChangeInterval;

	// ���݂̎��ԑ�.
	u8 CurrentTimeZone;

	// ���ԑѕω��^�C�}�[
	int TimeZoneChangeTimer;

	// �}�X�^�h�c
	u32 MasterId;

	// �^�C���]�[����ݒ�.
	void SetTimeZone(u8 NewTimeZone);

	// ========= Singleton =============
public:

	static TimeManager &GetInstance() { return Instance; }

private:

	TimeManager();
	static TimeManager Instance;

};

#endif		// #ifndef __TIMEMANAGER_H__
