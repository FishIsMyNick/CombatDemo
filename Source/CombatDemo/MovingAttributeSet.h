// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "MovingAttributeSet.generated.h"

//DECLARE_MULTICAST_DELEGATE_FourParams(FDamageTakenEvent, AActor* /*EffectInstigator*/, AActor* /*EffectCauser*/, const FGameplayTagContainer& /*GameplayTagContainer*/, float /*Damage*/)
/**
 *
 */
UCLASS()
class COMBATDEMO_API UMovingAttributeSet : public UBaseAttributeSet
{
	GENERATED_BODY()

public:
	UMovingAttributeSet();


	UPROPERTY(BlueprintReadOnly, Category = "MovingAttributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MovementSpeed;
	ATTRIBUTE_ACCESSORS(UMovingAttributeSet, MovementSpeed)

	UPROPERTY(BlueprintReadOnly, Category = "MovingAttributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData DefaultMovementSpeed;
	ATTRIBUTE_ACCESSORS(UMovingAttributeSet, DefaultMovementSpeed)

	UPROPERTY(BlueprintReadOnly, Category = "MovingAttributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxMovementSpeed;
	ATTRIBUTE_ACCESSORS(UMovingAttributeSet, MaxMovementSpeed)

protected:
	virtual void ClampAttributeOnChange(const FGameplayAttribute& Attribute, float& NewValue) const override;

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
};
