// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterGameplayAbility.h"
#include "CombatDemoCharacter.h"
#include "CharacterDashGameplayAbility.generated.h"

UENUM(BlueprintType)
enum class EDashNotifyType : uint8
{
	SmallDashStart UMETA(DisplayName = "SmallDashStart"),
	BigDashStart UMETA(DisplayName = "BigDashStart"),
	SmallDash UMETA(DisplayName = "SmallDash"),
	BigDash UMETA(DisplayName = "BigDash"),
	DashEnd UMETA(DisplayName = "DashEnd"),
	FullDashEnd UMETA(DisplayName = "FullDashEnd")
};
/**
 * 
 */
UCLASS()
class COMBATDEMO_API UCharacterDashGameplayAbility : public UCharacterGameplayAbility
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Owner")
	class UAnimMontage* DashMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Costs")
	float StaminaActionCost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Costs")
	float SmallDashCost = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Costs")
	float BigDashCost = 20;

private:
	UFUNCTION(BlueprintCallable, Category = "Custom Node", meta = (ExpandEnumAsExecs = "Result"))
	void HandleDashAnimNotify(FName InputValue, EDashNotifyType& Result);

public:
	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool CanDoSmallDash() const;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	bool CanDoBigDash() const;

	UFUNCTION(BlueprintCallable)
	void SetSmallDash();

	UFUNCTION(BlueprintCallable)
	void SetBigDash();
};
