// Amir Abbaspour 2021


#include "PawnTurret.h"
#include "Kismet/GameplayStatics.h"
#include "PawnTank.h"


// Called when the game starts or when spawned
void APawnTurret::BeginPlay()
{
	Super::BeginPlay();

	GetWorld() -> GetTimerManager().SetTimer(FireRateTimerHandle, this, &APawnTurret::CheckFireCondition, FireRate, true);

	PlayerPawn = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(this, 0));

}

void APawnTurret::HandleDestruction() 
{
	Super::HandleDestruction();

	UE_LOG(LogTemp, Warning, TEXT("A turret died."));
}


// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if(!PlayerPawn || ReturnDistanceToPlayer() > FireRange)
	{
		return;
	}
	Super::RotateTurret(PlayerPawn -> GetActorLocation());
}


void APawnTurret::CheckFireCondition() 
{
	if(!PlayerPawn)
	{
		return;
	}

	if(ReturnDistanceToPlayer() <= FireRange)
	{
		// Fire
		Super::Fire();
	}
}

float APawnTurret::ReturnDistanceToPlayer() 
{
	if (!PlayerPawn)
	{
		return 0.f;
	}

	return FVector::Dist(PlayerPawn->GetActorLocation(), GetActorLocation());
}
