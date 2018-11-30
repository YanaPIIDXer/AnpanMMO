#ifndef __WEAKPTRDEFINE_H__
#define __WEAKPTRDEFINE_H__

/**
 * 各種クラスのweak_ptrの別名を定義する為のヘッダファイル。
 * 個々のヘッダに定義すると循環参照の原因になったりして面倒なので
 * このヘッダに集約する。
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
