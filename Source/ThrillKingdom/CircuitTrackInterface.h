

#pragma once

#include "CircuitTrackInterface.generated.h"


USTRUCT()
struct FTrackPiece
{
	GENERATED_USTRUCT_BODY()
};

/**
 * 
 */

/** Class needed to support InterfaceCast<ICircuitTrackInterface>(Object) */
UINTERFACE(MinimalAPI)
class UCircuitTrackInterface : public UInterface
{
	GENERATED_UINTERFACE_BODY()
};

class ICircuitTrackInterface
{
	GENERATED_IINTERFACE_BODY()

	virtual void Test();
};
