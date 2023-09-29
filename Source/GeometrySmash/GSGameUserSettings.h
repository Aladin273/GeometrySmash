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
	float GetMouseSensitivity() const { return MouseSensitivity; };

	UFUNCTION(BlueprintCallable)
	static UGSGameUserSettings* GetBetterGameUserSettings()
	{
		return Cast<UGSGameUserSettings>(UGameUserSettings::GetGameUserSettings());
	}

protected:
	UPROPERTY(Config)
	float MouseSensitivity = 1.0f;
};
