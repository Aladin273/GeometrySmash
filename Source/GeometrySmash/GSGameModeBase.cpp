// Geometry Smash. All Rights Reserved


#include "GSGameModeBase.h"

#include "UI/GSGameHUD.h"
#include "Player/GSBaseCharacter.h"
#include "Player/GSPlayerController.h"

AGSGameModeBase::AGSGameModeBase()
{
    DefaultPawnClass = AGSBaseCharacter::StaticClass();
    PlayerControllerClass = AGSPlayerController::StaticClass();
    HUDClass = AGSGameHUD::StaticClass();
}
