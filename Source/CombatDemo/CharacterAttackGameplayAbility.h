// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterGameplayAbility.h"
#include "CombatDemoCharacter.h"
#include "CharacterAttackGameplayAbility.generated.h"

UENUM(BlueprintType)
enum class EAttackNotifyType : uint8
{
	LightHitStart UMETA(DisplayName = "LightHitStart"),
	HeavyHitStart UMETA(DisplayName = "HeavyHitStart"),
	LightKickStart UMETA(DisplayName = "LightKickStart"),
	HeavyKickStart UMETA(DisplayName = "HeavyKickStart"),
	LightHit UMETA(DisplayName = "LightHit"),
	HeavyHit UMETA(DisplayName = "HeavyHit"),
	LowKick UMETA(DisplayName = "LowKick"),
	MidKick UMETA(DisplayName = "MidKick"),
	HighKick UMETA(DisplayName = "HighKick"),
	HitEnd UMETA(DisplayName = "HitEnd"),
	AttackEnd UMETA(DisplayName = "AttackEnd")
};
/**
 * 
 */
UCLASS()
class COMBATDEMO_API UCharacterAttackGameplayAbility : public UCharacterGameplayAbility
{
	GENERATED_BODY()
protected:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Owner")
	class UAnimMontage* AttackMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	float StaminaActionCost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	float HitDamage = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	float HitReach = 15;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	float HitRadius = 15;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	FVector HitStartHeight = { 0, 0, 0 };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	FVector HitEndHeight = { 0, 0, 0 };
	// Light Hit
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	float LightHitDamage = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	float LightHitReach = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	float LightHitRadius = 30;
	// Heavy Hit
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	float HeavyHitDamage = 20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	float HeavyHitReach = 110;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	float HeavyHitRadius = 45;
	// Light Kick
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	float LightKickDamage = 15;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	float LightKickReach = 90;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	float LightKickRadius = 30;
	// Heavy Kick
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	float HeavyKickDamage = 30;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	float HeavyKickReach = 120;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	float HeavyKickRadius = 40;
	// Hit Heights
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	FVector ShoulderHeight = { 0, 0, 30 };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	FVector HipHeight = { 0, 0, 0 };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	FVector LowHitHeight = { 0, 0, -50 };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	FVector MidHitHeight = { 0, 0, 0 };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack")
	FVector HighHitHeight = { 0, 0, 50 };

	// Stamina costs
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Costs")
	float LightHitCost = 5;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Costs")
	float HeavyHitCost = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Costs")
	float LightKickCost = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Costs")
	float HeavyKickCost = 20;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Costs")
	float SmallDashCost = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Costs")
	float BigDashCost = 20;

private:
	UFUNCTION(BlueprintCallable, Category = "Custom Node", meta = (ExpandEnumAsExecs = "Result"))
	void HandleAttackAnimNotify(FName InputValue, EAttackNotifyType& Result);

protected:
	// GETTERS
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FVector GetHitTraceStart() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	FVector GetHitTraceEnd() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	float GetDamage() const;
	// SETTERS
	UFUNCTION(BlueprintCallable)
	void SetLightPunch();

	UFUNCTION(BlueprintCallable)
	void SetHeavyPunch();

	UFUNCTION(BlueprintCallable)
	void SetLowKick();

	UFUNCTION(BlueprintCallable)
	void SetMidKick();

	UFUNCTION(BlueprintCallable)
	void SetHighKick();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool CanStartAttack() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool CanDoLightAttack() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool CanDoHeavyAttack() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool CanDoLightKick() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool CanDoHeavyKick() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool IsHoldingAttackKey() const;

};
