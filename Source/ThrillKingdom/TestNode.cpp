

#include "ThrillKingdom.h"
#include "TestNode.h"


UTestNode::UTestNode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	if (GEngine == 0)
	{
		NumNodes = 0;
	}

	NodeNumber = NumNodes++;
}


