// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CombatDemo.h"
#include "Abilities/GameplayAbility.h"
#include "CharacterGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class COMBATDEMO_API UCharacterGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, Category = "Ability")
	EAbilityInputID AbilityInputId{ EAbilityInputID::None };

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Owner")
	class ACombatDemoCharacter* Character;
public:
	EAbilityInputID GetAbilityInputID() { return AbilityInputId; }
};
