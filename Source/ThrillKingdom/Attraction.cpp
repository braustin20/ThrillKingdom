
//#include "Guest.h"
#include "ThrillKingdom.h"
#include "Attraction.h"


AAttraction::AAttraction(const class FPostConstructInitializeProperties& PCIP)
: Super(PCIP)
{
	//TODO: add constructor code
}

//AGuest* AAttraction::ServiceGuest(AGuest* CurrGuest){}

FString AAttraction::GetAttractionName()
{
	return AttractionName;
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
	//else
	//{
	//	//TODO:  make something happen here if the above conditions are not met
	//}
}

void AAttraction::UpEntranceFee(float Amount)
{
	float NewEntranceFee = EntranceFee + Amount;

	if (Amount >= 0 && NewEntranceFee <= MaxEntranceFee)
	{
		EntranceFee = NewEntranceFee;
	}
	//else
	//{
	//	//TODO:  make something happen here if the above conditions are not met
	//}
}

void AAttraction::DownEntranceFee(float Amount)
{
	float NewEntranceFee = EntranceFee - Amount;

	if (Amount >= 0 && NewEntranceFee >= MinEntranceFee)
	{
		EntranceFee = NewEntranceFee;
	}
	//else
	//{
	//	//TODO:  make something happen here if the above conditions are not met
	//}
}

