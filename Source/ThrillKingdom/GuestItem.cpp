

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
	return RetailPrice;
}

float UGuestItem::GetSupplyCost()
{
	return SupplyCost;
}

EItemType::Type UGuestItem::GetType()
{
	return Type;
}

/*
 *	End Getters
 */
