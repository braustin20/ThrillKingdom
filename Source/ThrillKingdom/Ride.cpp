

#include "ThrillKingdom.h"
#include "Ride.h"


ARide::ARide(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

}


float ARide::GetDurability()
{
	return Durability;
}

float ARide::GetThrillFactor()
{
	return ThrillFactor;
}

float ARide::GetEnjoymentFactor()
{
	return EnjoymentFactor;
}

float ARide::GetNauseaFactor()
{
	return NauseaFactor;
}

float ARide::GetGForceFactor()
{
	return GForceFactor;
}


void ARide::SetDurability(float NewDurability)
{
	Durability = NewDurability;
}
