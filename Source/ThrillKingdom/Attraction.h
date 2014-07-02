

#pragma once

#include "GameFramework/Actor.h"
#include "Attraction.generated.h"

UENUM(BlueprintType)
namespace EAttractionStatus
{
	enum Status
	{
		open			UMETA(DisplayName = "open"),
		testing			UMETA(DisplayName = "testing"),
		closed			UMETA(DisplayName = "closed"),
		outOfService	UMETA(DisplayName = "out of service")
	};
}

//forward declaration of class AGuest
class AGuest;


/**
 *	The abstract class representing any item that a Guest
 *	can directly interact with.  Cannot be instantiated in
 *	game.
 */

UCLASS(abstract)
class AAttraction : public AActor
{
	GENERATED_UCLASS_BODY()
public:

	/*
	 *	Start Getter Methods
	 */

	UFUNCTION(BlueprintCallable, Category = getters)
		/**
		 *	Gets AttractionName.
		 *
		 *	@return the name of this Attraction
		 */
		FString GetAttractionName();

	UFUNCTION(BlueprintCallable, Category = getters)
		/**
		 *	Gets AttractionType.
		 *
		 *	@return an FString representing the type of this Attraction
		 */
		FString GetAttractionType();

	UFUNCTION(BlueprintCallable, Category = getters)
		/**
		 *	Gets EntranceLocation.
		 *
	 	 *	@return an FVector of the location of this Attraction's entrance
		 */
		FVector GetEntranceLocation();

	UFUNCTION(BlueprintCallable, Category = getters)
		/**
		 *	Gets ExitLocation.
		 *
		 *	@return an FVector of the location of this Attraction's exit
		 */
		FVector GetExitLocation();

	UFUNCTION(BlueprintCallable, Category = getters)
		/**
		 *	Gets EntranceFee.
		 *
		 *	@return a float of how much it costs a Guest to ride this Attraction
		 */
		float GetEntranceFee();

	UFUNCTION(BlueprintCallable, Category = getters)
		/**
		 *	Gets OperatingCosts.
		 *
		 *	@return a float of how much it costs a park to operate this Attraction per hour
		 */
		float GetOperatingCosts();

	//TODO: come up with a UFUNCTION for this
	/**
	 *	Gets AttractionStatus.
	 *
	 *	@return the status of this Attraction, an EAttractionStatus
	 */
	virtual EAttractionStatus::Status GetAttractionStatus();

	UFUNCTION(BlueprintCallable, Category = getters)
		/**
		 *	Returns the Construction state of this Attraction.
		 *	
		 *	@returns false if this Attraction is no longer under construction, and true if it is still under construction
		 */
		 bool IsUnderConstruction();

	/*
	 *	End Getter Methods
	 */


	/*
	 *	Start Setter Methods
	 */

	UFUNCTION(BlueprintCallable, Category = setters)
		/**
		 *	Sets AttractionName to NewAttractionName.
		 *
		 *	@param NewAttractionName - The value which AttractionName will be set to, an FString.
		 */
		void SetAttractionName(FString NewAttractionName);

	UFUNCTION(BlueprintCallable, Category = setters)
		/**
		 *	Sets EntranceLocation to NewEntranceLocation
		 *
		 *	@param NewEntranceLocation - The value which EntranceLocation will be set to, an FVector.
		 */
		void SetEntranceLocation(FVector NewEntranceLocation);

	UFUNCTION(BlueprintCallable, Category = setters)
		/**
		 *	Sets ExitLocation to NewExitLocation.
		 *
		 *	@param NewExitLocation - The value which ExitLocation will be set to, an FVector.
		 */
		void SetExitLocation(FVector NewExitLocation);

	UFUNCTION(BlueprintCallable, Category = setters)
		/**
		 *	Sets EntranceFee to NewEntranceFee.
		 *
		 *	@param NewEntranceFee - The value which EntranceFee will be set to, a float.
		 */
		void SetEntranceFee(float NewEntranceFee);

	UFUNCTION(BlueprintCallable, Category = setters)
		/**
		 *	Sets OperatingCosts to NewOperatingCosts.
		 *
		 *	@param NewOperatingCosts - The value which OperatingCosts will be set to, a float.
		 */
		void SetOperatingCosts(float NewOperatingCosts);

	UFUNCTION(BlueprintCallable, Category = setters)
		/**
		 *	Sets UnderConstruction to bIsUnderConstruction.
		 *
		 *	@param bIsUnderConstruction - Set to true if false Attraction is done being constructed, true if this Attraction is still under Construction.
		 */
		 void SetUnderConstruction(bool bIsUnderConstruction);

	//can see situations in which this may need to be overriden
	virtual void SetAttractionStatus(EAttractionStatus::Status NewAttractionStatus);

	/*
	 *	End Setter Methods
	 */

	/*
	 *	Start Attraction actions
	 */
	UFUNCTION(BlueprintCallable, Category = actions)
		/**
		 *	Increases EntranceFee by Amount, as long as Amount is greater than zero and the resulting EntranceFee is greater than MinEntranceFee and less than MaxEntranceFee.
		 *
		 *	@param Amount - how much to increase EntranceFee by, a float, cannot be zero
		 */
		void UpEntranceFee(float Amount);

	UFUNCTION(BlueprintCallable, Category = actions)
		/**
		 *	Decreases EntranceFee by Amount, as long as Amount is greater than zero and the resulting EntranceFee is greater than MinEntranceFee and less than MaxEntranceFee.
		 *
		 *	@param Amount - how much to decrease EntranceFee by, a float, cannot be zero
		 */
		void DownEntranceFee(float Amount);

	virtual AGuest* ServiceGuest(AGuest* CurrGuest) PURE_VIRTUAL(AAttraction::ServiceGuest, return CurrGuest;);		//abstract
	virtual void Operate() PURE_VIRTUAL(AAttraction::Operate,);														//abstract

	/*
	 *	End Attraction actions
	 */

	/*
	 *	Start Constants
	 */

	//TODO:  Re-const these fields once they have been changed to ints, also set these values in the constructor.  May need to use #define to set these values

	UPROPERTY(/*Const,*/ VisibleDefaultsOnly, Category = constants)
		/** The minimum amount that can be charged by this Attraction.*/
		/*const*/ float MinEntranceFee;

	UPROPERTY(/*Const,*/ VisibleDefaultsOnly, Category = constants)
		/** The maximum amount that can be charged by this Attraction.*/
		/*const*/ float MaxEntranceFee;

	/*
	 *	End Constants
	 */

protected:
	/*
	 *	Start Fields
	 */

	/** The name of this Attraction.*/
	FString AttractionName;
	/** The type of Attraction this Attraction is.*/
	FString AttractionType;

	/** The current state of opperation for this Attraction.*/
	EAttractionStatus::Status AttractionStatus;

	/** The location of this Attraction's entrance in the park.*/
	FVector EntranceLocation;
	/** The location of this Attraction's exit in the park.*/
	FVector ExitLocation;

	/** The length of the attraction.  Determined by the attraction's longest point.  Measured in the X direction.*/
	float Length;
	/** The width of the attraction.  Determined by the attraction's widest point.  Measured in the Y direction.*/
	float Width;
	/** The height of the attraction. Determined by the attraction's tallest point.  Measured in the Z direction.*/
	float Height;
	/** The price of entry for a Guest to interact with this Attraction.*/
	float EntranceFee;
	/** The cost per hour of this Attraction to the park owner.*/
	float OperatingCosts;

	/** True if this Attraction is currently under construction, false otherwise.*/
	bool bUnderConstruction;

	//TODO: add a container for scenery tags

	/*
	 *	End Fields
	 */

};
