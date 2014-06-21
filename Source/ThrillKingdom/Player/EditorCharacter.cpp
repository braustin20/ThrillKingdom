

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

void AEditorCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	check(InputComponent);

	InputComponent->BindAxis("Forward", this, &AEditorCharacter::MoveForward);

}
void AEditorCharacter::MoveForward(float Val)
{

}