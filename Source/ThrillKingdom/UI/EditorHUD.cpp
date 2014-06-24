

#pragma once

#include "ThrillKingdom/ThrillKingdom.h"
#include "EditorHUD.h"
#include "EditorUIWidget.h"


AEditorHUD::AEditorHUD(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{

}

void AEditorHUD::BeginPlay()
{
	////////////////////////////////////////////////////////////////////////////////////////////////////
	/////So far only TSharedPtr<SMyUIWidget> has been created, now create the actual object.
	/////Create a SMyUIWidget on heap, our MyUIWidget shared pointer provides handle to object
	/////Widget will not self-destruct unless the HUD's SharedPtr (and all other SharedPtrs) destruct first.
	SAssignNew(EditorUIWidget, SEditorUIWidget).OwnerHUD(this);

	////////////////////////////////////////////////////////////////////////////////////////////////////
	/////Pass our viewport a weak ptr to our widget
	if (GEngine->IsValidLowLevel())
	{
		GEngine->GameViewport->
			/*Viewport's weak ptr will not give Viewport ownership of Widget*/
			AddViewportWidgetContent(SNew(SWeakWidget).PossiblyNullContent(EditorUIWidget.ToSharedRef()));
	}

	if (EditorUIWidget.IsValid())
	{
		////////////////////////////////////////////////////////////////////////////////////////////////////
		/////Set widget's properties as visible (sets child widget's properties recursively)
		EditorUIWidget->SetVisibility(EVisibility::Visible);
	}
}
