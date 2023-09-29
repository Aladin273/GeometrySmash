// Geometry Smash. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GSAIController.generated.h"

/**
 * 
 */
UCLASS()
class GEOMETRYSMASH_API AGSAIController : public AAIController
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;	

	virtual void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;

private:
	void MoveToRandom();

	FTimerHandle TimerHandle;
};
