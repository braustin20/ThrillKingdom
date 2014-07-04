

#include "ThrillKingdom.h"
#include "Ride.h"


ARide::ARide(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	MinDurability = 0.0f;
	MaxDurability = 100.0f;

	MinThrillFactor = 0.0f;
	MaxThrillFactor = 10.0f;

	MinEnjoymentFactor = 0.0f;
	MaxEnjoymentFactor = 10.0f;

	MinNauseaFactor = 0.0f;
	MaxNauseaFactor = 10.0f;

	MinGForceFactor = 0.0f;
	MaxGForceFactor = 10.0f;
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
