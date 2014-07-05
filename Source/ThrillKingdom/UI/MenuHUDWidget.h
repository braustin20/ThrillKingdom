

#pragma once

#include "Slate.h"
#include "MenuHUD.h"
#include "Templates/SharedPointer.h"

/**
 * 
 */

class SMenuHUDWidget : public SCompoundWidget
{
	SLATE_BEGIN_ARGS(SMenuHUDWidget)
	{}
	/*See private declaration of OwnerHUD below.*/
	SLATE_ARGUMENT(TWeakObjectPtr<class AMenuHUD>, OwnerHUD)

		SLATE_END_ARGS()


public:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/////Needed for every widget
	/////Builds this widget and any of it's children
	void Construct(const FArguments& InArgs);

private:
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/////Pointer to our parent HUD
	/////To make sure HUD's lifetime is controlled elsewhere, use "weak" ptr.
	/////HUD has "strong" pointer to Widget,
	/////circular ownership would prevent/break self-destruction of hud/widget (cause memory leak).
	TWeakObjectPtr<class AMenuHUD> OwnerHUD;
	
};
