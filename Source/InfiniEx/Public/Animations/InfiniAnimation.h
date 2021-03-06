﻿// Copyright Abdulrahman Alhamoudi, 2016 - All rights reserved.

#pragma once

#include "Animation/AnimInstance.h"
#include "InfiniAnimation.generated.h"

/**
 * 
 */
UCLASS()
class INFINIEX_API UInfiniAnimation : public UAnimInstance
{
	GENERATED_BODY()
	
protected:
	// Montages
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
		UAnimMontage* AnimMontage;

	// Motion
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
		float Speed;
	
public:
	void Attack();
};
