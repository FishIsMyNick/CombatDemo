// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerStats.h"

void UPlayerStats::InitStats(float maxStamina, float maxHealth, float maxShield)
{
	Stamina = MaxStamina = maxStamina;
	Health = MaxHealth = maxHealth;
	Shield = MaxShield = maxShield;
}

void UPlayerStats::ReduceHealth(float amount)
{
	Health = FMath::Clamp(Health - amount, 0, MaxHealth);
}

void UPlayerStats::SetHealth(float amount)
{
	Health = FMath::Clamp(amount, 0, MaxHealth);
}

void UPlayerStats::ReduceStamina(float amount)
{
	Stamina = FMath::Clamp(Stamina - amount, 0, MaxStamina);
}

void UPlayerStats::SetStamina(float amount)
{
	Stamina = FMath::Clamp(amount, 0, MaxStamina);
}

void UPlayerStats::ReduceShield(float amount)
{
	Shield = FMath::Clamp(Shield - amount, 0, MaxShield);
}

void UPlayerStats::SetShield(float amount)
{
	Shield = FMath::Clamp(amount, 0, MaxShield);
}

float UPlayerStats::GetStaminaPercentage() const
{
	return Stamina / MaxStamina;
}

float UPlayerStats::GetShieldPercentage() const
{
	return Shield / MaxShield;
}

float UPlayerStats::GetHealthPercentage() const
{
	return Health / MaxHealth;
}
