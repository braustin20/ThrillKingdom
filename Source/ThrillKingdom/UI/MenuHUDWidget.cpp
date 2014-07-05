
#pragma once
#include "ThrillKingdom/ThrillKingdom.h"
#include "MenuHUDWidget.h"
#include "MenuHUD.h"


void SMenuHUDWidget::Construct(const FArguments& InArgs)
{
	OwnerHUD = InArgs._OwnerHUD;


	ChildSlot
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			.HAlign(HAlign_Center)
			.VAlign(VAlign_Top)
			[
				SNew(STextBlock)
				.ColorAndOpacity(FLinearColor::White)
				.ShadowColorAndOpacity(FLinearColor::Black)
				.ShadowOffset(FIntPoint(-1, 1))
				.Font(FSlateFontInfo("Arial", 26))
				.Text(FText::FromString("Thrill Kindom"))
			]
			+ SOverlay::Slot()
				.HAlign(HAlign_Center)
				.VAlign(VAlign_Center)
				[
					SNew(SVerticalBox)
					+ SVerticalBox::Slot()
					[
						SNew(SButton)
						.Text(FText::FromString("Play Game!"))
						//.OnClicked(this, &SMenuHUDWidget::PlayGameClicked) Unkown line should this be keeped?
					]
					+ SVerticalBox::Slot()
						[
							SNew(SButton)
							.Text(FText::FromString("Ride Editor"))
							//.OnClicked(this, &SMenuHUDWidget::QuitGameClicked)
						]
					+ SVerticalBox::Slot()
						[
							SNew(SButton)
							.Text(FText::FromString("Options"))
							//.OnClicked(this, &SMenuHUDWidget::QuitGameClicked)
						]
					+ SVerticalBox::Slot()
						[
							SNew(SButton)
							.Text(FText::FromString("Quit Game"))
							//.OnClicked(this, &SMenuHUDWidget::QuitGameClicked)
						]
				]
		];


	////////////////////////////////////////////////////////////////////////////////////////////////////
	/////If the code below doesn't look like C++ to you it's because it (sort-of) isn't,
	/////Slate makes extensive use of the C++ Prerocessor(macros) and operator overloading,
	/////Epic is trying to make our lives easier, look-up the macro/operator definitions to see why.
	//ChildSlot

	//	.VAlign(VAlign_Fill)
	//	.HAlign(HAlign_Fill)
	//	[
	//		SNew(SScrollBox)
	//		+ SScrollBox::Slot().Padding(10, 5)
	//		[
	//			SNew(SHorizontalBox)
	//			+ SHorizontalBox::Slot()
	//			[
	//				SNew(SVerticalBox)
	//				+ SVerticalBox::Slot()
	//				[
	//						//poop
	//					SNew(STextBlock)
	//					.Text((FString)"This is the Menu")

	//					/*SNew(SVerticalBox)
	//					+ SVerticalBox::Slot()
	//					[
	//						SNew(SButton)
	//					]*/
	//					
	//				]
	//			] // end horizontal slot
	//			//end border
	//		]
	//	]; //end childslot


}

//FReply SMenuHUDWidget::PlayGameClicked()
//{
//	MenuHUD->PlayGameClicked();
//	return FReply::Handled();
//}
////
//FReply SMenuHUDWidget::QuitGameClicked()
//{
//	AMenuHUD->QuitGameClicked();
//	return FReply::Handled();
//}

