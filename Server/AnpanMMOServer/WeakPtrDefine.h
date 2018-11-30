#ifndef __WEAKPTRDEFINE_H__
#define __WEAKPTRDEFINE_H__

/**
 * �e��N���X��weak_ptr�̕ʖ����`����ׂ̃w�b�_�t�@�C���B
 * �X�̃w�b�_�ɒ�`����Əz�Q�Ƃ̌����ɂȂ����肵�Ėʓ|�Ȃ̂�
 * ���̃w�b�_�ɏW�񂷂�B
 */

class PlayerCharacter;
typedef weak_ptr<PlayerCharacter> PlayerCharacterPtr;

class Anpan;
typedef weak_ptr<Anpan> AnpanPtr;

class Party;
typedef weak_ptr<Party> PartyPtr;

class Client;
typedef weak_ptr<Client> ClientPtr;

class AreaBase;
typedef weak_ptr<AreaBase> AreaPtr;

class InstanceAreaTicket;
typedef weak_ptr<InstanceAreaTicket> InstanceAreaTicketPtr;

#endif		// #ifndef __WEAKPTRDEFINE_H__
