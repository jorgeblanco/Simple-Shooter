// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class SIMPLESHOOTER_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();
	virtual void Tick(float DeltaTime) override;
	void Shoot();
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;
	UPROPERTY(VisibleAnywhere)
	USkeletalMeshComponent* Mesh;
	UPROPERTY(EditAnywhere)
	UParticleSystem* MuzzleParticles;
	UPROPERTY(EditAnywhere)
	UParticleSystem* ImpactParticles;
	UPROPERTY(EditAnywhere)
	float ShotRange = 10000.f;
	UPROPERTY(EditAnywhere)
	float Damage = 50.f;
	
	bool GunTrace(FHitResult& Hit, FVector& ShotDirection) const;
	AController* GetOwnerController() const;
};
