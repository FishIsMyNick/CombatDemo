// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CombatDemo.h"
#include "Abilities/GameplayAbility.h"
#include "ActorGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class COMBATDEMO_API UActorGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, Category = "Ability")
	EAbilityInputID AbilityInputId{ EAbilityInputID::None };

public:
	EAbilityInputID GetAbilityInputID() { return AbilityInputId; }
};
