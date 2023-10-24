// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePickUp.h"
#include "AmmoPickUp.generated.h"

class ADrone;

UCLASS()
class DRONEGAME_API AAmmoPickUp : public ABasePickUp
{
	GENERATED_BODY()

private:
	virtual bool GivePickupTo(ADrone* Pawn) override;
};
