// Copyright Abdulrahman Alhamoudi, 2016 - All rights reserved.

#include "InfiniEx.h"
#include "InfiniPlayerController.h"
#include "AI/Navigation/NavigationSystem.h"
#include "Runtime/Engine/Classes/Components/DecalComponent.h"
#include "Kismet/HeadMountedDisplayFunctionLibrary.h"
#include "InfiniCharacter.h"
#include "InfiniEnemy.h"
#include "InfiniItem.h"
#include "InfiniAnimation.h"

AInfiniPlayerController::AInfiniPlayerController()
{
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Crosshairs;

	bEnableClickEvents = true;
	bEnableTouchEvents = true;
	bEnableMouseOverEvents = true;
	bEnableTouchOverEvents = true;

	Hero = Cast<AInfiniHero>(GetPawn());
}

void AInfiniPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	

	// keep updating the destination every tick while desired
	if (bMoveToMouseCursor)
	{
		MoveToMouseCursor();
	}



	if (Target)
	{
		if ((GetPawn()->GetDistanceTo(Target)) > 100.0)
			SetNewMoveDestination(Target->GetActorLocation());
		else
			PlayAttackAnimation();

	}
}

void AInfiniPlayerController::SetupInputComponent()
{
	// set up gameplay key bindings
	Super::SetupInputComponent();

	InputComponent->BindAction("SetDestination", IE_Pressed, this, &AInfiniPlayerController::OnSetDestinationPressed);
	InputComponent->BindAction("SetDestination", IE_Released, this, &AInfiniPlayerController::OnSetDestinationReleased);

	//InputComponent->BindAction("Attack", IE_Pressed, this, &AInfiniPlayerController::Attack);
	InputComponent->BindAction("PrimaryAbility", IE_Pressed, this, &AInfiniPlayerController::PrimaryAbility);
	InputComponent->BindAction("SecondaryAbility", IE_Pressed, this, &AInfiniPlayerController::SecondaryAbility);
	InputComponent->BindAction("UltimateAbility", IE_Pressed, this, &AInfiniPlayerController::UltimateAbility);


	// support touch devices 
	InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AInfiniPlayerController::MoveToTouchLocation);
	InputComponent->BindTouch(EInputEvent::IE_Repeat, this, &AInfiniPlayerController::MoveToTouchLocation);

	InputComponent->BindAction("ResetVR", IE_Pressed, this, &AInfiniPlayerController::OnResetVR);
}

void AInfiniPlayerController::OnResetVR()
{
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

void AInfiniPlayerController::MoveToMouseCursor()
{
	if (UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled())
	{
		if (AInfiniCharacter* MyPawn = Cast<AInfiniCharacter>(GetPawn()))
		{
			if (MyPawn->GetCursorToWorld())
			{
				UNavigationSystem::SimpleMoveToLocation(this, MyPawn->GetCursorToWorld()->GetComponentLocation());
			}
		}
	}
	else
	{
		// Trace to see what is under the mouse cursor
		FHitResult Hit;
		GetHitResultUnderCursor(ECC_Visibility, false, Hit);

		if (Hit.bBlockingHit)
		{
			// We hit something, move there
			SetNewMoveDestination(Hit.ImpactPoint);
		}
		
		
	}
}

void AInfiniPlayerController::MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	FVector2D ScreenSpaceLocation(Location);

	// Trace to see what is under the touch location
	FHitResult HitResult;
	GetHitResultAtScreenPosition(ScreenSpaceLocation, CurrentClickTraceChannel, true, HitResult);

	// Determine if an enemy is clicked on
	if (HitResult.GetActor()->GetClass()->IsChildOf(AInfiniEnemy::StaticClass()))
		Attack(HitResult.GetActor());

	// Determine if an item is clicked on
	else if (HitResult.GetActor()->GetClass()->IsChildOf(AInfiniItem::StaticClass()))
		PickUp(HitResult.GetActor());

	else if (HitResult.bBlockingHit)
	{
		Target = NULL;
		SetNewMoveDestination(HitResult.ImpactPoint);
	}
}

void AInfiniPlayerController::SetNewMoveDestination(const FVector DestLocation)
{
	APawn* const MyPawn = GetPawn();
	if (MyPawn)
	{
		UNavigationSystem* const NavSys = GetWorld()->GetNavigationSystem();
		float const Distance = FVector::Dist(DestLocation, MyPawn->GetActorLocation());

		// We need to issue move command only if far enough in order for walk animation to play correctly
		if (NavSys && (Distance > 120.0f))
		{
			NavSys->SimpleMoveToLocation(this, DestLocation);
		}
	}

}

void AInfiniPlayerController::OnSetDestinationPressed()
{
	// set flag to keep updating destination until released
	bMoveToMouseCursor = true;
}

void AInfiniPlayerController::OnSetDestinationReleased()
{
	// clear flag to indicate we should stop updating the destination
	bMoveToMouseCursor = false;
}


void AInfiniPlayerController::Attack(AActor* Enemy)
{
	Target = Enemy;

	// Move closer if too far
	if ((GetPawn()->GetDistanceTo(Enemy)) > 120.0)
		SetNewMoveDestination(Enemy->GetActorLocation());

	
}


void AInfiniPlayerController::PickUp(AActor* Item)
{
	if ((GetPawn()->GetDistanceTo(Item)) > 120.0)
		SetNewMoveDestination(Item->GetActorLocation());

}

void AInfiniPlayerController::PrimaryAbility()
{

	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), (Cast<AInfiniHero>(GetPawn()))->PrimaryAbilityParticleSystem->Template, (Cast<AInfiniHero>(GetPawn()))->GetActorLocation(), (Cast<AInfiniHero>(GetPawn()))->GetActorRotation());
	
}

void AInfiniPlayerController::SecondaryAbility()
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), (Cast<AInfiniHero>(GetPawn()))->SecondaryAbilityParticleSystem->Template, (Cast<AInfiniHero>(GetPawn()))->GetActorLocation(), (Cast<AInfiniHero>(GetPawn()))->GetActorRotation());
}

void AInfiniPlayerController::UltimateAbility()
{
	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), (Cast<AInfiniHero>(GetPawn()))->UltimateAbilityParticleSystem->Template, (Cast<AInfiniHero>(GetPawn()))->GetActorLocation(), (Cast<AInfiniHero>(GetPawn()))->GetActorRotation());
}

void AInfiniPlayerController::PlayAttackAnimation()
{
	// Play attack animation
	AInfiniCharacter* ControlledCharacter = Cast<AInfiniCharacter>(GetPawn());
	if (ControlledCharacter)
	{
		UInfiniAnimation* AnimInstanceRef = Cast<UInfiniAnimation>(ControlledCharacter->GetMesh()->GetAnimInstance());
		if (AnimInstanceRef) AnimInstanceRef->Attack();
	}
}