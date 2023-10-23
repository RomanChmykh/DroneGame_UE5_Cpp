// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Drone.generated.h"

class UBoxComponent;
class UCameraComponent;
class UStaticMeshComponent;
class UFloatingPawnMovement;

UCLASS()
class DRONEGAME_API ADrone : public APawn
{
	GENERATED_BODY()

public:
	ADrone();
	float GetHealht() const { return Healht; }
	float GetAmmo() const { return Ammo; }

protected:
	
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UBoxComponent* BoxComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UStaticMeshComponent* StaticMeshComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Components")
	UFloatingPawnMovement* FloatingPawnMovement;

	UPROPERTY(EditDefaultsOnly, Category = "Parameters")
	TSubclassOf<AActor> SpawnBullet;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Healht")
	float MaxHealht = 100.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Ammo")
	float MaxAmmo = 50.0;

public:	
	
	virtual void Tick(float DeltaTime) override;

	
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


private:
	void MoveForwardBack(float Amount);
	void MoveRightLeft(float Amount);
	void MoveUp(float Amount);
	void MoveDown(float Amount);
	void LookX(float Amount);
	void LookY(float Amount);
	void Shoot();

private:
	float Healht = 0.0f;
	float Ammo = 0.0f;
};
