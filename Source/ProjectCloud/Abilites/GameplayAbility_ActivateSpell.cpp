// Fill out your copyright notice in the Description page of Project Settings.


#include "GameplayAbility_ActivateSpell.h"
#include "ProjectCloud/Weapon/CLProjectileActor.h"
#include "ProjectCloud/Components/CLAbilitySystemComponent.h"
#include "ProjectCloud/Character/CLHeroCharacter.h"
#include "ProjectCloud/Components/CLAttackerNodeComponent.h"

bool UGameplayAbility_ActivateSpell::ShootProjectile(TSubclassOf<ACLProjectileActor> ProjectileToSpawn, FTransform ANTransform)
{
	if (ProjectileToSpawn)
	{
		FActorSpawnParameters SpawnParameter;
		SpawnParameter.Owner = GetAvatarActorFromActorInfo();

		ACLProjectileActor* ProjectileActor = GetWorld()->SpawnActor<ACLProjectileActor>(ProjectileToSpawn, ANTransform.GetLocation(), ANTransform.Rotator(), SpawnParameter);

		if (!ensureAlways(ProjectileActor))
		{
			return false;
		}
		ProjectileActor->SetBaseDamageFromWeapon(BaseDamage);
		ProjectileActor->LaunchVector = -1 * ANTransform.Rotator().Vector();
		ProjectileActor->LaunchProjectile();

		return true;
	}

	return false;
}

bool UGameplayAbility_ActivateSpell::ShootMagicProjectiles(int32 count, TSubclassOf<ACLProjectileActor> ProjectileToSpawn)
{
	AActor* Actor = GetAvatarActorFromActorInfo();

	if (!ensure(Actor))
	{
		return false;
	}

	//Hero가 아닌 애가 마법을 쓸 일이 있을까?
	ACLHeroCharacter* HeroPawn = Cast<ACLHeroCharacter>(Actor);
	FTransform ANTransform = HeroPawn->GetAttackerNode()->GetAttackPointTransform();

	for (int i = 0; i < count; ++i)
	{
		if (!ShootProjectile(ProjectileToSpawn, ANTransform))
			return false;
	}

	return true;
}



