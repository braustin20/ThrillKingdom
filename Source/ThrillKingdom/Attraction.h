

#pragma once

#include "GameFramework/Actor.h"
#include "Attraction.generated.h"

/**
 *	Class:		Attraction
 *
 *  Purpose:	The abstract class representing any item that a Guest
 *              can directly interact with.  Cannot be instantiated in
 *              game.
 *
 *  Native:		Attraction.h
 *
 *  Fields:
 *  Methods:
 */

UCLASS()
class AAttraction : public AActor
{
		GENERATED_UCLASS_BODY()

		/*
		 *  Start Constants
		 */

		UPROPERTY()
			const float MIN_ENTRANCE_FEE = 0.0f;

		UPROPERTY()
			const float MAX_ENTRANCE_FEE = 999.99f;

		/*
		 *  End Constants
		 */


		/*
		 *  Start Fields
		 */

		UPROPERTY()
			FString AttractionName;

		UPROPERTY()
			EAttractionStatus::Status AttractionStatus;

		UPROPERTY()
			float Length;

		UPROPERTY()
			float Width;

		UPROPERTY()
			float Height;

		UPROPERTY()
			float EntranceFee;

		UPROPERTY()
			float OperatingCosts;

		//TODO: add a container for scenery tags

		/*
		 *  End Fields
		 */

	public:

		/*
		 *  Start Getter Methods
		 */

		FString GetAttractionName();
		float GetEntranceFee();
		float GetOperatingCosts();

		virtual EAttractionStatus::Status GetAttractionStatus();

		/*
		 *  End Getter Methods
		 */


		/*
		 *  Start Setter Methods
		 */

		void SetAttractionName(FString NewAttractionName);
		void SetEntranceFee(float NewEntranceFee);
		void SetOperatingCosts();

		//can see situations in which this may need to be overriden
		virtual void SetAttractionStatus(EAttractionStatus::Status NewAttractionStatus);

		/*
		 *  End Setter Methods
		 */

		/*
		 *  Start Attraction actions
		 */

		void UpEntranceFee(float Amount);
		void DownEntranceFee(float Amount);

		virtual AGuest ServiceGuest(AGuest CurrGuest) = 0;      //abstract
		virtual void Operate() = 0;                             //abstract

		/*
		 *  End Attraction actions
		 */
	
};
