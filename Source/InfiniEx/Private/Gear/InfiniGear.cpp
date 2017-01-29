// // Copyright Abdulrahman Alhamoudi, 2016 - All rights reserved.

#include "InfiniEx.h"
#include "InfiniGear.h"


// Sets default values
AInfiniGear::AInfiniGear()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AInfiniGear::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInfiniGear::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

