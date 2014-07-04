

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
	float Durability;
	float ThrillFactor;
	float EnjoymentFactor;
	float NauseaFactor;
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
