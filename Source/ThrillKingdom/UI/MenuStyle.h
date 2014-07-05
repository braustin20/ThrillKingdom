

#pragma once

//#include "Styling/SlateWidgetStyleAsset.h"
//#include "MenuStyle.generated.h"

/**
 * 
 */

class FMenuStyle
{
public:

	/**
	* Initializes the value of MenuStyleInstance and registers it with the Slate Style Registry.
	**/
	static void Initialize();

	/**
	* Unregisters the Slate Style Set and then resets the MenuStyleInstance pointer.
	**/
	static void Shutdown();

	/**
	* Retrieves a reference to the Slate Style pointed to by MenuStyleInstance.
	**/
	static const class ISlateStyle& Get();

	/*
		retrieves the name of the style set
	*/
	static FName GetStyleSetName();

private:
	//Creates the style set
	static TSharedRef<class FSlateStyleSet> Create();

	static TSharedPtr<class FSlateStyleSet> MenuStyleInstance;
	
};
