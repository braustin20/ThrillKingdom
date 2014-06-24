

#include "ThrillKingdom/ThrillKingdom.h"
#include "ParkGameMode.h"
#include <iostream>
#include <fstream>


AParkGameMode::AParkGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	FString line;

	std::ifstream MaleNameIn("maleNamesFormatted.txt");
	std::ifstream FemNameIn("femaleNamesFormatted.txt");
	std::ifstream LastNameIn("lastNamesFormatted.txt");


}


