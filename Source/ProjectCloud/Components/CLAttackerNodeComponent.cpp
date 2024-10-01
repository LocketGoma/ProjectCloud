// Fill out your copyright notice in the Description page of Project Settings.
#include "CLAttackerNodeComponent.h"
#include "Components/SphereComponent.h"
#include "ProjectCloud/Weapon/CLWeapon.h"

// Sets default values for this component's properties
UCAttackerNodeComponent::UCAttackerNodeComponent()	
{
	bWeaponRelativeSpin = false;
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

	CorePoint->AttachToComponent(this, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	AttackPoint->AttachToComponent(this, FAttachmentTransformRules::KeepRelativeTransform);

	AttackPoint->SetRelativeLocation(FVector(AttactPointLength, 0, 0));	

	if (WeaponActorClass)
	{
		WeaponActor = GetWorld()->SpawnActor<ACLWeapon>(WeaponActorClass);

		WeaponActor->AttachToComponent(AttackPoint, FAttachmentTransformRules::KeepRelativeTransform);
	}
}

void UCAttackerNodeComponent::UpdateAttactPointLength(float NewLenght)
{
	if (NewLenght >= 0.0f)
	{
		AttackPoint->SetRelativeLocation(AttackPoint->GetRelativeLocation() * (NewLenght / AttactPointLength));

		K2_UpdateAttactPointLength(NewLenght);
	}
}

void UCAttackerNodeComponent::UpdateRotation(float Val)
{
	SetRelativeRotation(FRotator(0, Val, 0));
	
	if (!bWeaponRelativeSpin)
	{
		WeaponActor->SetActorRelativeRotation(-1 * GetRelativeRotation());
	}

	K2_UpdateRotation(GetRelativeRotation());
}

void UCAttackerNodeComponent::AddRotation(float Val)
{
	AddRelativeRotation(FRotator(0, Val, 0));

	if (!bWeaponRelativeSpin)
	{		
		WeaponActor->SetActorRelativeRotation(-1 * GetRelativeRotation());
	}

	K2_UpdateRotation(GetRelativeRotation());
}

const USceneComponent* UCAttackerNodeComponent::GetAttackPoint()
{
	//방향 뿜어줄때는 AttackPoint의 RightVector 뿜어주면 됨 <- 아니면 바꾸던지

	return AttackPoint;
}

const FTransform UCAttackerNodeComponent::GetAttackPointTransform()
{
	return AttackPoint->GetComponentTransform();
}

ACLWeapon* UCAttackerNodeComponent::GetWeaponActor()
{
	return WeaponActor;
}

const EWeaponType UCAttackerNodeComponent::GetWeaponType() const
{
	return WeaponActor->GetWeaponType();
}

