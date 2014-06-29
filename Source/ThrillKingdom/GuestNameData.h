

#pragma once

#include "Runtime/Engine/Classes/Engine/DataTable.h"
#include "Runtime/Core/Public/HAL/Platform.h"
#include "GuestNameData.generated.h"

/**
 *	
 */
USTRUCT(BlueprintType)
struct FGuestNameData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()
public:

	//Default values I think, the documentation isn't really clear
	FGuestNameData()
		: Name("Default Name")
		, Frequency(0.0f)
		, ApproxNumInUSA(0)
		, Ranking(0)
	{}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GuestNameData)
		FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GuestNameData)
		float Frequency;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GuestNameData)
		int32 ApproxNumInUSA;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = GuestNameData)
		int32 Ranking;
};
