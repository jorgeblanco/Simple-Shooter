// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"

#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

void AShooterAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

void AShooterAIController::BeginPlay()
{
    Super::BeginPlay();

    PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    APawn* ThisPawn = GetPawn();
    
    if (AIBehavior == nullptr)
    {
        return;
    }
    
    RunBehaviorTree(AIBehavior);
    if (PlayerPawn != nullptr)
    {
        GetBlackboardComponent()->SetValueAsVector(
            TEXT("PlayerLocation"),
            PlayerPawn->GetActorLocation()
        );
    }

    if (ThisPawn != nullptr)
    {
        GetBlackboardComponent()->SetValueAsVector(
            TEXT("StartLocation"),
            ThisPawn->GetActorLocation()
        );
    }
}
