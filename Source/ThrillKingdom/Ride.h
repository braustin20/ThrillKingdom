

#pragma once

#include "Attraction.h"
#include "Ride.generated.h"

/**
 * 
 */
UCLASS(abstract)
class ARide : public AAttraction
{
	GENERATED_UCLASS_BODY()


	/*
	*  Start Fields
	*/

	float Durability;
};
