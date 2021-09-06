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


// Called every frame
void APawnTurret::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
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
		UE_LOG(LogTemp, Warning, TEXT("Fire Condirion Checked."));
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