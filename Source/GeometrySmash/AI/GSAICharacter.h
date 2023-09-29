// Geometry Smash. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "../Player/GSBaseCharacter.h"
#include "GSAICharacter.generated.h"

/**
 * 
 */
UCLASS()
class GEOMETRYSMASH_API AGSAICharacter : public AGSBaseCharacter
{
	GENERATED_BODY()

public:
	virtual void Mark(AActor* InActor, FLinearColor InBaseColor, FLinearColor InEmissionColor, float InEmissionIntense);
	virtual void Clear();

protected:
	virtual void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;

	virtual void OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

	bool bMarked = false;
	FLinearColor MarkBaseColor;
	FLinearColor MarkEmissionColor;
	float MarkEmissionIntense;
};
