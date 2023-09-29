// Geometry Smash. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "../GSGameModeBase.h"

#include "GSBaseCharacter.generated.h"

class UStaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class GEOMETRYSMASH_API AGSBaseCharacter : public APawn
{
	GENERATED_BODY()

public:
	AGSBaseCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UCameraComponent* CameraComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USoundWave *HitSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MovementSpeed = 1600.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float LookSensitivity = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor BaseColor = FLinearColor::Black;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor EmissionColor = FLinearColor::Black;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float EmissionIntense = 0.0;

protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	virtual void SetupPlayerColor(FLinearColor InBaseColor, FLinearColor InEmissionColor, float InEmissionIntense);

	UFUNCTION()
	virtual void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	void MoveForward(float Amount);
	void MoveRight(float Amount);

	void LookUp(float Amount);
	void LookAround(float Amount);
};
