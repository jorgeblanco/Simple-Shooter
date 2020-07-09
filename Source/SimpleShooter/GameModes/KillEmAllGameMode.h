// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SimpleShooter/SimpleShooterGameModeBase.h"
#include "KillEmAllGameMode.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API AKillEmAllGameMode : public ASimpleShooterGameModeBase
{
	GENERATED_BODY()

private:
    void EndGame(bool bPlayerWin);

public:
    virtual void PawnKilled(APawn* PawnKilled) override;
};
