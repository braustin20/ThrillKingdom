

#pragma once

#include "Object.h"
#include "GuestItem.generated.h"

//forward declarations
class AGuest;

/**
	The type of this GuestItem.  Can be food, drink, souvenier, accessory, clothing, and camera (for now).
*/
UENUM(BlueprintType)
namespace EItemType
{
	enum Type
	{
		food		UMETA(DisplayName = "food"),
		drink		UMETA(DisplayName = "drink"),
		souvenier	UMETA(DisplayName = "souvenier"),	
		accessory	UMETA(DisplayName = "accessory"),
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
		/**
		*	Adds to RetailPrice by Amount.  UpRetailPrice cannot increase RetailPrice beyond MaxRetailPrice.
		*
		*	@param Amount - The float amount to be added to RetailPrice, cannot be a negative value.
		*/
		void UpRetailPrice(float Amount);
	UFUNCTION(BlueprintCallable, Category = actions)
		/**
		*	Subtracts from RetailPrice by Amount.  DownRetailPrice cannot decrease RetailPrice below MinRetailPrice.
		*
		*	@param Amount - The float amount to be subtracted from RetailPrice, cannot be a negative value.
		*/
		void DownRetailPrice(float Amount);

	UFUNCTION(BlueprintCallable, Category = actions)
		/**
		*	Adds to SupplyCost by Amount.  UpSupplyCost cannot increase SupplyCost beyond MaxSupplyCost.
		*
		*	@param Amount - The float amount to be added to SupplyCost, cannot be a negative value.
		*/
		void UpSupplyCost(float Amount);
	UFUNCTION(BlueprintCallable, Category = actions)
		/**
		*	Subtracts from SupplyCost by Amount.  DownSupplyCost cannot decrease SupplyCost below MinSupplyCost.
		*
		*	@param Amount - The float amount to be subtracted from SupplyCost, cannot be a negative value.
		*/
		void DownSupplyCost(float Amount);

	virtual void BeConsumed(AGuest* Possesor) PURE_VIRTUAL(UGuestItem::BeConsumed,);		//TODO: add the boilerplate for this

	/*
	 *	End GuestItem actions
	 */


	/*
	 *	Start Constants
	 */

	UPROPERTY(VisibleDefaultsOnly, Category = constants)
		/** The minimum value that RetailPrice can be. A float, will need to be specified by #define after final value is decided.*/
		float MinRetailPrice;
	UPROPERTY(VisibleDefaultsOnly, Category = constants)
		/** The maximum value that RetailPrice can be. A float, will need to be specified by #define after final value is decided.*/
		float MaxRetailPrice;

	UPROPERTY(VisibleDefaultsOnly, Category = constants)
		/** The minimum value that SupplyCost can be. A float, will need to be specified by #define after final value is decided.*/
		float MinSupplyCost;
	UPROPERTY(VisibleDefaultsOnly, Category = constants)
		/** The maximum value that SupplyCost can be. A float, will need to be specified by #define after final value is decided.*/
		float MaxSupplyCost;

	/*
	 *	End Constants
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
