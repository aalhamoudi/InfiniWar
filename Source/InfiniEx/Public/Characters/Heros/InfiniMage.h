// Copyright Abdulrahman Alhamoudi, 2016 - All rights reserved.

#pragma once

#include "Characters/Heros/InfiniHero.h"
#include "InfiniMage.generated.h"

/**
 * 
 */
UCLASS()
class INFINIEX_API AInfiniMage : public AInfiniHero
{
	GENERATED_BODY()
	
public:
	// Character Vitals //
	/** Max Stamina */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Vitals)
		float MaxStamina;

	/** Stamina Regen */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Vitals)
		float StaminaRegen;

	/** Actual Stamina */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Vitals)
		float Stamina;

	
	
};
