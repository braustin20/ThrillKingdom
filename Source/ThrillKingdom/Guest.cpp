

#include "ThrillKingdom.h"
#include "Guest.h"


AGuest::AGuest(const class FPostConstructInitializeProperties& PCIP) 
	: Super(PCIP)
{
	//TODO: add constructor code
}

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


//Sets guestName to name
void AGuest::SetName(FString name)
{
	GuestName = name;
}

//sets status to NewStatus
void AGuest::SetStatus(FString NewStatus)
{
	Status = NewStatus;
}

//sets Hunger to NewHunger if NewHunger is in between MIN_HUNGER and MAX_HUNGER
void AGuest::SetHunger(float NewHunger)
{
	if (NewHunger >= MIN_HUNGER && NewHunger <= MAX_HUNGER)
	{
		Hunger = NewHunger;
	}
	/*else
	{
		//TODO: do something if either of the above conditions are not met
	}*/
}

//sets thrist to NewThrist if NewThirst is in between MIN_THIRST and MAX_THIRST
void AGuest::SetThirst(float NewThirst)
{
	if (NewThirst >= MIN_THIRST && NewThirst <= MAX_THIRST)
	{
		Thirst = NewThirst;
	}
	//else
	//{
	//	//TODO: do something if either of the above conditions are not met
	//}
}

//sets Mood to NewMood if NewMoood is in between MIN_MOOD and MAX_MOOD
void AGuest::SetMood(float NewMood)
{
	if (NewMood >= MIN_MOOD && NewMood <= MAX_MOOD)
	{
		Mood = NewMood;
	}
	//else
	//{
	//	//TODO: do something if either of the above conditions are not met
	//}
}

void AGuest::SetEnergy(float NewEnergy)
{
	if (NewEnergy >= MIN_ENERGY && NewEnergy <= MAX_ENERGY)
	{
		Energy = NewEnergy;
	}
	//else
	//{
	//	//TODO: do something if either of the above conditions are not met
	//}
}

void AGuest::SetWallet(float NewWallet)
{
	if (NewWallet >= MIN_WALLET && NewWallet <= MAX_WALLET)
	{
		Wallet = NewWallet;
	}
	//else
	//{
	//	//TODO: do something`
	//}
}

void AGuest::Spend(float Amount)
{
	float NewWallet = Wallet - Amount;

	//only process the transaction if Amount is positive and if spending Amount will leave the guest with a positive Wallet
	if (Amount >= 0 && NewWallet >= MIN_WALLET)
	{
		Wallet = NewWallet;
	}
	//else
	//{
	//	//TODO: do something if either of the above conditions are not met
	//}
}

void AGuest::Withdraw(float Amount)
{
	float NewWallet = Wallet - Amount;

	if (Amount >= 0 && NewWallet <= MAX_WALLET)
	{
		Wallet += Amount;
	}
	//else
	//{
	//	//TODO: do something if Amount is a negative number
	//}
}

void AGuest::UpThirst(float Amount)
{
	float NewThirst = Thirst + Amount;

	if (Amount >= 0 && NewThirst <= MAX_THIRST)
	{
		Thirst = NewThirst;
	}
	//else
	//{
	//	//TODO: do something if either of the above conditions are not met
	//}
}

void AGuest::DownThirst(float Amount)
{
	float NewThirst = Thirst - Amount;

	if (Amount >= 0 && NewThirst >= MIN_THIRST)
	{
		Thirst = NewThirst;
	}
	//else
	//{
	//	//TODO: do something if either of the above conditions are not met
	//}
}

void AGuest::UpHunger(float Amount)
{
	float NewHunger = Hunger + Amount;

	if (Amount >= 0 && NewHunger <= MAX_HUNGER)
	{
		Hunger = NewHunger;
	}
	//else
	//{
	//	//TODO: do something if either of the above conditions are not met
	//}
}

void AGuest::DownHunger(float Amount)
{
	float NewHunger = Hunger - Amount;

	if (Amount >= 0 && NewHunger >= MIN_HUNGER)
	{
		Hunger = NewHunger;
	}
	//else
	//{
	//	//TODO: do something if either of the above conditions are not met
	//}
}

void AGuest::UpMood(float Amount)
{
	float NewMood = Mood + Amount;

	if (Amount >= 0 && NewMood <= MAX_MOOD)
	{
		Mood = NewMood;
	}
	//else
	//{
	//	//TODO: do something if either of the above conditions are not met
	//}
}

void AGuest::DownMood(float Amount)
{
	float NewMood = Mood - Amount;

	if (Amount >= 0 && NewMood >= MIN_MOOD)
	{
		Mood = NewMood;
	}
	//else
	//{
	//	//TODO: do something if either of the above conditions are not met
	//}
}

void AGuest::UpEnergy(float Amount)
{
	float NewEnergy = Energy + Amount;

	if (Amount >= 0 && NewEnergy <= MAX_ENERGY)
	{
		Energy = NewEnergy;
	}
	//else
	//{
	//	//TODO: do something if either of the above conditions are not met
	//}
}

void AGuest::DownEnergy(float Amount)
{
	float NewEnergy = Energy - Amount;

	if (Amount >= 0 && NewEnergy >= MIN_ENERGY)
	{
		Energy = NewEnergy;
	}
	//else
	//{
	//	//TODO: do something if either of the above conditions are not met
	//}
}


FString AGuest::GetName()
{
	return GuestName;
}

FString AGuest::GetStatus()
{
	return Status;
}

float AGuest::GetWallet()
{
	return trunc(Wallet * 100) / 100;
}

int8 AGuest::GetAge()
{
	return Age;
}

EGuestGender::Gender AGuest::GetGender()
{
	return Gender;
}
