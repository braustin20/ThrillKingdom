

#pragma once

#include "Attraction.h"
#include "GameFramework/Character.h"
#include "Guest.generated.h"

/**
 *  Class:      Guest
 *
 *  Purpose :	A character in a park.Can interact with attractions.
 *              Has a number of attributes which affect the behavior of
 *              the Guest, which are represented by fields.
 *
 *  Native :	Guest.h
 *
 *  Fields :
 *	Methods :
 */


//TODO:  add autodoc syntax to comments
UCLASS()
class AGuest : public ACharacter
{
		GENERATED_UCLASS_BODY()

		/*
		 *	Start Constants
	   	 *
		 *	Honestly chances are that all of these values are going to have to be tweaked
		 */

		UPROPERTY()
			const float MIN_THIRST = 0.0f;
		UPROPERTY()
			const float MAX_THIRST = 100.0f;

		UPROPERTY()
			const float MIN_HUNGER = 0.0f;
		UPROPERTY()
			const float MAX_HUNGER = 100.0f;

		UPROPERTY()
			const float MIN_MOOD = -100.0f;
		UPROPERTY()
			const float MAX_MOOD = 100.0f;

		UPROPERTY()
			const float MIN_ENERGY = 0.0f;
		UPROPERTY()
			const float MAX_ENERGY = 100.0f;

		UPROPERTY()
			const float MIN_WALLET = 0.0f;
		UPROPERTY()
			const float MAX_WALLET = 99999.99f;     //TODO: figure out a good value for this

		/*
		 *	End constants
		 */

		/*
		 *	Start Fields
		 *
		 *	These fields are written using easy to tweak and work with types
		 *	should be refactored for efficiency once tweaked with more efficient types
		 */

		//TODO: write a set of functions using NTCS instead of FStrings

		//The guest's name
		UPROPERTY()
			FString GuestName;

		//A string containing a short status update regarding the guest
		UPROPERTY()
			FString Status;

		//A string containing the thoughts of the guest about the park.
		//Not 100% sure if we need one of these, what do you guys think?
		UPROPERTY()
			FString CurrThought;

		//Represents how thirsty the guest is, always positive.
		//0 meeans no thirst, 100.0f is the maximum value for thirst.
		UPROPERTY()
			float Thirst;

		//Represents how hungry the guest is, always positive.
		//0 means no hunger, 100.0f is the maximum value for hunger.
		UPROPERTY()
			float Hunger;

		//Represents how the guest feels.  0 is neutral,
		//a negative number represents a bad mood, a positive number
		//represents a good mood. -100.0f and 100.0f are the lower
		//and upper limits respectively.
		UPROPERTY()
			float Mood;

		//Represents how tired the guest is, always positive.
		//0 means no energy, 100.0f is the maximum amount of energy
		UPROPERTY()
			float Energy;

		//Represents how sick the guest feels, always positive.
		//0 means the guest does not feel sick, and 100.0f means the guest
		//feels very sick
		UPROPERTY()
			float Nauseau;

		//TODO: decide the upper limit on the guest wallet
		//Represents the amount of money the guest has, is never
		//a negative number.  Always truncated to two decimal
		//points.
		UPROPERTY()
			float Wallet;

		//Represents the age of the guest.  Determined by the protected
		//method generateAge when a Guest is initialized.
		UPROPERTY()
			int8 Age;

		//Represents the guest's Gender.  Determined by the protected
		//method generateGender when a Guest is initialized, or when
		//initialized through the constructor.
		UPROPERTY()
			EGuestGender::Gender Gender;

		//TODO: write container for guest inventory

		/*
		 *	End fields
		 */

		void GenerateAge();     //TODO: impliment this method
		void GenerateGender();
		void GenerateName();    //TODO: impliment this method

	public:

		/*
		 *	Start Getter methods
		 *
		 *	All methods will need to be refactored at some point as well
		 */

		FString GetName();
		FString GetStatus();
		float GetWallet();
		int GetAge();
		EGuestGender::Gender GetGender();

		/*
		 *	End Getter methods
		 */

		/*
		 *	Start Setter methods
		 */

		void SetName(FString Name);
		void SetStatus(FString NewStatus);

		//not sure if I want to keep any of the below setters, but I have a feeling they might be useful, delete them if they don't end up being used
		void SetHunger(float NewHunger);
		void SetThirst(float NewThirst);
		void SetMood(float NewMood);
		void SetEnergy(float NewEnergy);
		void SetWallet(float NewWallet);

		/*
		 *	End Setter Methods
		 */

		/*
		 *	Start Guest actions
		 *
		 *	May want to use excpetions in these to detect errors, or return boolean values to designate failure or success
		 */

		void Spend(float Amount);
		void Withdraw(float Amount);

		void UpThirst(float Amount);
		void DownThirst(float Amount);

		void UpHunger(float Amount);
		void DownHunger(float Amount);

		void UpMood(float Amount);
		void DownMood(float Amount);

		void UpEnergy(float Amount);
		void DownEnergy(float Amount);

		virtual void Interact(AAttraction* CurrAttraction);

		/*
		 *	End Guest actions
		 */
	
};
