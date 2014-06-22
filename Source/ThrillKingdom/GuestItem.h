

#pragma once

#include "Object.h"
#include "Guest.h"
#include "GuestItem.generated.h"


/**

*/
UENUM(BlueprintType)
namespace EItemType
{
	enum Type
	{
		food		UMETA(DisplayName = "food"),
		drink		UMETA(DisplayName = "drink"),
		souvenier	UMETA(DisplayName = "souvenier"),	
		accesory	UMETA(DisplayName = "accesory"),
		clothing	UMETA(DisplayName = "clothing"),
		camera		UMETA(DisplayName = "camera")		//Not sure if this should be an item or just a bool in Guest like hasCamera
	};
}


/**
 
 */
UCLASS(absrtact)
class UGuestItem : public UObject
{
public:
	GENERATED_UCLASS_BODY()


	/*
	 *	Start Getters
	 */

	UPROPERTY(BlueprintCallable, Category = getters)
		FString GetName();
	UPROPERTY(BlueprintCallable, Category = getters)
		float GetRetailPrice();
	UPROPERTY(BlueprintCallable, Category = getters)
		float GetSupplyCost();
	UPROPERTY(BlueprintCallable, Category = getters)
		EItemType::Type GetType();

	/*
	 *	End Getters
	 */


protected:
	FString ItemName;
	float RetailPrice;
	float SupplyCost;
	EItemType::Type Type;

	virtual void BeConsumed(AGuest Possesor) PURE_VIRTUAL(AAttraction::ServiceGuest, return CurrGuest;);
};
