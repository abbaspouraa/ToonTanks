// Amir Abbaspour 2021


#include "PawnTank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/PlayerController.h"


APawnTank::APawnTank()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm -> SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera -> SetupAttachment(SpringArm);
}

// Called when the game starts or when spawned
void APawnTank::BeginPlay()
{
	Super::BeginPlay();

	PlayerControllerRef = Cast<APlayerController>(GetController());
}

void APawnTank::HandleDestruction() 
{
	Super::HandleDestruction();

	// Hide Player - Create a new function to handle this.
}


// Called every frame
void APawnTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Rotate();
	Move();

	if (PlayerControllerRef)
	{
		FHitResult TraceHitResults;
		PlayerControllerRef -> GetHitResultUnderCursor(ECC_Visibility, false, TraceHitResults);
		FVector HitLocation = TraceHitResults.ImpactPoint;

		RotateTurret(HitLocation);
	}
}

// Called to bind functionality to input
void APawnTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent -> BindAxis("MoveForward", this, &APawnTank::CalculateMoveInput);
	PlayerInputComponent -> BindAxis("Turn", this, &APawnTank::CalculateRotationInput);
	PlayerInputComponent -> BindAction("Fire", IE_Pressed, this, &APawnTank::Fire);
}


void APawnTank::CalculateMoveInput(float Value) 
{
	MoveDirecton = FVector(Value * MoveSpeed * GetWorld() -> DeltaTimeSeconds, 0, 0);
}

void APawnTank::CalculateRotationInput(float Value) 
{
	float RotateAmount = Value * RotationSpeed * GetWorld() -> DeltaTimeSeconds;
	FRotator Rotation = FRotator(0, RotateAmount, 0);
	RotationDirectin = FQuat(Rotation);
}

void APawnTank::Move() 
{
	AddActorLocalOffset(MoveDirecton, true);
}

void APawnTank::Rotate() 
{
	AddActorLocalRotation(RotationDirectin, true);
}