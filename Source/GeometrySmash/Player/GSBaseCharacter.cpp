// Geometry Smash. All Rights Reserved


#include "GSBaseCharacter.h"
#include "../AI/GSAICharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

AGSBaseCharacter::AGSBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	StaticMeshComponent->SetupAttachment(GetRootComponent());

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(GetRootComponent());

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);
}

void AGSBaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	StaticMeshComponent->OnComponentHit.AddDynamic(this, &AGSBaseCharacter::OnHit);
	StaticMeshComponent->OnComponentBeginOverlap.AddDynamic(this, &AGSBaseCharacter::OnOverlap);

	SetupColor(BaseColor, EmissionColor, EmissionIntense);
}

void AGSBaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AGSBaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &AGSBaseCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AGSBaseCharacter::MoveRight);

	PlayerInputComponent->BindAxis("LookUp", this, &AGSBaseCharacter::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookAround", this, &AGSBaseCharacter::AddControllerYawInput);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &AGSBaseCharacter::Jump);
}

void AGSBaseCharacter::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{

}

void AGSBaseCharacter::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AGSAICharacter* TargetActor = Cast<AGSAICharacter>(OtherActor);

	if (TargetActor)
		TargetActor->Mark(this, BaseColor, EmissionColor, EmissionIntense);
}

void AGSBaseCharacter::SetupColor(FLinearColor InBaseColor, FLinearColor InEmissionColor, float InEmissionIntense)
{
	UMaterialInstanceDynamic* MaterialInstance = StaticMeshComponent->CreateAndSetMaterialInstanceDynamic(0);

	if (MaterialInstance)
	{
		MaterialInstance->SetVectorParameterValue("Base Color", InBaseColor);
		MaterialInstance->SetVectorParameterValue("Emission Color", InEmissionColor);
		MaterialInstance->SetScalarParameterValue("Emission Intense", InEmissionIntense);
	}
}

void AGSBaseCharacter::MoveForward(float Amount)
{
	AddMovementInput(GetActorForwardVector(), Amount);
}

void AGSBaseCharacter::MoveRight(float Amount)
{
	AddMovementInput(GetActorRightVector(), Amount);
}

