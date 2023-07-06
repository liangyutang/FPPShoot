// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FPSObjectActor.generated.h"

UCLASS()
class FPPSHOOT_API AFPSObjectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFPSObjectActor();
	
protected:
	UPROPERTY(EditAnywhere,Category="Components")
	UStaticMeshComponent* MeshComponent;

	UPROPERTY(EditAnywhere,Category="Components")
	class USphereComponent* SphereComponent;

	//碰撞特效
	UPROPERTY(EditDefaultsOnly,Category="Effects")
	UParticleSystem* PickupFX;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void PlayEffects();

	virtual void NotifyActorBeginOverlap(AActor* OtherActor) override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
