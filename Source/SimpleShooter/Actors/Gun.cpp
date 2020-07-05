// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"

#include "DrawDebugHelpers.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Controller.h"
#include "SimpleShooter/Characters/Shooter.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>("Mesh");
	Mesh->SetupAttachment(Root);
}

void AGun::Shoot()
{
	UGameplayStatics::SpawnEmitterAttached(MuzzleParticles, Mesh, TEXT("MuzzleFlashSocket"));
	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if (!OwnerPawn)
	{
		return;
	}
	AController* OwnerController = OwnerPawn->GetController();
	if (!OwnerController)
	{
		return;
	}
	FVector OwnerLocation;
	FRotator OwnerRotation;
	OwnerController->GetPlayerViewPoint(OwnerLocation, OwnerRotation);

	const FVector End = OwnerLocation + OwnerRotation.Vector() * ShotRange;
	FHitResult Hit;
	bool bHitSuccess = GetWorld()->LineTraceSingleByChannel(Hit, OwnerLocation, End, ECC_GameTraceChannel1);
	if (bHitSuccess)
	{
		FVector ShotDirection = -OwnerRotation.Vector();
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactParticles, Hit.ImpactPoint, Hit.ImpactNormal.Rotation());
		FPointDamageEvent DamageEvent = FPointDamageEvent(
			Damage,
			Hit,
			ShotDirection,
			nullptr
		);
		AActor* ActorHit = Hit.GetActor();
		if (ActorHit != nullptr)
		{
			ActorHit->TakeDamage(Damage, DamageEvent, OwnerController, this);
		}
	}
}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

