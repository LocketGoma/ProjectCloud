// Fill out your copyright notice in the Description page of Project Settings.


#include "CLEquipmentActor.h"
#include "Components/SphereComponent.h"
#include "PaperFlipbookComponent.h"
#include "ProjectCloud/Character/CLBaseCharacter.h"
#include "ProjectCloud/ProjectCloudLogChannels.h"

FName ACLEquipmentActor::SpriteComponentName(TEXT("MainSprite"));
// Sets default values
ACLEquipmentActor::ACLEquipmentActor(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer)
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CoreComponent = CreateDefaultSubobject<USphereComponent>(TEXT("CoreComponent"));
	CoreComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	CoreComponent->SetCollisionResponseToAllChannels(ECR_Ignore);
	CoreComponent->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap);
	RootComponent = CoreComponent;

	// Try to create the sprite component
	Sprite = CreateOptionalDefaultSubobject<UPaperFlipbookComponent>(ACLEquipmentActor::SpriteComponentName);
	if (Sprite)
	{
		Sprite->AlwaysLoadOnClient = true;
		Sprite->AlwaysLoadOnServer = true;
		Sprite->bOwnerNoSee = false;
		Sprite->bAffectDynamicIndirectLighting = true;
		Sprite->PrimaryComponentTick.TickGroup = TG_PrePhysics;
		Sprite->SetupAttachment(CoreComponent);
		static FName CollisionProfileName(TEXT("ObjectMesh"));
		Sprite->SetCollisionProfileName(CollisionProfileName);
		Sprite->SetGenerateOverlapEvents(false);
	}

	CoreComponent->BodyInstance.bLockZRotation = true;

}

// Called when the game starts or when spawned
void ACLEquipmentActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACLEquipmentActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACLEquipmentActor::SetEquipmentFromInstance()
{
	UpdateEquipmentEvent();
	//Do Something
}

void ACLEquipmentActor::ActiveEquipment()
{
	UpdateEquipmentEvent();
	//Do Something
}

bool ACLEquipmentActor::CanActiveEquipment()
{
	//Do Something
	return false;
}

void ACLEquipmentActor::Reload()
{
	UpdateEquipmentEvent();
	//Do Something
}

bool ACLEquipmentActor::CanReload()
{
	return false;
}

AController* ACLEquipmentActor::GetOwnerController()
{
	if (!GetOwner())
	{
		return nullptr;
	}
	APawn* OwnerPawn = Cast<APawn>(GetOwner());

	if (IsValid(OwnerPawn))
	{
		return OwnerPawn->GetController();
	}

	return nullptr;
}

UCLAbilitySystemComponent* ACLEquipmentActor::GetOwnerAbilitySystemComponent() const
{
	if (!ensure(GetOwner()))
	{
		return nullptr;
	}

	ACLBaseCharacter* OwnerCharacter = Cast<ACLBaseCharacter>(GetOwner());

	if (!ensure(OwnerCharacter))
	{
		return nullptr;
	}

	UCLAbilitySystemComponent* ASC = OwnerCharacter->GetAbilitySystemComponent();

	if (!ensure(ASC))
	{
		return nullptr;
	}

	return ASC;
}

//Do Something...

#pragma region Virtual Functions

const int ACLEquipmentActor::GetMagazineSize() const
{
	return 0;
}

const int ACLEquipmentActor::GetMagazineAmmo() const
{
	return 0;
}

const int ACLEquipmentActor::GetSpareAmmo() const
{
	return 0;
}

const bool ACLEquipmentActor::GetIsInfinite() const
{
	return false;
}

const float ACLEquipmentActor::GetBaseEquipmentValue() const
{
	return 0.0f;
}

#pragma endregion

