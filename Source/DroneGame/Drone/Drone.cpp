// Fill out your copyright notice in the Description page of Project Settings.


#include "Drone.h"
#include "DroneGame/Bullet/BaseBullet.h"
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
	BoxComponent->OnComponentBeginOverlap.AddDynamic(this, &ADrone::GetDamageFromBullet);

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

	Healht = MaxHealht;
	Ammo = MaxAmmo;
}

// Called every frame
void ADrone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator CameraRotator = ADrone::CameraComponent->GetComponentRotation();
	FRotator NewRotator = FRotator(CameraRotator.Pitch, CameraRotator.Yaw, ADrone::BoxComponent->GetComponentRotation().Roll);
	ADrone::BoxComponent->SetWorldRotation(NewRotator);

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
	PlayerInputComponent->BindAction("Shoot", IE_Pressed, this, &ADrone::Shoot);
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

void ADrone::Shoot()
{
	if ((Ammo > 0) && (Healht!=0.0))
	{
		GetWorld()->SpawnActor<AActor>(SpawnBullet, this->CameraComponent->GetComponentLocation(), GetActorRotation());
		Ammo--;
	}
}

//its event when bullet BeginOverLap drone
void ADrone::GetDamageFromBullet(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
	UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ABaseBullet* BulletThatDamage = Cast<ABaseBullet>(OtherActor);

	if (BulletThatDamage)
	{
		float HealhtAfterDamage = this->GetHealht() - BulletThatDamage->GetDamageValue();

		if (HealhtAfterDamage >= 0.0f)
		{
			this->Healht = HealhtAfterDamage;
		}
		else
		{
			Healht = 0;
		}
		if(Healht==0.0)
		{
			IsDead = true;
		}
	}
}


