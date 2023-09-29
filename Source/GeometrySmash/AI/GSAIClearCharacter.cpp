// Geometry Smash. All Rights Reserved

#include "GSAIClearCharacter.h"

void AGSAIClearCharacter::Mark(AActor* InActor, FLinearColor InBaseColor, FLinearColor InEmissionColor, float InEmissionIntense)
{
	if (!bMarked)
	{
		if (!Cast<AGSAICharacter>(InActor))
		{
			AGSGameModeBase* GameMode = Cast<AGSGameModeBase>(UGameplayStatics::GetGameMode(this));
			GameMode->Cleaners--;

			Super::Mark(InActor, InBaseColor, InEmissionColor, InEmissionIntense);
		}
	}
}

void AGSAIClearCharacter::Clear()
{
	if (bMarked)
	{
		AGSGameModeBase* GameMode = Cast<AGSGameModeBase>(UGameplayStatics::GetGameMode(this));
		GameMode->Cleaners++;

		Super::Clear();
	}
}

void AGSAIClearCharacter::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (!bMarked)
	{
		AGSAICharacter* TargetActor = Cast<AGSAICharacter>(OtherActor);

		if (TargetActor)
			TargetActor->Clear();
	}

	Super::OnHit(HitComponent, OtherActor, OtherComp, NormalImpulse, Hit);
}
