

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

	/*
	 *	End Setters
	 */


	/*
	 *	Start Utilities
	 */

	bool IsSelected();
	UDoublyLinkedListNode* RFindSelected();
	UDoublyLinkedListNode* ChangeSelected(int32 DistanceToMove);

	virtual UDoublyLinkedListNode* DeleteNode();
	virtual UDoublyLinkedListNode* ShiftSelectedForward();
	virtual UDoublyLinkedListNode* ShiftSelectedBack();
	virtual UDoublyLinkedListNode* MakeNodeSelected();
	virtual UDoublyLinkedListNode* AddToPrev(UDoublyLinkedListNode* NewNode);
	virtual UDoublyLinkedListNode* AddToNext(UDoublyLinkedListNode* NewNode);
	virtual void PrintList();

	/*
	 *	End Utilities
	 */
	
protected:

	UDoublyLinkedListNode* Next;
	UDoublyLinkedListNode* Prev;
	bool bSelected;
};
