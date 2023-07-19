// Fill out your copyright notice in the Description page of Project Settings.


#include "FPSGameStateBase.h"

void AFPSGameStateBase::MulticastOnMissionComplete_Implementation(APawn* InstigatorPawn, bool bMissionCompleted)
{
	for (FConstPawnIterator it=GetWorld()->GetPawnIterator();it;it++)
	{
		//禁用本地玩家的控制
		APawn* Pawn=it->Get();
		if (Pawn&&Pawn->IsLocallyControlled())
		{
			Pawn->DisableInput(nullptr);
		}
	}
}
