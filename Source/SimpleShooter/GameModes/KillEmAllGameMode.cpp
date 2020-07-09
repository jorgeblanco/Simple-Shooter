// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"

void AKillEmAllGameMode::EndGame(bool bPlayerWin)
{
    for (AController* Controller : TActorRange<AController>(GetWorld()))
    {
        const bool bIsPlayerController = Controller->IsPlayerController();
        Controller->GameHasEnded(Controller->GetPawn(), bIsPlayerController == bPlayerWin);
    }
}

void AKillEmAllGameMode::PawnKilled(APawn* PawnKilled)
{
    Super::PawnKilled(PawnKilled);
    
    UE_LOG(LogTemp, Warning, TEXT("%s killed"), *PawnKilled->GetName());

    APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
    if (PlayerController != nullptr)
    {
        EndGame(false);
    }
}
