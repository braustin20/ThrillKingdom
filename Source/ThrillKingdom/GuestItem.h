

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
UCLASS(abstract)
class UGuestItem : public UObject
{
public:
	GENERATED_UCLASS_BODY()


	/*
	 *	Start Getters
	 */

	UFUNCTION(BlueprintCallable, Category = getters)
		FString GetName();
	UFUNCTION(BlueprintCallable, Category = getters)
		float GetRetailPrice();
	UFUNCTION(BlueprintCallable, Category = getters)
		float GetSupplyCost();
	UFUNCTION(BlueprintCallable, Category = getters)
		EItemType::Type GetType();

	/*
	 *	End Getters
	 */

	virtual void BeConsumed(AGuest Possesor) PURE_VIRTUAL(AAttraction::ServiceGuest, return CurrGuest;);

protected:
	FString ItemName;
	float RetailPrice;
	float SupplyCost;
	EItemType::Type Type;
};
