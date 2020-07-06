// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTask_Shoot.h"

#include "AIController.h"
#include "SimpleShooter/Characters/Shooter.h"

EBTNodeResult::Type UBTTask_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    EBTNodeResult::Type Result = Super::ExecuteTask(OwnerComp, NodeMemory);
    
    AAIController* OwnerAI = OwnerComp.GetAIOwner();
    if (OwnerAI == nullptr)
    {
        return EBTNodeResult::Failed;
    }
    
    AShooter* Shooter = Cast<AShooter>(OwnerComp.GetAIOwner()->GetPawn());
    if (Shooter == nullptr)
    {
        return EBTNodeResult::Failed;
    }
    
    Shooter->Shoot();
    
    return EBTNodeResult::Succeeded;
}

UBTTask_Shoot::UBTTask_Shoot()
{
    NodeName = TEXT("Shoot");
}
