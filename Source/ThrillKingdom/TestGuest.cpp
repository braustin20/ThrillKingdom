

#include "ThrillKingdom.h"
#include "TestGuest.h"


ATestGuest::ATestGuest(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	Super::GenerateName(EGuestGender::male);
}


