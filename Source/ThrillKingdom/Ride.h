

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

	/*
	 *	Start Getters
	 */

	UFUNCTION(BlueprintCallable, Category = getters)
		float GetDurability();
	UFUNCTION(BlueprintCallable, Category = getters)
		float GetThrillFactor();
	UFUNCTION(BlueprintCallable, Category = getters)
		float GetEnjoymentFactor();
	UFUNCTION(BlueprintCallable, Category = getters)
		float GetNauseaFactor();
	UFUNCTION(BlueprintCallable, Category = getters)
		float GetGForceFactor();

	/*
	 *	End Getters
	 */


	/*
	 *	Start Setters
	 */
	UFUNCTION(BlueprintCallable, Category = setters)
		void SetDurability(float NewDurability);

	/*
	 *	End Setters
	 */

protected:

	/*
	 *  Start Fields
	 */
	
	//TODO: work on finding good types and values for these fields
	/** How likely the ride is to breakdown.  0 Durability means 100% chance of breakdown, 100 Durability means 0% chance of breakdown.*/
	float Durability;
	/** How thrilling the ride is considered by Guests.  0 is the least thrilling, 10 is the most thrilling.  Determined by things like speed, acceleration, airtime, 
	and g-forces.*/
	float ThrillFactor;
	/** How enjoyable the ride is considered by Guests.  0 is the least enjoyable, 10 is the most enjoyable.  Determined by things like theming, comfort, special effects, 
	and thrill.*/
	float EnjoymentFactor;
	/** How nauseous the ride makes Guests.  0 does not make Guests nauseous, 10 makes Guests extrememly nauseous.  Determined by rapid acceleration, directional changes, 
	and disorientation.*/
	float NauseaFactor;
	/** How intense the G-forces this ride exerts on guests are.  0 is minimal G-forces, 10 is maximum G-forces.  Determined by vertical, lateral, and horizontal Gs.*/
	float GForceFactor;

	/*
	 *	End Fields
	 */

	
	/*
	 *	Start Constants
	 */

	//TODO: make these actual constants when their associated variables are their final types and values
	float MinDurability;
	float MaxDurability;

	float MinThrillFactor;
	float MaxThrillFactor;

	float MinEnjoymentFactor;
	float MaxEnjoymentFactor;

	float MinNauseaFactor;
	float MaxNauseaFactor;

	float MinGForceFactor;
	float MaxGForceFactor;

	/*
	 *	End Constants
	 */
};
