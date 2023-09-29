// Geometry Smash. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GSAICharacter.h"

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

	virtual void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) override;
};
