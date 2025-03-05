// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterDashGameplayAbility.h"

void UCharacterDashGameplayAbility::HandleDashAnimNotify(FName InputValue, EDashNotifyType& Result)
{
	if (InputValue == "SmallDashStart") {
		Result = EDashNotifyType::SmallDashStart;
	}
	else if (InputValue == "BigDashStart") {
		Result = EDashNotifyType::BigDashStart;
	}
	else if (InputValue == "SmallDash") {
		Result = EDashNotifyType::SmallDash;
	}
	else if (InputValue == "BigDash") {
		Result = EDashNotifyType::BigDash;
	}
	else if (InputValue == "DashEnd") {
		Result = EDashNotifyType::DashEnd;
	}
	else if (InputValue == "FullDashEnd") {
		Result = EDashNotifyType::FullDashEnd;
	}
}

bool UCharacterDashGameplayAbility::CanDoSmallDash() const
{
	return Character->GetStamina() >= SmallDashCost;
}

bool UCharacterDashGameplayAbility::CanDoBigDash() const
{
	return Character->GetStamina() >= BigDashCost;
}

void UCharacterDashGameplayAbility::SetSmallDash()
{
	StaminaActionCost = SmallDashCost;
}

void UCharacterDashGameplayAbility::SetBigDash()
{
	StaminaActionCost = BigDashCost;
}
