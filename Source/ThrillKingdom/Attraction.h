

#pragma once

#include "Guest.h"
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


UCLASS()
class AAttraction : public AActor
{
		GENERATED_UCLASS_BODY()

		/*
		 *	Start Constants
		 */

		UPROPERTY(Const, VisibleDefaultsOnly, Category = constants)
			const float MIN_ENTRANCE_FEE = 0.0f;

		UPROPERTY(Const, VisibleDefaultsOnly, Category = constants)
			const float MAX_ENTRANCE_FEE = 999.99f;

		/*
		 *	End Constants
		 */


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

	public:

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

		UFUNCTION(BlueprintCallable, Category = getters)
			void SetEntranceFee(float NewEntranceFee);

		UFUNCTION(BlueprintCallable, Category = getters)
			void SetOperatingCosts();

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

		virtual AGuest ServiceGuest(AGuest CurrGuest) = 0;      //abstract
		virtual void Operate() = 0;                             //abstract

		/*
		 *	End Attraction actions
		 */
	
};
