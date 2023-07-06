// Copyright Epic Games, Inc. All Rights Reserved.

#include "FPPShootGameMode.h"
#include "FPPShootCharacter.h"
#include "UObject/ConstructorHelpers.h"

AFPPShootGameMode::AFPPShootGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}