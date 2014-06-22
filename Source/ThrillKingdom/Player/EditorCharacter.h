

#pragma once

#include "GameFramework/Pawn.h"
#include "EditorCharacter.generated.h"

/**
 * 
 */
UCLASS()
class AEditorCharacter : public APawn
{
public:

	GENERATED_UCLASS_BODY()

	/** Component used as a base and collision */
	UPROPERTY(Category = Default, VisibleAnywhere, BlueprintReadOnly)
	TSubobjectPtr<class UCapsuleComponent> Base;

	/** Camera component that will be our viewpoint */
	UPROPERTY(Category = Camera, VisibleAnywhere, BlueprintReadOnly)
	TSubobjectPtr<class UCameraComponent> Camera;
	
	// Begin AActor overrides
	virtual void Tick(float DeltaSeconds) OVERRIDE;
	virtual void ReceiveHit(class UPrimitiveComponent* MyComp, class AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) OVERRIDE;
	// End AActor overrides

	UPROPERTY(Category = Controls, EditAnywhere, BlueprintReadWrite)
		float MoveSpeed;

	UPROPERTY(Category = Controls, EditAnywhere, BlueprintReadWrite)
		float RotateFactor;

	UPROPERTY(Category = Controls, EditAnywhere, BlueprintReadWrite)
		float ZoomFactor;

	UPROPERTY(Category = Controls, EditAnywhere, BlueprintReadWrite)
		float MinZoomAltitude;

	UPROPERTY(Category = Controls, EditAnywhere, BlueprintReadWrite)
		float MaxZoomAltitude;

	UPROPERTY(Category = Controls, EditAnywhere, BlueprintReadWrite)
		float SprintMultiplyAmt;

protected:

	// APawn overrides
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) OVERRIDE; // Allows binding actions/axes to functions

	// Called when forward/back input is pressed
	void MoveForward(float Val);

	// Called when right/left input is pressed
	void MoveRight(float Val);

	// Called when the rotation input is pressed
	void Rotate(float Val);

	// Called when the zoom in input is pressed
	void ZoomIn();

	// Called when the zoom out input is pressed
	void ZoomOut();

	// Called when sprint input is pressed
	void ToggleSprintOn();

	// Called when sprint input is released
	void ToggleSprintOff();

private:
	
	// Store current rotation before editing
	FRotator TempRotation;
};
