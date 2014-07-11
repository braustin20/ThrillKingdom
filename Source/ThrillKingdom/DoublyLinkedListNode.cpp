//TODO: fill in all the empty functions

#include "ThrillKingdom.h"
#include "DoublyLinkedListNode.h"


UDoublyLinkedListNode::UDoublyLinkedListNode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	Next = nullptr;
	Prev = nullptr;
	Selected = false;
}


UDoublyLinkedListNode* UDoublyLinkedListNode::GetNext()
{
	return Next;
}

UDoublyLinkedListNode* UDoublyLinkedListNode::GetPrev()
{
	return Prev;
}

bool UDoublyLinkedListNode::IsSelected()
{
	return Selected;
}

UDoublyLinkedListNode* UDoublyLinkedListNode::DeleteNode()
{
	if (this->Selected)
	{
		//If this node is the only node in the list mark it as a pending kill for the garbage collector
		if (Next == nullptr && Prev == nullptr)
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
			CurrPrev = this->Prev;
			CurrNext = this->Next;
			
			//remove references to Curr and Next from this node
			this->Prev = nullptr;
			this->Next = nullptr;
			this->Selected = false;

			//repair the list
			CurrPrev->Next = CurrNext;
			CurrNext->Prev = CurrPrev;
			CurrPrev->Selected = true;

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

UDoublyLinkedListNode* UDoublyLinkedListNode::FindSelected()
{

}

UDoublyLinkedListNode* UDoublyLinkedListNode::ShiftSelectedForward()
{
	if (this->IsSelected())
	{
		UDoublyLinkedListNode* Curr = NewObject<UDoublyLinkedListNode>();

		if (this->GetNext() == nullptr)
		{
			this->Next = Curr;
			this->Selected = false;
			Curr->Selected = true;
			Curr->GetNext()->Prev = this;
			Curr->Next = nullptr;

			return Curr;
		}

		this->Selected = false;
		this->GetNext()->Selected = true;
		return this->GetNext();
	}

	return this->FindSelected();
}

UDoublyLinkedListNode* UDoublyLinkedListNode::ShiftSelectedBack()
{
	if (this->IsSelected())
	{
		UDoublyLinkedListNode* Curr = NewObject<UDoublyLinkedListNode>();;

		if (this->GetPrev() == nullptr)
		{
			this->Prev = Curr;
			this->Selected = false;
			Curr->Selected = true;
			Curr->Next = this;
			Curr->Prev = nullptr;

			return Curr;
		}

		this->Selected = false;
		this->GetPrev()->Selected = true;
		return this->GetPrev();
	}

	return this->FindSelected();
}

UDoublyLinkedListNode* UDoublyLinkedListNode::AddToPrev(UDoublyLinkedListNode NewNode)
{
	//if there are no other nodes in this list
	if (this->Next == nullptr && this->Prev == nullptr)
	{
		//set up circular references to NewNode from this node
		this->Next = &NewNode;
		this->Prev = &NewNode;
		this->Selected = false;

		//set up circular references to this node from NewNode
		NewNode.Next = this;
		NewNode.Prev = this;
		NewNode.Selected = true;

		//return the new node
		return &NewNode;
	}

	//TODO: finish this function
}

UDoublyLinkedListNode* UDoublyLinkedListNode::AddToNext(UDoublyLinkedListNode NewNode)
{
	//if there are no other nodes in this list
	if (this->Next == nullptr && this->Prev == nullptr)
	{
		//set up circular references to NewNode from this node
		this->Next = &NewNode;
		this->Prev = &NewNode;
		this->Selected = false;

		//set up circular references to this node from NewNode
		NewNode.Next = this;
		NewNode.Prev = this;
		NewNode.Selected = true;

		//return the new node
		return &NewNode;
	}

	//if it is partially linked throw an error
}

UDoublyLinkedListNode* UDoublyLinkedListNode::MakeNodeSelected()
{
	//if this node is the selected node just return this node
	if (this->Selected)
	{
		return this;
	}

	//set this node to selected
	this->Selected = true;

	//find the old selected node and unselect it
	UDoublyLinkedListNode* Curr;

	while (!Curr->Selected)
	{
		Curr = Curr->GetNext();
	}

	//make sure that there actually was a previously selected node before unselecting it
	if (Curr != this)
	{
		Curr->Selected = false;
	}

	return this;
}
