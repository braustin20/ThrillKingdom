

#include "ThrillKingdom.h"
#include "ThrillKingdomGameMode.h"
#include "ThrillKingdomPlayerController.h"

AThrillKingdomGameMode::AThrillKingdomGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	PlayerControllerClass = AThrillKingdomPlayerController::StaticClass();
}


