

#pragma once

#include "Object.h"
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
UCLASS()
class UGuestItem : public UObject
{
public:
	GENERATED_UCLASS_BODY()


	/*
	 *	Start Getters
	 */

	FString GetName();
	float GetPrice();
	EItemType::Type GetType();

	/*
	 *	End Getters
	 */


private:
	FString ItemName;
	float Price;
	EItemType::Type Type;
};
