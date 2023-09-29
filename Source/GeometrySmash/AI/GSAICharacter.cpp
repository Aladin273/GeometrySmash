// Geometry Smash. All Rights Reserved


#include "GSAICharacter.h"
#include "GSAIClearCharacter.h"

#include "../GSGameModeBase.h"
#include "Kismet/GameplayStatics.h"

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

		SetupColor(MarkBaseColor, MarkEmissionColor, MarkEmissionIntense);
	}
}

void AGSAICharacter::Clear()
{
	if (bMarked)
	{
		AGSGameModeBase* GameMode = Cast<AGSGameModeBase>(UGameplayStatics::GetGameMode(this));
		GameMode->Marked--;

		bMarked = false;
		SetupColor(BaseColor, EmissionColor, EmissionIntense);
	}
}

void AGSAICharacter::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

}

void AGSAICharacter::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (bMarked)
	{
		AGSAICharacter* TargetActor = Cast<AGSAICharacter>(OtherActor);

		if (TargetActor)
			TargetActor->Mark(this, MarkBaseColor, MarkEmissionColor, MarkEmissionIntense);
	}
}
