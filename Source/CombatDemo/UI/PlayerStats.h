// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PlayerStats.generated.h"

/**
 * 
 */
UCLASS()
class COMBATDEMO_API UPlayerStats : public UUserWidget
{
	GENERATED_BODY()

protected:
	float Stamina;
	float MaxStamina = 100;
	float Shield;
	float MaxShield = 100;
	float Health;
	float MaxHealth = 100;
	
public:
	UFUNCTION(BlueprintCallable)
	void InitStats(float maxStamina, float maxHealth, float maxShield);

	UFUNCTION(BlueprintCallable)
	void ReduceHealth(float amount);

	UFUNCTION(BlueprintCallable)
	void SetHealth(float amount);

	UFUNCTION(BlueprintCallable)
	void ReduceStamina(float amount);

	UFUNCTION(BlueprintCallable)
	void SetStamina(float amount);

	UFUNCTION(BlueprintCallable)
	void ReduceShield(float amount);

	UFUNCTION(BlueprintCallable)
	void SetShield(float amount);

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetStaminaPercentage() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetShieldPercentage() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetHealthPercentage() const;
};
