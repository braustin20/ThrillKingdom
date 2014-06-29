

#include "ThrillKingdom.h"
#include "Guest.h"
#include "Ride.h"
#include "GuestNameData.h"

/*
 *	Start Constructors
 */

AGuest::AGuest(const class FPostConstructInitializeProperties& PCIP)
: Super(PCIP)
{
	//TODO: add constructor code

	MinThirst = 0.0f;
	MaxThirst = 100.0f;

	MinHunger = 0.0f;
	MaxHunger = 100.0f;

	MinMood = -100.0f;
	MaxMood = 100.0f;

	MinEnergy = 0.0f;
	MaxEnergy = 100.0f;

	MinWallet = 0.0f;
	MaxWallet = 99999.99f;
}

/*
 *	End Constructors
 */


/*
 *	Start Getters
 */

FString AGuest::GetName()
{
	return GuestName;
}

FString AGuest::GetStatus()
{
	return Status;
}

FString AGuest::GetCurrThought()
{
	return CurrThought;
}

float AGuest::GetWallet()
{
	return trunc(Wallet * 100) / 100;
}

int8 AGuest::GetAge()
{
	return Age;
}

int8 AGuest::GetNumRidesRidden()
{
	return NumRidesRidden;
}

EGuestGender::Gender AGuest::GetGender()
{
	return Gender;
}

TArray <FString> AGuest::GetRidesRidden()
{
	return RidesRidden;
}

/*
 *	End Getters
 */


/*
 *	Start Setters
 */

void AGuest::SetName(FString name)
{
	GuestName = name;
}

void AGuest::SetStatus(FString NewStatus)
{
	Status = NewStatus;
}

void AGuest::SetHunger(float NewHunger)
{
	if (NewHunger >= MinHunger && NewHunger <= MaxHunger)
	{
		Hunger = NewHunger;
	}
	else
	{
		//TODO: do something if either of the above conditions are not met
	}
}

void AGuest::SetThirst(float NewThirst)
{
	if (NewThirst >= MinThirst && NewThirst <= MaxThirst)
	{
		Thirst = NewThirst;
	}
	else
	{
		//TODO: do something if either of the above conditions are not met
	}
}

void AGuest::SetMood(float NewMood)
{
	if (NewMood >= MinMood && NewMood <= MaxMood)
	{
		Mood = NewMood;
	}
	else
	{
		//TODO: do something if either of the above conditions are not met
	}
}

void AGuest::SetEnergy(float NewEnergy)
{
	if (NewEnergy >= MinEnergy && NewEnergy <= MaxEnergy)
	{
		Energy = NewEnergy;
	}
	else
	{
		//TODO: do something if either of the above conditions are not met
	}
}

void AGuest::SetWallet(float NewWallet)
{
	if (NewWallet >= MinWallet && NewWallet <= MaxWallet)
	{
		Wallet = NewWallet;
	}
	else
	{
		//TODO: do something`
	}
}

/*
 *	End Setters
 */


/*
 *	Start Guest Activities
 */

void AGuest::Spend(float Amount)
{
	float NewWallet = Wallet - Amount;

	//only process the transaction if Amount is positive and if spending Amount will leave the guest with a positive Wallet
	if (Amount >= 0 && NewWallet >= MinWallet)
	{
		Wallet = NewWallet;
	}
	else
	{
		//TODO: do something if either of the above conditions are not met
	}
}

void AGuest::Withdraw(float Amount)
{
	float NewWallet = Wallet - Amount;

	if (Amount >= 0 && NewWallet <= MaxWallet)
	{
		Wallet += Amount;
	}
	else
	{
		//TODO: do something if Amount is a negative number
	}
}

void AGuest::UpThirst(float Amount)
{
	float NewThirst = Thirst + Amount;

	if (Amount >= 0 && NewThirst <= MaxThirst)
	{
		Thirst = NewThirst;
	}
	else
	{
		//TODO: do something if either of the above conditions are not met
	}
}

void AGuest::DownThirst(float Amount)
{
	float NewThirst = Thirst - Amount;

	if (Amount >= 0 && NewThirst >= MinThirst)
	{
		Thirst = NewThirst;
	}
	else
	{
		//TODO: do something if either of the above conditions are not met
	}
}

void AGuest::UpHunger(float Amount)
{
	float NewHunger = Hunger + Amount;

	if (Amount >= 0 && NewHunger <= MaxHunger)
	{
		Hunger = NewHunger;
	}
	else
	{
		//TODO: do something if either of the above conditions are not met
	}
}

void AGuest::DownHunger(float Amount)
{
	float NewHunger = Hunger - Amount;

	if (Amount >= 0 && NewHunger >= MinHunger)
	{
		Hunger = NewHunger;
	}
	else
	{
		//TODO: do something if either of the above conditions are not met
	}
}

void AGuest::UpMood(float Amount)
{
	float NewMood = Mood + Amount;

	if (Amount >= 0 && NewMood <= MaxMood)
	{
		Mood = NewMood;
	}
	else
	{
		//TODO: do something if either of the above conditions are not met
	}
}

void AGuest::DownMood(float Amount)
{
	float NewMood = Mood - Amount;

	if (Amount >= 0 && NewMood >= MinMood)
	{
		Mood = NewMood;
	}
	else
	{
		//TODO: do something if either of the above conditions are not met
	}
}

void AGuest::UpEnergy(float Amount)
{
	float NewEnergy = Energy + Amount;

	if (Amount >= 0 && NewEnergy <= MaxEnergy)
	{
		Energy = NewEnergy;
	}
	else
	{
		//TODO: do something if either of the above conditions are not met
	}
}

void AGuest::DownEnergy(float Amount)
{
	float NewEnergy = Energy - Amount;

	if (Amount >= 0 && NewEnergy >= MinEnergy)
	{
		Energy = NewEnergy;
	}
	else
	{
		//TODO: do something if either of the above conditions are not met
	}
}

void AGuest::Interact(AAttraction* CurrAttraction)
{
	//TODO: impliment this methods
}

/*
 *	End Guest Activities
 */


//Generates a Gender for the guest.  Has no arguments and returns no value,
//sets Gender to either male or female.  50% chance of generating either.
//Used primarily for single guests.
void AGuest::GenerateGender()
{
	int8 Temp = FMath::RandRange(0, 1);

	if (Temp == 0)
	{
		Gender = EGuestGender::female;
	}

	else
	{
		Gender = EGuestGender::male;
	}
}

void AGuest::GenerateName(EGuestGender::Gender Gender)
{
	//TODO: fill in this function

	//GEngine seems to not have a value here and is preventing me from printing and testing this value
	if (GEngine != 0)
	{
		//TODO:  Figure out what is going wrong in the call to GetRow
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, MaleNameTable.GetRow<FGuestNameData>("MaleNames.csv")[2].Name);
	}
	else
	{

	}
}

void AGuest::AddToRidesRidden(ARide* CurrRide)
{
	RidesRidden[NumRidesRidden] = CurrRide->GetAttractionName();
	NumRidesRidden++;
}
