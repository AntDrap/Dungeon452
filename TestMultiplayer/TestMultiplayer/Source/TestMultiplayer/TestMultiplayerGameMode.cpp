// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestMultiplayerGameMode.h"
#include "TestMultiplayerCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATestMultiplayerGameMode::ATestMultiplayerGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
