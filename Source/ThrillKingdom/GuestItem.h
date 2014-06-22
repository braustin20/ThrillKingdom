

#pragma once

#include "Object.h"
#include "GuestItem.generated.h"

/**
 * 
 */
UCLASS()
class UGuestItem : public UObject
{
	GENERATED_UCLASS_BODY()

	FString ItemName;
	float Price;
};
