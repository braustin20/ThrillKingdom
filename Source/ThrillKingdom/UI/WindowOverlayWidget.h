

#pragma once

#include "Slate.h"

/**
 * 
 */

class SWindowOverlayWidget : public SOverlay
{
public:
	SLATE_BEGIN_ARGS(SWindowOverlayWidget)
	{}
	SLATE_SUPPORTS_SLOT(SOverlay::FOverlaySlot)
		SLATE_END_ARGS()
		~SWindowOverlayWidget()
	{
			// REMEMBER TO CLEAN UP ! ! !
			if (WindowContainer.IsValid())
			{
				WindowContainer->RequestDestroyWindow();
			}

			WindowContainer.Reset();
		}

	void Construct(const FArguments& InArgs)
	{
		WindowContainer = SWindow::MakeCursorDecorator();

		FSlateApplication::Get().AddWindow(WindowContainer.ToSharedRef(), false);

		WindowContainer->SetContent(
			// Im using Stooltip only because it looks nicer than empty window
			SNew(SToolTip)
			.Content()
			[
				// Add whetever you want here
				SNew(STextBlock)
				.Text(FText::FromString("Window Container Text"))

			]);

		const int32 NumSlots = InArgs.Slots.Num();
		for (int32 SlotIndex = 0; SlotIndex < NumSlots; ++SlotIndex)
		{
			Children.Add(InArgs.Slots[SlotIndex]);
		}

		// uncomment to show window after construction
		WindowContainer->ShowWindow();

	}

	virtual FReply OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) OVERRIDE
	{
		if (WindowContainer.IsValid())
		{
			// Update WindowContainers location, you can add offsets to mouse position here
			WindowContainer->MoveWindowTo(MouseEvent.GetScreenSpacePosition() + FSlateApplication::Get().GetCursorSize());
		}

		return SOverlay::OnMouseMove(MyGeometry, MouseEvent);
	}

	void SetWindowContainerVisibility(bool NewVis)
	{
		if (WindowContainer.IsValid())
		{
			// change WindowContainer's visibility
			NewVis ? WindowContainer->ShowWindow() : WindowContainer->HideWindow();
		}

	}

private:
	TSharedPtr<SWindow> WindowContainer;

};
