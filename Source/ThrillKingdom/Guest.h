

#pragma once

#include "GameFramework/Character.h"
#include "Guest.generated.h"


UENUM(BlueprintType)
/**
 	Enum representing the gender of the guest.
 	Has two options, female and male.
 */
namespace EGuestGender
{
	enum Gender
	{
		female		UMETA(DisplayName = "female"),
		male		UMETA(DisplayName = "male")
	};
}


//forward declarations
class AAttraction;
class ARide;


UCLASS(abstract)
/**
	A character in a park.  Can interact with attractions.
	Has a number of attributes which affect the behavior of
	this Guest, which are represented by fields.  An abstract class.
*/
class AGuest : public ACharacter
{
public:
	GENERATED_UCLASS_BODY()

	/*
	 *	Start Getter methods
	 *
	 *	All methods will need to be refactored at some point as well
	 */

	
	UFUNCTION(BlueprintCallable, Category = getters)
		/**
		 *	Gets GuestName.
		 *
		 *	@return the name of this Guest
		 */
		FString GetName();

	UFUNCTION(BlueprintCallable, Category = getters)
		/**
		 *	Gets Status.
		 *
		 *	@return an FString of what this Guest is currently doing
		 */
		FString GetStatus();

	UFUNCTION(BlueprintCallable, Category = getters)
		/**
		 *	Gets CurrThought.
		 *
		 *	@return an FString of what this Guest is currently thinking
		 */
		FString GetCurrThought();

	UFUNCTION(BlueprintCallable, Category = getters)
		/**
		 *	Gets Wallet.
		 *
		 *	@return a float containing how much money this Guest currently has
		 */
		float GetWallet();

	UFUNCTION(BlueprintCallable, Category = getters)
		/**
		 *	Gets Age.
		 *
		 *	@return an int8 containing the age of this Guest
		 */
		int8 GetAge();

	UFUNCTION(BlueprintCallable, Category = getters)
		/**
		 *	Gets NumRidesRidden.
		 *
		 *	@return an int8 containing the number of rides this Guest has ridden while in the current park
		 */
		int8 GetNumRidesRidden();

	UFUNCTION(BlueprintCallable, Category = getters)
		/**
		 *	Gets Gender.
		 *
		 *	@return an EGuestGender::Gender containing this Guest's gender
		 */
		EGuestGender::Gender GetGender();

	UFUNCTION(BlueprintCallable, Category = getters)
		/**
		 *	Gets RidesRidden.
		 *
		 *	@return a TArray containing the names of rides this Guest has ridden while in the current park
		 */
		TArray <FString> GetRidesRidden();

	/*
	 *	End Getter methods
	 */

	/*
	 *	Start Setter methods
	 */

	UFUNCTION(BlueprintCallable, Category = setters)
		/**
		 *	Sets GuestName to Name.
		 *
		 *	@param Name - The value which GuestName will be set to, an FString.
		 */
		void SetName(FString Name);

	UFUNCTION(BlueprintCallable, Category = setters)
		/**
		 *	Sets Status to NewStatus.
		 *
		 *	@param NewStatus - The value which Status will be set to, an FString.
		 */
		void SetStatus(FString NewStatus);

	//not sure if I want to keep any of the below setters, but I have a feeling they might be useful, delete them if they don't end up being used

	UFUNCTION(BlueprintCallable, Category = setters)
		/**
		 *	Sets Hunger to NewHunger if NewHunger is in between MinHunger and MaxHunger.
		 *
		 *	@param NewHunger - The value which Hunger will be set to, a float.
		 */
		void SetHunger(float NewHunger);

	UFUNCTION(BlueprintCallable, Category = setters)
		/**
		 *	Sets Thrist to NewThrist if NewThirst is in between MinThirst and MaxThirst.
		 *
		 *	@param NewThirst - The value which Thirst will be set to, a float.
		 */
		void SetThirst(float NewThirst);

	UFUNCTION(BlueprintCallable, Category = setters)
		/**
		 *	Sets Mood to NewMood if NewMoood is in between MinMood and MaxMood.
		 *
		 *	@param NewMood - The value which Mood will be set to, a float.
		 */
		void SetMood(float NewMood);

	UFUNCTION(BlueprintCallable, Category = setters)
		/**
		 *	Sets Energy to NewEnergy if NewEnergy is in between MinEnergy and MaxEnergy.
		 *
		 *	@param NewEnergy - The value which Energy will be set to, a float.
		 */
		void SetEnergy(float NewEnergy);

	UFUNCTION(BlueprintCallable, Category = setters)
		/**
		 *	Sets Wallet to NewWallet if NewWallet is in between MinWallet and MaxWallet.
		 *
		 *	@param NewWallet - The value which Wallet will be set to, a float.
		 */
		void SetWallet(float NewWallet);

	/*
	 *	End Setter Methods
	 */

	/*
	 *	Start Guest actions
	 *
	 *	May want to use excpetions in these to detect errors, or return boolean values to designate failure or success, or return error strings upon failure
	 */

	UFUNCTION(BlueprintCallable, Category = actions)
		void Spend(float Amount);
	UFUNCTION(BlueprintCallable, Category = actions)
		void Withdraw(float Amount);


	UFUNCTION(BlueprintCallable, Category = actions)
		void UpThirst(float Amount);
	UFUNCTION(BlueprintCallable, Category = actions)
		void DownThirst(float Amount);


	UFUNCTION(BlueprintCallable, Category = actions)
		void UpHunger(float Amount);
	UFUNCTION(BlueprintCallable, Category = actions)
		void DownHunger(float Amount);


	UFUNCTION(BlueprintCallable, Category = actions)
		void UpMood(float Amount);
	UFUNCTION(BlueprintCallable, Category = actions)
		void DownMood(float Amount);


	UFUNCTION(BlueprintCallable, Category = actions)
		void UpEnergy(float Amount);
	UFUNCTION(BlueprintCallable, Category = actions)
		void DownEnergy(float Amount);


	UFUNCTION(BlueprintCallable, Category = actions)
		virtual void Interact(AAttraction* CurrAttraction);

	/*
	 *	End Guest actions
	 */

	/*
	 *	Start Constants
	 *
	 *	Honestly chances are that all of these values are going to have to be tweaked
	 */

	//TODO:  Re-const these fields once they have been changed to ints, also set these values in the constructor.  May need to use #define to set these values

	UPROPERTY(/*Const,*/ VisibleDefaultsOnly, Category = constants)
		/*const*/ float MinThirst;
	UPROPERTY(/*Const,*/ VisibleDefaultsOnly, Category = constants)
		/*const*/ float MaxThirst;

	UPROPERTY(/*Const,*/ VisibleDefaultsOnly, Category = constants)
		/*const*/ float MinHunger;
	UPROPERTY(/*Const,*/ VisibleDefaultsOnly, Category = constants)
		/*const*/ float MaxHunger;

	UPROPERTY(/*Const,*/ VisibleDefaultsOnly, Category = constants)
		/*const*/ float MinMood;
	UPROPERTY(/*Const,*/ VisibleDefaultsOnly, Category = constants)
		/*const*/ float MaxMood;

	UPROPERTY(/*Const,*/ VisibleDefaultsOnly, Category = constants)
		/*const*/ float MinEnergy;
	UPROPERTY(/*Const,*/ VisibleDefaultsOnly, Category = constants)
		/*const*/ float MaxEnergy;

	UPROPERTY(/*Const,*/ VisibleDefaultsOnly, Category = constants)
		/*const*/ float MinWallet;
	UPROPERTY(/*Const,*/ VisibleDefaultsOnly, Category = constants)
		/*const*/ float MaxWallet;	//TODO: figure out a good value for this

	/*
	 *	End constants
	 */

protected:
	/*
	 *	Start Fields
	 *
	 *	These fields are written using easy to tweak and work with types
	 *	should be refactored for efficiency once tweaked with more efficient types
	 */

	//TODO: write a set of functions using NTCS instead of FStrings

	//The guest's name
	FString GuestName;

	//A string containing a short status update regarding the guest
	FString Status;

	//A string containing the thoughts of the guest about the park.
	//Not 100% sure if we need one of these, what do you guys think?
	FString CurrThought;

	//Represents how thirsty the guest is, always positive.
	//0 meeans no thirst, 100.0f is the maximum value for thirst.
	float Thirst;

	//Represents how hungry the guest is, always positive.
	//0 means no hunger, 100.0f is the maximum value for hunger.
	float Hunger;

	//Represents how the guest feels.  0 is neutral,
	//a negative number represents a bad mood, a positive number
	//represents a good mood. -100.0f and 100.0f are the lower
	//and upper limits respectively.
	float Mood;

	//Represents how tired the guest is, always positive.
	//0 means no energy, 100.0f is the maximum amount of energy
	float Energy;

	//Represents how sick the guest feels, always positive.
	//0 means the guest does not feel sick, and 100.0f means the guest
	//feels very sick
	float Nauseau;

	//Represents the amount of money the guest has, is never
	//a negative number.  Always truncated to two decimal
	//points.
	float Wallet;

	//Represents the age of the guest.  Determined by the protected
	//method generateAge when a Guest is initialized.
	int8 Age;

	//Represents the guest's Gender.  Determined by the protected
	//method generateGender when a Guest is initialized, or when
	//initialized through the constructor.
	EGuestGender::Gender Gender;

	//TODO: write containers

	//An array of strings that contains the names of the rides ridden by the guest, uses NumRidesRidden 
	//to store the total number of rides the guest has ridden 
	TArray <FString> RidesRidden;
	int8 NumRidesRidden;


	/*
	 *	End fields
	 */

	/*virtual*/ void GenerateAge();     //TODO: impliment this method and uncomment virtual
	void GenerateGender();
	void GenerateName();    //TODO: impliment this method
	void AddToRidesRidden(ARide* CurrRide);

};
