

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

public:

	virtual void PostInitializeComponents() OVERRIDE;

	//Reference to an SCompoundWidget, TSharedPtr adds to the refcount of MyUIWidget
	//MyUIWidget will not self-destruct as long as refcount > 0
	//MyUIWidget refcount will be (refcout-1) if HUD is destroyed.
	TSharedPtr<class SEditorUIWidget> EditorUIWidget;
	
private:

	// Reference to slate's main menu slate UI
	TSharedPtr<class SMainMenuUI> MainMenuUI;

};


