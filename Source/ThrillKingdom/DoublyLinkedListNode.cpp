

#include "ThrillKingdom.h"
#include "DoublyLinkedListNode.h"


UDoublyLinkedListNode::UDoublyLinkedListNode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	Next = nullptr;
	Prev = nullptr;
	bSelected = false;
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
	return bSelected;
}

UDoublyLinkedListNode* UDoublyLinkedListNode::RFindSelected()
{
	if (this->bSelected)
	{
		return this;
	}

	return this->GetNext()->RFindSelected();
}

UDoublyLinkedListNode* UDoublyLinkedListNode::DeleteNode()
{
	if (this->bSelected)
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
			this->bSelected = false;

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

UDoublyLinkedListNode* UDoublyLinkedListNode::ShiftSelectedForward()
{
	if (this->IsSelected())
	{
		UDoublyLinkedListNode* Curr = NewObject<UDoublyLinkedListNode>();

		if (this->GetNext() == nullptr)
		{
			//TODO: print an error message
			return nullptr;
		}

		this->bSelected = false;
		this->GetNext()->bSelected = true;
		return this->GetNext();
	}

	//TODO: print an error message here
	return nullptr;
}

UDoublyLinkedListNode* UDoublyLinkedListNode::ShiftSelectedBack()
{
	if (this->IsSelected())
	{
		UDoublyLinkedListNode* Curr = NewObject<UDoublyLinkedListNode>();

		if (this->GetNext() == nullptr)
		{
			//TODO: print an error message
			return nullptr;
		}

		this->bSelected = false;
		this->GetPrev()->bSelected = true;
		return this->GetPrev();
	}

	//TODO: print an error message here
	return nullptr;
}

UDoublyLinkedListNode* UDoublyLinkedListNode::MakeNodeSelected()
{
	//if this node is the selected node just return this node
	if (this->bSelected)
	{
		return this;
	}

	//set this node to selected
	this->bSelected = true;

	//find the old selected node and unselect it
	UDoublyLinkedListNode* Curr;
	Curr = this;

	while (!Curr->bSelected)
	{
		Curr = Curr->GetNext();
	}

	//make sure that there actually was a previously selected node before unselecting it
	if (Curr != this)
	{
		Curr->bSelected = false;
	}

	return this;
}

UDoublyLinkedListNode* UDoublyLinkedListNode::AddToPrev(UDoublyLinkedListNode* NewNode)
{
	if (this->bSelected)
	{
		//if there are no other nodes in this list
		if (this->Next == nullptr && this->Prev == nullptr)
		{
			//set up circular references to NewNode from this node
			this->Next = NewNode;
			this->Prev = NewNode;
			this->bSelected = false;

			//set up circular references to this node from NewNode
			NewNode->Next = this;
			NewNode->Prev = this;
			NewNode->bSelected = true;

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
			Temp = this->GetPrev();

			//sandwich NewNode inbetween this node and the previous node
			this->Prev = NewNode;
			NewNode->Next = Prev;

			NewNode->Prev = Temp;
			Temp->Next = NewNode;

			//switch NewNode to the selected node
			this->bSelected = false;
			this->bSelected = true;

			return NewNode;
		}
	}

	//TODO: print an error message
	return nullptr;
}

UDoublyLinkedListNode* UDoublyLinkedListNode::AddToNext(UDoublyLinkedListNode* NewNode)
{
	if (this->bSelected)
	{
		//if there are no other nodes in this list
		if (this->Next == nullptr && this->Prev == nullptr)
		{
			//set up circular references to NewNode from this node
			this->Next = NewNode;
			this->Prev = NewNode;
			this->bSelected = false;

			//set up circular references to this node from NewNode
			NewNode->Next = this;
			NewNode->Prev = this;
			NewNode->bSelected = true;

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
			Temp = this->GetNext();

			//sandwich NewNode inbetween this node and the next node
			this->Next = NewNode;
			NewNode->Prev = this;

			NewNode->Next = Temp;
			Temp->Prev = NewNode;

			//switch NewNode to the selected node
			this->bSelected = false;
			NewNode->bSelected = true;

			return NewNode;
		}
	}
	
	//TODO: print an error message
	return nullptr;
}
