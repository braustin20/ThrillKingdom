

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
	UPROPERTY(Category = Default, VisibleDefaultsOnly, BlueprintReadOnly)
	TSubobjectPtr<class UCapsuleComponent> Base;

	/** Camera component that will be our viewpoint */
	UPROPERTY(Category = Camera, VisibleDefaultsOnly, BlueprintReadOnly)
	TSubobjectPtr<class UCameraComponent> Camera;
	
	// Begin AActor overrides
	virtual void Tick(float DeltaSeconds) OVERRIDE;
	virtual void ReceiveHit(class UPrimitiveComponent* MyComp, class AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) OVERRIDE;
	// End AActor overrides

protected:

	// Begin APawn overrides
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) OVERRIDE; // Allows binding actions/axes to functions
	// End APawn overrides

	// Called when forward input is pressed
	void MoveForward(float Val);
};
