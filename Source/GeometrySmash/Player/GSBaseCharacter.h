// Geometry Smash. All Rights Reserved

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "GSBaseCharacter.generated.h"

class UStaticMeshComponent;

class USpringArmComponent;
class UCameraComponent;

UCLASS()
class GEOMETRYSMASH_API AGSBaseCharacter : public ACharacter
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
	virtual void OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION()
	virtual void OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void SetColor(FLinearColor InBaseColor, FLinearColor InEmissionColor, float InEmissionIntense);

private:
	void MoveForward(float Amount);
	void MoveRight(float Amount);
};
