

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
		void* GetNext();
	UFUNCTION(BlueprintCallable, Category = getters)
		void* GetPrev();
	UFUNCTION(BlueprintCallable, Category = getters)
		bool IsSelected();

	/*
	 *	End Getters
	 */


	/*
	 *	Start List Operations
	 */

	UFUNCTION(BlueprintCallable, Category = listOperations)
		void* RFindSelected();

	UFUNCTION(BlueprintCallable, Category = listOperations)
		virtual void* DeleteNode();
	UFUNCTION(BlueprintCallable, Category = listOperations)
		virtual void* ShiftSelectedForward();
	UFUNCTION(BlueprintCallable, Category = listOperations)
		virtual void* ShiftSelectedBack();
	UFUNCTION(BlueprintCallable, Category = listOperations)
		virtual void* MakeNodeSelected();
	UFUNCTION(BlueprintCallable, Category = listOperations)
		virtual void* AddToPrev(void* NewNode);
	UFUNCTION(BlueprintCallable, Category = listOperations)
		virtual void* AddToNext(void* NewNode);
	
	//TODO: probably going to want to make this a pure virtual method
	//virtual void PrintList();

	/*
	 *	End List Operations
	 */
	
protected:

	/*
	 *	Start Fields
	 */

	void* Next;
	void* Prev;
	bool bSelected;

	/*
	 *  End Fields
	 */
};
