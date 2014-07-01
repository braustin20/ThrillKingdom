

#pragma once

#include "Slate.h"

class SMyWindowWidget : public SWindow
{
	
public:

	SLATE_BEGIN_ARGS( SMyWindowWidget )
	{ 
	}
	SLATE_DEFAULT_SLOT(FArguments, Content)
	SLATE_END_ARGS()


	void Construct(const FArguments& InArgs);

protected:

	FReply SMyWindowWidget::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) OVERRIDE;

};
