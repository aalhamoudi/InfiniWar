// // Copyright Abdulrahman Alhamoudi, 2016 - All rights reserved.

#pragma once

#include "Characters/InfiniCharacter.h"
#include "InfiniEnemy.generated.h"

/**
 * 
 */
UCLASS()
class INFINIEX_API AInfiniEnemy : public AInfiniCharacter
{
	GENERATED_BODY()
public:
	AInfiniEnemy();
	virtual void BeginPlay() override;

protected:
	UFUNCTION()
		void OnBeginMouseHover(class UPrimitiveComponent* Capsule);

	UFUNCTION()
		void OnEndMouseHover(class UPrimitiveComponent* Capsule);

	UFUNCTION()
		void OnClicked(class UPrimitiveComponent* Capsule);

	UFUNCTION()
		void OnTouchHover(ETouchIndex::Type Index, class AActor* OtherActor);
	
	
};
