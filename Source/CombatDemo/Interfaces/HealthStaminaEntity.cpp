// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthStaminaEntity.h"

float IHealthStaminaEntity::GetStamina() const
{
    return 0.0f;
}

float IHealthStaminaEntity::LoseStamina(float amount)
{
    return 0.0f;
}

float IHealthStaminaEntity::RegainStamina(float amount)
{
    return 0.0f;
}

void IHealthStaminaEntity::StopStaminaRegen()
{
}

void IHealthStaminaEntity::StartStaminaRegenTimer()
{
}

void IHealthStaminaEntity::StaminaRegenLoop()
{
}
