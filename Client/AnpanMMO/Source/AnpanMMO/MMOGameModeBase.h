// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include <functional>
#include "MMOGameModeBase.generated.h"

enum PacketID;
class MemoryStreamInterface;
using namespace std::placeholders;

/**
 * GameMode���N���X
 */
UCLASS()
class ANPANMMO_API AMMOGameModeBase : public AGameModeBase
{

	GENERATED_BODY()

private:		// �ʖ���`.

	typedef std::function<void(MemoryStreamInterface *)> PacketFunc;
	typedef TMap<PacketID, PacketFunc> FunctionMap;

public:

	// �R���X�g���N�^
	AMMOGameModeBase(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~AMMOGameModeBase() {}

	// �J�n���̏���.
	virtual void BeginPlay() override;
	
protected:

	// �p�P�b�g��͊֐��ǉ�.
	void AddPacketFunction(PacketID ID, const PacketFunc &Func);

private:

	// �p�P�b�g��͊֐��Q.
	FunctionMap PacketFunctions;


	// �p�P�b�g����M�����B
	void OnRecvPacket(PacketID ID, MemoryStreamInterface *pStream);

};
