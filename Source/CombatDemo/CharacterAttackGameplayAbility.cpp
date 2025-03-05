// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterAttackGameplayAbility.h"

void UCharacterAttackGameplayAbility::HandleAttackAnimNotify(FName InputValue, EAttackNotifyType& Result)
{
	if (InputValue == "LightHitStart") {
		Result = EAttackNotifyType::LightHitStart;
	}
	else if (InputValue == "HeavyHitStart") {
		Result = EAttackNotifyType::HeavyHitStart;
	}
	else if (InputValue == "LightKickStart") {
		Result = EAttackNotifyType::LightKickStart;
	}
	else if (InputValue == "HeavyKickStart") {
		Result = EAttackNotifyType::HeavyKickStart;
	}
	else if (InputValue == "LightHit") {
		Result = EAttackNotifyType::LightHit;
	}
	else if (InputValue == "HeavyHit") {
		Result = EAttackNotifyType::HeavyHit;
	}
	else if (InputValue == "LowKick") {
		Result = EAttackNotifyType::LowKick;
	}
	else if (InputValue == "MidKick") {
		Result = EAttackNotifyType::MidKick;
	}
	else if (InputValue == "HighKick") {
		Result = EAttackNotifyType::HighKick;
	}
	else if (InputValue == "HitEnd") {
		Result = EAttackNotifyType::HitEnd;
	}
	else if (InputValue == "AttackEnd") {
		Result = EAttackNotifyType::AttackEnd;
	}
}

FVector UCharacterAttackGameplayAbility::GetHitTraceStart() const
{
	return Character->GetActorLocation() + HitStartHeight;
}

FVector UCharacterAttackGameplayAbility::GetHitTraceEnd() const
{
	return Character->GetActorLocation() + HitEndHeight + Character->GetActorRotation().Vector() * HitReach;
}

float UCharacterAttackGameplayAbility::GetDamage() const
{
	return HitDamage;
}

void UCharacterAttackGameplayAbility::SetLightPunch()
{
	HitDamage = LightHitDamage;
	HitReach = LightHitReach;
	HitRadius = LightHitRadius;
	StaminaActionCost = LightHitCost;
	HitStartHeight = ShoulderHeight;
	HitEndHeight = ShoulderHeight;
}

void UCharacterAttackGameplayAbility::SetHeavyPunch()
{
	HitDamage = HeavyHitDamage;
	HitReach = HeavyHitReach;
	HitRadius = HeavyHitRadius;
	StaminaActionCost = HeavyHitCost;
	HitStartHeight = ShoulderHeight;
	HitEndHeight = ShoulderHeight;
}

void UCharacterAttackGameplayAbility::SetLowKick()
{
	HitDamage = LightKickDamage;
	HitReach = LightKickReach;
	HitRadius = LightKickRadius;
	StaminaActionCost = LightKickCost;
	HitStartHeight = HipHeight;
	HitEndHeight = LowHitHeight;
}

void UCharacterAttackGameplayAbility::SetMidKick()
{
	HitDamage = HeavyKickDamage;
	HitReach = HeavyKickReach;
	HitRadius = HeavyKickRadius;
	StaminaActionCost = HeavyKickCost;
	HitStartHeight = HipHeight;
	HitEndHeight = HipHeight;
}

void UCharacterAttackGameplayAbility::SetHighKick()
{
	HitDamage = HeavyKickDamage;
	HitReach = HeavyKickReach;
	HitRadius = HeavyKickRadius;
	StaminaActionCost = HeavyKickCost;
	HitStartHeight = HipHeight;
	HitEndHeight = HighHitHeight;
}

bool UCharacterAttackGameplayAbility::CanStartAttack() const
{
	if (!AttackMontage)
		return false;

	if (AttackMontage->GetName() == "AM_Punch1")
		return Character->GetStamina() >= LightHitCost;
	else if (AttackMontage->GetName() == "AM_Kick")
		return Character->GetStamina() >= LightKickCost;
	else
		return false;
}

bool UCharacterAttackGameplayAbility::CanDoLightAttack() const
{
	return Character->GetStamina() >= LightHitCost;
}

bool UCharacterAttackGameplayAbility::CanDoHeavyAttack() const
{
	return Character->GetStamina() >= HeavyHitCost;
}

bool UCharacterAttackGameplayAbility::CanDoLightKick() const
{
	return Character->GetStamina() >= LightKickCost;
}

bool UCharacterAttackGameplayAbility::CanDoHeavyKick() const
{
	return Character->GetStamina() >= HeavyKickCost;
}

bool UCharacterAttackGameplayAbility::IsHoldingAttackKey() const
{
	if (!Character)
		return false;

	if(Character->CharacterASC->HasMatchingGameplayTag(FGameplayTag::RequestGameplayTag(FName("Attack.Hit"))) && Character->isHitting)
		return true;
	if (Character->CharacterASC->HasMatchingGameplayTag(FGameplayTag::RequestGameplayTag(FName("Attack.Kick"))) && Character->isKicking)
		return true;

	return false;
}

