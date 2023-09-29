// Geometry Smash. All Rights Reserved

#include "GSAIClearCharacter.h"

#include "../GSGameModeBase.h"
#include "Kismet/GameplayStatics.h"

void AGSAIClearCharacter::Mark(AActor* InActor, FLinearColor InBaseColor, FLinearColor InEmissionColor, float InEmissionIntense)
{
	if (!bMarked)
	{
		if (!Cast<AGSAICharacter>(InActor))
		{
			Super::Mark(InActor, InBaseColor, InEmissionColor, InEmissionIntense);

			AGSGameModeBase* GameMode = Cast<AGSGameModeBase>(UGameplayStatics::GetGameMode(this));
			GameMode->Cleaners--;
		}
	}
}

void AGSAIClearCharacter::Clear()
{
	if (bMarked)
	{
		AGSGameModeBase* GameMode = Cast<AGSGameModeBase>(UGameplayStatics::GetGameMode(this));
		GameMode->Cleaners++;
	}
	
	Super::Clear();
}

void AGSAIClearCharacter::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	Super::OnOverlap(OverlappedComp, OtherActor, OtherComp, OtherBodyIndex, bFromSweep, SweepResult);

	if (!bMarked)
	{
		AGSAICharacter* TargetActor = Cast<AGSAICharacter>(OtherActor);

		if (TargetActor)
			TargetActor->Clear();
	}
}
