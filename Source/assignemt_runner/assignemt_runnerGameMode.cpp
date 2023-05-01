// Copyright Epic Games, Inc. All Rights Reserved.

#include "assignemt_runnerGameMode.h"
#include "assignemt_runnerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "UObject/ConstructorHelpers.h"

Aassignemt_runnerGameMode::Aassignemt_runnerGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	static ConstructorHelpers::FClassFinder<APawn> Player2PawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_Player2"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
		UGameplayStatics::CreatePlayer(Player2PawnBPClass.Class,2,true);
		
	}
	
}
