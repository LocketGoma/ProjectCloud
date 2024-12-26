// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Curves/CurveVector.h"
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

	void SetTargetCharacter(ACLBaseCharacter* NewTarget);

public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	UProjectileMovementComponent* GetMovementComponent() { return MovementComponent; }

	float GetBaseDamageFromWeapon() { return BaseDamageFromWeapon; }
	void SetBaseDamageFromWeapon(float NewDamage) { BaseDamageFromWeapon = NewDamage; }

//충돌 처리
	UFUNCTION()
	virtual void OnComponentBeginOverlap(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void ActiveDestroyEvent();


private:
	void FindNextNearestTarget();

	void SetNiagaraEffect();

	void UpdateNiagaraEffectLotation();
	void UpdateNiagaraEffectTransform();

public:
	//추적할 타겟 캐릭터 여부
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Target")	
	TWeakObjectPtr<ACLBaseCharacter> TargetCharacter;

	//타겟을 정확히 맞춰야만 터지는지 여부 (타겟이 있을때 한정)
	UPROPERTY(EditDefaultsOnly, Category = "Attributes|Target")	
	bool bIsPrecision;

	UPROPERTY(EditDefaultsOnly, Category = "Attributes|Options")
	EProjectileType ProjectileType;
	

	//상부 커브 하나 추가해서 커브를 통해서 위로 던졌다가 아래로 내려오게 하기
	UPROPERTY(EditDefaultsOnly, Category = "Attributes|Movement")
	TObjectPtr<UCurveBase> CurveData;	
	
	UPROPERTY(EditDefaultsOnly, Category = "Attributes")
	TSubclassOf<UGameplayEffect> GameplayEffect;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes|Effect|VFX")
	TObjectPtr<UNiagaraSystem> MainVFX;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes|Effect|VFX")
	TObjectPtr<UNiagaraSystem> SubVFX;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes|Effect|VFX")
	TObjectPtr<UNiagaraSystem> TrailVFX;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes|Effect|SFX")
	TObjectPtr<USoundBase> LaunchSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes|Effect|SFX")
	TObjectPtr<USoundBase> ExplosionSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Attributes|Effect|SFX")
	TObjectPtr<USoundBase> DestroySound;

	//나아가는 방향
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Attributes")
	FVector LaunchVector;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attributes", meta = (UIMin = 0, ClampMin = 0))
	float LaunchSpeed;

	static FName SpriteComponentName;

private:
	float BaseDamageFromWeapon;

	UPROPERTY()
	TArray<TObjectPtr<UNiagaraComponent>> NiagaraComponents;

	UPROPERTY(EditDefaultsOnly)
	TObjectPtr<UCapsuleComponent> CapsuleComponent;
	
	UPROPERTY()
	TObjectPtr<UProjectileMovementComponent> MovementComponent;
		
	UPROPERTY(BlueprintReadOnly, Category = "Attributes|Effect", meta = (AllowPrivateAccess = "true"))
	TObjectPtr<class UPaperFlipbookComponent> Sprite;	

#if WITH_EDITORONLY_DATA	
	UPROPERTY()
	TObjectPtr<UArrowComponent> ArrowComponent;
#endif

	//메인이펙트 크기
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attributes|Effect", meta = (AllowPrivateAccess = "true"))
	float MainEffectSize;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attributes|Effect", meta = (AllowPrivateAccess = "true"))
	float SubEffectSize;

	//트레일 길이
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attributes|Effect", meta = (AllowPrivateAccess = "true"))
	float TrailLength;

	UPROPERTY(EditDefaultsOnly, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	bool bDestroyWhenHit;

	UPROPERTY(EditDefaultsOnly, Category = "Attributes", meta = (AllowPrivateAccess = "true"))
	float MaximimLifetime;

private:

	FTimerHandle DestroyTimerHandle;

	//커브에서 뽑아낸 벡터
	FVector StartLocation = FVector::ZeroVector;

	FVector AdditionalVector = FVector::ZeroVector;

	double StartTime = 0.f;

	bool bStartLaunch;

public:
	/** Returns Sprite subobject **/
	FORCEINLINE class UPaperFlipbookComponent* GetSprite() const { return Sprite; }

};
