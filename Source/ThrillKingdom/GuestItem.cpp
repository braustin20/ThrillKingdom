

#include "ThrillKingdom.h"
#include "GuestItem.h"


UGuestItem::UGuestItem(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	//TODO: add constructor code, or not

	MinRetailPrice = 0.0f;
	MaxRetailPrice = 999.99f;

	MinSupplyCost = 0.0f;
	MaxSupplyCost = 999.99f;
}


/*
 *	Start Getters
 */

FString UGuestItem::GetName()
{
	return ItemName;
}

float UGuestItem::GetRetailPrice()
{
	return trunc(RetailPrice * 100) / 100;
}

float UGuestItem::GetSupplyCost()
{
	return trunc(SupplyCost * 100) / 100;
}

EItemType::Type UGuestItem::GetType()
{
	return Type;
}

/*
 *	End Getters
 */


/*
 *	Start Setters
 */

void UGuestItem::SetRetailPrice(float NewPrice)
{
	if (NewPrice >= MinRetailPrice && NewPrice <= MaxRetailPrice)
	{
		RetailPrice = NewPrice;
	}
	else
	{
		//TODO: do something if either of the above conditions are not met
	}
}

void UGuestItem::SetSupplyCost(float NewCost)
{
	if (NewCost >= MinSupplyCost && NewCost <= MaxSupplyCost)
	{
		SupplyCost = NewCost;
	}
	else
	{
		//TODO: do something if either of the above conditions are not met
	}
}

/*
 *	End Setters
 */


/*
 *	Start GuestItems actions
 */

void UGuestItem::UpRetailPrice(float Amount)
{
	float NewPrice = RetailPrice + Amount;

	if (Amount >= 0 && NewPrice <= MaxRetailPrice)
	{
		RetailPrice = NewPrice;
	}
	else
	{
		//TODO: do something if either of the above conditions are not met
	}
}

void UGuestItem::DownRetailPrice(float Amount)
{
	float NewPrice = RetailPrice - Amount;

	if (Amount >= 0 && NewPrice >= MinRetailPrice)
	{
		RetailPrice = NewPrice;
	}
	else
	{
		//TODO: do something if either of the above conditions are not met
	}
}


void UGuestItem::UpSupplyCost(float Amount)
{
	float NewCost = SupplyCost + Amount;

	if (Amount >= 0 && NewCost <= MaxSupplyCost)
	{
		SupplyCost = NewCost;
	}
	else
	{
		//TODO: do something if either of the above conditions are not met
	}
}

void UGuestItem::DownSupplyCost(float Amount)
{
	float NewCost = SupplyCost - Amount;

	if (Amount >= 0 && NewCost >= MinSupplyCost)
	{
		SupplyCost = NewCost;
	}
	else
	{
		//TODO: do something if either of the above conditions are not met
	}
}

/*
 *	End GuestItems actions
 */
