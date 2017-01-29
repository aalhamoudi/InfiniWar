// Copyright Abdulrahman Alhamoudi, 2016 - All rights reserved.

#pragma once
#include "GameFramework/PlayerController.h"
#include "Characters/Heros/InfiniHero.h"
#include "InfiniPlayerController.generated.h"

UCLASS()
class AInfiniPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AInfiniPlayerController();

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;
	bool bIsAttacking;
	AActor* Target;
	AInfiniHero* Hero;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	/** Navigate player to the current mouse cursor location. */
	void MoveToMouseCursor();

	/** Navigate player to the current touch location. */
	void MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location);
	
	/** Navigate player to the given world location. */
	void SetNewMoveDestination(const FVector DestLocation);

	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();

	/** Handle attack action */
	void Attack(AActor* Enemy);

	/** Handle pickup */
	void PickUp(AActor* Item);

	/** Handle abilities */
	void PrimaryAbility();
	void SecondaryAbility();
	void UltimateAbility();

	/** Animations */
	void PlayAttackAnimation();
};


