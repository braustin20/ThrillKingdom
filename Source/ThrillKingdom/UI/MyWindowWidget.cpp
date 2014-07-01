

#include "ThrillKingdom/ThrillKingdom.h"
#include "MyWindowWidget.h"


namespace SWindowDefs
{
	/** Height of a Slate window title bar, in pixels */
	static const float DefaultTitleBarSize = 24.0f;

	/** Size of the hit result border for the window borders */
	static const FSlateRect HitResultBorderSize(10, 10, 10, 10);

	/** Actual size of the window borders */
	static const FMargin WindowBorderSize(5, 5, 5, 5);

	/** Size of the corner rounding radius.  Used for regular, non-maximized windows only (not tool-tips or decorators.) */
	static const int32 CornerRadius = 6;
}

void SMyWindowWidget::Construct(const FArguments& InArgs)
{
check(InArgs._Style);
	this->Style = InArgs._Style;
	this->WindowBackground = &InArgs._Style->BackgroundBrush;

	this->Title = InArgs._Title;
	this->bDragAnywhere = InArgs._bDragAnywhere;
	this->bIsTransparent = InArgs._SupportsTransparency;
	this->Opacity = InArgs._InitialOpacity;
	this->bInitiallyMaximized = InArgs._IsInitiallyMaximized;
	this->SizingRule = InArgs._SizingRule;
	this->bIsPopupWindow = InArgs._IsPopupWindow;
	this->bFocusWhenFirstShown = InArgs._FocusWhenFirstShown;
	this->bActivateWhenFirstShown = InArgs._ActivateWhenFirstShown;
	this->bHasOSWindowBorder = InArgs._UseOSWindowBorder;
	this->bHasMinimizeButton = InArgs._SupportsMinimize;
	this->bHasMaximizeButton = InArgs._SupportsMaximize;
	this->bHasSizingFrame = !InArgs._IsPopupWindow && InArgs._SizingRule == ESizingRule::UserSized;
	
	// calculate window size from client size
	const bool bCreateTitleBar = InArgs._CreateTitleBar && !bIsPopupWindow && !bIsCursorDecoratorWindow && !bHasOSWindowBorder;
	FVector2D WindowSize = InArgs._ClientSize;

	// Do not adjust the client size if we have an OS border.  
	if (!HasOSWindowBorder())
	{
		const FMargin BorderSize = GetWindowBorderSize();

		WindowSize.X += BorderSize.Left + BorderSize.Right;
		WindowSize.Y += BorderSize.Bottom + BorderSize.Top;

		if (bCreateTitleBar)
		{
			WindowSize.Y += SWindowDefs::DefaultTitleBarSize;
		}
	}

	// calculate initial window position
	FVector2D WindowPosition = InArgs._ScreenPosition;

	AutoCenterRule = InArgs._AutoCenter;

	// Get desktop metrics
	FDisplayMetrics DisplayMetrics;
	FSlateApplicationBase::Get().GetDisplayMetrics( DisplayMetrics );
	const FPlatformRect& VirtualDisplayRect = DisplayMetrics.VirtualDisplayRect;
	const FPlatformRect& PrimaryDisplayRect = DisplayMetrics.PrimaryDisplayWorkAreaRect;

	// If we're manually positioning the window we need to check if it's outside
	// of the virtual bounds of the current displays or too large.
	if ( AutoCenterRule == EAutoCenter::None && InArgs._SaneWindowPlacement )
	{
		// Check to see if the upper left corner of the window is outside the virtual
		// bounds of the display, if so reset to preferred work area
		if (WindowPosition.X < VirtualDisplayRect.Left ||
			WindowPosition.X >= VirtualDisplayRect.Right ||
			WindowPosition.Y < VirtualDisplayRect.Top ||
			WindowPosition.Y >= VirtualDisplayRect.Bottom)
		{
			AutoCenterRule = EAutoCenter::PreferredWorkArea;
		}

		float PrimaryWidthPadding = DisplayMetrics.PrimaryDisplayWidth - 
			(PrimaryDisplayRect.Right - PrimaryDisplayRect.Left);
		float PrimaryHeightPadding = DisplayMetrics.PrimaryDisplayHeight - 
			(PrimaryDisplayRect.Bottom - PrimaryDisplayRect.Top);

		float VirtualWidth = (VirtualDisplayRect.Right - VirtualDisplayRect.Left);
		float VirtualHeight = (VirtualDisplayRect.Bottom - VirtualDisplayRect.Top);

		// Make sure that the window size is no larger than the virtual display area.
		WindowSize.X = FMath::Clamp(WindowSize.X, 0.0f, VirtualWidth - PrimaryWidthPadding);
		WindowSize.Y = FMath::Clamp(WindowSize.Y, 0.0f, VirtualHeight - PrimaryHeightPadding);
	}

	if( AutoCenterRule != EAutoCenter::None )
	{
		FSlateRect AutoCenterRect;

		switch( AutoCenterRule )
		{
		default:
		case EAutoCenter::PrimaryWorkArea:
			AutoCenterRect = FSlateRect(
				(float)PrimaryDisplayRect.Left, 
				(float)PrimaryDisplayRect.Top,
				(float)PrimaryDisplayRect.Right,
				(float)PrimaryDisplayRect.Bottom );		
			break;
		case EAutoCenter::PreferredWorkArea:
			AutoCenterRect = FSlateApplicationBase::Get().GetPreferredWorkArea();
			break;
		}

		// Setup a position and size for the main frame window that's centered in the desktop work area
		const FVector2D DisplayTopLeft( AutoCenterRect.Left, AutoCenterRect.Top );
		const FVector2D DisplaySize( AutoCenterRect.Right - AutoCenterRect.Left, AutoCenterRect.Bottom - AutoCenterRect.Top );
		WindowPosition = DisplayTopLeft + ( DisplaySize - WindowSize ) * 0.5f;
	}

#if PLATFORM_HTML5 
	// UE expects mouse coordinates in screen space. SDL/HTML5 canvas provides in client space. 
	// Anchor the window at the top/left corner to make sure client space coordinates and screen space coordinates match up. 
	WindowPosition.X =  WindowPosition.Y = 0; 
#endif 
	this->InitialDesiredScreenPosition = WindowPosition;
	this->InitialDesiredSize = WindowSize;

	this->ConstructWindowInternals( bCreateTitleBar );
	this->SetContent( InArgs._Content.Widget );
}


void SMyWindowWidget::ConstructWindowInternals(const bool bCreateTitleBar)
{
	ForegroundColor = FCoreStyle::Get().GetSlateColor("DefaultForeground");

	// Setup widget that represents the main area of the window.  That is, everything inside the window's border.
	TSharedRef< SVerticalBox > MainWindowArea =
		SNew(SVerticalBox)
		.Visibility(EVisibility::SelfHitTestInvisible);

	if (bCreateTitleBar)
	{
		// @todo mainframe: Should be measured from actual title bar content widgets.  Don't use a hard-coded size!
		TitleBarSize = SWindowDefs::DefaultTitleBarSize;

		MainWindowArea->AddSlot()
			.AutoHeight()
			[
				FSlateApplicationBase::Get().MakeWindowTitleBar(SharedThis(this), nullptr, HAlign_Center, TitleBar)
			];
	}
	else
	{
		TitleBarSize = 0;
	}

	// create window content slot
	MainWindowArea->AddSlot()
		.FillHeight(1.0f)
		.Expose(ContentSlot)
		[
			SNullWidget::NullWidget
		];

	// create window
	if (!bIsToolTipWindow && !bIsPopupWindow && !bHasOSWindowBorder)
	{
		TAttribute<EVisibility> WindowContentVisibility(this, &SWindow::GetWindowContentVisibility);
		TAttribute<const FSlateBrush*> WindowBackgroundAttr(this, &SWindow::GetWindowBackground);
		TAttribute<const FSlateBrush*> WindowOutlineAttr(this, &SWindow::GetWindowOutline);
		TAttribute<FSlateColor> WindowOutlineColorAttr(this, &SWindow::GetWindowOutlineColor);

		this->ChildSlot
			[
				SAssignNew(WindowOverlay, SOverlay)
				.Visibility(EVisibility::SelfHitTestInvisible)

				// window background
				+ SOverlay::Slot()
				[
					FSlateApplicationBase::Get().MakeImage(
					WindowBackgroundAttr,
					FLinearColor::White,
					WindowContentVisibility
					)
				]

				// window border
				+ SOverlay::Slot()
					[
						FSlateApplicationBase::Get().MakeImage(
						&Style->BorderBrush,
						FLinearColor::White,
						WindowContentVisibility
						)
					]

				// main area
				+ SOverlay::Slot()
					[
						SNew(SVerticalBox)
						.Visibility(WindowContentVisibility)

						+ SVerticalBox::Slot()

						.Padding(TAttribute<FMargin>(this, &SWindow::GetWindowBorderSize))
						[
							MainWindowArea
						]
					]

				// pop-up layer
				+ SOverlay::Slot()
					[
						SAssignNew(PopupLayer, SPopupLayer, SharedThis(this))
					]

				// window outline
				+ SOverlay::Slot()
					[
						FSlateApplicationBase::Get().MakeImage(
						WindowOutlineAttr,
						WindowOutlineColorAttr,
						WindowContentVisibility
						)
					]
			];
	}
	else if (bHasOSWindowBorder)
	{
		this->ChildSlot
			[
				SAssignNew(WindowOverlay, SOverlay)
				+ SOverlay::Slot()
				[
					MainWindowArea
				]
				+ SOverlay::Slot()
					[
						SAssignNew(PopupLayer, SPopupLayer, SharedThis(this))
					]
			];
	}
}

FReply SMyWindowWidget::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{

	// Update WindowContainers location, you can add offsets to mouse position here
	MoveWindowTo(MouseEvent.GetScreenSpacePosition() + FSlateApplication::Get().GetCursorSize());


	return FReply::Handled();
}
