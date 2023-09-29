// Geometry Smash. All Rights Reserved


#include "GSAIClearCharacter.h"

void AGSAIClearCharacter::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

}

void AGSAIClearCharacter::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (bMarked)
	{
		AGSAICharacter* TargetActor = Cast<AGSAICharacter>(OtherActor);

		if (TargetActor && Cast<AGSAIClearCharacter>(OtherActor) == false)
			TargetActor->Mark(MarkBaseColor, MarkEmissionColor, MarkEmissionIntense);
	}
	else
	{
		AGSAICharacter* TargetActor = Cast<AGSAICharacter>(OtherActor);

		if (TargetActor)
			TargetActor->Clear();
	}
}
