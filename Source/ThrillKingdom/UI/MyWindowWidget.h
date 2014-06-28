

#pragma once

#include "Slate.h"

/**
 * 
 */

class SMyWindowWidget : public SWindow
{
	
public:

	SLATE_BEGIN_ARGS( SMyWindowWidget )
		: _Style(&FCoreStyle::Get().GetWidgetStyle<FWindowStyle>("Window"))
		, _Title()
		, _bDragAnywhere(false)
		, _AutoCenter(EAutoCenter::PreferredWorkArea)
		, _ScreenPosition(FVector2D::ZeroVector)
		, _ClientSize(FVector2D::ZeroVector)
		, _SupportsTransparency(false)
		, _InitialOpacity(1.0f)
		, _IsInitiallyMaximized(false)
		, _SizingRule(ESizingRule::UserSized)
		, _IsPopupWindow(false)
		, _FocusWhenFirstShown(true)
		, _ActivateWhenFirstShown(true)
		, _UseOSWindowBorder(false)
		, _SupportsMaximize(true)
		, _SupportsMinimize(true)
		, _CreateTitleBar(true)
		, _SaneWindowPlacement(true)
	{ }

	/** Style used to draw this window */
	SLATE_STYLE_ARGUMENT(FWindowStyle, Style)

		/** Title of the window */
		SLATE_ATTRIBUTE(FText, Title)

		/** When true, the window can be dragged from anywhere. */
		SLATE_ARGUMENT(bool, bDragAnywhere)

		/** The windows auto-centering mode. If set to anything other than None, then the
		ScreenPosition value will be ignored */
		SLATE_ARGUMENT(EAutoCenter::Type, AutoCenter)

		/** Screen-space position where the window should be initially located. */
		SLATE_ARGUMENT(FVector2D, ScreenPosition)

		/** What the initial size of the window should be. */
		SLATE_ARGUMENT(FVector2D, ClientSize)

		/** Should this window support transparency */
		SLATE_ARGUMENT(bool, SupportsTransparency)

		/** The initial opacity of the window */
		SLATE_ARGUMENT(float, InitialOpacity)

		/** Is the window initially maximized */
		SLATE_ARGUMENT(bool, IsInitiallyMaximized)

		/** How the window should be sized */
		SLATE_ARGUMENT(ESizingRule::Type, SizingRule)

		/** True if this should be a 'pop-up' window */
		SLATE_ARGUMENT(bool, IsPopupWindow)

		/** Should this window be focused immediately after it is shown? */
		SLATE_ARGUMENT(bool, FocusWhenFirstShown)

		/** Should this window be activated immediately after it is shown? */
		SLATE_ARGUMENT(bool, ActivateWhenFirstShown)

		/** Use the default os look for the border of the window */
		SLATE_ARGUMENT(bool, UseOSWindowBorder)

		/** Can this window be maximized? */
		SLATE_ARGUMENT(bool, SupportsMaximize)

		/** Can this window be minimized? */
		SLATE_ARGUMENT(bool, SupportsMinimize)

		/** True if we should initially create a traditional title bar area.  If false, the user must embed the title
		area content into the window manually, taking into account platform-specific considerations!  Has no
		effect for certain types of windows (popups, tool-tips, etc.) */
		SLATE_ARGUMENT(bool, CreateTitleBar)

		/** If the window appears off screen or is too large to safely fit this flag will force realistic
		constraints on the window and bring it back into view. */
		SLATE_ARGUMENT(bool, SaneWindowPlacement)

		SLATE_DEFAULT_SLOT(FArguments, Content)
		SLATE_END_ARGS()


	void Construct(const FArguments& InArgs);

	virtual FReply SMyWindowWidget::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) OVERRIDE
	{

		// Update WindowContainers location, you can add offsets to mouse position here
		MoveWindowTo(MouseEvent.GetScreenSpacePosition() + FSlateApplication::Get().GetCursorSize());
	

		return FReply::Handled();
	}
};
