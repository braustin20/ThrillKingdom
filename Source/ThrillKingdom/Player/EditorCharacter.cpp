

#include "ThrillKingdom/ThrillKingdom.h"
#include "EditorCharacter.h"


AEditorCharacter::AEditorCharacter(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	// Structure to hold one-time initialization
	struct FConstructorStatics
	{

	};
	
	// Create a collision capsule and set it's collider properties
	Base = PCIP.CreateDefaultSubobject<UCapsuleComponent>(this, TEXT("CollisionBase"));
	Base->InitCapsuleSize(30.0f, 80.0f);
	Base->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Base->SetCollisionResponseToAllChannels(ECR_Ignore);
	Base->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	// Replace the root component with the capsule
	RootComponent = Base;

	

	// Create camera component 
	Camera = PCIP.CreateDefaultSubobject<UCameraComponent>(this, TEXT("Camera0"));
	Camera->AttachTo(Base);
	// Don't rotate camera with controller
	Camera->bUseControllerViewRotation = false; 

	// Rotate the camera facing downwards
	Camera->AddLocalRotation(FRotator(-30.0f, 0.0f, 0.f));

	// Speed variables
	MoveSpeed = 15.0f;
	RotateFactor = 2.0f;
	ZoomFactor = 30.0f;
	SprintMultiplyAmt = 2.5f;

	// Zoom bounds
	MinZoomAltitude = 10.0f;
	MaxZoomAltitude = 1000.0f;
}

// Frame loop
void AEditorCharacter::Tick(float DeltaSeconds)
{
	// Call any parent class Tick implementation
	Super::Tick(DeltaSeconds);
}

void AEditorCharacter::ReceiveHit(class UPrimitiveComponent* MyComp, class AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::ReceiveHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
}

// Set up input actions
void AEditorCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	check(InputComponent);

	InputComponent->BindAxis("Forward", this, &AEditorCharacter::MoveForward);
	InputComponent->BindAxis("Right", this, &AEditorCharacter::MoveRight);

	InputComponent->BindAxis("Rotate", this, &AEditorCharacter::Rotate);

	InputComponent->BindAction("ZoomIn", IE_Pressed, this, &AEditorCharacter::ZoomIn);
	InputComponent->BindAction("ZoomOut", IE_Pressed, this, &AEditorCharacter::ZoomOut);

	InputComponent->BindAction("Sprint", IE_Pressed, this, &AEditorCharacter::ToggleSprintOn);
	InputComponent->BindAction("Sprint", IE_Released, this, &AEditorCharacter::ToggleSprintOff);
}


void AEditorCharacter::MoveForward(float Val)
{
	SetActorLocation((GetActorForwardVector() * (Val * MoveSpeed)) + GetActorLocation());
}

void AEditorCharacter::MoveRight(float Val)
{
	SetActorLocation((GetActorRightVector() * (Val * MoveSpeed)) + GetActorLocation());
}

// Rotates around the origin at a determined rate
void AEditorCharacter::Rotate(float Val)
{
	TempRotation = GetActorRotation();
	TempRotation.Yaw = TempRotation.Yaw + (Val * RotateFactor);
	SetActorRotation(TempRotation);
}

// Move up and back at a 45 degree angle
void AEditorCharacter::ZoomIn()
{
	if (GetActorLocation().Z > MinZoomAltitude){
		SetActorLocation(GetActorLocation() + (GetActorUpVector() - GetActorForwardVector()) * (ZoomFactor * -1.0f));
	}
}

// Move forward and down at a 45 degree angle
void AEditorCharacter::ZoomOut()
{
	if (GetActorLocation().Z < MaxZoomAltitude){
		SetActorLocation(GetActorLocation() + (GetActorUpVector() - GetActorForwardVector()) * ZoomFactor);
	}
}

// Multiply movement speeds by the multiplier
void AEditorCharacter::ToggleSprintOn()
{
	MoveSpeed *= SprintMultiplyAmt;
	RotateFactor *= SprintMultiplyAmt;
	ZoomFactor *= SprintMultiplyAmt;
}

// Divide movement speeds by the multiplier
void AEditorCharacter::ToggleSprintOff()
{
	MoveSpeed /= SprintMultiplyAmt;
	RotateFactor /= SprintMultiplyAmt;
	ZoomFactor /= SprintMultiplyAmt;
}