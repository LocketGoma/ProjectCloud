// Fill out your copyright notice in the Description page of Project Settings.
#include "CLAttackerNodeComponent.h"
#include "Components/SphereComponent.h"

// Sets default values for this component's properties
UCAttackerNodeComponent::UCAttackerNodeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// Our root component will be a sphere that reacts to physics

	CorePoint = CreateDefaultSubobject<USphereComponent>(TEXT("CorePoint"));
	AttackPoint = CreateDefaultSubobject<USphereComponent>(TEXT("AttackPoint"));
	CorePoint->InitSphereRadius(10.0f);
	AttackPoint->InitSphereRadius(10.0f);
	CorePoint->SetCollisionProfileName(TEXT("None"));
	AttackPoint->SetCollisionProfileName(TEXT("None"));	
}


// Called when the game starts
void UCAttackerNodeComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UCAttackerNodeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

