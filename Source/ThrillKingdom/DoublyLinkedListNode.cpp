

#include "ThrillKingdom.h"
#include "DoublyLinkedListNode.h"


UDoublyLinkedListNode::UDoublyLinkedListNode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	Next = nullptr;
	Prev = nullptr;
	bSelected = false;
}


void* UDoublyLinkedListNode::GetNext()
{
	return Next;
}

void* UDoublyLinkedListNode::GetPrev()
{
	return Prev;
}

bool UDoublyLinkedListNode::IsSelected()
{
	return bSelected;
}

void* UDoublyLinkedListNode::RFindSelected()
{
	if (IsSelected())
	{
		return this;
	}

	return ((UDoublyLinkedListNode*)Next)->RFindSelected();
}

void* UDoublyLinkedListNode::DeleteNode()
{
	if (IsSelected())
	{
		//If this node is the only node in the list mark it as a pending kill for the garbage collector
		if (Prev == nullptr && Next == nullptr)
		{
			MarkPendingKill();
			return nullptr;
		}

		//If this node only has a previous or next reference and not both, the list is not circular, print an error and return a null pointer reference
		else if ((Next == nullptr && Prev != nullptr) || (Next != nullptr && Prev == nullptr))
		{
			//TODO:  print an error message
			return nullptr;
		}

		//otherwise this node is part of an active list
		else
		{
			UDoublyLinkedListNode* CurrPrev;
			UDoublyLinkedListNode* CurrNext;

			//save references to Curr and Next of this node
			CurrPrev = (UDoublyLinkedListNode*)Prev;
			CurrNext = (UDoublyLinkedListNode*)Next;
			
			//remove references to Curr and Next from this node
			Prev = nullptr;
			Next = nullptr;
			bSelected = false;

			//repair the list
			CurrPrev->Next = CurrNext;
			CurrNext->Prev = CurrPrev;
			CurrPrev->bSelected = true;

			MarkPendingKill();
			return CurrPrev;
		}
	}
	else
	{
		//This node is not the selected node
		//TODO: print an error here
		return nullptr;
	}
}

void* UDoublyLinkedListNode::ShiftSelectedForward()
{
	if (IsSelected())
	{
		UDoublyLinkedListNode* Curr = NewObject<UDoublyLinkedListNode>();

		if (Next == nullptr)
		{
			//TODO: print an error message
			return nullptr;
		}

		bSelected = false;
		((UDoublyLinkedListNode*)Next)->bSelected = true;
		return Next;
	}

	//TODO: print an error message here
	return nullptr;
}

void* UDoublyLinkedListNode::ShiftSelectedBack()
{
	if (IsSelected())
	{
		UDoublyLinkedListNode* Curr = NewObject<UDoublyLinkedListNode>();

		if (Prev == nullptr)
		{
			//TODO: print an error message
			return nullptr;
		}

		bSelected = false;
		((UDoublyLinkedListNode*)Prev)->bSelected = true;
		return Prev;
	}

	//TODO: print an error message here
	return nullptr;
}

void* UDoublyLinkedListNode::MakeNodeSelected()
{
	//if this node is the selected node just return this node
	if (IsSelected())
	{
		return this;
	}

	//if this is the only node in the list just change Selected to true and return it
	if (Prev == nullptr && Next == nullptr)
	{
		bSelected = true;
		return this;
	}

	//set this node to selected
	bSelected = true;

	//find the old selected node and unselect it
	UDoublyLinkedListNode* Curr;
	Curr = this;

	while (!Curr->bSelected)
	{
		Curr = (UDoublyLinkedListNode*)Curr->Next;
	}

	//make sure that there actually was a previously selected node before unselecting it
	if (Curr != this)
	{
		Curr->bSelected = false;
	}

	return this;
}

void* UDoublyLinkedListNode::AddToPrev(void* NewNode)
{
	if (IsSelected())
	{
		//if there are no other nodes in this list
		if (Next == nullptr && Prev == nullptr)
		{
			//set up circular references to NewNode from this node
			Next = NewNode;
			Prev = NewNode;
			bSelected = false;

			//set up circular references to this node from NewNode
			((UDoublyLinkedListNode*)NewNode)->Next = this;
			((UDoublyLinkedListNode*)NewNode)->Prev = this;
			((UDoublyLinkedListNode*)NewNode)->bSelected = true;

			//return the new node
			return NewNode;
		}

		//if it is partially linked print an error and return nullptr
		else if ((Next == nullptr && Prev != nullptr) || (Next != nullptr && Prev == nullptr))
		{
			//TODO:  print an error message
			return nullptr;
		}

		else
		{
			//a temporary node for referencing this node's previous node
			UDoublyLinkedListNode* Temp;
			Temp = (UDoublyLinkedListNode*)Prev;

			//sandwich NewNode inbetween this node and the previous node
			Prev = NewNode;
			((UDoublyLinkedListNode*)NewNode)->Next = Prev;

			((UDoublyLinkedListNode*)NewNode)->Prev = Temp;
			Temp->Next = NewNode;

			//switch NewNode to the selected node
			bSelected = false;
			((UDoublyLinkedListNode*)NewNode)->bSelected = true;

			return NewNode;
		}
	}

	//TODO: print an error message
	return nullptr;
}

void* UDoublyLinkedListNode::AddToNext(void* NewNode)
{
	if (IsSelected())
	{
		//if there are no other nodes in this list
		if (Next == nullptr && Prev == nullptr)
		{
			//set up circular references to NewNode from this node
			Next = NewNode;
			Prev = NewNode;
			bSelected = false;

			//set up circular references to this node from NewNode
			((UDoublyLinkedListNode*)NewNode)->Next = this;
			((UDoublyLinkedListNode*)NewNode)->Prev = this;
			((UDoublyLinkedListNode*)NewNode)->bSelected = true;

			//return the new node
			return NewNode;
		}

		//if it is partially linked print an error and return nullptr
		else if ((Next == nullptr && Prev != nullptr) || (Next != nullptr && Prev == nullptr))
		{
			//TODO:  print an error message
			return nullptr;
		}

		else
		{
			//a temporary node for referencing this node's next node
			UDoublyLinkedListNode* Temp;
			Temp = (UDoublyLinkedListNode*)GetNext();

			//sandwich NewNode inbetween this node and the next node
			Next = NewNode;
			NewNode->Prev = this;

			NewNode->Next = Temp;
			Temp->Prev = NewNode;

			//switch NewNode to the selected node
			bSelected = false;
			NewNode->bSelected = true;

			return NewNode;
		}
	}
	
	//TODO: print an error message
	return nullptr;
}
