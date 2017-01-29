// Copyright Abdulrahman Alhamoudi, 2016 - All rights reserved.

#include "InfiniEx.h"
#include "InfiniMeleeWeapon.h"



AInfiniMeleeWeapon::AInfiniMeleeWeapon()
{
	//GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AInfiniMeleeWeapon::OnBeginOverlap);
}


void AInfiniMeleeWeapon::OnBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, FString(TEXT("Hit")));

}
