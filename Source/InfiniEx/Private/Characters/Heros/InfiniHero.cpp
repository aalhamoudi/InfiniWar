// Copyright Abdulrahman Alhamoudi, 2016 - All rights reserved.

#include "InfiniEx.h"
#include "InfiniHero.h"

AInfiniHero::AInfiniHero()
{
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AInfiniHero::OnBeginOverlap);
	GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic(this, &AInfiniHero::OnEndOverlap);

	PrimaryAbilityParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("PrimaryAbilityParticleSystem"));
	SecondaryAbilityParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("SecondaryAbilityParticleSystem"));
	UltimateAbilityParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("UltimateAbilityParticleSystem"));

	PrimaryAbilityParticleSystem->bAutoActivate = false;
	SecondaryAbilityParticleSystem->bAutoActivate = false;
	UltimateAbilityParticleSystem->bAutoActivate = false;

	static ConstructorHelpers::FObjectFinder<UParticleSystem> PAPS(TEXT("ParticleSystem'/Game/FX/rpgeffects/Particles/P_Mage_MagicMissile.P_Mage_MagicMissile'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> SAPS(TEXT("ParticleSystem'/Game/FX/rpgeffects/Particles/P_Mage_EnergyBeam.P_Mage_EnergyBeam'"));
	static ConstructorHelpers::FObjectFinder<UParticleSystem> UAPS(TEXT("ParticleSystem'/Game/FX/rpgeffects/Particles/P_Mage_MagicSphere.P_Mage_MagicSphere'"));

	if (PAPS.Succeeded())
	{
		PrimaryAbilityParticleSystem->SetTemplate(PAPS.Object);
	}

	if (SAPS.Succeeded())
	{
		SecondaryAbilityParticleSystem->SetTemplate(SAPS.Object);
	}

	if (UAPS.Succeeded())
	{
		UltimateAbilityParticleSystem->SetTemplate(UAPS.Object);
	}

}


void AInfiniHero::OnBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->GetClass()->IsChildOf(AInfiniItem::StaticClass()))
		OtherActor->Destroy();

	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Item Begin"));

}

void AInfiniHero::OnEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Green, TEXT("Item End"));
		
}
