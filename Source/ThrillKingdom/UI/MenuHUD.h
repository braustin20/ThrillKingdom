

#pragma once

#include "GameFramework/HUD.h"
#include "MenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class AMenuHUD : public AHUD
{
	GENERATED_UCLASS_BODY()

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/////Reference to an SCompoundWidget, TSharedPtr adds to the refcount of MyUIWidget
	/////MyUIWidget will not self-destruct as long as refcount > 0
	/////MyUIWidget refcount will be (refcout-1) if HUD is destroyed.
	TSharedPtr<class SMenuHUDWidget> MenuHUDWidget;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/////Called as soon as game starts, create SCompoundWidget and give Viewport access
	void BeginPlay();
	
};
