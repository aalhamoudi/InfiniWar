// Copyright Abdulrahman Alhamoudi, 2016 - All rights reserved.

#pragma once

#include "Characters/InfiniCharacter.h"
#include "Items/InfiniItem.h"
#include "ParticleDefinitions.h"
#include "InfiniHero.generated.h"

/**
 * 
 */
UCLASS()
class INFINIEX_API AInfiniHero : public AInfiniCharacter
{
	GENERATED_BODY()
	
public:
	AInfiniHero();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle Systems")
		UParticleSystemComponent* PrimaryAbilityParticleSystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle Systems")
		UParticleSystemComponent* SecondaryAbilityParticleSystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Particle Systems")
		UParticleSystemComponent* UltimateAbilityParticleSystem;

protected:
	TArray<AInfiniItem> Inventory;
	
	/** called when something enters the sphere component */
	UFUNCTION()
		void OnBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	/** called when something leaves the sphere component */
	UFUNCTION()
		void OnEndOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	
	
};
