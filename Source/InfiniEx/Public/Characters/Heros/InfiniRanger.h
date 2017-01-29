// Copyright Abdulrahman Alhamoudi, 2016 - All rights reserved.

#pragma once

#include "Characters/Heros/InfiniHero.h"
#include "InfiniRanger.generated.h"

/**
 * 
 */
UCLASS()
class INFINIEX_API AInfiniRanger : public AInfiniHero
{
	GENERATED_BODY()
	
public:
	// Character Vitals //	
	/** Max Mana */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Vitals)
		float MaxMana;

	/** Mana Regen */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Vitals)
		float ManaRegen;

	/** Actual Mana */
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Vitals)
		float Mana;

	
	
};
