// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterGameplayAbility.h"
#include "CancelGameplayAbility.generated.h"

/**
 * 
 */
UCLASS()
class COMBATDEMO_API UCancelGameplayAbility : public UCharacterGameplayAbility
{
	GENERATED_BODY()


public:
    // Tags to cancel
    UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Tags")
    FGameplayTagContainer TagsToCancel;
};
