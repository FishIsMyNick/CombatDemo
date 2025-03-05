// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

UENUM(BLueprintType)
enum class EAbilityInputID : uint8
{
	None,
	Confirm,
	Cancel,
	Attack1Ability,
	Attack2Ability,
	DashAbility,
	SlamAbility
};