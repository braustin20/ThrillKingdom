

#pragma once

#include "EditorHUD.h"
#include "Slate.h"
#include "Templates/SharedPointer.h"
#include "MyWindowWidget.h"

class SEditorUIWidget : public SCompoundWidget
{

	SLATE_BEGIN_ARGS(SEditorUIWidget) 
		: _OwnerHUD()
	{
	}

	/*See private declaration of OwnerHUD below.*/
	SLATE_ARGUMENT(TWeakObjectPtr<class AEditorHUD>, OwnerHUD)

	SLATE_END_ARGS()


public:

	//Needed for every widget
	//Builds this widget and any of it's children
	void Construct(const FArguments& InArgs);

protected:
	
	TSharedRef <ITableRow> SEditorUIWidget::OnGenerateTile(TSharedPtr<FString> Item, const TSharedRef<STableViewBase>& OwnerTable);

	FReply SEditorUIWidget::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) OVERRIDE;

private:
	//Pointer to our parent HUD
	//To make sure HUD's lifetime is controlled elsewhere, use "weak" ptr.
	//HUD has "strong" pointer to Widget,
	//circular ownership would prevent/break self-destruction of hud/widget (cause memory leak).
	TWeakObjectPtr<class AEditorHUD> OwnerHUD;

	TSharedPtr<STileView<TSharedPtr<FString>>> TileViewWidget;

	TSharedPtr<SMyWindowWidget> WindowWidget;

	TSharedPtr<FString> TestString1;

	TArray <TSharedPtr<FString>> Items;
//	TArray> Items;
};

