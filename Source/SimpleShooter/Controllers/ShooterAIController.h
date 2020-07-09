// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterAIController.generated.h"

/**
 * 
 */
UCLASS()
class SIMPLESHOOTER_API AShooterAIController : public AAIController
{
	GENERATED_BODY()

private:
	APawn* PlayerPawn = nullptr;
	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior;
	
public:
	virtual void Tick(float DeltaTime) override;
	bool IsDead() const;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	float StoppingDistance = 200.f;
};
