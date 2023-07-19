// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSGameStateBase.h"

#include "FPSPlayerController.h"

void AFPSGameStateBase::MulticastOnMissionComplete_Implementation(APawn* InstigatorPawn, bool bMissionCompleted)
{
	for (FConstPlayerControllerIterator It = GetWorld()->GetPlayerControllerIterator();It;It++)
	{
		AFPSPlayerController* PC=Cast<AFPSPlayerController>(It->Get());
		if (PC&&PC->IsLocalController())
		{
			PC->OnMissionCompleted(InstigatorPawn,bMissionCompleted);
			//禁用本地玩家的控制
			if (APawn* Pawn=PC->GetPawn())
			{
				Pawn->DisableInput(PC);
			}
		}
	}
}
