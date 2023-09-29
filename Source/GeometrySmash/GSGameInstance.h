// Geometry Smash. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GSGameUserSettings.h"
#include "GSGameInstance.generated.h"

class AGSBaseCharacter;

/**
 * 
 */
UCLASS()
class GEOMETRYSMASH_API UGSGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	void Init() override
	{
		Super::Init();

		UGSGameUserSettings::GetBetterGameUserSettings()->LoadSettings();

		if (UGSGameUserSettings::GetBetterGameUserSettings()->GetOverallScalabilityLevel() == -1)
			UGSGameUserSettings::GetBetterGameUserSettings()->SetOverallScalabilityLevel(3);

		UGSGameUserSettings::GetBetterGameUserSettings()->ApplySettings(false);
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AGSBaseCharacter> Blank;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<AGSBaseCharacter> Cleaner;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 NumBlanks = 6;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 NumCleaners = 6;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor PlayerColor = FColor::Red;
};
