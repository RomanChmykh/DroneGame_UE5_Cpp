#include "AmmoPickUp.h"

DEFINE_LOG_CATEGORY_STATIC(LogAmmoPickup, All, All)

bool AAmmoPickUp::GivePickupTo(APawn* Drone)
{
	UE_LOG(LogAmmoPickup, Error, TEXT("AmmoPickUp wastaken"));
	return true;
}
