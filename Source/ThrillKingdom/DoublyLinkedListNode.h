

#pragma once

#include "Object.h"
#include "DoublyLinkedListNode.generated.h"

/**
 * 
 */
UCLASS()
class UDoublyLinkedListNode : public UObject
{
	GENERATED_UCLASS_BODY()
public:

	/*
	 *	Start Getters
	 */

	UDoublyLinkedListNode* GetNext();
	UDoublyLinkedListNode* GetPrev();

	/*
	 *	End Getters
	 */


	/*
	 *	Start Setters
	 */

	void SetNext(UDoublyLinkedListNode* NewNext);
	void SetPrev(UDoublyLinkedListNode* NewPrev);

	/*
	 *	End Setters
	 */


	/*
	 *	Start Utilities
	 */

	bool IsFront();
	UDoublyLinkedListNode* FindFront();
	UDoublyLinkedListNode* ChangeFront(int32 DistanceToMove);

	virtual UDoublyLinkedListNode* AddToEnd(UDoublyLinkedListNode* NewNode);
	virtual UDoublyLinkedListNode* AddToFront(UDoublyLinkedListNode* NewNode);
	virtual UDoublyLinkedListNode* DeleteNode();
	virtual UDoublyLinkedListNode* ShiftFrontForwardOne();
	virtual UDoublyLinkedListNode* ShiftFrontBackOne();

	/*
	 *	End Utilities
	 */
	
protected:

	UDoublyLinkedListNode* Next;
	UDoublyLinkedListNode* Prev;
	bool Front;
};
