

#include "ThrillKingdom.h"
#include "Attraction.h"


AAttraction::AAttraction(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	FString GetAttractionName()
	{
		return AttractionName;
	}

	float GetEntranceFee()
	{
		return EntranceFee;
	}

	virtual EAttractionStatus::Status GetAttractionStatus()
	{
		return AttractionStatus;
	}

	virtual void SetAttractionStatus(EAttractionStatus::Status NewAttractionStatus)
	{
		AttractionStatus = NewAttractionStatus;
	}

	void SetAttractionName(FString NewAttractionName)
	{
		AttractionName = NewAttractionName;
	}

	void SetEntranceFee(float NewEntranceFee)
	{
		if (NewEntranceFee >= MIN_ENTRANCE_FEE && NewEntranceFee <= MAX_ENTRANCE_FEE)
		{
			EntranceFee = NewEntranceFee;
		}
		else
		{
			//TODO:  make something happen here if the above conditions are not met
		}
	}

	void UpEntranceFee(float Amount)
	{
		float NewEntranceFee = EntranceFee + Amount;

		if (Amount >= 0 && NewEntranceFee <= MAX_ENTRANCE_FEE)
		{
			EntranceFee = NewEntranceFee;
		}
		else
		{
			//TODO:  make something happen here if the above conditions are not met
		}
	}

	void DownEntranceFee(float Amount)
	{
		float NewEntranceFee = EntranceFee - Amount;

		if (Amount >= 0 && NewEntranceFee >= MIN_ENTRANCE_FEE)
		{
			EntranceFee = NewEntranceFee;
		}
		else
		{
			//TODO:  make something happen here if the above conditions are not met
		}
	}

}


