// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "FPSGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class FPPSHOOT_API AFPSGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	//网络组播实现
	UFUNCTION(NetMulticast,Reliable)
	void MulticastOnMissionComplete(APawn* InstigatorPawn,bool bMissionCompleted);
};
