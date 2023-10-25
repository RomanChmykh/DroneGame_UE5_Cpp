// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Turret.generated.h"

class SceneComponent;
class UStaticMeshComponent;
class UArrowComponent;
class UPawnSensingComponent;

UCLASS()
class DRONEGAME_API ATurret : public APawn
{
	GENERATED_BODY()

public:
	ATurret();

	UFUNCTION(BlueprintCallable)
	float GetHealht() const { return Healht; }
	UFUNCTION(BlueprintCallable)
	void  SetHealht(float HealthValue) { Healht = HealthValue; }

	UFUNCTION(BlueprintCallable)
	bool GetIsDestroyed() const { return IsDestroyed; }
	UFUNCTION(BlueprintCallable)
	void SetIsDestroyed(bool IsDestroyedValue)  { IsDestroyed = IsDestroyedValue; }

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	USceneComponent* SceneComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Components")
	UArrowComponent* ArrowComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UPawnSensingComponent* PawnSensingComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Parameters")
	TSubclassOf<AActor> SpawnBullet;

	UPROPERTY(EditDefaultsOnly, Category = "Parameters")
	float ShootingInterval = 0.2f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Healht")
	float MaxHealht = 100.0f;


public:	
	
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


protected:
	void Shoot();

	UFUNCTION()
	void SeeDrone(APawn* SeeDrone);


private:

	UFUNCTION()
	void GetDamageFromBullet(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

private:
	float Healht = 0.0f;
	bool IsDestroyed = false;
};
