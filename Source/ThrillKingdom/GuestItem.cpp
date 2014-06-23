

#include "ThrillKingdom.h"
#include "GuestItem.h"


UGuestItem::UGuestItem(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

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
	RetailPrice = NewPrice;
}

void UGuestItem::SetSupplyCost(float NewCost)
{
	SupplyCost = NewCost;
}

/*
 *	End Setters
 */
