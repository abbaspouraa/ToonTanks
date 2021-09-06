// Copyright Amir Abbaspour 2021


#include "BasePawn.h"
#include "Components/CapsuleComponent.h"

// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComp = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComp;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent> (TEXT("Base Mesh"));
	BaseMesh -> SetupAttachment(RootComponent);

	TurretMesh = CreateDefaultSubobject<UStaticMeshComponent> (TEXT("Turrent Mesh"));
	TurretMesh -> SetupAttachment(BaseMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent> (TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint -> SetupAttachment(TurretMesh);
}

void ABasePawn::RotateTurret(FVector LookAtTarget) 
{
	// Look at targets passed in from child classes
	FVector TargetVector = FVector(LookAtTarget.X, LookAtTarget.Y, TurretMesh -> GetComponentLocation().Z);
	FVector StartLocation  = TurretMesh -> GetComponentLocation();
	FRotator TurretRotation = (TargetVector - StartLocation).Rotation();

	// TurretMesh -> SetWorldRotation()...
	TurretMesh -> SetWorldRotation(TurretRotation);
}

void ABasePawn::Fire() 
{
	UE_LOG(LogTemp, Warning, TEXT("Fire Condirion Checked."));
}

void ABasePawn::HandleDestruction() 
{
	// --- Universal Functionality ---
	// Play death effects particle, sound and camera shake.

	// --- Then do child overrides ---
	// --- PawnTurret - Inform GameMode Turret died -> Then Destroy() self.

	// PawnTank - Inform GameMode Player died -> Then Hide() all components & stop movement input.
}


