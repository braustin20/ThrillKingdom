

#include "ThrillKingdom.h"
#include "TestNode.h"


UTestNode::UTestNode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	NodeNumber = 0;
}

void UTestNode::PrintList()
{
	//if the node is the selected node continue, otherwise print an error message
	if (IsSelected())
	{
		//check to make sure the list isn't broken
		if ((Prev != nullptr && Next != nullptr) || (Prev == nullptr && Next == nullptr))
		{
			//if this is the only node in the list just print its NodeNumber
			if (Prev == nullptr && Next == nullptr)
			{
				//TODO: print NodeNumber here
			}

			else
			{
				UTestNode* Curr;
				Curr = this;

				while (Curr->Next != this)
				{
					//TODO: print NodeNumber of the current node
					Curr = (UTestNode*)Curr->Next;
				}
			}
		}
		else
		{
			//TODO: print an error message here
		}
	}

	else
	{
		//TODO: print an error message here
	}
}
