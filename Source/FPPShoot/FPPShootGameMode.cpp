// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPPShootGameMode.h"
#include "FPPShootCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

AFPPShootGameMode::AFPPShootGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}

void AFPPShootGameMode::CompleteMission(APawn* InstigatorPawn)
{
	if (InstigatorPawn)
	{
		//禁用输入
		InstigatorPawn->DisableInput(nullptr);
	}
	if (SpectViewPointClass)
	{
		TArray<AActor*> ReturnedActors;
		UGameplayStatics::GetAllActorsOfClass(this,SpectViewPointClass,ReturnedActors);
		if (ReturnedActors.Num()>0)
		{
			AActor* NewViewTarget=ReturnedActors[0];
			APlayerController* PC=Cast<APlayerController>(InstigatorPawn->GetController());
			if (PC)
			{
				PC->SetViewTargetWithBlend(NewViewTarget,0.5f,VTBlend_Cubic);
			}
			else
			{
				UE_LOG(LogTemp,Warning,TEXT("空指针"));
			}
		}
	}
	OnMissionCompleted(InstigatorPawn);
}
