

#pragma once

#include "Attraction.h"
#include "Ride.generated.h"

/**
 *	An abstract class used to represent rides within theme parks.
 *	Cannot be instantiated in game.
 */

UCLASS(abstract)
class ARide : public AAttraction
{
	GENERATED_UCLASS_BODY()
public:

	float GetDurability();
	float GetThrillFactor();
	float GetEnjoymentFactor();
	float GetNauseaFactor();
	float GetGForceFactor();

	void SetDurability(float NewDurability);

protected:

	/*
	 *  Start Fields
	 */

	float Durability;
	float ThrillFactor;
	float EnjoymentFactor;
	float NauseaFactor;
	float GForceFactor;
};
