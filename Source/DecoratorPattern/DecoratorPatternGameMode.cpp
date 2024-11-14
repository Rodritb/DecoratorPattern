// Copyright Epic Games, Inc. All Rights Reserved.

#include "DecoratorPatternGameMode.h"
#include "DecoratorPatternCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADecoratorPatternGameMode::ADecoratorPatternGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
