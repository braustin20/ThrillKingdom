

#include "ThrillKingdom/ThrillKingdom.h"
#include "MyWindowWidget.h"

void SMyWindowWidget::Construct(const FArguments& InArgs)
{

}

FReply SMyWindowWidget::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{

	// Update WindowContainers location, you can add offsets to mouse position here
	MoveWindowTo(MouseEvent.GetScreenSpacePosition() + FSlateApplication::Get().GetCursorSize());


	return FReply::Handled();
}
