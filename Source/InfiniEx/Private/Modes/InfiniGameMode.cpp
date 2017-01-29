// Copyright Abdulrahman Alhamoudi, 2016 - All rights reserved.

#include "InfiniEx.h"
#include "InfiniGameMode.h"
#include "InfiniPlayerController.h"
#include "InfiniCharacter.h"

AInfiniGameMode::AInfiniGameMode()
{
	// use custom PlayerController class
	PlayerControllerClass = AInfiniPlayerController::StaticClass();

	// set up blueprint
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Characters/Heros/Knight/Blueprints/InfiniKnightBP"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}