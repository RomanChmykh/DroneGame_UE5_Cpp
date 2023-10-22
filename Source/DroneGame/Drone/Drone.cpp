// Fill out your copyright notice in the Description page of Project Settings.


#include "Drone.h"
#include "Components/BoxComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
ADrone::ADrone()
{
	PrimaryActorTick.bCanEverTick = true;


	BoxComponent = CreateDefaultSubobject<UBoxComponent>("BoxComponent");
	RootComponent = BoxComponent;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComponent->SetupAttachment(GetRootComponent());

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	StaticMeshComponent->SetupAttachment(GetRootComponent());

	FloatingPawnMovement = CreateDefaultSubobject<UFloatingPawnMovement>("FloatingPawnMovement");
}

// Called when the game starts or when spawned
void ADrone::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADrone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ADrone::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForwardBack", this, &ADrone::MoveForwardBack);
	PlayerInputComponent->BindAxis("MoveRightLeft", this, &ADrone::MoveRightLeft);
	PlayerInputComponent->BindAxis("MoveUp", this, &ADrone::MoveUp);
	PlayerInputComponent->BindAxis("MoveDown", this, &ADrone::MoveDown);
	PlayerInputComponent->BindAxis("LookX", this, &ADrone::LookX);
	PlayerInputComponent->BindAxis("LookY", this, &ADrone::LookY);
}

void ADrone::MoveForwardBack(float Amount)
{
	AddMovementInput(GetActorForwardVector(), Amount);
}

void ADrone::MoveRightLeft(float Amount)
{
	AddMovementInput(GetActorRightVector(), Amount);
}

void ADrone::MoveUp(float Amount)
{
	AddMovementInput(GetActorUpVector(), Amount);
}

void ADrone::MoveDown(float Amount)
{
	AddMovementInput(GetActorUpVector(), Amount);
}

void ADrone::LookX(float Amount)
{
	AddControllerYawInput(Amount);
}

void ADrone::LookY(float Amount)
{
	AddControllerPitchInput(Amount);
}

