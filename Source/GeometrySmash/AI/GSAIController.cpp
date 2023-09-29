// Geometry Smash. All Rights Reserved

#include "GSAIController.h"

#include "NavigationSystem.h"
#include "NavigationData.h"

#include "GameFramework/CharacterMovementComponent.h"

void AGSAIController::BeginPlay()
{
    Super::BeginPlay();

    MoveToRandom();
}

void AGSAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AGSAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
    MoveToRandom();
}

void AGSAIController::MoveToRandom()
{
    if (GetPawn())
    {
        UCharacterMovementComponent* MovementComponent = Cast<UCharacterMovementComponent>(GetPawn()->GetMovementComponent());

        if (MovementComponent)
        {
            MovementComponent->MaxWalkSpeed = FMath::RandRange(600.f, 1200.f);

            UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetCurrent(GetWorld());

            FNavLocation Result;
            NavSystem->GetRandomReachablePointInRadius(GetPawn()->GetActorLocation(), 1500, Result);

            MoveToLocation(Result.Location);
        }
    }
}
