
//#include "Guest.h"
#include "ThrillKingdom.h"
#include "Attraction.h"

/*
 *	Start Constructors
 */

AAttraction::AAttraction(const class FPostConstructInitializeProperties& PCIP)
: Super(PCIP)
{
	//TODO: add constructor code
	MinEntranceFee = 0.0f;
	MaxEntranceFee = 999.99f;
}

/*
 *	End Constructors
 */


/*
 *	Start Getters
 */

FString AAttraction::GetAttractionName()
{
	return AttractionName;
}

FString AAttraction::GetAttractionType()
{
	return AttractionType;
}

FVector AAttraction::GetEntranceLocation()
{
	return EntranceLocation;
}

FVector AAttraction::GetExitLocation()
{
	return ExitLocation;
}

float AAttraction::GetEntranceFee()
{
	return EntranceFee;
}

float AAttraction::GetOperatingCosts()
{
	return OperatingCosts;
}

EAttractionStatus::Status AAttraction::GetAttractionStatus()
{
	return AttractionStatus;
}

bool AAttraction::IsUnderConstruction()
{
	return bUnderConstruction;
}

/*
 *	End Getters
 */


/*
 *	Start Setters
 */

void AAttraction::SetAttractionName(FString NewAttractionName)
{
	AttractionName = NewAttractionName;
}

void AAttraction::SetEntranceLocation(FVector NewEntranceLocation)
{
	//TODO: check that the location is within the bounds of the park before setting this
	EntranceLocation = NewEntranceLocation;
	//TODO: do something if entrance is not within park boundaries
}

void AAttraction::SetExitLocation(FVector NewExitLocation)
{
	//TODO: check that the location is within the bounds of the park before setting this
	ExitLocation = NewExitLocation;
	//TODO: do something if entrance is not within park boundaries
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

void AAttraction::SetOperatingCosts(float NewOperatingCosts)
{
	OperatingCosts = NewOperatingCosts;
}

void AAttraction::SetAttractionStatus(EAttractionStatus::Status NewAttractionStatus)
{
	AttractionStatus = NewAttractionStatus;
}

void AAttraction::SetUnderConstruction(bool bIsUnderConstruction)
{
	bUnderConstruction = bIsUnderConstruction;
}

/*
 *	End Setters
 */


/*
 *	Start Attraction Actions
 */

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

/*
 *	End Attraction Actions
 */
