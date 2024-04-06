// Copyright Epic Games, Inc. All Rights Reserved.

#include "SeekGameMode.h"
#include "../Character/SeekPlayerCharacter.h"
#include "UObject/ConstructorHelpers.h"

ASeekGameMode::ASeekGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(
		TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
