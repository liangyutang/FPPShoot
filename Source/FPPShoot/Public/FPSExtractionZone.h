// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSExtractionZone.generated.h"

class UBoxComponent;

UCLASS()
class FPPSHOOT_API AFPSExtractionZone : public AActor
{
	///游戏通关盒子
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AFPSExtractionZone();

protected:
	UPROPERTY(EditAnywhere,Category="Components")
	UBoxComponent* OverlapComponent;

	//贴花组件
	UPROPERTY(EditAnywhere,Category="Components")
	UDecalComponent* DecalComponent;

	/**
	 * @brief 未携带物品进入通过口的提示音效
	 */
	UPROPERTY(EditAnywhere,Category="Sounds")
	USoundBase* ObjectiveMissingSound;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void HandleOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
