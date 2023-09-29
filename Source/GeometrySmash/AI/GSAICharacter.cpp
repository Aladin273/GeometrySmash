// Geometry Smash. All Rights Reserved


#include "GSAICharacter.h"
#include "GSAIClearCharacter.h"

void AGSAICharacter::Mark(FLinearColor InBaseColor, FLinearColor InEmissionColor, float InEmissionIntense)
{
	bMarked = true;
	MarkBaseColor = InBaseColor;
	MarkEmissionColor = InEmissionColor;
	MarkEmissionIntense = InEmissionIntense;

	SetColor(MarkBaseColor, MarkEmissionColor, MarkEmissionIntense);
}

void AGSAICharacter::Clear()
{
	bMarked = false;
	SetColor(BaseColor, EmissionColor, EmissionIntense);
}

void AGSAICharacter::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

}

void AGSAICharacter::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (bMarked)
	{
		AGSAICharacter* TargetActor = Cast<AGSAICharacter>(OtherActor);

		if (TargetActor && Cast<AGSAIClearCharacter>(OtherActor) == false)
			TargetActor->Mark(MarkBaseColor, MarkEmissionColor, MarkEmissionIntense);
	}
}
