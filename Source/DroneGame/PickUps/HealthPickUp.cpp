#include "HealthPickUp.h"

DEFINE_LOG_CATEGORY_STATIC(LogHealthPickup, All, All)

bool AHealthPickUp::GivePickupTo(APawn* Drone)
{
	UE_LOG(LogHealthPickup, Error, TEXT("HealthPickUp was taken"));
	return true;
}
