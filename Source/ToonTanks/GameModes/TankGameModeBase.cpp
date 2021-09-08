// Amir Abbaspour 2021


#include "TankGameModeBase.h"
#include "ToonTanks/Pawns/PawnTank.h"
#include "ToonTanks/Pawns/PawnTurret.h"
#include "Kismet/GameplayStatics.h"

#define OUT

void ATankGameModeBase::BeginPlay() 
{
    Super::BeginPlay();

    HandleGameStart();
}

void ATankGameModeBase::ActorDied(AActor* DiedActor) 
{
    // Check what type of Actor died.
    // If Player -> go to lose condition. 
    if(DiedActor == PlayerTank)
    {
        PlayerTank -> HandleDestruction();
        HandleGameOver(false);
        return;
    }
    
    // If Turret, tally.
    if(APawnTurret* TurretTower = Cast<APawnTurret>(DiedActor))
    {
        TurretTower -> HandleDestruction();

        // Update number of enemies
        --TargetTurrts;
    }

    if(TargetTurrts <= 0 )
    {
        HandleGameOver(true);
    }

    // for debugging!
    // UE_LOG(LogTemp, Warning, TEXT("%s Died"), *DiedActor -> GetName());
}

void ATankGameModeBase::HandleGameStart() 
{
    // Find the number of enemies
    TArray<AActor*> TurretActors;
    UGameplayStatics::GetAllActorsOfClass(GetWorld(), APawnTurret::StaticClass(), OUT TurretActors);
    TargetTurrts = TurretActors.Num();

    // Acquire the player thank for this class
    PlayerTank = Cast<APawnTank>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

    // Start the game!
    GameStart();
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon) 
{
   GameOver(PlayerWon);

   if (PlayerWon)
   {
       UE_LOG(LogTemp, Warning, TEXT("Game Over, You won!"));
       return;
   }
   UE_LOG(LogTemp, Warning, TEXT("Game Over, You lost!"));
}