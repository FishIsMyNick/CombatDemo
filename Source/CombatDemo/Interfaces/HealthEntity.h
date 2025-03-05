// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "HealthEntity.generated.h"

/**
 * 
 */
UINTERFACE(MinimalAPI)
class UHealthEntity : public UInterface
{
	GENERATED_BODY()
};

class IHealthEntity
{
	GENERATED_BODY()

public:
	/// <summary>
	/// Return the health
	/// </summary>
	/// <returns></returns>
	virtual float GetHealth() const;

	/// <summary>
	/// Deal damage to self
	/// </summary>
	/// <param name="amount"></param>
	/// <returns></returns>
	virtual float TakeDamage(float amount);

	/// <summary>
	/// Regain health
	/// </summary>
	/// <param name="amount"></param>
	/// <returns></returns>
	virtual float HealHealth(float amount);

	virtual void StartHealthRegenTimer();
	virtual void HealthRegenLoop();
	virtual void StopHealthRegen();

	/// <summary>
	/// Kill self
	/// </summary>
	virtual void Die();
};
