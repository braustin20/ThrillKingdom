

#pragma once

#include "GameFramework/HUD.h"
#include "EditorHUD.generated.h"

/**
 * 
 */
UCLASS()
class AEditorHUD : public AHUD
{
	GENERATED_UCLASS_BODY()

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/////Reference to an SCompoundWidget, TSharedPtr adds to the refcount of MyUIWidget
	/////MyUIWidget will not self-destruct as long as refcount > 0
	/////MyUIWidget refcount will be (refcout-1) if HUD is destroyed.
	TSharedPtr<class SEditorUIWidget> EditorUIWidget;

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/////Called as soon as game starts, create SCompoundWidget and give Viewport access
	void BeginPlay();
};


