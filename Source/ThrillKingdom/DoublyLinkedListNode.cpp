//TODO: read through this and make sure it all looks good.  also test thoroughly

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
	if (Curr->GetNext == nullptr)
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

	while (!Curr->GetPrev()->IsFront() && Curr->GetPrev != nullptr)
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
