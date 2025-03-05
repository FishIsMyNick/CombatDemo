// Copyright Epic Games, Inc. All Rights Reserved.

#include "CombatDemoGameMode.h"
#include "CombatDemoCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACombatDemoGameMode::ACombatDemoGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
