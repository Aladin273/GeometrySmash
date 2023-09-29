// Geometry Smash. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "GSGameInstance.h"

#include "GSGameModeBase.generated.h"

class AGSBaseCharacter;

/**
 * 
 */
UCLASS()
class GEOMETRYSMASH_API AGSGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGSGameModeBase();

	void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	bool IsGameOver() const;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 Enemies = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 Blanks = 0;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 Cleaners = 0;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 Marked = 0;
};
