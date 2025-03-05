// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "HealthAttributeSet.generated.h"

DECLARE_MULTICAST_DELEGATE_FourParams(FDamageTakenEvent, AActor* /*EffectInstigator*/, AActor* /*EffectCauser*/, const FGameplayTagContainer& /*GameplayTagContainer*/, float /*Damage*/)
/**
 * 
 */
UCLASS()
class COMBATDEMO_API UHealthAttributeSet : public UBaseAttributeSet
{
	GENERATED_BODY()
	
public:
	UHealthAttributeSet();

	UPROPERTY(BlueprintReadOnly, Category = "HealthAttributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UHealthAttributeSet, Health)

	UPROPERTY(BlueprintReadOnly, Category = "HealthAttributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UHealthAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, Category = "HealthAttributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Shield;
	ATTRIBUTE_ACCESSORS(UHealthAttributeSet, Shield);

	UPROPERTY(BlueprintReadOnly, Category = "HealthAttributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxShield;
	ATTRIBUTE_ACCESSORS(UHealthAttributeSet, MaxShield);

	UPROPERTY(BlueprintReadOnly, Category = "HealthAttributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UHealthAttributeSet, Stamina);

	UPROPERTY(BlueprintReadOnly, Category = "HealthAttributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UHealthAttributeSet, MaxStamina);

	UPROPERTY(BlueprintReadOnly, Category = "HealthAttributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData ShieldRegen;
	ATTRIBUTE_ACCESSORS(UHealthAttributeSet, ShieldRegen);

	UPROPERTY(BlueprintReadOnly, Category = "HealthAttributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData HealthRegen;
	ATTRIBUTE_ACCESSORS(UHealthAttributeSet, HealthRegen);

	UPROPERTY(BlueprintReadOnly, Category = "HealthAttributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData StaminaRegen;
	ATTRIBUTE_ACCESSORS(UHealthAttributeSet, StaminaRegen);

	UPROPERTY(BlueprintReadOnly, Category = "HealthAttributes", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData InDamage;
	ATTRIBUTE_ACCESSORS(UHealthAttributeSet, InDamage);

	mutable FDamageTakenEvent OnDamageTaken;

protected:
	virtual void ClampAttributeOnChange(const FGameplayAttribute& Attribute, float& NewValue) const override;

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;
};
