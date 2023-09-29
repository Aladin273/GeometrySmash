// Geometry Smash. All Rights Reserved


#include "GSAICharacter.h"

void AGSAICharacter::Mark(AActor* InActor, FLinearColor InBaseColor, FLinearColor InEmissionColor, float InEmissionIntense)
{
	if (!bMarked)
	{
		AGSGameModeBase* GameMode = Cast<AGSGameModeBase>(UGameplayStatics::GetGameMode(this));
		GameMode->Marked++;

		bMarked = true;
		MarkBaseColor = InBaseColor;
		MarkEmissionColor = InEmissionColor;
		MarkEmissionIntense = InEmissionIntense;
		SetupPlayerColor(MarkBaseColor, MarkEmissionColor, MarkEmissionIntense);

		UGameplayStatics::PlaySoundAtLocation(this, MarkSound, GetActorLocation());
	}
}

void AGSAICharacter::Clear()
{
	if (bMarked)
	{
		AGSGameModeBase* GameMode = Cast<AGSGameModeBase>(UGameplayStatics::GetGameMode(this));
		GameMode->Marked--;

		bMarked = false;
		SetupPlayerColor(BaseColor, EmissionColor, EmissionIntense);

		UGameplayStatics::PlaySoundAtLocation(this, ClearSound, GetActorLocation());
	}
}

void AGSAICharacter::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (bMarked)
	{
		AGSAICharacter* TargetActor = Cast<AGSAICharacter>(OtherActor);

		if (TargetActor)
			TargetActor->Mark(this, MarkBaseColor, MarkEmissionColor, MarkEmissionIntense);
	}
}