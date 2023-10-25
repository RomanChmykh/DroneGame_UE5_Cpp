#include "AmmoPickUp.h"
#include "Drone.h"


bool AAmmoPickUp::GivePickupTo(ADrone* Pawn)
{
	if (!(Pawn->GetIsDead()) && FMath::IsNearlyEqual(Pawn->GetAmmo(), Pawn->GetMaxAmmo())) { return false; }

	if (Pawn->GetAmmo() < Pawn->GetMaxAmmo())
	{
		if ((Pawn->GetMaxAmmo() - Pawn->GetAmmo()) <= AddAmmo)
		{
			Pawn->SetAmmo(Pawn->GetMaxAmmo());
			return true;
		}
		if ((Pawn->GetMaxAmmo() - Pawn->GetAmmo()) > AddAmmo)
		{
			Pawn->SetAmmo(Pawn->GetAmmo() + AddAmmo);
			return true;
		}
	}
	return false;
}
