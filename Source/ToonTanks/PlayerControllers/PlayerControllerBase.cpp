// Amir Abbaspour 2021


#include "PlayerControllerBase.h"


void APlayerControllerBase::SetPlayerEnableState(bool SetPlayerEnabled) 
{
    if (SetPlayerEnabled)
    {
        GetPawn() -> EnableInput(this);
    }
    else
    {
        GetPawn() -> DisableInput(this);
    }

    bShowMouseCursor = SetPlayerEnabled;
}
