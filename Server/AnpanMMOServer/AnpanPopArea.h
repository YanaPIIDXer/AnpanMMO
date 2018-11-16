#ifndef __ANPANPOPAREA_H__
#define __ANPANPOPAREA_H__

#include <boost/function.hpp>
#include "Math/Vector2D.h"
#include "AnpanManager.h"

struct AnpanPopAreaItem;
class Anpan;

/**
 * �A���p�������������G���A
 */
class AnpanPopArea
{

private:		// �ʖ���`.

	typedef boost::function<void(shared_ptr<Anpan>)> SpawnFunc;

public:

	// �R���X�g���N�^
	AnpanPopArea(const AnpanPopAreaItem *pMasterItem);

	// �f�X�g���N�^
	~AnpanPopArea() {}

	// ���t���[���̏���.
	void Poll(int DeltaTime);

	// �����������̃R�[���o�b�N�ݒ�.
	void SetSpawnFunction(const SpawnFunc &InSpawnFunction) { SpawnFunction = InSpawnFunction; }

private:

	// ���a.
	float Range;

	// ���W.
	Vector2D Position;

	// �ő吶����,
	u32 MaxCount;

	// �ŏ�HP
	int MinHp;

	// �ő�HP
	int MaxHp;

	// �ŏ��U����.
	int MinAtk;

	// �ő�U����.
	int MaxAtk;

	// �ŏ��h���.
	int MinDef;

	// �ő�h���.
	int MaxDef;

	// �ŏ��o���l.
	int MinExp;

	// �ő�o���l.
	int MaxExp;

	// �C���^�[�o��
	const int PopInterval;

	// ���݂̃C���^�[�o��
	int CurrentInterval;

	// �������R�[���o�b�N
	SpawnFunc SpawnFunction;

	// ���̃|�b�v�G���A�����������A���p�����X�g
	std::vector<AnpanPtr> AnpanList;


	// �A���p���𐶐�.
	void SpawnAnpan();

	// ���X�g�X�V.
	void UpdateList();

};

#endif		// #ifndef __ANPANPOPAREA_H__
