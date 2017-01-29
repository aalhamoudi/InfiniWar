// // Copyright Abdulrahman Alhamoudi, 2016 - All rights reserved.

#pragma once

#include "GameFramework/Actor.h"
#include "InfiniGear.generated.h"

UCLASS()
class INFINIEX_API AInfiniGear : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInfiniGear();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	
	
};
