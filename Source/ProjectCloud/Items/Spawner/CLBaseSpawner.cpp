// Fill out your copyright notice in the Description page of Project Settings.


#include "CLBaseSpawner.h"

// Sets default values
ACLBaseSpawner::ACLBaseSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACLBaseSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACLBaseSpawner::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
}

// Called every frame
void ACLBaseSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACLBaseSpawner::OnComponentBeginOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
}

void ACLBaseSpawner::SetNiagaraEffect()
{
}

