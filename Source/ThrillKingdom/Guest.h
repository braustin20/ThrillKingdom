

#pragma once

#include "GameFramework/Character.h"
#include "Guest.generated.h"

UENUM(BlueprintType)
namespace EGuestGender
{
	enum Gender
	{
		female		UMETA(DisplayName = "female"),
		male		UMETA(DisplayName = "male")
	};
}


/**
 *	Class:      Guest
 *
 *	Purpose :	A character in a park.Can interact with attractions.
 *				Has a number of attributes which affect the behavior of
 *				the Guest, which are represented by fields.
 *
 *	Native :	Guest.h
 *
 *	Fields :
 *	Methods :
 */

//forward declarations
class AAttraction;
class ARide;

//TODO:  add autodoc syntax to comments
UCLASS()
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
		FString GetName();

	UFUNCTION(BlueprintCallable, Category = getters)
		FString GetStatus();

	UFUNCTION(BlueprintCallable, Category = getters)
		FString GetCurrThought();

	UFUNCTION(BlueprintCallable, Category = getters)
		float GetWallet();

	UFUNCTION(BlueprintCallable, Category = getters)
		int8 GetAge();

	UFUNCTION(BlueprintCallable, Category = getters)
		EGuestGender::Gender GetGender();

	UFUNCTION(BlueprintCallable, Category = getters)
		TArray <FString> GetRidesRidden();

	UFUNCTION(BlueprintCallable, Category = getters)
		int8 GetNumRidesRidden();

	/*
	 *	End Getter methods
	 */

	/*
	 *	Start Setter methods
	 */

	UFUNCTION(BlueprintCallable, Category = setters)
		void SetName(FString Name);

	UFUNCTION(BlueprintCallable, Category = setters)
		void SetStatus(FString NewStatus);

	//not sure if I want to keep any of the below setters, but I have a feeling they might be useful, delete them if they don't end up being used
	UFUNCTION(BlueprintCallable, Category = setters)
		void SetHunger(float NewHunger);

	UFUNCTION(BlueprintCallable, Category = setters)
		void SetThirst(float NewThirst);

	UFUNCTION(BlueprintCallable, Category = setters)
		void SetMood(float NewMood);

	UFUNCTION(BlueprintCallable, Category = setters)
		void SetEnergy(float NewEnergy);

	UFUNCTION(BlueprintCallable, Category = setters)
		void SetWallet(float NewWallet);

	/*
	 *	End Setter Methods
	 */

	/*
	 *	Start Guest actions
	 *
	 *	May want to use excpetions in these to detect errors, or return boolean values to designate failure or success
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

	int8 NumRidesRidden;
	TArray <FString> RidesRidden;


	/*
	 *	End fields
	 */

	void GenerateAge();     //TODO: impliment this method
	void GenerateGender();
	void GenerateName();    //TODO: impliment this method
	void AddToRidesRidden(ARide CurrRide);

};
