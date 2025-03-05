// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseAttributeSet.h"
#include "CannonLizardAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class COMBATDEMO_API UCannonLizardAttributeSet : public UBaseAttributeSet
{
	GENERATED_BODY()
	
public:
	UCannonLizardAttributeSet();

	UPROPERTY(BlueprintReadOnly, Category = "AttackAttributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData HitDamage;
	ATTRIBUTE_ACCESSORS(UCannonLizardAttributeSet, HitDamage)

		UPROPERTY(BlueprintReadOnly, Category = "AttackAttributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData HitRange;
	ATTRIBUTE_ACCESSORS(UCannonLizardAttributeSet, HitRange)

		UPROPERTY(BlueprintReadOnly, Category = "AttackAttributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData SpitDamage;
	ATTRIBUTE_ACCESSORS(UCannonLizardAttributeSet, SpitDamage)

		UPROPERTY(BlueprintReadOnly, Category = "AttackAttributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData SpitRange;
	ATTRIBUTE_ACCESSORS(UCannonLizardAttributeSet, SpitRange)
};
