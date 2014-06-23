

#pragma once

#include "ThrillKingdom/ThrillKingdom.h"
#include "EditorUIWidget.h"
#include "EditorHUD.h"

//EditorUIWidget::EditorUIWidget()
//{
//}


//EditorUIWidget::~EditorUIWidget()
//{
//}

void SEditorUIWidget::Construct(const FArguments& InArgs)
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
			/**
			SNew(SOverlay)
			+ SOverlay::Slot()
			.VAlign(VAlign_Top)
			.HAlign(HAlign_Center)
			[
				SNew(STextBlock)
				.ShadowColorAndOpacity(FLinearColor::Black)
				.ColorAndOpacity(FLinearColor::White)
				.ShadowOffset(FIntPoint(-1, 1))
				.Font(FSlateFontInfo("Veranda", 16)) //don't believe this works, see Rama's tutorial
				.Text(FText::FromString("Hello, Slate!"))
			]
			*/
			SNew(STileView<FString>)
				.ListItemsSource(OwnerHUD->Items)
				.OnGenerateTile(this, &SEditorUIWidget::OnGenerateWidgetForTileView)

		];
		
}

TSharedRef <FString> SEditorUIWidget::OnGenerateWidgetForTileView(FString* InItem)
{
	return SNew(STextBlock).Text((*InItem))
}
