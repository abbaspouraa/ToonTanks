// Amir Abbaspour 2021


#include "PawnTank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"


APawnTank::APawnTank()
{
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
	SpringArm -> SetupAttachment(RootComponent);

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera -> SetupAttachment(SpringArm);

	FVector MoveDirecton;
	FQuat RotationDirectin;

	void CalculateMoveInput(float Value);
	void CalculateRotationInput(float Value);

	void Move();
	void Rotate();
}

// Called when the game starts or when spawned
void APawnTank::BeginPlay()
{
	Super::BeginPlay();
	
}


// Called every frame
void APawnTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APawnTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void CalculateMoveInput(float Value) 
{
	
}

void CalculateRotationInput(float Value) 
{
	
}

void Move() 
{
	
}

void Rotate() 
{
	
}