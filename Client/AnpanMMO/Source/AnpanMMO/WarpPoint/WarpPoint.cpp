// Copyright 2018 YanaPIIDXer All Rights Reserved.

#include "WarpPoint.h"
#include "UObject/ConstructorHelpers.h"

const TCHAR *AWarpPoint::ParticlePath = TEXT("/Game/Effects/Effects/FX_Mobile/Fire/combat/P_AuraCircle_Fire_02.P_AuraCircle_Fire_02");

// コンストラクタ
AWarpPoint::AWarpPoint(const FObjectInitializer &ObjectInitializer)
	: Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	pParticleComponent = ObjectInitializer.CreateDefaultSubobject<UParticleSystemComponent>(this, "ParticleSystem");
	pParticleComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);

	static ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleFinder(ParticlePath);
	pParticleComponent->SetTemplate(ParticleFinder.Object);
}
