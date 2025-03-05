// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "Interfaces/AttackingEntity.h"
#include "CannonLizardAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class COMBATDEMO_API UCannonLizardAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
	
private:
	FTimerHandle stateSetTimerHandle;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	APawn* owner;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isAttacking = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isShooting = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool isAttackOnCooldown = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float attackCooldown = 1.0f;

	float angularMomentum;

public:
	UFUNCTION(BlueprintCallable)
	void DoAttackAnim();

	UFUNCTION(BlueprintCallable)
	void DoShootAnim();

	UFUNCTION(BlueprintCallable)
	void StopShooting();

protected:
	UFUNCTION(BlueprintCallable)
	void SetAttackingOff();

	UFUNCTION(BlueprintCallable)
	void SetShootingOff();

	void TurnOffAttackCooldown();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetVelocity() const;
};
