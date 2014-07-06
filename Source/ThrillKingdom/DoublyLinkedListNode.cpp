//TODO: read through this and make sure it all looks good.  also test thoroughly
//TODO: rewrite functions to always return and operate from the front node
//TODO: write a set of recursive functions and decide which to use based on performance and maintainability

#include "ThrillKingdom.h"
#include "DoublyLinkedListNode.h"


UDoublyLinkedListNode::UDoublyLinkedListNode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	Next = NULL;
	Prev = NULL;
	Front = false;
}


UDoublyLinkedListNode* UDoublyLinkedListNode::GetNext()
{
	return Next;
}

UDoublyLinkedListNode* UDoublyLinkedListNode::GetPrev()
{
	return Prev;
}

void UDoublyLinkedListNode::SetNext(UDoublyLinkedListNode* NewNext)
{
	Next = NewNext;
}

void UDoublyLinkedListNode::SetPrev(UDoublyLinkedListNode* NewPrev)
{
	Prev = NewPrev;
}

bool UDoublyLinkedListNode::IsFront()
{
	return Front;
}

UDoublyLinkedListNode*  UDoublyLinkedListNode::AddToEnd(UDoublyLinkedListNode* NewNode)
{
	//Store a reference to the current node
	UDoublyLinkedListNode* Curr;
	Curr = this;

	//if the next node is null you have reached the end
	if (Curr->GetNext() == nullptr)
	{
		//set NewNode as the next node
		Curr->SetNext(NewNode);

		//Set NewNode's Next to null and Prev to Curr
		NewNode->SetNext(nullptr);
		NewNode->SetPrev(Curr);
	}

	while (!Curr->GetNext()->IsFront() && Curr->GetNext() != nullptr)
	{
		Curr = Curr->GetNext();
	}

	if (Curr->GetNext() == nullptr)
	{
		Curr->SetNext(NewNode);

		NewNode->SetNext(nullptr);
		NewNode->SetPrev(Curr);

		//return Curr as the front node of the list
		while (!Curr->IsFront() && Curr->GetPrev() != nullptr)
		{
			Curr = Curr->GetPrev();
		}

		return Curr;
	}

	//TODO:  print something here

	while (!Curr->GetPrev()->IsFront())
	{
		Curr = Curr->GetPrev();
	}

	return Curr;
}

UDoublyLinkedListNode* UDoublyLinkedListNode::AddToFront(UDoublyLinkedListNode* NewNode)
{
	UDoublyLinkedListNode* Curr;
	Curr = this;

	if (Curr->GetPrev() == nullptr)
	{
		Curr->SetPrev(NewNode);

		NewNode->SetPrev(nullptr);
		NewNode->SetNext(Curr);

		return Curr;
	}

	while (!Curr->GetPrev()->IsFront() && Curr->GetPrev() != nullptr)
	{
		Curr = Curr->GetPrev();
	}

	if (Curr->GetPrev() == nullptr)
	{
		Curr->SetPrev(NewNode);

		NewNode->SetPrev(nullptr);
		NewNode->SetNext(Curr);

		return Curr;
	}

	//TODO: print something here since the list is circular

	while (!Curr->GetNext()->IsFront())
	{
		Curr = Curr->GetNext();
	}

	return Curr;
}

UDoublyLinkedListNode* UDoublyLinkedListNode::DeleteNode()
{
	UDoublyLinkedListNode* Curr;
	Curr = this;

	if (this->GetNext() == nullptr)
	{
		if (this->GetPrev() == nullptr)
		{
			return nullptr;
		}

		if (this->IsFront())
		{
			this->Front = false;
			this->GetPrev()->Front = true;

			Curr = this->GetPrev();
			Curr->SetNext(nullptr);

			return Curr;
		}

		Curr = this->GetPrev();
		Curr->SetNext(nullptr);

		return Curr;
	}

	if (this->GetPrev() == nullptr)
	{
		if (this->IsFront())
		{
			this->Front = false;
			this->GetNext()->Front = true;

			Curr = this->GetNext();
			Curr->SetPrev(nullptr);

			return Curr;
		}

		Curr = this->GetNext();
		Curr->SetPrev(nullptr);

		return Curr;
	}

	if (this->IsFront())
	{
		this->Front = false;
		this->GetNext()->Front = true;

		Curr = this->GetNext();
		Curr->SetPrev(nullptr);

		return Curr;
	}

	Curr = this->GetNext();
	Curr->SetPrev(nullptr);

	Curr = this->GetPrev();
	Curr->SetNext(nullptr);

	return Curr;
}

UDoublyLinkedListNode* UDoublyLinkedListNode::FindFront()
{
	UDoublyLinkedListNode* Curr;
	Curr = this->GetNext();

	if (this->IsFront())
	{
		return this;
	}

	//iterates through the list and stops either when front is found or the end of the list has been reached 
	while (!Curr->IsFront() && Curr->GetNext() != nullptr)
	{
		Curr = Curr->GetNext();
	}

	//if the end of the list was reached but the front has not been found
	if (!Curr->IsFront() && Curr->GetNext() == nullptr)
	{
		//search the other way from this
		Curr = this;

		while (!Curr->IsFront() && Curr->GetNext() == nullptr)
		{
			Curr = Curr->GetNext();
		}

		//if the end of the list has been reached but front has not been found
		if (!Curr->IsFront() && Curr->GetPrev() != nullptr)
		{
			Curr = Curr->GetPrev();
		}

		//if front was found return Curr
		return Curr;
	}

	//if front was found return Curr
	return Curr;
}

void UDoublyLinkedListNode::PrintList()
{
	if (this->IsFront())
	{
		UDoublyLinkedListNode* Curr;
		Curr = this->GetNext();

		//TODO:  print the value of this node here

		//repeat until the end of the list
		while (!Curr->IsFront() && Curr->GetNext() != nullptr)
		{
			//TODO: print the values of this node here

			Curr = Curr->GetNext();
		}
	}

	else
	{
		//TODO: do something if the current node is not the front of this list
	}
}

UDoublyLinkedListNode* UDoublyLinkedListNode::ShiftFrontForward()
{
	if (this->IsFront())
	{
		UDoublyLinkedListNode* Curr;

		if (this->GetNext() == nullptr)
		{
			this->SetNext(Curr);
			this->Front = false;
			Curr->Front = true;
			Curr->SetPrev(this);
			Curr->SetNext(nullptr);

			return Curr;
		}

		this->Front = false;
		this->GetNext()->Front = true;
		return this->GetNext();
	}
}

UDoublyLinkedListNode* UDoublyLinkedListNode::ShiftFrontBack()
{
	if (this->IsFront())
	{
		UDoublyLinkedListNode* Curr;

		if (this->GetPrev() == nullptr)
		{
			this->SetPrev(Curr);
			this->Front = false;
			Curr->Front = true;
			Curr->SetNext(this);
			Curr->SetPrev(nullptr);

			return Curr;
		}

		this->Front = false;
		this->GetPrev()->Front = true;
		return this->GetPrev();
	}
}