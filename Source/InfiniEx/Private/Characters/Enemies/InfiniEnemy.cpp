// // Copyright Abdulrahman Alhamoudi, 2016 - All rights reserved.

#include "InfiniEx.h"
#include "InfiniEnemy.h"

AInfiniEnemy::AInfiniEnemy()
{
	PrimaryActorTick.bCanEverTick = true;



}

void AInfiniEnemy::BeginPlay()
{
	Super::BeginPlay();

	
	GetCapsuleComponent()->OnBeginCursorOver.AddDynamic(this, &AInfiniEnemy::OnBeginMouseHover);
	GetCapsuleComponent()->OnEndCursorOver.AddDynamic(this, &AInfiniEnemy::OnEndMouseHover);
	OnInputTouchEnter.AddDynamic(this, &AInfiniEnemy::OnTouchHover);
}

void AInfiniEnemy::OnBeginMouseHover(UPrimitiveComponent* Capsule)
{
	GetMesh()->SetRenderCustomDepth(true);
}

void AInfiniEnemy::OnEndMouseHover(UPrimitiveComponent* Capsule)
{
	GetMesh()->SetRenderCustomDepth(false);
}

void AInfiniEnemy::OnClicked(UPrimitiveComponent* Capsule)
{
	GetMesh()->SetRenderCustomDepth(true);
}

void AInfiniEnemy::OnTouchHover(ETouchIndex::Type Index, AActor* OtherActor)
{
	GetMesh()->SetRenderCustomDepth(true);
}



