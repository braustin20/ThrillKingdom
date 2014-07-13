

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
	int32 NodeNumber;

	void PrintList();
};
