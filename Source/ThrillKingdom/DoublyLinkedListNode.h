

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

	UFUNCTION(BlueprintCallable, Category = getters)
		UDoublyLinkedListNode* GetNext();
	UFUNCTION(BlueprintCallable, Category = getters)
		UDoublyLinkedListNode* GetPrev();
	UFUNCTION(BlueprintCallable, Category = getters)
		bool IsSelected();

	/*
	 *	End Getters
	 */


	/*
	 *	Start List Operations
	 */

	UFUNCTION(BlueprintCallable, Category = listOperations)
		UDoublyLinkedListNode* RFindSelected();

	UFUNCTION(BlueprintCallable, Category = listOperations)
		virtual UDoublyLinkedListNode* DeleteNode();
	UFUNCTION(BlueprintCallable, Category = listOperations)
		virtual UDoublyLinkedListNode* ShiftSelectedForward();
	UFUNCTION(BlueprintCallable, Category = listOperations)
		virtual UDoublyLinkedListNode* ShiftSelectedBack();
	UFUNCTION(BlueprintCallable, Category = listOperations)
		virtual UDoublyLinkedListNode* MakeNodeSelected();
	UFUNCTION(BlueprintCallable, Category = listOperations)
		virtual UDoublyLinkedListNode* AddToPrev(UDoublyLinkedListNode* NewNode);
	UFUNCTION(BlueprintCallable, Category = listOperations)
		virtual UDoublyLinkedListNode* AddToNext(UDoublyLinkedListNode* NewNode);
	
	//TODO: probably going to want to make this a pure virtual method
	//virtual void PrintList();

	/*
	 *	End List Operations
	 */
	
protected:

	/*
	 *	Start Fields
	 */

	UDoublyLinkedListNode* Next;
	UDoublyLinkedListNode* Prev;
	bool bSelected;

	/*
	 *  End Fields
	 */
};
