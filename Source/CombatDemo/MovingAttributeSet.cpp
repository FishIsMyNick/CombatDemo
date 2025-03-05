// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingAttributeSet.h"

UMovingAttributeSet::UMovingAttributeSet()
{
}

void UMovingAttributeSet::ClampAttributeOnChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	if (Attribute == GetMovementSpeedAttribute()) {
		NewValue = FMath::Clamp(NewValue, 0.0f, GetMaxMovementSpeed());
	}
}

void UMovingAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);
}
