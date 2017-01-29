// Copyright Abdulrahman Alhamoudi, 2016 - All rights reserved.

#pragma once

#include "Gear/Weapons/InfiniWeapon.h"
#include "InfiniMeleeWeapon.generated.h"

/**
 * 
 */
UCLASS()
class INFINIEX_API AInfiniMeleeWeapon : public AInfiniWeapon
{
	GENERATED_BODY()
	
public:
	AInfiniMeleeWeapon();
	
protected:
	UFUNCTION()
	void OnBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
