// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePickUp.h"
#include "HealthPickUp.generated.h"

class ADrone;

UCLASS()
class DRONEGAME_API AHealthPickUp : public ABasePickUp
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Parameters", meta = (ClampMin = "1.0", ClampMax = "100.0"))
	float AddHealth = 25.0;
private:
	virtual bool GivePickupTo(ADrone* Pawn) override;
};
