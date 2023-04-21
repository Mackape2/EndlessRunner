// Copyright Epic Games, Inc. All Rights Reserved.

#include "assignemt_runnerGameMode.h"
#include "assignemt_runnerCharacter.h"
#include "UObject/ConstructorHelpers.h"

Aassignemt_runnerGameMode::Aassignemt_runnerGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
	
}
