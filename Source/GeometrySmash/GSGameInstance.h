// Geometry Smash. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GSGameUserSettings.h"
#include "Kismet/GameplayStatics.h"
#include "GSGameInstance.generated.h"

class AGSBaseCharacter;

/**
 * 
 */
UCLASS()
class GEOMETRYSMASH_API UGSGameInstance : public UGameInstance
{
	GENERATED_BODY()

protected:
	void OnStart() override
	{
		Super::OnStart();

		UGSGameUserSettings::GetBetterGameUserSettings()->LoadSettings();

		if (UGSGameUserSettings::GetBetterGameUserSettings()->GetFirstLaunch())
		{
			UGSGameUserSettings::GetBetterGameUserSettings()->SetOverallScalabilityLevel(3);
			UGSGameUserSettings::GetBetterGameUserSettings()->SetMusicVolume(0.75f);
			UGSGameUserSettings::GetBetterGameUserSettings()->SetSFXVolume(0.75f);
			UGSGameUserSettings::GetBetterGameUserSettings()->SetFirstLaunch(false);
		}

		UGSGameUserSettings::GetBetterGameUserSettings()->ApplySettings(false);

		UGameplayStatics::SetBaseSoundMix(this, Master);
		UGameplayStatics::SetSoundMixClassOverride(this, Master, Music, UGSGameUserSettings::GetBetterGameUserSettings()->GetMusicVolume(), 1.0f, 0.0f);
		UGameplayStatics::SetSoundMixClassOverride(this, Master, SFX, UGSGameUserSettings::GetBetterGameUserSettings()->GetSFXVolume(), 1.0f, 0.0f);
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundMix* Master;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundClass* Music;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundClass* SFX;

public:
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
