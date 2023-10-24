// Fill out your copyright notice in the Description page of Project Settings.


#include "Turret.h"
#include "DroneGame/Drone/Drone.h"
#include "DroneGame/Bullet/BaseBullet.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "Perception/PawnSensingComponent.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ATurret::ATurret()
{
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>("SceneComponent");
	RootComponent = SceneComponent;

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	StaticMeshComponent->SetupAttachment(GetRootComponent());


	ArrowComponent = CreateDefaultSubobject<UArrowComponent>("ArrowComponent");
	ArrowComponent->SetupAttachment(StaticMeshComponent);

	PawnSensingComponent = CreateDefaultSubobject<UPawnSensingComponent>("PawnSensingComponent");
	PawnSensingComponent->OnSeePawn.AddDynamic(this, &ATurret::SeeDrone);
}

// Called when the game starts or when spawned
void ATurret::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ATurret::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATurret::Shoot()
{
	GetWorld()->SpawnActor<AActor>(SpawnBullet, this->ArrowComponent->GetComponentLocation(), GetActorRotation());
}


void ATurret::SeeDrone(APawn* SeeDrone)
{
	const ADrone* Drone = Cast<ADrone>(SeeDrone);
	if(Drone)
	{
		if (!(Drone->GetIsDead()))
		{
			const FVector DroneLocation = Drone->GetActorLocation();

			const FVector TurretLocation = this->GetActorLocation();
			const FVector DirectionToDrone = (DroneLocation - TurretLocation).GetSafeNormal();
			const FRotator TurretRotation = FRotationMatrix::MakeFromX(DirectionToDrone).Rotator();

			this->SetActorRotation(TurretRotation);

			//Do delay after each shot
			FTimerHandle ShootTimerHandle;
			GetWorldTimerManager().SetTimer(ShootTimerHandle, this, &ATurret::Shoot, ShootingInterval, false);
		}
	}
}

