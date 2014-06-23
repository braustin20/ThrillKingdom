

#pragma once

#include "GameFramework/Character.h"
#include "GuestItem.h"
#include "Guest.generated.h"


/**
	Enum representing the gender of the guest.
	Has two options, female and male.
*/
UENUM(BlueprintType)
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


/**
	A character in a park.  Can interact with attractions.
	Has a number of attributes which affect the behavior of
	this Guest, which are represented by fields.  An abstract class.
*/
UCLASS(abstract)
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
		 *	@return a float containing how much money this Guest currently has, rounded to two decimal places
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
		/**
		 *	Removes an amount of money from Wallet.  Will not subtract negative values or
		 *	remove money from an empty Wallet.
		 *
		 *	@param Amount - The float amount to be subtracted from Wallet, cannot be a negative value.
		 */
		void Spend(float Amount);
	UFUNCTION(BlueprintCallable, Category = actions)
		/**
		 *	Adds an amount of money from Wallet.  Will not add negative values or
		 *	add money to a full Wallet.
		 *
		 *	@param Amount - The float amount to be added to Wallet, cannot be a negative value.
		 */
		void Withdraw(float Amount);


	UFUNCTION(BlueprintCallable, Category = actions)
		/**
		 *	Adds to Thirst by Amount.  UpThirst cannot increase Thirst beyond MaxThirst.
		 *
		 *	@param Amount - The float amount to be added to Thirst, cannot be a negative value.
		 */
		void UpThirst(float Amount);
	UFUNCTION(BlueprintCallable, Category = actions)
		/**
		 *	Subtracts from Thirst by Amount.  DownThirst cannot decrease Thirst below MinThirst.
		 *	
		 *	@param Amount - The float amount to be subtracted from Thirst, cannot be a negative value.
		 */
		void DownThirst(float Amount);


	UFUNCTION(BlueprintCallable, Category = actions)
		/**
		 *	Adds to Hunger by Amount.  UpHunger cannot increase Hunger beyond MaxHunger.
		 *
		 *	@param Amount - The float amount to be added to Hunger, cannot be a negative value.
		 */
		void UpHunger(float Amount);
	UFUNCTION(BlueprintCallable, Category = actions)
		/**
		 *	Subtracts from Hunger by Amount.  DownHunger cannot decrease Hunger below MinHunger.
		 *
		 *	@param Amount - The float amount to be subtracted from Hunger, cannot be a negative value.
		 */
		void DownHunger(float Amount);


	UFUNCTION(BlueprintCallable, Category = actions)
		/**
		 *	Adds to Mood by Amount.  UpMood cannot increase Mood beyond MaxMood.
		 *
		 *	@param Amount - The float amount to be added to Mood, cannot be a negative value.
		 */
		void UpMood(float Amount);
	UFUNCTION(BlueprintCallable, Category = actions)
		/**
		 *	Subtracts from Mood by Amount.  DownMood cannot decrease Mood below MinMood.
		 *
		 *	@param Amount - The float amount to be subtracted from Mood, cannot be a negative value.
		 */
		void DownMood(float Amount);


	UFUNCTION(BlueprintCallable, Category = actions)
		/**
		 *	Adds to Energy by Amount.  UpEnergy cannot increase Energy beyond MaxEnergy.
		 *
		 *	@param Amount - The float amount to be added to Energy, cannot be a negative value.
		 */
		void UpEnergy(float Amount);
	UFUNCTION(BlueprintCallable, Category = actions)
		/**
		 *	Subtracts from Energy by Amount.  DownEnergy cannot decrease Energy below MinEnergy.
		 *
		 *	@param Amount - The float amount to be subtracted from Energy, cannot be a negative value.
		 */
		void DownEnergy(float Amount);


	UFUNCTION(BlueprintCallable, Category = actions)
		/**
		 *	Allows this Guest to interact with an Attraction.  A virtual function.  Not finished yet :/
		 *	
		 *	@param CurrAttraction - The Attraction this Guest is currently trying to interact with.
		 */
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
		/** The minimum value that Thirst can be. A float, needs to be made an int and const after the final value is decided.*/
		/*const*/ float MinThirst;
	UPROPERTY(/*Const,*/ VisibleDefaultsOnly, Category = constants)
		/** The maximum value that Thirst can be. A float, needs to be made an int and const after the final value is decided.*/
		/*const*/ float MaxThirst;

	UPROPERTY(/*Const,*/ VisibleDefaultsOnly, Category = constants)
		/** The minimum value that Hunger can be. A float, needs to be made an int and const after the final value is decided.*/
		/*const*/ float MinHunger;
	UPROPERTY(/*Const,*/ VisibleDefaultsOnly, Category = constants)
		/** The maximum value that Hunger can be. A float, needs to be made an int and const after the final value is decided.*/
		/*const*/ float MaxHunger;

	UPROPERTY(/*Const,*/ VisibleDefaultsOnly, Category = constants)
		/** The minimum value that Mood can be. A float, needs to be made an int and const after the final value is decided.*/
		/*const*/ float MinMood;
	UPROPERTY(/*Const,*/ VisibleDefaultsOnly, Category = constants)
		/** The maximum value that Mood can be. A float, needs to be made an int and const after the final value is decided.*/
		/*const*/ float MaxMood;

	UPROPERTY(/*Const,*/ VisibleDefaultsOnly, Category = constants)
		/** The minimum value that Energy can be. A float, needs to be made an int and const after the final value is decided.*/
		/*const*/ float MinEnergy;
	UPROPERTY(/*Const,*/ VisibleDefaultsOnly, Category = constants)
		/** The maximum value that Energy can be. A float, needs to be made an int and const after the final value is decided.*/
		/*const*/ float MaxEnergy;

	UPROPERTY(/*Const,*/ VisibleDefaultsOnly, Category = constants)
		/** The minimum value that Wallet can be. A float, will need to be specified by #define after final value is decided.*/
		/*const*/ float MinWallet;
	UPROPERTY(/*Const,*/ VisibleDefaultsOnly, Category = constants)
		/** The maximum value that Wallet can be. A float, will need to be specified by #define after final value is decided.*/
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

	/** The guest's name.*/
	FString GuestName;

	/** A string containing a short status update regarding the guest.*/
	FString Status;

	/** 
		A string containing the thoughts of the guest about the park.
		Not 100% sure if we need one of these, what do you guys think?
	*/
	FString CurrThought;

	/**
		Represents how thirsty the guest is, always positive.
		0 meeans no thirst, 100.0f is the maximum value for thirst.
	*/
	float Thirst;

	/**
		Represents how hungry the guest is, always positive.
		0 means no hunger, 100.0f is the maximum value for hunger.
	*/
	float Hunger;

	/**
		Represents how the guest feels.  0 is neutral,
		a negative number represents a bad mood, a positive number
		represents a good mood. -100.0f and 100.0f are the lower
		and upper limits respectively.
	*/
	float Mood;

	/**
		Represents how tired the guest is, always positive.
		0 means no energy, 100.0f is the maximum amount of energy
	*/
	float Energy;

	/**
		Represents how sick the guest feels, always positive.
		0 means the guest does not feel sick, and 100.0f means the guest
		feels very sick
	*/
	float Nauseau;

	/**
		Represents the amount of money the guest has, is never
		a negative number.  Always truncated to two decimal
		points.
	*/
	float Wallet;

	/**
		Represents the age of the guest.  Determined by the protected
		method generateAge when a Guest is initialized.
	*/
	int8 Age;

	/**
		Represents the guest's Gender.  Determined by the protected
		method generateGender when a Guest is initialized, or when
		initialized through the constructor.
	*/
	EGuestGender::Gender Gender;

	//TODO: write containers

	/**
		An array of strings that contains the names of the rides ridden by the guest, uses NumRidesRidden 
		to store the total number of rides the guest has ridden
	*/
	TArray <FString> RidesRidden;
	
	/**
		An array of GuestItems.  Represents the items that this Guest is carrying on their person.
	*/
	TArray <UGuestItem> Inventory;

	/** The number of rides this Guest has ridden.*/
	int8 NumRidesRidden;


	/*
	 *	End fields
	 */

	//TODO:  impliment and comment these methods
	/*virtual*/ void GenerateAge();     //TODO: impliment this method and uncomment virtual

	/** 
		Generates a value for this Guest's Gender.  50% chance of male, 50% for female.
		Used in a constructor for individual Guests.
	*/
	void GenerateGender();
	void GenerateName(EGuestGender::Gender Gender);    //TODO: impliment this method
	void AddToRidesRidden(ARide* CurrRide);

};
