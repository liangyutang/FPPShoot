// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AIGuard.generated.h"

UENUM(BlueprintType)
enum class EAIState:uint8
{
	Idle,
	Suspicious,
	Alerted
};

class UPawnSensingComponent;

UCLASS()
class FPPSHOOT_API AAIGuard : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AAIGuard();

protected:
	/**
	 * @brief 人型感应组件
	 */
	UPROPERTY(EditAnywhere,Category="Components")
	UPawnSensingComponent* PawnSensingComponent;

	FRotator OriginalRotation;

	FTimerHandle TimerHandle_ResetOrient;

	float ResetOrientTime=3.f;

	//守卫状态
	UPROPERTY(ReplicatedUsing=On_RepGuardState)
	EAIState GuardState;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/**
	 * @brief 观测玩家
	 * @param SeenPawn 玩家
	 */
	UFUNCTION()
	void OnPawnSeen(APawn* SeenPawn);

	/**
	 * @brief 听玩家声音
	 * @param Instigat 
	 * @param Location 
	 * @param Volume 
	 */
	UFUNCTION(NetMulticast,Reliable)
	void OnNoiseHeard(APawn* Instigat,const FVector &Location,float Volume);

	void ResetOrientation();

	void SetGuardState(EAIState NewState);

	UFUNCTION(BlueprintImplementableEvent,Category="AI")
	void OnStateChanged(EAIState NewState);

	UFUNCTION()
	void On_RepGuardState();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
