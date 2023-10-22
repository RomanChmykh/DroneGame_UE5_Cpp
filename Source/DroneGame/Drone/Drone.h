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
};
