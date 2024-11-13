// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjectCloud/Utilites/CLCommonEnum.h"
#include "CLProjectileActor.generated.h"

class UNiagaraComponent;
class UNiagaraSystem;
class UCapsuleComponent;
class UGameplayEffect;
class UCLWeaponAttributeSet;
class UArrowComponent;
class ACLBaseCharacter;
class UProjectileMovementComponent;

UCLASS(BlueprintType)
class PROJECTCLOUD_API ACLProjectileActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACLProjectileActor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
	void LaunchProjectile();

public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	UProjectileMovementComponent* GetMovementComponent() { return MovementComponent; }

	float GetBaseDamageFromWeapon() { return BaseDamageFromWeapon; }
	void SetBaseDamageFromWeapon(float NewDamage) { BaseDamageFromWeapon = NewDamage; }

//충돌 처리
	UFUNCTION()
	virtual void OnComponentBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void ActiveDestroyEvent();

public:
	//추적할 타겟 캐릭터 여부
	UPROPERTY()
	TWeakObjectPtr<ACLBaseCharacter> TargetCharacter;

	UPROPERTY(EditDefaultsOnly, Category = "Attributes")
	TSubclassOf<UGameplayEffect> GameplayEffect;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VisualSettings")
	TObjectPtr<UNiagaraSystem> MainVFX;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VisualSettings")
	TObjectPtr<UNiagaraSystem> SubVFX;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VisualSettings")
	TObjectPtr<UNiagaraSystem> TrailVFX;

	//나아가는 방향
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Attributes")
	FVector LaunchVector;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attributes", meta = (UIMin = 0, ClampMin = 0))
	float LaunchSpeed;

	static FName SpriteComponentName;

private:
	void SetNiagaraEffect();

private:
	float BaseDamageFromWeapon;

	UPROPERTY()
	TObjectPtr<UNiagaraComponent> NiagaraComponent;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UCapsuleComponent> CapsuleComponent;
		
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UPROPERTY()
	TObjectPtr<UProjectileMovementComponent> MovementComponent;
		
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "VisualSettings", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UPaperFlipbookComponent> Sprite;

#if WITH_EDITORONLY_DATA
	/** Component shown in the editor only to indicate character facing */
	UPROPERTY()
	TObjectPtr<UArrowComponent> ArrowComponent;
#endif
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float EffectSize;

	UPROPERTY(EditDefaultsOnly, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	bool bDestroyWhenHit;

	UPROPERTY(EditDefaultsOnly, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	float MaximimLifetime;

	FTimerHandle DestroyTimerHandle;

	bool bStartLaunch;

public:
	/** Returns Sprite subobject **/
	FORCEINLINE class UPaperFlipbookComponent* GetSprite() const { return Sprite; }

};
