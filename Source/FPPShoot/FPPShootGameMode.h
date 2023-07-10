// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "FPPShootGameMode.generated.h"

UCLASS(minimalapi)
class AFPPShootGameMode : public AGameModeBase
{
	GENERATED_BODY()

protected:
	UPROPERTY(EditDefaultsOnly,Category="Spectating")
	TSubclassOf<AActor> SpectViewPointClass;
	
public:
	AFPPShootGameMode();

	void CompleteMission(APawn* InstigatorPawn);

	UFUNCTION(BlueprintImplementableEvent,Category="GameMode")
	void OnMissionCompleted(APawn* InstigatorPawn);
};



