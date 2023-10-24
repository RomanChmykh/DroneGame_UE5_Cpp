// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePickUp.h"
#include "Drone.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"


ABasePickUp::ABasePickUp()
{
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	SphereComponent->InitSphereRadius(50.0f);
	SphereComponent->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	SetRootComponent(SphereComponent);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("StaticMeshComponent");
	StaticMeshComponent->SetupAttachment(SphereComponent);
}

void ABasePickUp::BeginPlay()
{
	Super::BeginPlay();
	
}

void ABasePickUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ABasePickUp::GivePickupTo(APawn* Drone)
{
	return false;
}


void ABasePickUp::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);

	ADrone* Drone = Cast<ADrone>(OtherActor);
	if (GivePickupTo(Drone))
	{
		PickupWasTaken();
	}
}

void ABasePickUp::PickupWasTaken()
{
	SphereComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Ignore);
	GetRootComponent()->SetVisibility(false, true);

	FTimerHandle RespawnTimerHandle;
	GetWorldTimerManager().SetTimer(RespawnTimerHandle, this, &ABasePickUp::RespawnPickup, RespawnTime);
}

void ABasePickUp::RespawnPickup()
{
	SphereComponent->SetCollisionResponseToAllChannels(ECollisionResponse::ECR_Overlap);
	GetRootComponent()->SetVisibility(true, true);
}

