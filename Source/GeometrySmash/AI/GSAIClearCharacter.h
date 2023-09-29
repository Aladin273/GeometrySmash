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
	virtual void Mark(AActor* InActor, FLinearColor InBaseColor, FLinearColor InEmissionColor, float InEmissionIntense) override;

	virtual void Clear() override;

	virtual void OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

private:
	bool bCleared;
};
