// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "HealthEntity.h"
#include "HealthStaminaEntity.generated.h"

/**
 * 
 */
UINTERFACE(MinimalAPI)
class UHealthStaminaEntity : public UInterface
{
	GENERATED_BODY()
};

class IHealthStaminaEntity 
{
	GENERATED_BODY()
public:

	virtual float GetStamina() const;
	virtual float LoseStamina(float amount);
	virtual float RegainStamina(float amount);
	virtual void StartStaminaRegenTimer();
	virtual void StaminaRegenLoop();
	virtual void StopStaminaRegen();
};