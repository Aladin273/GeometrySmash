// Geometry Smash. All Rights Reserved


#include "GSBaseCharacter.h"
#include "../AI/GSAICharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"

AGSBaseCharacter::AGSBaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	SetRootComponent(StaticMeshComponent);

	SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>("SpringArmComponent");
	SpringArmComponent->SetupAttachment(StaticMeshComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(SpringArmComponent);

	StaticMeshComponent->SetSimulatePhysics(true);
	SpringArmComponent->bUsePawnControlRotation = true;
}

void AGSBaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	StaticMeshComponent->OnComponentHit.AddDynamic(this, &AGSBaseCharacter::OnHit);
	StaticMeshComponent->OnComponentBeginOverlap.AddDynamic(this, &AGSBaseCharacter::OnOverlap);

	SetupPlayerColor(BaseColor, EmissionColor, EmissionIntense);
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

	PlayerInputComponent->BindAxis("LookUp", this, &AGSBaseCharacter::LookUp);
	PlayerInputComponent->BindAxis("LookAround", this, &AGSBaseCharacter::LookAround);
}

void AGSBaseCharacter::SetupPlayerColor(FLinearColor InBaseColor, FLinearColor InEmissionColor, float InEmissionIntense)
{
	UMaterialInstanceDynamic* MaterialInstance = StaticMeshComponent->CreateAndSetMaterialInstanceDynamic(0);

	if (MaterialInstance)
	{
		MaterialInstance->SetVectorParameterValue("Base Color", InBaseColor);
		MaterialInstance->SetVectorParameterValue("Emission Color", InEmissionColor);
		MaterialInstance->SetScalarParameterValue("Emission Intense", InEmissionIntense);
	}
}

void AGSBaseCharacter::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	AGSAICharacter* TargetActor = Cast<AGSAICharacter>(OtherActor);

	if (TargetActor)
		TargetActor->Mark(this, BaseColor, EmissionColor, EmissionIntense);

	if (NormalImpulse.Length() > MovementSpeed * 0.125f)
		UGameplayStatics::PlaySoundAtLocation(this, HitSound, GetActorLocation());
}

void AGSBaseCharacter::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//AGSAICharacter* TargetActor = Cast<AGSAICharacter>(OtherActor);
	//
	//if (TargetActor)
	//	TargetActor->Mark(this, BaseColor, EmissionColor, EmissionIntense);
	//
	//UGameplayStatics::PlaySoundAtLocation(this, HitSound, GetActorLocation());
}

void AGSBaseCharacter::MoveForward(float Amount)
{
	FVector ForceVector = CameraComponent->GetForwardVector();
	ForceVector.X = ForceVector.X * MovementSpeed * Amount;
	ForceVector.Y = ForceVector.Y * MovementSpeed * Amount;
	StaticMeshComponent->AddForce(ForceVector);
}

void AGSBaseCharacter::MoveRight(float Amount)
{
	FVector ForceVector = CameraComponent->GetRightVector();
	ForceVector.X = ForceVector.X * MovementSpeed * Amount;
	ForceVector.Y = ForceVector.Y * MovementSpeed * Amount;
	StaticMeshComponent->AddForce(ForceVector);
}

void AGSBaseCharacter::LookUp(float Amount)
{
	AddControllerPitchInput(LookSensitivity * Amount * 0.5);
}

void AGSBaseCharacter::LookAround(float Amount)
{
	AddControllerYawInput(LookSensitivity * Amount * 0.5);
}

