// Copyright 2018 YanaPIIDXer All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include <functional>
#include <map>
#include "Packet/PacketID.h"
#include "MMOGameModeBase.generated.h"

class MemoryStreamInterface;
class ULayeredMenuWidgetBase;
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
	typedef std::map<uint8, PacketFunc> FunctionMap;

public:

	// �R���X�g���N�^
	AMMOGameModeBase(const FObjectInitializer &ObjectInitializer);

	// �f�X�g���N�^
	virtual ~AMMOGameModeBase() {}

	// �J�n���̏���.
	virtual void BeginPlay() override;

	// ���݂̃��j���[��ݒ�.
	void SetCurrentMenu(ULayeredMenuWidgetBase *pMenu) { pCurrentMenu = pMenu; }
	
protected:

	// �p�P�b�g��͊֐��ǉ�.
	void AddPacketFunction(uint8 ID, const PacketFunc &Func);

private:

	// �p�P�b�g��͊֐��Q.
	FunctionMap PacketFunctions;

	// ���݂̃��j���[
	TWeakObjectPtr<ULayeredMenuWidgetBase> pCurrentMenu;


	// �p�P�b�g����M�����B
	void OnRecvPacket(uint8 ID, MemoryStreamInterface *pStream);

};
