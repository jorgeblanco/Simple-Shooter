// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"

#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "SimpleShooter/Characters/Shooter.h"

void AShooterAIController::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

bool AShooterAIController::IsDead() const
{
    AShooter* ThisPawn = Cast<AShooter>(GetPawn());
    return !ThisPawn || ThisPawn->IsDead();
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

    if (ThisPawn != nullptr)
    {
        GetBlackboardComponent()->SetValueAsVector(
            TEXT("StartLocation"),
            ThisPawn->GetActorLocation()
        );
    }
}
