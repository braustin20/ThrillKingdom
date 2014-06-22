

#pragma once

#include "Attraction.h"
#include "Ride.generated.h"

/**
 *	Class:		Ride
 *
 *	Purpose:	An abstract class used to represent rides within theme parks.
 *				Cannot be instantiated in game.
 *
 *	Fields:
 *	Methods:
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
