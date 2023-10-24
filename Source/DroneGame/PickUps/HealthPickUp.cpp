#include "HealthPickUp.h"
#include "Drone.h"


bool AHealthPickUp::GivePickupTo(ADrone* Pawn)
{
	if (!(Pawn->GetIsDead()) && FMath::IsNearlyEqual(Pawn->GetHealht(),Pawn->GetMaxHealht())) { return false; }

	if(Pawn->GetHealht() < Pawn->GetMaxHealht())
	{
		if((Pawn->GetMaxHealht() - Pawn->GetHealht()) <= AddHealth)
		{
			Pawn->SetHealht(Pawn->GetMaxHealht());
			return true;
		}
		if ((Pawn->GetMaxHealht() - Pawn->GetHealht()) > AddHealth)
		{
			Pawn->SetHealht(Pawn->GetHealht() + AddHealth);
			return true;
		}
	}
	return false;
}
