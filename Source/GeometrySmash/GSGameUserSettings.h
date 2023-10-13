// Geometry Smash. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameUserSettings.h"
#include "GSGameUserSettings.generated.h"

/**
 * 
 */
UCLASS()
class GEOMETRYSMASH_API UGSGameUserSettings : public UGameUserSettings
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	void SetMouseSensitivity(float InMouseSensitivity) { MouseSensitivity = InMouseSensitivity; };
	
	UFUNCTION(BlueprintCallable)
	void SetMusicVolume(float InMusicVolume) { MusicVolume = InMusicVolume; };

	UFUNCTION(BlueprintCallable)
	void SetSFXVolume(float InSFXVolume) { SFXVolume = InSFXVolume; };

	UFUNCTION(BlueprintCallable)
	void SetFirstLaunch(bool InFirstLaunch) { bFirstLaunch = InFirstLaunch; };

	UFUNCTION(BlueprintCallable)
	float GetMouseSensitivity() const { return MouseSensitivity; };
	
	UFUNCTION(BlueprintCallable)
	float GetMusicVolume() const { return MusicVolume; };
	
	UFUNCTION(BlueprintCallable)
	float GetSFXVolume() const { return SFXVolume; };

	UFUNCTION(BlueprintCallable)
	bool GetFirstLaunch() const { return bFirstLaunch; };

	UFUNCTION(BlueprintCallable)
	static UGSGameUserSettings* GetBetterGameUserSettings()
	{
		return Cast<UGSGameUserSettings>(UGameUserSettings::GetGameUserSettings());
	}

protected:
	UPROPERTY(Config)
	float MusicVolume = 1.0f;

	UPROPERTY(Config)
	float SFXVolume = 1.0f;

	UPROPERTY(Config)
	float MouseSensitivity = 1.0f;

	UPROPERTY(Config)
	bool bFirstLaunch = true;
};
