// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePickUp.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogBasePickUp, All, All)

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

void ABasePickUp::NotifyActorBeginOverlap(AActor* OtherActor)
{
	Super::NotifyActorBeginOverlap(OtherActor);
	UE_LOG(LogBasePickUp, Warning, TEXT("PickUpWasTaken!"))
	Destroy();
}


