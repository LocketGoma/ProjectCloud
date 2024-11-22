// Fill out your copyright notice in the Description page of Project Settings.
#include "CLAttackerNodeComponent.h"
#include "Components/SphereComponent.h"
#include "ProjectCloud/Weapon/CLWeapon.h"
#include "ProjectCloud/Weapon/CLSubActionEquipment.h"

// Sets default values for this component's properties
UCLAttackerNodeComponent::UCLAttackerNodeComponent()	
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
	
	CorePoint->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	CorePoint->SetCollisionResponseToAllChannels(ECR_Ignore);
	AttackPoint->SetCollisionEnabled(ECollisionEnabled::NoCollision);	
	AttackPoint->SetCollisionResponseToAllChannels(ECR_Ignore);
}

// Called when the game starts
void UCLAttackerNodeComponent::BeginPlay()
{
	Super::BeginPlay();

	CorePoint->AttachToComponent(this, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
	AttackPoint->AttachToComponent(this, FAttachmentTransformRules::KeepRelativeTransform);

	AttackPoint->SetRelativeLocation(FVector(AttactPointLength, 0, 0));	

	if (WeaponActorClass)
	{
		WeaponActor = GetWorld()->SpawnActor<ACLWeapon>(WeaponActorClass);
		WeaponActor->SetOwner(GetOwner());
		WeaponActor->AttachToComponent(AttackPoint, FAttachmentTransformRules::KeepRelativeTransform);
		WeaponActor->SetEquipmentFromInstance();
	}
	EquipSubEquipmentActor(SubEquipmentActorClass);

	OnMainWeaponChanged.AddUObject(this, &ThisClass::HandleEquipMainWeaponActor);
	OnSubWeaponChanged.AddUObject(this, &ThisClass::HandleEquipSubEquipmentActor);
}

void UCLAttackerNodeComponent::UpdateAttactPointLength(float NewLenght)
{
	if (NewLenght >= 0.0f)
	{
		AttackPoint->SetRelativeLocation(AttackPoint->GetRelativeLocation() * (NewLenght / AttactPointLength));

		K2_UpdateAttactPointLength(NewLenght);
	}
}

void UCLAttackerNodeComponent::UpdateRotation(float Val)
{
	SetRelativeRotation(FRotator(0, Val, 0));
	
	if (!bWeaponRelativeSpin)
	{
		if (WeaponActor)
			WeaponActor->SetActorRelativeRotation(-1 * GetRelativeRotation());
	}
	if (SubEquipmentActor)
		SubEquipmentActor->SetActorRelativeRotation(-1 * GetRelativeRotation());

	K2_UpdateRotation(GetRelativeRotation());
}

void UCLAttackerNodeComponent::AddRotation(float Val)
{
	AddRelativeRotation(FRotator(0, Val, 0));

	if (!bWeaponRelativeSpin)
	{		
		if (WeaponActor)
			WeaponActor->SetActorRelativeRotation(-1 * GetRelativeRotation());
	}
	if (SubEquipmentActor)
		SubEquipmentActor->SetActorRelativeRotation(-1 * GetRelativeRotation());

	K2_UpdateRotation(GetRelativeRotation());
}

void UCLAttackerNodeComponent::EquipSubEquipmentActor(TSubclassOf<ACLSubActionEquipment> EquipmentActorClass)
{
	if (IsValid(SubEquipmentActor))
	{
		//무조건 교체라고...
		//if (SubEquipmentActor->GetSubEquipmentType() == EquipmentActorClass.GetDefaultObject()->GetSubEquipmentType())
		//{
		//	SubEquipmentActor->Reload();
		//	return;
		//}

		SubEquipmentActor->Destroy();
		SubEquipmentActor = nullptr;
	}

	if (EquipmentActorClass)
	{
		SubEquipmentActor = GetWorld()->SpawnActor<ACLSubActionEquipment>(EquipmentActorClass);
		SubEquipmentActor->SetOwner(GetOwner());
		SubEquipmentActor->AttachToComponent(CorePoint, FAttachmentTransformRules::KeepRelativeTransform);
		SubEquipmentActor->SetEquipmentFromInstance();	
	}
}

void UCLAttackerNodeComponent::HandleEquipMainWeaponActor(TObjectPtr<ACLWeapon> NewWeaponActor)
{
	if (NewWeaponActor)
	{
		//Do Something...
	}
}

void UCLAttackerNodeComponent::HandleEquipSubEquipmentActor(TObjectPtr<ACLSubActionEquipment> NewEquipActor)
{
	if (NewEquipActor)
	{
		EquipSubEquipmentActor(NewEquipActor.GetClass());
	}
	else
	{
		EquipSubEquipmentActor(nullptr);
	}
	
}

const USceneComponent* UCLAttackerNodeComponent::GetAttackPoint()
{
	//방향 뿜어줄때는 AttackPoint의 RightVector 뿜어주면 됨 <- 아니면 바꾸던지

	return AttackPoint;
}

const FTransform UCLAttackerNodeComponent::GetAttackPointTransform()
{
	return AttackPoint->GetComponentTransform();
}

ACLWeapon* UCLAttackerNodeComponent::GetWeaponActor()
{
	return WeaponActor;
}

//액터 파괴될때 또 호출하면 pending Destroyed 상태여서 Object는 살아있는데 내부 데이터가 깨져있는 경우가 있음...
ACLSubActionEquipment* UCLAttackerNodeComponent::GetSubEquipmentActor()
{
	return SubEquipmentActor;
}

const EWeaponType UCLAttackerNodeComponent::GetWeaponType() const
{
	return WeaponActor->GetWeaponType();
}

