// Geometry Smash. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GSPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class GEOMETRYSMASH_API AGSPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	void OnPossess(APawn* aPawn) override;
};
