// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthEntity.h"

float IHealthEntity::GetHealth() const
{
    return 0.0f;
}

float IHealthEntity::TakeDamage(float amount)
{
    return 0.0f;
}

float IHealthEntity::HealHealth(float amount)
{
    return 0.0f;
}

void IHealthEntity::StartHealthRegenTimer()
{
}

void IHealthEntity::HealthRegenLoop()
{
}

void IHealthEntity::StopHealthRegen()
{
}

void IHealthEntity::Die()
{
}
