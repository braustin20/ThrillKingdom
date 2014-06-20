
//#include "Guest.h"
#include "ThrillKingdom.h"
#include "Attraction.h"


AAttraction::AAttraction(const class FPostConstructInitializeProperties& PCIP)
: Super(PCIP)
{
	//TODO: add constructor code
	MinEntranceFee = 0.0f;
	MaxEntranceFee = 999.99f;
}

//Not a useable implementation, this function is a pure virtual one
//AGuest* AAttraction::ServiceGuest(AGuest* CurrGuest)
//{
//	return CurrGuest;
//}

FString AAttraction::GetAttractionName()
{
	return AttractionName;
}

FString AAttraction::GetAttractionType()
{
	return AttractionType;
}

float AAttraction::GetEntranceFee()
{
	return EntranceFee;
}

EAttractionStatus::Status AAttraction::GetAttractionStatus()
{
	return AttractionStatus;
}

void AAttraction::SetAttractionStatus(EAttractionStatus::Status NewAttractionStatus)
{
	AttractionStatus = NewAttractionStatus;
}

void AAttraction::SetAttractionName(FString NewAttractionName)
{
	AttractionName = NewAttractionName;
}

void AAttraction::SetEntranceFee(float NewEntranceFee)
{
	if (NewEntranceFee >= MinEntranceFee && NewEntranceFee <= MaxEntranceFee)
	{
		EntranceFee = NewEntranceFee;
	}
	else
	{
		//TODO:  make something happen here if the above conditions are not met
	}
}

void AAttraction::UpEntranceFee(float Amount)
{
	float NewEntranceFee = EntranceFee + Amount;

	if (Amount >= 0 && NewEntranceFee <= MaxEntranceFee)
	{
		EntranceFee = NewEntranceFee;
	}
	else
	{
		//TODO:  make something happen here if the above conditions are not met
	}
}

void AAttraction::DownEntranceFee(float Amount)
{
	float NewEntranceFee = EntranceFee - Amount;

	if (Amount >= 0 && NewEntranceFee >= MinEntranceFee)
	{
		EntranceFee = NewEntranceFee;
	}
	else
	{
		//TODO:  make something happen here if the above conditions are not met
	}
}

float AAttraction::GetOperatingCosts()
{
	return OperatingCosts;
}

void AAttraction::SetOperatingCosts(float NewOperatingCosts)
{
	OperatingCosts = NewOperatingCosts;
}

FVector AAttraction::GetEntranceLocation()
{
	return EntranceLocation;
}

void AAttraction::SetEntranceLocation(FVector NewEntranceLocation)
{
	//TODO: check that the location is within the bounds of the park before setting this
	EntranceLocation = NewEntranceLocation;
	//TODO: do something if entrance is not within park boundaries
}
