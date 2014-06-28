

#pragma once

#include "ThrillKingdom/ThrillKingdom.h"
#include "EditorUIWidget.h"
#include "EditorHUD.h"
#include "MyWindowWidget.h"

//EditorUIWidget::EditorUIWidget()
//{
//}


//EditorUIWidget::~EditorUIWidget()
//{
//}

void SEditorUIWidget::Construct(const FArguments& InArgs)
{
	OwnerHUD = InArgs._OwnerHUD;

	TestString1 = (MakeShareable(new FString("Test String 1")));

	//Items.Add(&TestString1);
	Items.Empty();
	Items.Add(TestString1);
	Items.Add(MakeShareable(new FString("Test String 2")));
	Items.Add(MakeShareable(new FString("Test String 3")));

	//GEngine->GameViewport->AddViewportWidgetContent(SAssignNew(OverlayWidget, SWindowOverlayWidget));

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/////If the code below doesn't look like C++ to you it's because it (sort-of) isn't,
	/////Slate makes extensive use of the C++ Prerocessor(macros) and operator overloading,
	/////Epic is trying to make our lives easier, look-up the macro/operator definitions to see why.
	ChildSlot

		//.VAlign(VAlign_Top)
		//.HAlign(HAlign_Left)
		[
			SNew(SCanvas)
			+ SCanvas::Slot()
			.Size(FVector2D(200.0f, 200.0f))
			.Position(FVector2D(100.f, 100.f))
			.VAlign(VAlign_Top)
			.HAlign(HAlign_Left)
			[
				SAssignNew(this->WindowWidget, SMyWindowWidget)
				.bDragAnywhere(true)
				[
					SNew(SScrollBox)
					+ SScrollBox::Slot().Padding(10, 5)
					[
						SAssignNew(this->TileViewWidget, STileView<TSharedPtr<FString>>)
						.ItemWidth(128)
						.ItemHeight(128)
						.ListItemsSource(&Items)
						.OnGenerateTile(this, &SEditorUIWidget::OnGenerateTile)
					]
				]
			]
		]; //end childslot
}
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

TSharedRef<ITableRow> SEditorUIWidget::OnGenerateTile(TSharedPtr<FString> Item, const TSharedRef<STableViewBase>& OwnerTable)
{

		return SNew(STableRow< TSharedPtr<SWidget> >, OwnerTable)
			[
				SNew(STextBlock).Text(*Item)
			];

}
FReply SEditorUIWidget::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent){
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, (FString) "Touched");
	return FReply::Handled();
}
