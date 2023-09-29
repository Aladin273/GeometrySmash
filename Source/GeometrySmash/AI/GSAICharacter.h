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
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundWave *MarkSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundWave *ClearSound;

	virtual void Mark(AActor* InActor, FLinearColor InBaseColor, FLinearColor InEmissionColor, float InEmissionIntense);

	virtual void Clear();

protected:
	virtual void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;

	bool bMarked = false;
	FLinearColor MarkBaseColor;
	FLinearColor MarkEmissionColor;
	float MarkEmissionIntense;
};
