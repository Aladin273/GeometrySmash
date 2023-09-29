// Geometry Smash. All Rights Reserved

#include "GSAIController.h"

#include "NavigationSystem.h"
#include "NavigationData.h"

#include "GSAICharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

void AGSAIController::BeginPlay()
{
    Super::BeginPlay();

    GetWorldTimerManager().SetTimer(TimerHandle, this, &AGSAIController::MoveToRandom, FMath::RandRange(0.25f, 0.5f), true);
}

void AGSAIController::MoveToRandom()
{
    AGSAICharacter* AIPawn = Cast<AGSAICharacter>(GetPawn());

    if (AIPawn)
    {
        UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetCurrent(GetWorld());

        if (NavSystem)
        {
            FNavLocation Result;
            NavSystem->GetRandomReachablePointInRadius(AIPawn->GetActorLocation(), AIPawn->MovementSpeed * FMath::RandRange(0.5f, 1.0f), Result);

            AIPawn->StaticMeshComponent->AddImpulse(Result.Location - AIPawn->GetActorLocation());

            GetWorldTimerManager().ClearTimer(TimerHandle);
            GetWorldTimerManager().SetTimer(TimerHandle, this, &AGSAIController::MoveToRandom, FMath::RandRange(0.25f, 0.5f), true);
        }
    }
}
