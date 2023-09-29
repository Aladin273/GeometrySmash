// Geometry Smash. All Rights Reserved


#include "GSGameModeBase.h"

#include "Player/GSBaseCharacter.h"
#include "Player/GSPlayerController.h"
#include "AI/GSAICharacter.h"
#include "AI/GSAIClearCharacter.h"
#include "UI/GSGameHUD.h"
#include "Engine/TargetPoint.h"

AGSGameModeBase::AGSGameModeBase()
{
    DefaultPawnClass = AGSBaseCharacter::StaticClass();
    PlayerControllerClass = AGSPlayerController::StaticClass();
    HUDClass = AGSGameHUD::StaticClass();
}

void AGSGameModeBase::BeginPlay()
{
    Super::BeginPlay();    
    
    UGSGameInstance* GameInstance = Cast<UGSGameInstance>(UGameplayStatics::GetGameInstance(this));
    
    Blanks = GameInstance->NumBlanks;
    Cleaners = GameInstance->NumCleaners;
    Enemies = Blanks + Cleaners;
    Marked = 0;

    AActor* SpawnPoint = UGameplayStatics::GetActorOfClass(GetWorld(), ATargetPoint::StaticClass());

    if (SpawnPoint)
    {
        for (int32 i = 1; i <= GameInstance->NumBlanks; ++i)
        {
            FVector SpawnLocation = SpawnPoint->GetTransform().GetLocation();
            APawn* SpawnedPawn = GetWorld()->SpawnActor<APawn>(GameInstance->Blank, SpawnLocation + FVector(0, -75, 0) * i, FRotator::ZeroRotator);
            
            if (SpawnedPawn)
                SpawnedPawn->SpawnDefaultController();
        }

        for (int32 i = 1; i <= GameInstance->NumCleaners; ++i)
        {
            FVector SpawnLocation = SpawnPoint->GetTransform().GetLocation();
            APawn* SpawnedPawn = GetWorld()->SpawnActor<APawn>(GameInstance->Cleaner, SpawnLocation + FVector(0, 75, 0) * i, FRotator::ZeroRotator);
            
            if (SpawnedPawn)
                SpawnedPawn->SpawnDefaultController();
        }
    }
}

bool AGSGameModeBase::IsGameOver() const
{
    return Marked == Enemies;
}

