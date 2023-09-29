// Geometry Smash. All Rights Reserved


#include "GSPlayerController.h"
#include "GSBaseCharacter.h"
#include "../GSGameUserSettings.h"


void AGSPlayerController::OnPossess(APawn* aPawn)
{
    Super::OnPossess(aPawn);

    UGSGameInstance* GameInstance = Cast<UGSGameInstance>(UGameplayStatics::GetGameInstance(this));
    
    AGSBaseCharacter* CurrentPlayer = Cast<AGSBaseCharacter>(GetPawn());
    CurrentPlayer->BaseColor = GameInstance->PlayerColor;
    CurrentPlayer->LookSensitivity = UGSGameUserSettings::GetBetterGameUserSettings()->GetMouseSensitivity();
}
