// Amir Abbaspour 2021


#include "TankGameModeBase.h"

void ATankGameModeBase::BeginPlay() 
{
    
}

void ATankGameModeBase::ActorDied(AActor* DiedActor) 
{
    // Checl what type of Actor died. If Turret, tally. If Player -> go to lose condition. 
    // Checl what type of Actor died. If Turret, tally. If Player -> go to lose condition.
    UE_LOG(LogTemp, Warning, TEXT("%s Died"), *DiedActor -> GetName());

}

void ATankGameModeBase::HandleGameStart() 
{
    
}

void ATankGameModeBase::HandleGameOver(bool PlayerWon) 
{
    
}