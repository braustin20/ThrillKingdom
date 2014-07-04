

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
		/**
		 *	Gets Durability.
		 *
		 *	@return the Durability of this ride
		 */
		float GetDurability();

	UFUNCTION(BlueprintCallable, Category = getters)
		/**
		*	Gets ThrillFactor.
		*
		*	@return the ThrillFactor of this ride
		*/
		float GetThrillFactor();

	UFUNCTION(BlueprintCallable, Category = getters)
		/**
		*	Gets EnjoymentFactor.
		*
		*	@return the EnjoymentFactor of this ride
		*/
		float GetEnjoymentFactor();

	UFUNCTION(BlueprintCallable, Category = getters)
		/**
		*	Gets NauseaFactor.
		*
		*	@return the NauseaFactor of this ride
		*/
		float GetNauseaFactor();

	UFUNCTION(BlueprintCallable, Category = getters)
		/**
		*	Gets GForceFactor.
		*
		*	@return the GForceFactor of this ride
		*/
		float GetGForceFactor();

	/*
	 *	End Getters
	 */


	/*
	 *	Start Setters
	 */

	UFUNCTION(BlueprintCallable, Category = setters)
		/**
		*	Sets Durability to NewDurability.
		*
		*	@param NewDurability - The value which Durability will be set to, a float.
		*/
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
	/** The minimum value for Durability.*/
	float MinDurability;
	/** The maximum value for Durability.*/
	float MaxDurability;

	/** The minimum value for ThrillFactor.*/
	float MinThrillFactor;
	/** The maximum value for ThrillFactor.*/
	float MaxThrillFactor;

	/** The minimum value for EnjoymentFactor.*/
	float MinEnjoymentFactor;
	/** The maximum value for EnjoymentFactor.*/
	float MaxEnjoymentFactor;

	/** The minimum value for NauseaFactor.*/
	float MinNauseaFactor;
	/** The maximum value for NauseaFactor.*/
	float MaxNauseaFactor;

	/** The minimum value for GForceFactor.*/
	float MinGForceFactor;
	/** The maximum value for GForceFactor.*/
	float MaxGForceFactor;

	/*
	 *	End Constants
	 */
};
