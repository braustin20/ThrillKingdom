

#include "ThrillKingdom.h"
#include "Guest.h"


AGuest::AGuest(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	//Generates a Gender for the guest.  Has no arguments and returns no value,
	//sets Gender to either male or female.  50% chance of generating either.
	//Used primarily for single guests.
	void GenerateGender()
	{
		int8 Temp = FMath::RandRange(0, 1);

		if (Temp == 0)
		{
			Gender = Female;
		}

		else
		{
			Gender = Male;
		}
	}


	//Sets guestName to name
	void SetName(TString name)
	{
		GuestName = name;
	}

	//sets status to NewStatus
	void SetStatus(TString NewStatus)
	{
		Status = NewStatus;
	}

	//sets Hunger to NewHunger if NewHunger is in between MIN_HUNGER and MAX_HUNGER
	void SetHunger(float NewHunger)
	{
		if (NewHunger >= MIN_HUNGER && NewHUNGER <= MAX_HUNGER)
		{
			Hunger = NewHunger;
		}
		else
		{
			//TODO: do something if either of the above conditions are not met
		}
	}

	//sets thrist to NewThrist if NewThirst is in between MIN_THIRST and MAX_THIRST
	void SetThirst(float NewThirst)
	{
		if (NewThirst >= MIN_THIRST && NewThirst <= MAX_THIRST)
		{
			Thirst = NewThirst;
		}
		else
		{
			//TODO: do something if either of the above conditions are not met
		}
	}

	//sets Mood to NewMood if NewMoood is in between MIN_MOOD and MAX_MOOD
	void SetMood(float NewMood)
	{
		if (NewMood >= MIN_MOOD && NewMood <= MAX_MOOD)
		{
			Mood = NewMood;
		}
		else
		{
			//TODO: do something if either of the above conditions are not met
		}
	}

	void SetEnergy(float NewEnergy)
	{
		if (NewEnergy >= MIN_ENERGY && NewMood <= MAX_ENERGY)
		{
			Energy = NewEnergy;
		}
		else
		{
			//TODO: do something if either of the above conditions are not met
		}
	}

	void SetWallet(float NewWallet)
	{
		if (NewWallet >= MIN_WALLET && NewWallet <= MAX_WALLET)
		{
			Wallet = NewWallet;
		}
		else
		{
			//TODO: do something`
		}
	}

	void Spend(float Amount)
	{
		float NewWallet = Wallet - Amount;

		//only process the transaction if Amount is positive and if spending Amount will leave the guest with a positive Wallet
		if (Amount >= 0 && NewWallet >= MIN_WALLET)
		{
			Wallet = NewWallet;
		}
		else
		{
			//TODO: do something if either of the above conditions are not met
		}
	}

	void Withdraw(float Amount)
	{
		float NewWallet = Wallet - Amount;

		if (Amount >= 0 && NewWallet <= MAX_WALLET)
		{
			Wallet += Amount;
		}
		else
		{
			//TODO: do something if Amount is a negative number
		}
	}

	void UpThirst(float Amount)
	{
		float NewThirst = Thirst + Amount;

		if (Amount >= 0 && NewThirst <= MAX_THIRST)
		{
			Thirst = NewThirst;
		}
		else
		{
			//TODO: do something if either of the above conditions are not met
		}
	}

	void DownThirst(float Amount)
	{
		float NewThirst = Thirst - Amount;

		if (Amount >= 0 && NewThirst >= MIN_THIRST)
		{
			Thirst = NewThirst;
		}
		else
		{
			//TODO: do something if either of the above conditions are not met
		}
	}

	void UpHunger(float Amount)
	{
		float NewHunger = Hunger + Amount;

		if (Amount >= 0 && NewHunger <= MAX_HUNGER)
		{
			Hunger = NewHunger;
		}
		else
		{
			//TODO: do something if either of the above conditions are not met
		}
	}

	void DownHunger(float Amount)
	{
		float NewHunger = Hunger - Amount;

		if (Amount >= 0 && NewHunger >= MIN_HUNGER)
		{
			Hunger = NewHunger;
		}
		else
		{
			//TODO: do something if either of the above conditions are not met
		}
	}

	void UpMood(float Amount)
	{
		float NewMood = Mood + Amount;

		if (Amount >= 0 && NewMood <= MAX_MOOD)
		{
			Mood = NewMood;
		}
		else
		{
			//TODO: do something if either of the above conditions are not met
		}
	}

	void DownMood(float Amount)
	{
		float NewMood = Mood - Amount;

		if (Amount >= 0 && NewMood >= MIN_MOOD)
		{
			Mood = NewMood;
		}
		else
		{
			//TODO: do something if either of the above conditions are not met
		}
	}

	void UpEnergy(float Amount)
	{
		float NewEnergy = Energy + Amount;

		if (Amount >= 0 && NewEnergy <= MAX_ENERGY)
		{
			Energy = NewEnergy;
		}
		else
		{
			//TODO: do something if either of the above conditions are not met
		}
	}

	void DownEnergy(float Amount)
	{
		float NewEnergy = Energy - Amount;

		if (Amount >= 0 && NewEnergy >= MIN_ENERGY)
		{
			Energy = NewEnergy;
		}
		else
		{
			//TODO: do something if either of the above conditions are not met
		}
	}


	FString GetName()
	{
		return guestName;
	}

	FString GetStatus()
	{
		return status;
	}

	float GetWallet()
	{
		return trunc(Wallet * 100) / 100;
	}

	int8 GetAge()
	{
		return age;
	}

	Gender GetGender()
	{
		return Gender;
	}
}


