

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
	UDoublyLinkedListNode* AddToEnd(UDoublyLinkedListNode* NewNode);
	UDoublyLinkedListNode* AddtoFront(UDoublyLinkedListNode* NewNode);
	UDoublyLinkedListNode* DeleteNode();
	UDoublyLinkedListNode* FindFront();
	UDoublyLinkedListNode* ChangeFront(int32 DistanceToMove);

	/*
	 *	End Utilities
	 */
	
protected:

	UDoublyLinkedListNode* Next;
	UDoublyLinkedListNode* Prev;
	bool Front;
};
