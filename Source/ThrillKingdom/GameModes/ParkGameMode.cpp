

#include "ThrillKingdom/ThrillKingdom.h"
#include "ThrillKingdom/Guestname.h"
#include "ParkGameMode.h"
#include <iostream>
#include <fstream>
#include <string>


AParkGameMode::AParkGameMode(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	std::string CLine;
	FString UELine;

	std::ifstream MaleNameIn("maleNamesFormatted.txt");
	std::ifstream FemNameIn("femaleNamesFormatted.txt");
	std::ifstream LastNameIn("lastNamesFormatted.txt");

	for (int16 i = 0; i < 1062; i++)
	{
		std::getline(MaleNameIn, CLine);
		UELine = CLine.c_str();
		MaleName::FirstName[i] = UELine;
	}

	for (int16 i = 0; i < 4076; i++)
	{
		std::getline(FemNameIn, CLine);
		UELine = CLine.c_str();
		FemaleName::FirstName[i] = UELine;
	}

	for (int16 i = 0; i < 54010; i++)
	{
		std::getline(LastNameIn, CLine);
		UELine = CLine.c_str();
		LastName::LastName[i] = UELine;
	}
}


