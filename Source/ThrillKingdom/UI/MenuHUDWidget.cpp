
#pragma once
#include "ThrillKingdom/ThrillKingdom.h"
#include "MenuHUDWidget.h"
#include "MenuHUD.h"


void SMenuHUDWidget::Construct(const FArguments& InArgs)
{
	OwnerHUD = InArgs._OwnerHUD;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/////If the code below doesn't look like C++ to you it's because it (sort-of) isn't,
	/////Slate makes extensive use of the C++ Prerocessor(macros) and operator overloading,
	/////Epic is trying to make our lives easier, look-up the macro/operator definitions to see why.
	ChildSlot

		.VAlign(VAlign_Fill)
		.HAlign(HAlign_Fill)
		[
			SNew(SScrollBox)
			+ SScrollBox::Slot().Padding(10, 5)
			[
				SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					[
					
					]
				] // end horizontal slot
				//end border
			]
		]; //end childslot
}


