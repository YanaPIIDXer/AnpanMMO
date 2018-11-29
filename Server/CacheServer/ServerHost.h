#ifndef __SERVERHOST_H__
#define __SERVERHOST_H__

/**
 * ���T�[�o�̃z�X�g
 * ���e��T�[�o�Ŏg���񂷃R�[�h
 */
class ServerHost
{

public:

	// �L���b�V���T�[�o�z�X�g
	static const std::string CacheServerHost;

	// ���[�h�`�F�b�N�T�[�o�z�X�g
	static const std::string WordCheckServerHost;

	// �Q�[���T�[�o�|�[�g
	static const int GameServerPort;

	// �L���b�V���T�[�o�|�[�g
	static const int CacheServerPort;

	// ���[�h�`�F�b�N�T�[�o�|�[�g
	static const int WordCheckServerPort;

};

#endif		// #ifndef __SERVERHOST_H__
