

#pragma once

#include "DoublyLinkedListNode.h"
#include "TestNode.generated.h"

/**
 * 
 */
UCLASS()
class UTestNode : public UDoublyLinkedListNode
{
	GENERATED_UCLASS_BODY()
public:

private:
	static int32 NumNodes;
	int32 NodeNumber;
};
