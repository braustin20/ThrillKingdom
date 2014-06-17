

#pragma once

//#include "Guest.h"
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


/**
 *	Class:		Attraction
 *
 *	Purpose:	The abstract class representing any item that a Guest
 *				can directly interact with.  Cannot be instantiated in
 *				game.
 *
 *	Native:		Attraction.h
 *
 *	Fields:
 *	Methods:
 */


//forward declaration of class AGuest
class AGuest;

UCLASS(abstract)
class AAttraction : public AActor
{
public:
	GENERATED_UCLASS_BODY()

		/*
		 *	Start Getter Methods
		 */
	UFUNCTION(BlueprintCallable, Category = getters)
		FString GetAttractionName();

	UFUNCTION(BlueprintCallable, Category = getters)
		float GetEntranceFee();

	UFUNCTION(BlueprintCallable, Category = getters)
		float GetOperatingCosts();

	virtual EAttractionStatus::Status GetAttractionStatus();

	/*
	 *	End Getter Methods
	 */


	/*
	 *	Start Setter Methods
	 */

	UFUNCTION(BlueprintCallable, Category = setters)
		void SetAttractionName(FString NewAttractionName);

	UFUNCTION(BlueprintCallable, Category = setters)
		void SetEntranceFee(float NewEntranceFee);

	UFUNCTION(BlueprintCallable, Category = setters)
		void SetOperatingCosts(float NewOperatingCosts);

	//can see situations in which this may need to be overriden
	virtual void SetAttractionStatus(EAttractionStatus::Status NewAttractionStatus);

	/*
	 *	End Setter Methods
	 */

	/*
	 *	Start Attraction actions
	 */
	UFUNCTION(BlueprintCallable, Category = actions)
		void UpEntranceFee(float Amount);
	UFUNCTION(BlueprintCallable, Category = actions)
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
		/*const*/ float MinEntranceFee;// = 0.0f;

	UPROPERTY(/*Const,*/ VisibleDefaultsOnly, Category = constants)
		/*const*/ float MaxEntranceFee;// = 999.99f;

	/*
	 *	End Constants
	 */

protected:
	/*
	 *	Start Fields
	 */

	FString AttractionName;

	EAttractionStatus::Status AttractionStatus;

	float Length;
	float Width;
	float Height;
	float EntranceFee;
	float OperatingCosts;

	//TODO: add a container for scenery tags

	/*
	 *	End Fields
	 */

};
