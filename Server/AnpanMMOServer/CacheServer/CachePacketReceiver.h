#ifndef __CACHEPACKETRECEIVER_H__
#define __CACHEPACKETRECEIVER_H__

#include <boost/function.hpp>
#include <boost/unordered_map.hpp>
#include "Packet/PacketID.h"

class CacheServerConnection;
class MemoryStreamInterface;

/**
 * �p�P�b�g����M����N���X
 */
class CachePacketReceiver
{

private:		// �ʖ���`.

	typedef function<void(MemoryStreamInterface *)> PacketFunc;
	typedef unordered_map<PacketID, PacketFunc> PacketFuncMap;

public:

	// �R���X�g���N�^
	CachePacketReceiver(CacheServerConnection *pInParent);

	// �f�X�g���N�^
	~CachePacketReceiver() {}

	// �p�P�b�g��M.
	void RecvPacket(PacketID ID, MemoryStreamInterface *pStream);

private:

	// �e.
	CacheServerConnection *pParent;

	// �p�P�b�g��M�֐��}�b�v
	PacketFuncMap PacketFuncs;


	// �p�P�b�g��M�֐���ǉ�.
	void AddPacketFunc(PacketID ID, const PacketFunc &Func);

	// ���O�C�����ʂ���M�����B
	void OnRecvLogInResult(MemoryStreamInterface *pStream);

	// �L�����N�^�쐬���ʂ���M�����B
	void OnRecvCreateCharacterResult(MemoryStreamInterface *pStream);

	// �L�����N�^���̌��ʂ���M�����B
	void OnRecvCharacterDataResult(MemoryStreamInterface *pStream);

	// �X�N���v�g�t���O����M�����B
	void OnRecvScriptFlagResponse(MemoryStreamInterface *pStream);

};

#endif		// #ifndef __CACHEPACKETRECEIVER_H__
