

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
	An item that can be carried by a Guest.  These items are also sold at in-park shops.
	Abstract class.
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
		/**
		 *	Gets ItemName.
		 *
		 *	@return the name of this GuestItem
		 */
		FString GetName();

	UFUNCTION(BlueprintCallable, Category = getters)
		/**
		 *	Gets RetailPrice.
		 *
		 *	@return the price that this GuestItem costs a Guest
		 */
		float GetRetailPrice();

	UFUNCTION(BlueprintCallable, Category = getters)
		/**
		 *	Gets SupplyCost.
		 *
		 *	@return the cost of this item to the Park owner
		 */
		float GetSupplyCost();

	UFUNCTION(BlueprintCallable, Category = getters)
		/**
		 *	Gets Type.
		 *
		 *	@return the type of this GuestItem
		 */
		EItemType::Type GetType();

	/*
	 *	End Getters
	 */


	/*
	 *	Start Setters
	 */

	UFUNCTION(BlueprintCallable, Category = setters)
		/**
		 *	Sets RetailPrice.
		 *
		 *	@param NewPrice - The value which RetailPrice will be set to, a float.
		 */
		void SetRetailPrice(float NewPrice);

	UFUNCTION(BlueprintCallable, Category = setters)
		/**
		 *	Sets SupplyCost.
		 *
		 *	@param NewCost - The value which SupplyCost will be set to, a float.
		 */
		void SetSupplyCost(float NewCost);

	/*
	 *	End Setters
	 */


	/*
	 *	Start GuestItem actions
	 */

	UFUNCTION(BlueprintCallable, Category = actions)
		void UpRetailPrice(float Amount);
	UFUNCTION(BlueprintCallable, Category = actions)
		void DownRetailPrice(float Amount);

	UFUNCTION(BlueprintCallable, Category = actions)
		void UpSupplyCost(float Amount);
	UFUNCTION(BlueprintCallable, Category = actions)
		void DownSupplyCost(float Amount);

	virtual void BeConsumed(AGuest Possesor) PURE_VIRTUAL(UGuestItem::BeConsumed,);		//TODO: add the boilerplate for this

	/*
	 *	End GuestItem actions
	 */


protected:

	/** The name of this GuestItem.*/
	FString ItemName;

	/** The price of this GuestItem to a Guest.*/
	float RetailPrice;

	/** The cost of this GuestItem to the Park owner.*/
	float SupplyCost;

	/** The type of this GuestItem.*/
	EItemType::Type Type;
};
