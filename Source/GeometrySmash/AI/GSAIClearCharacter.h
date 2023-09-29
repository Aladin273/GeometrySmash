// Geometry Smash. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "../AI/GSAICharacter.h"
#include "GSAIClearCharacter.generated.h"

/**
 * 
 */
UCLASS()
class GEOMETRYSMASH_API AGSAIClearCharacter : public AGSAICharacter
{
	GENERATED_BODY()

protected:
	virtual void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;

	virtual void OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;
};
